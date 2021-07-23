#include <iostream>
#include "Trie.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int ind = 0; //индикатор 
    char buffer[50]; //буфер символов (вводимых слов)
    string findStr; //строка поиска

    // создаем и заполняем префиксное дерево
    TrieNode* root = getNewNode();

    insert(root, "and");
    insert(root, "all");
    insert(root, "are");
    insert(root, "around");
    insert(root, "again");
    insert(root, "begin");
    insert(root, "because");
    insert(root, "black");
    insert(root, "break");
    insert(root, "better");
    insert(root, "friend"); 
    insert(root, "father");
    insert(root, "forward");
    insert(root, "finally");
    insert(root, "shadow");
    insert(root, "silence");
    insert(root, "surpise");
    insert(root, "school");
    insert(root, "study");
    insert(root, "uncomfortable");
    insert(root, "unknown");
    insert(root, "underground");
    insert(root, "winter");
    insert(root, "warrior");
    insert(root, "wednesday");
    insert(root, "violet");
    insert(root, "valley");
    insert(root, "vehicle");
    
    char choice; 
    do {
        cout << "Выберите: поиск нужного слова (f) или выход из программы (q) : ";

        cin >> choice;

        if ((choice != 'f') && (choice != 'q'))
            continue;

        if (choice == 'q')
            continue;
        
        cout << "Введите слово полностью или его первые буквы (a-z): ";
        cin.ignore();
        getline(cin, findStr);
        TrieNode* findPrefixes = find(root, findStr); 

        if (findPrefixes == nullptr)
            cout << "Ничего не найдено, попробуйте ещё раз" << endl;
        else 
        {
            cout << "Возможно, Вы имели ввиду слово: " << endl;
            searchWords(findPrefixes, buffer, ind, findStr);
        }
                   
        cin.clear();

    } 
    while (choice != 'q');
    cout << "До свидания! " << endl;

    return 0;
}
