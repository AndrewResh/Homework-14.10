#include <iostream>
#include "Trie.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    int ind = 0; //��������� 
    char buffer[50]; //����� �������� (�������� ����)
    string findStr; //������ ������

    // ������� � ��������� ���������� ������
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
        cout << "��������: ����� ������� ����� (f) ��� ����� �� ��������� (q) : ";

        cin >> choice;

        if ((choice != 'f') && (choice != 'q'))
            continue;

        if (choice == 'q')
            continue;
        
        cout << "������� ����� ��������� ��� ��� ������ ����� (a-z): ";
        cin.ignore();
        getline(cin, findStr);
        TrieNode* findPrefixes = find(root, findStr); 

        if (findPrefixes == nullptr)
            cout << "������ �� �������, ���������� ��� ���" << endl;
        else 
        {
            cout << "��������, �� ����� ����� �����: " << endl;
            searchWords(findPrefixes, buffer, ind, findStr);
        }
                   
        cin.clear();

    } 
    while (choice != 'q');
    cout << "�� ��������! " << endl;

    return 0;
}
