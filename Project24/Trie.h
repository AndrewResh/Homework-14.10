#pragma once
#include <string>
using namespace std;

const int ALPHABET = 26;


struct TrieNode // ��������� ���� ������ 
{
    struct TrieNode* children[ALPHABET];
    
    bool isEndOfWord; // ������� ������� isEndOfWord - true, ���� ���� �������� ������ �����; false - ��������
    int freq;
};


TrieNode* getNewNode();
void insert(TrieNode*, string); //������� �������
bool isEmpty(TrieNode*); // �������� ������� ����
TrieNode* remove(TrieNode*, string, int depth = 0); //������� ��������
void findMinPrefixes(TrieNode*, char[], int, string&); //������� ������ ����������� ������������ ��������
TrieNode* find(TrieNode*, string); //������� ������
void searchWords(TrieNode*, char[], int, string&); //����� ����