#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class File
{
public:
    std::ofstream out;
    std::ifstream in;

    std::string text;

    std::vector<char> characters;
    std::vector<int> ocurrence;

    File() { text = ""; }

    void write(std::string line)
    {   
        out.open("file.txt", std::ios::out | std::ios::trunc);
        if(out.fail()) std::cerr << "Error!\n";
        else
        {
            out << line << "\n";
            std::cout << "Correcto!\n";
        }
        out.close();
    }

    void read()
    {
        std::string line = "";
        in.open("file.txt", std::ios::in);
        if(out.fail()) std::cerr << "Error!\n";
        else
            while(getline(in, line))
                text += line;
        in.close();
    }

    void extractLetters()
    {
        read();
        bool unique = false;
        for(char letter : text)
        {
            if(characters.size() == 0) 
                characters.push_back(letter);
            else
            {
                for(char v2 : characters)
                {
                    if(letter == v2) 
                    {
                        unique = false;
                        break;
                    }
                    else
                        unique = true;
                }
                if(unique) 
                    characters.push_back(letter);
            }
        }
    }

    void calOcurrence()
    {
        int count = 0;
        for(auto value : characters)
        {
            for(auto v : text)
            {
                if(value == v)
                    count++;
            }
            ocurrence.push_back(count);
            count = 0;
        }
    }

    void printTable()
    {
        extractLetters();
        calOcurrence();
        std::cout << "Caracter    Ocurrencia\n";
        for(int i = 0; i < characters.size(); ++i)
            std::cout << "   " << characters[i] << "\t\t" << ocurrence[i] << "\n";
    }
};

int main()
{
    File* f = new File();
    f->write("adas es nada de nada");
    f->printTable();
    

    return 0;
}
