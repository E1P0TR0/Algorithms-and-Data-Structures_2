#include <iostream>


void boomerangSort(std::string cadena) // O(n^2)
{
    int i = 0, j = 1;                                           // 2 + 2
    while(j != cadena.length())                                 // n ( 1 + ___ + 2 + 2)
    {
        if(cadena[i] > cadena[j])                               // 1 + 1 + 1 + max (  , 0)
        {
            std::swap(cadena[i], cadena[j]);                    //
            i--; j--;                                           //
            while(cadena[i] > cadena[j])                        //
            { 
                std::swap(cadena[i], cadena[j]);                //
                i--; j--;                                       //
                if(i == -1 || (cadena[i] < cadena[j])) break;   //
            }
        }
        i++; j++;                                               //
    }
    std::cout << cadena;                                        //
}

int main()
{
    std::string cadena = "aojcnofajfofjafjaofjaofaoj";
    boomerangSort(cadena); // n = length
}