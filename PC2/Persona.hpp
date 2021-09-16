#pragma once
#ifndef __PERSONA_HPP__
#define __PERSONA_HPP__

#include <string>

class Person
{
public:
    std::string name;
    int dni;
    int grupoVotacion;
    Person* next;
public:
    Person() {}
    Person(std::string _name, int _dni, int grupo, Person* _next = nullptr);
    std::string getName() {return this->name;}
    int getDni() { return this->dni; }
    int getGrupo() { return this->grupoVotacion; }
    Person* getNext() { return this->next; }
    void setNext(Person* _next) { this->next = _next; }
};

Person::Person(std::string _name, int _dni, int grupo, Person* _next) : name(_name), dni(_dni), grupoVotacion(grupo), next(_next) {}

#endif