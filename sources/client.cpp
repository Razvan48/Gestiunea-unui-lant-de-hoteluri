#include "../includes/client.h"

Client::Client(const std::string& nume, const std::string& prenume, const std::string& numarTelefon) :
        Persoana(nume, prenume, numarTelefon)
{
    ///
}

Client::Client(const Client& b) : Persoana(b)
{
    ///
}

Client& Client::operator=(const Client& b)
{
    if (this != &b)
    {
        Persoana::operator=(b);

        ///Client temp(b);
        /// Aici ar veni swap-urile atributelor specifice doar clasei Client.
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

bool Client::operator==(const Client& b) const
{
    if (!Persoana::operator==(b))
        return false;

    ///

    return true;
}

bool Client::operator!=(const Client& b) const
{
    return !Client::operator==(b);
}

std::shared_ptr<Persoana> Client::cloneaza() const
{
    return std::make_shared<Client>(*this);
}

void Client::afiseaza(std::ostream& out) const
{
    out << "Clientul " << this->nume << " " << this->prenume << '\n';
    out << "are numarul de telefon " << this->numarTelefon << '\n';
}