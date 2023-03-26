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
    std::string CNP;
    std::string numarTelefon;

public:
    Client(const std::string& nume = "", const std::string& prenume = "", const std::string& CNP = "", const std::string& numarTelefon = "") :
        nume(nume), prenume(prenume), CNP(CNP), numarTelefon(numarTelefon)
    {

    }

    Client(const Client& b) : nume(b.nume), prenume(b.prenume), CNP(b.CNP), numarTelefon(b.numarTelefon)
    {

    }

    Client& operator=(const Client& b);

    friend std::istream& operator>>(std::istream& in, Client& c);
    friend std::ostream& operator<<(std::ostream& out, const Client& c);

    bool operator==(const Client& b) const
    {
        return this->nume == b.nume && this->prenume == b.prenume && this->CNP == b.CNP && this->numarTelefon == b.numarTelefon;
    }

    bool operator!=(const Client& b) const
    {
        return this->nume != b.nume || this->prenume != b.prenume || this->CNP != b.CNP || this->numarTelefon != b.numarTelefon;
    }

    ~Client()
    {

    }
};

#endif
