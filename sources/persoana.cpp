#include "../includes/persoana.h"

Persoana& Persoana::operator=(const Persoana& b)
{
    if (this != &b)
    {
        /// Persoana temp(b); /// Persoana este clasa abstracta.

        this->nume = b.nume;
        this->prenume = b.prenume;
        this->numarTelefon = b.numarTelefon;
    }

    return *this;
}

void Persoana::afiseaza(std::ostream& out) const
{
    out << "Persoana " << this->nume << " " << this->prenume << '\n';
    out << "are numarul de telefon " << this->numarTelefon << '\n';
}

std::istream& operator>>(std::istream& in, Persoana& p)
{
    in >> p.nume >> p.prenume >> p.numarTelefon;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Persoana& p)
{
    out << "Persoana " << p.nume << " " << p.prenume << '\n';
    out << "are numarul de telefon " << p.numarTelefon << '\n';

    return out;
}
