#ifndef OOP_PERSOANA_H
#define OOP_PERSOANA_H

#include <string>

#include <iostream>
#include <istream>
#include <ostream>

class Persoana
{
private:

protected:

    std::string nume;
    std::string prenume;
    std::string numarTelefon;

public:

    Persoana(const std::string& nume = "-", const std::string& prenume = "-", const std::string& numarTelefon = "-") :
            nume(nume), prenume(prenume), numarTelefon(numarTelefon)
    {

    }

    Persoana(const Persoana& b) : nume(b.nume), prenume(b.prenume), numarTelefon(b.numarTelefon)
    {

    }

    Persoana& operator=(const Persoana& b);

    friend std::istream& operator>>(std::istream& in, Persoana& p);
    friend std::ostream& operator<<(std::ostream& out, const Persoana& p);

    bool operator==(const Persoana& b) const
    {
        return this->nume == b.nume && this->prenume == b.prenume && this->numarTelefon == b.numarTelefon;
    }

    bool operator!=(const Persoana& b) const
    {
        return this->nume != b.nume || this->prenume != b.prenume || this->numarTelefon != b.numarTelefon;
    }

    ~Persoana()
    {

    }
};

#endif
