#pragma once
#include <string>
#include <iostream>
#include<vector>
#include <conio.h>


const int SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[SIZE];
    bool isEndOfWord;

    TrieNode();
    ~TrieNode();
};

class Trie
{
public:
    Trie();
    ~Trie();    

    TrieNode* getNewNode();
    void insert(TrieNode* root, const std::string &key);
    TrieNode* search(const std::string& key);
    void constructionDictionary();
    std::string enterPrefix();
    std::vector<std::string> vectorWords(TrieNode* pNode, std::string str, std::vector<std::string> vec);
    void wordsPrefix(std::string pref);

private:
    TrieNode* root;
};

