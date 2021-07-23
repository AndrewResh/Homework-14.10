#include "Trie.h"
#include <iostream>

using namespace std;

// Функция возвращет новый узел с пустыми детьми
TrieNode* getNewNode()
{
    // Выделяем память по новый узел
    struct TrieNode* pNode = new TrieNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false;
    pNode->freq = 1;

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


// Вставляем ключ в дерево, если его нет 
// иначе если ключ явлется префксом узла дерева 
// помечает вкачестве листового т.е. конец слова
void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    root->freq = 0;

    for (int i = 0; i < key.length(); i++)
    {
        // вычисляем индекс в алфавите через смещение отнсительно первой буквы
        int index = key[i] - 'a';


        // если указатель пустрой, т.е. детей с таким префиксом нет
        // создаем новый узел
        if (!node->children[index])
            node->children[index] = getNewNode();
        else
            (node->children[index]->freq)++;

        node = node->children[index];
    }

    // помечаем последний узел как лист, т.е. конец слова
    node->isEndOfWord = true;
}

// Возвращает true если root имеет лист, иначе false 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET; i++)
        if (root->children[i])
            return false;
    return true;
}

// Рекурсивная функция удаления ключа из дерева 
TrieNode* remove(TrieNode* root, string key, int depth)
{
    // Если дерево пустое 
    if (!root)
        return nullptr;

    // если дошли до конца ключа 
    if (depth == key.size()) 
    {
        // Этот узел больше не конец слова 
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // Если ключ не является префиксом, удаляем его
        if (isEmpty(root)) 
        {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // Если не дошли до конца ключа, рекурсивно вызываем для ребенка 
    // соответствующего символа 
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    // Если у корня нет дочернего слова 
    // (удален только один его дочерний элемент), 
    // и он не заканчивается другим словом. 
    if (isEmpty(root) && root->isEndOfWord == false) 
    {
        delete (root);
        root = nullptr;
    }

    // возвращаем новый корень
    return root;
}

// поиск минимального префикса
void findMinPrefixes(TrieNode* root, char buffer[], int ind, string& res)
{
    
    if (root == nullptr)
        return;

    if (root->freq == 1)
    {
        buffer[ind] = '\0';
        res += string(buffer) + " ";
        return;
    }

    for (int i = 0; i < ALPHABET; i++)
    {
        if (root->children[i] != nullptr)
        {
            char c = i + 'a';
            buffer[ind] = c;
            
            findMinPrefixes(root->children[i], buffer, ind + 1, res);
        }
    }
}

// поиск узла которым заканчивается ключ 
TrieNode* find(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return nullptr;

        node = node->children[index];
    }

    if (node != nullptr)
        return node;
    else
        return nullptr;
}

// рекурсивная функция поиска частей слов находящися ниже узла root
void searchWords(struct TrieNode* root, char buffer[], int ind, string& res)
{
    if (root == nullptr)
        return;

    if (root->isEndOfWord)
    {
        buffer[ind] = ' ';
        buffer[ind + 1] = '\0';
        cout << res << buffer << endl;

        if (isEmpty(root))
            return;
    }

    for (int i = 0; i < ALPHABET; i++)
    {
        if (root->children[i] != nullptr)
        {
            buffer[ind] = static_cast<char>(i + 97);
            searchWords(root->children[i], buffer, ind + 1, res);
        }
    }
}