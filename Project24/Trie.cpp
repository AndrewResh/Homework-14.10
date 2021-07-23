#include "Trie.h"
#include <iostream>

using namespace std;

// ������� ��������� ����� ���� � ������� ������
TrieNode* getNewNode()
{
    // �������� ������ �� ����� ����
    struct TrieNode* pNode = new TrieNode;

    // ������������� ���� ����� ����� � false
    pNode->isEndOfWord = false;
    pNode->freq = 1;

    // �������������� ����� ������� ���������
    for (int i = 0; i < ALPHABET; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


// ��������� ���� � ������, ���� ��� ��� 
// ����� ���� ���� ������� �������� ���� ������ 
// �������� ��������� ��������� �.�. ����� �����
void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    root->freq = 0;

    for (int i = 0; i < key.length(); i++)
    {
        // ��������� ������ � �������� ����� �������� ����������� ������ �����
        int index = key[i] - 'a';


        // ���� ��������� �������, �.�. ����� � ����� ��������� ���
        // ������� ����� ����
        if (!node->children[index])
            node->children[index] = getNewNode();
        else
            (node->children[index]->freq)++;

        node = node->children[index];
    }

    // �������� ��������� ���� ��� ����, �.�. ����� �����
    node->isEndOfWord = true;
}

// ���������� true ���� root ����� ����, ����� false 
bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET; i++)
        if (root->children[i])
            return false;
    return true;
}

// ����������� ������� �������� ����� �� ������ 
TrieNode* remove(TrieNode* root, string key, int depth)
{
    // ���� ������ ������ 
    if (!root)
        return nullptr;

    // ���� ����� �� ����� ����� 
    if (depth == key.size()) 
    {
        // ���� ���� ������ �� ����� ����� 
        if (root->isEndOfWord)
            root->isEndOfWord = false;

        // ���� ���� �� �������� ���������, ������� ���
        if (isEmpty(root)) 
        {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // ���� �� ����� �� ����� �����, ���������� �������� ��� ������� 
    // ���������������� ������� 
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    // ���� � ����� ��� ��������� ����� 
    // (������ ������ ���� ��� �������� �������), 
    // � �� �� ������������� ������ ������. 
    if (isEmpty(root) && root->isEndOfWord == false) 
    {
        delete (root);
        root = nullptr;
    }

    // ���������� ����� ������
    return root;
}

// ����� ������������ ��������
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

// ����� ���� ������� ������������� ���� 
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

// ����������� ������� ������ ������ ���� ���������� ���� ���� root
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