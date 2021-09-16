#ifndef __CLASEGENERAL_HPP__
#define __CLASEGENERAL_HPP__

#include <string>

class Persona
{
private:
    int id;
    std::string nombre;
    float promedio;
public:
    Persona(int _id = 0, std::string _nombre = "", float _promedio = 0.0): id(_id), nombre(_nombre), promedio(_promedio) {}
    ~Persona() = default;
    int getId() { return this->id; }
    std::string getNombre() { return this->nombre; }
    float getPromedio() { return this->promedio; }
};

#endif // __CLASEGENERAL_HPP__