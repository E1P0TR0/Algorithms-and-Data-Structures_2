#include <iostream>

// TRIE STRUCTURE

#define N 256

class Node
{
public:
    char letter;
    bool isWord;
    std::string definition;
    Node* children[N];

    Node(char l) : letter(l), isWord(false), definition("")
    {
        for(int i = 0; i < N; i++)
            children[i] = NULL;
    }
};

class Trie
{
private:
    Node* root;

    Node* getNode(std::string word)
    {
        Node* current = root;
        for(auto value : word)
        {
            if(current->children[value - 'a'] == NULL)
                return NULL;
            current = current->children[value - 'a'];
        }
        return current;
    }

public:

    Trie() : root(new Node('\0')) {}
    
    void insert(std::string word, std::string definition)
    {
        Node* current = root;
        for(auto value : word)
        {
            if(current->children[value - 'a'] == NULL)
                current->children[value - 'a'] = new Node(value);
            current = current->children[value - 'a'];
        }
        current->isWord = true;
        current->definition = definition;
    }

    std::string search(std::string word)
    {
        Node* node = getNode(word);
        return (node != NULL && node->isWord) ? node->definition : "No existe!";
    }

    bool startWith(std::string prefix) { return getNode(prefix) != NULL; }
};

int main()
{
    Trie* trie = new Trie();

    trie->insert("CTUTCTUCCUCTT", "asassa");
    

    std::cout << trie->search("CTUTCTUCCUCTT");

    // if(trie->startWith("b")) std::cout << "Found!\n"; else std::cout << "No EXIST!\n";
    return 0;
}