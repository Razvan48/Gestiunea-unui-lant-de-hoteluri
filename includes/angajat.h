#ifndef OOP_ANGAJAT_H
#define OOP_ANGAJAT_H

#include <string>

#include <iostream>
#include <istream>
#include <ostream>

#include "persoana.h"

class Angajat : public Persoana
{
private:

    std::string functie;
    int salariu;

public:
    Angajat(const std::string& nume = "-", const std::string& prenume = "-", const std::string& numarTelefon = "-", const std::string& functie = "-", int salariu = -1) :
            Persoana(nume, prenume, numarTelefon), functie(functie), salariu(salariu)
    {
        ///
    }

    Angajat(const Angajat& b) :
            Persoana(b)
    {
        this->functie = b.functie;
        this->salariu = b.salariu;
    }

    Angajat& operator=(const Angajat& b);

    friend std::istream& operator>>(std::istream& in, Angajat& a);
    friend std::ostream& operator<<(std::ostream& out, const Angajat& a);

    bool operator==(const Angajat& b) const
    {
        if (!Persoana::operator==(b))
            return false;

        /// return this->functie == b.functie && this->salariu == b.salariu;

        return true;
    }

    bool operator!=(const Angajat& b) const
    {
        if (!Persoana::operator!=(b))
            return false;

        /// return this->functie != b.functie || this->salariu != b.salariu;

        return true;
    }

    ~Angajat()
    {

    }
};

#endif
