#pragma once
#include <string>
using namespace std;

const int ALPHABET = 26;


struct TrieNode // Структура узла дерева 
{
    struct TrieNode* children[ALPHABET];
    
    bool isEndOfWord; // булевая функция isEndOfWord - true, если ключ является концом слова; false - наоборот
    int freq;
};


TrieNode* getNewNode();
void insert(TrieNode*, string); //функция вставки
bool isEmpty(TrieNode*); // проверка пустого узла
TrieNode* remove(TrieNode*, string, int depth = 0); //функция удаления
void findMinPrefixes(TrieNode*, char[], int, string&); //функция поиска кратчайшего минимального суффикса
TrieNode* find(TrieNode*, string); //функция поиска
void searchWords(TrieNode*, char[], int, string&); //поиск слов