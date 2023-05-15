#ifndef PERSOANA_H
#define PERSOANA_H

#include <string>

#include <iostream>
#include <istream>
#include <ostream>

#include <memory>

#include "exceptie.h"

class Persoana
{
private:

protected:

    std::string nume;
    std::string prenume;
    std::string numarTelefon;

public:

    Persoana(const std::string& nume = "-", const std::string& prenume = "-", const std::string& numarTelefon = "-");
    Persoana(const Persoana& b);
    Persoana& operator=(const Persoana& b);
    friend std::istream& operator>>(std::istream& in, Persoana& p);
    friend std::ostream& operator<<(std::ostream& out, const Persoana& p);
    bool operator==(const Persoana& b) const;
    bool operator!=(const Persoana& b) const;
    std::string getNume() const;
    std::string getPrenume() const;
    std::string getNumarTelefon() const;
    virtual std::shared_ptr<Persoana> cloneaza() const = 0;
    virtual void afiseaza(std::ostream& out) const = 0;
    virtual ~Persoana();
};

#endif
