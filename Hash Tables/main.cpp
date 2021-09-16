#include <iostream>

#include "Hashes2.hpp"
#include "Person.hpp"

int main()
{
    HashTable<Person*>* table = new HashTable<Person*>(10);

    Person* p0 = new Person("Jacob", 12345678, 123114);
    Person* p1 = new Person("Natalie",  15425678, 141243);
    Person* p2 = new Person("Sara",  42315234,543124);
    Person* p3 = new Person("Sara",  5467657,341242);
    Person* p4 = new Person("Sae",  23645676,532123);
    Person* p5 = new Person("Sae",  65345673,421242);
    Person* p6 = new Person("Torres",  23423567,124452);
    Person* p7 = new Person("Torres",  75345632,542124);
    table->insert(p0);
    table->insert(p1);
    table->insert(p2);
    table->insert(p3);
    table->insert(p4);
    table->insert(p5);
    table->insert(p6);

    table->print();

    return 0;
}