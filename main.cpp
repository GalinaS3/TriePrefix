#include"Trie.h"

int main()
{
    setlocale(LC_ALL, "");

    Trie trie;
    trie.constructionDictionary();
     std::cout << std::endl;
 
     //тесты
     trie.wordsPrefix("(5");
     trie.wordsPrefix("ref");
     trie.wordsPrefix("ццц");
     trie.wordsPrefix("");
     trie.wordsPrefix("chi");
     
     //с вводом префикса пользователем
    std::string pref = trie.enterPrefix();
     trie.wordsPrefix(pref);

    return 0;
}