#include "../includes/angajat.h"

std::istream& operator>>(std::istream& in, Angajat& a)
{
    Persoana& p = a;
    in >> p;

    in >> a.functie >> a.salariu;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Angajat& a)
{
    out << "Angajatul " << a.nume << " " << a.prenume << '\n';
    out << "are numarul de telefon " << a.numarTelefon << '\n';

    out << "ocupa functia de " << a.functie << '\n';
    out << "si are salariul de " << a.salariu << '\n';

    return out;
}

Angajat& Angajat::operator=(const Angajat& b)
{
    if (this != &b)
    {
        Persoana::operator=(b);
        Angajat temp(b);

        std::swap(this->functie, temp.functie);
        std::swap(this->salariu, temp.salariu);
    }

    return *this;
}
