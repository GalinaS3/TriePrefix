#include "Trie.h"


TrieNode::TrieNode()
{
    isEndOfWord = false;
    for (int i = 0; i < SIZE; i++)
    children[i] = nullptr;
}
TrieNode::~TrieNode()
{
    for (int i = 0; i < SIZE; i++)
        if (children[i])
            delete children[i];
}

Trie::Trie()
{
    root = new TrieNode();
}

Trie::~Trie()
{
    if (root)
        delete root;
}

TrieNode* Trie::getNewNode()
{
    struct TrieNode* pNode = new TrieNode;
    
    pNode->isEndOfWord = false;
    
    for (int i = 0; i < SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void Trie::insert(TrieNode* root, const std::string& key)
{
    TrieNode* pNode = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
                
        if (!pNode->children[index])
        {
            pNode->children[index] = getNewNode();
        }
        pNode = pNode->children[index];
    }    
    pNode->isEndOfWord = true;
}

TrieNode* Trie::search(const std::string &key) {
    
    TrieNode* current = root;
    
    for (size_t i = 0; i < key.size(); i++) 
    {
        int index = key[i] - 'a';
        if (current->children[index] && (index < SIZE && index>=0))
        {
            current = current->children[index];
        }
        else 
        {
            current = nullptr;
            break;
        }
    }
    return current;
}

std::vector<std::string> Trie::vectorWords(TrieNode* pNode, std::string str, std::vector<std::string> vec)
{
    
    if (pNode->isEndOfWord && str.size())
    {
        vec.push_back(str);
    }

    for (int i = 0; i < SIZE; i++)
    {
        std::string curr = str;
        if (pNode->children[i]) 
        {
            curr += i + 'a';
            vec = vectorWords(pNode->children[i], curr, vec);
        }
    }
    return vec;
}

void Trie::wordsPrefix(std::string pref)
{
    std::vector<std::string> temp;
    TrieNode* current = search(pref);
    if (current == nullptr || current == root)
    {
        std::cout << "No words with prefix  " << pref << std::endl;
        if(pref == "")
        {
            std::cout << "all words in the trie: " << std::endl;
            std::vector<std::string> vec = vectorWords(root, "", temp);

            for (auto i : vec)
            {
                std::cout << i << std::endl;
            }
        }
     return;
    }

    std::vector<std::string> vec = vectorWords(current, pref, temp);
    if(vec.empty())
    {
        std::cout << "no words with prefix  " << pref  << std::endl;
        return;
    }
    else
    {
        std::cout << "selecting words by any key.  " << std::endl;
        std::cout << "enter - completing the selection  " << std::endl;
        for (int i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i];
            int input = _getch();
            std::cout << "\r";
            std::cout << "                     ";
            std::cout << "\r";

            if (input == 13)
            {
                std::cout << vec[i];
                break;
            }
        }
    }
}

std::string Trie::enterPrefix()
{
    std::cout << "enter the prefix: ";
    std::string str;
    std::cin >> str;
    
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);

    return str;
}

void Trie::constructionDictionary()
{
    insert(root, "cab");
    insert(root, "cabbage");
    insert(root, "cabin");
    insert(root, "cabinet");
    insert(root, "cable");
    insert(root, "child");
    insert(root, "children");
    insert(root, "chilly");
    insert(root, "chin");
    insert(root, "china");
    insert(root, "chirp");
    insert(root, "ear");
    insert(root, "dust");
    insert(root, "am");
}

