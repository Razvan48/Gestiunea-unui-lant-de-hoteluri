#ifndef CLIENT_H
#define CLIENT_H

#include "persoana.h"

class Client : public Persoana
{
private:

public:
    Client(const std::string& nume = "-", const std::string& prenume = "-", const std::string& numarTelefon = "-") :
        Persoana(nume, prenume, numarTelefon)
    {
        ///
    }

    Client(const Client& b) :
        Persoana(b)
    {
        ///
    }

    Client& operator=(const Client& b);
    friend std::istream& operator>>(std::istream& in, Client& c);
    friend std::ostream& operator<<(std::ostream& out, const Client& c);

    bool operator==(const Client& b) const
    {
        if (!Persoana::operator==(b))
            return false;

        ///

        return true;
    }

    bool operator!=(const Client& b) const { return !Client::operator==(b); }

    Client* cloneaza() const override { return new Client(*this); }
    void afiseaza(std::ostream& out) const override;

    ~Client() {}
};

#endif
