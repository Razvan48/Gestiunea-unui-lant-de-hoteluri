#include "../includes/angajat.h"

Angajat& Angajat::operator=(const Angajat& b)
{
    if (this != &b)
    {
        Angajat temp(b);

        std::swap(this->nume, temp.nume);
        std::swap(this->prenume, temp.prenume);
        std::swap(this->numarTelefon, temp.numarTelefon);

        std::swap(this->functie, temp.functie);
        std::swap(this->salariu, temp.salariu);
    }

    return *this;
}

std::istream& operator>>(std::istream& in, Angajat& a)
{
    in >> a.nume >> a.prenume >> a.numarTelefon;

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

void Angajat::afiseaza(std::ostream& out) const
{
    out << "Angajatul " << this->nume << " " << this->prenume << '\n';
    out << "are numarul de telefon " << this->numarTelefon << '\n';

    out << "ocupa functia de " << this->functie << '\n';
    out << "si are salariul de " << this->salariu << '\n';
}
