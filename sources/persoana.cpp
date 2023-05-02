#include "../includes/persoana.h"

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
