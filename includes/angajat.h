#ifndef ANGAJAT_H
#define ANGAJAT_H

#include "persoana.h"

class Angajat : public Persoana
{
private:

    std::string functie;
    int salariu;

public:

    Angajat(const std::string& nume = "-", const std::string& prenume = "-", const std::string& numarTelefon = "-", const std::string& functie = "-", int salariu = -1);
    Angajat(const Angajat& b);
    Angajat& operator=(const Angajat& b);
    friend std::istream& operator>>(std::istream& in, Angajat& a);
    friend std::ostream& operator<<(std::ostream& out, const Angajat& a);
    bool operator==(const Angajat& b) const;
    bool operator!=(const Angajat& b) const;
    std::shared_ptr<Persoana> cloneaza() const override;
    void afiseaza(std::ostream& out) const override;
};

#endif
