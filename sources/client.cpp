#include "../includes/client.h"

Client& Client::operator=(const Client& b)
{
    if (this != &b)
    {
        Client temp(b);

        std::swap(this->nume, temp.nume);
        std::swap(this->prenume, temp.prenume);
        std::swap(this->numarTelefon, temp.numarTelefon);
    }

    return *this;
}

std::istream& operator>>(std::istream& in, Client& c)
{
    in >> c.nume >> c.prenume >> c.numarTelefon;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Client& c)
{
    out << "Clientul " << c.nume << " " << c.prenume << '\n';
    out << "are numarul de telefon " << c.numarTelefon << '\n';

    return out;
}

void Client::afiseaza(std::ostream& out) const
{
    out << "Clientul " << this->nume << " " << this->prenume << '\n';
    out << "are numarul de telefon " << this->numarTelefon << '\n';
}