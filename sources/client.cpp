#include "../includes/client.h"

std::iostream& operator>>(std::iostream& in, Client& c)
{
    in >> c.nume >> c.prenume >> c.CNP >> c.numarTelefon;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Client& c)
{
    out << "Clientul " << c.nume << " " << c.prenume << '\n';
    out << "are CNP-ul: " << c.CNP << '\n';
    out << "si numarul de telefon " << c.numarTelefon << '\n';

    return out;
}