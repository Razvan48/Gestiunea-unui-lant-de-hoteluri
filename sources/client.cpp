#include "../includes/client.h"

Client& Client::operator=(const Client& b)
{
    if (this != &b)
    {
        Persoana::operator=(b);
        Client temp(b);

        ///
    }

    return *this;
}

std::istream& operator>>(std::istream& in, Client& c)
{
    Persoana& p = c;
    in >> p;

    ///

    return in;
}

std::ostream& operator<<(std::ostream& out, const Client& c)
{
    out << "Clientul " << c.nume << " " << c.prenume << '\n';
    out << "are numarul de telefon " << c.numarTelefon << '\n';

    ///

    return out;
}

void Client::afiseaza(std::ostream& out) const
{
    out << "Clientul " << this->nume << " " << this->prenume << '\n';
    out << "are numarul de telefon " << this->numarTelefon << '\n';

    ///
}