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
    Client(const std::string& nume, const std::string& prenume, const std::string& CNP, const std::string& numarTelefon) :
        nume(nume), prenume(prenume), CNP(CNP), numarTelefon(numarTelefon)
    {

    }

    friend std::iostream& operator>>(std::iostream& in, Client& c);
    friend std::ostream& operator<<(std::ostream& out, const Client& c);

    ~Client()
    {

    }
};

#endif
