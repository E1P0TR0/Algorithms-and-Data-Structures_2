#include <iostream>
#include <fstream>
#include <string>

#define N 256

#define ebola "UTTCUC"
#define gripeviar "TCUTC"
#define sars "CTUTCTUCCCUTT"
#define mersCov "CTUTCTUCCUCTT"

class Virus
{
public:
    std::string name;
    std::string type;
    Virus(std::string _name = "", std::string _type = "") : name(_name), type(_type) {} 
};


class Node
{
public:
    char letter;
    bool isVirus;
    Virus* data;
    Node* children[N];

    Node(char l) : letter(l), isVirus(false), data(nullptr)
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
            if(current->children[tolower(value) - 'a'] == NULL)
                return NULL;
            current = current->children[tolower(value) - 'a'];
        }
        return current;
    }

public:

    Trie() : root(new Node('\0')) {}
    
    Node* getRoot() { return this->root; }

    void insertRecur(Node* n, std::string word, int i)
    {
        if(i < word.length())
        {
            int j = tolower(word[i]) - 'a';
            if(n->children[j] == NULL)
                n->children[j] = new Node(tolower(word[i]));
            insertRecur(n->children[j], word, i + 1);
        }
        else
            if(word == ebola)
            {
                n->data = new Virus("ebola", "T1");
                n->isVirus = true;
            }
            else if(word == gripeviar)
            {
                n->data = new Virus("gripe aviar", "T2");
                n->isVirus = true;
            }
            else if(word == sars)
            {
                n->data = new Virus("sars", "T3");
                n->isVirus = true;
                    
            }
            else if(word == mersCov)
            {
                n->data = new Virus("mers-Cov", "T4");
                n->isVirus = true;
            }
    }

    void insert(std::string word) { insertRecur(root, word, 0); }

    std::string search(std::string word)
    {
        Node* node = getNode(word);
        return (node != NULL && node->isVirus) ? node->data->type : "No existe!\n";
    }

    // void startWith(std::string prefix) 
    // { 
    //     Node* aux = getNode(prefix);
    //     if(getNode(prefix) != NULL) std::cout << aux->data->type;
    // }

    // int count(std::string type, int c)
    // {
    //     int cont = c;
    //     if(search(ebola) == type)
    //     {
    //         cont++;
    //         count(type, cont);
    //     }
    //     return cont;
    // }

    bool empty(Node* n)
    {
        for(int i = 0; i < N; i++)
            if(n->children[i])
                return false;
        return true;
    }

    Node* remove(Node* n, std::string word, int profund = 0)
    {
        if(!n)
            return NULL;
    
        if(profund == word.size()) 
        {
            if(n->isVirus)
                n->isVirus = false;
    
            if(empty(n)) 
            {
                delete(n);
                n = NULL;
            }
            return n;
        }
    
        int i = tolower(word[profund]) - 'a';
        n->children[i] = remove(n->children[i], word, profund + 1);
    
        if(empty(n) && n->isVirus == false) 
        {
            delete (n);
            n = NULL;
        }
        return n;
    }
};

class File
{
public:
    std::string text;
    std::ifstream readFile;

    Trie* aux;

    File(Trie* trie)
    {
        std::ofstream out("file.txt", std::ios::out | std::ios::app);
        aux = trie;
    }
    void read()
    {
        std::string line = "";
        readFile.open("file.txt", std::ios::in);
        if(readFile.fail()) std::cerr << "Error!\n";
        else
            while(getline(readFile, line))
                aux->insert(line);
        readFile.close();
    }

    void search(std::string word) { std::cout << aux->search(word) << "\n"; }

    // void countType(std::string type) { std::cout << aux->count(type, 0); }

    void delet(std::string word) { aux->remove(aux->getRoot(), word); }
};

int main()
{
    Trie* trie = new Trie();
    File* f = new File(trie);

    f->read();
    f->search("CTUTCTUCCUCTT");
    f->search("TCUTC");
    f->search("UTTCUC");
    f->search("CTUTCTUCCCUTT");
    // f->search("TUCTUCUTC");
    // f->search("TUCTUTCTU");

    f->delet("CTUTCTUCCUCTT");
    f->search("CTUTCTUCCUCTT");

    return 0;
}

// ABET

// Como toda red social, podriamos tomar a una persona como un nodo, y uniendo todas estos nodos tendriamos una conexión
// global, la cual representa el rol principal de una red social. Tambien podemos tener en cuenta el uso de pilas el momento    
// de mostrar las noticias que comparte cada usuario, la cual la ultima que hallas publicado en tu perfil, será la primera que
// veas al entrar. Otro factor importante es la encriptación de los datos de cada usuario, y para ello conocemos las estructuras
// de Hash, que alamacenaran estos datos de manera eficiente y segura. Y para la busqueda de usuarios se utiliza la estructura de 
// Arboles, ya que en este rol son eficientes y mas rápidos.