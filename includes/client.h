#ifndef OOP_CLIENT_H
#define OOP_CLIENT_H

#include <string>

#include <istream>
#include <ostream>

class Client
{
private:

    std::string nume;
    std::string prenume;
    std::string numarTelefon;

public:
    Client(const std::string& nume = "-", const std::string& prenume = "-", const std::string& numarTelefon = "-") :
        nume(nume), prenume(prenume), numarTelefon(numarTelefon)
    {

    }

    Client(const Client& b) : nume(b.nume), prenume(b.prenume), numarTelefon(b.numarTelefon)
    {

    }

    Client& operator=(const Client& b);

    friend std::istream& operator>>(std::istream& in, Client& c);
    friend std::ostream& operator<<(std::ostream& out, const Client& c);

    bool operator==(const Client& b) const
    {
        return this->nume == b.nume && this->prenume == b.prenume && this->numarTelefon == b.numarTelefon;
    }

    bool operator!=(const Client& b) const
    {
        return this->nume != b.nume || this->prenume != b.prenume || this->numarTelefon != b.numarTelefon;
    }

    ~Client()
    {

    }
};

#endif
