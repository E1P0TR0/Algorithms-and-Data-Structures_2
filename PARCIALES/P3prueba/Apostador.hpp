#include <iostream>

class Apostador
{
private:
    std::string nombre;
    float monto;
    int Nronda;
public:
    Apostador(std::string _nombre = "", float _monto = 0.0, int _Nronda = 0) : nombre(_nombre), monto(_monto), Nronda(_Nronda) {}
    ~Apostador() = default;

    std::string getNombre() { return this->nombre; }
    float getMonto() { return this->monto; }
    int getNronda() { return this->Nronda; }
    void restarMonto(float _monto) { this->monto -= _monto; }
};