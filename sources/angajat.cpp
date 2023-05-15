#include "../includes/angajat.h"

Angajat::Angajat(const std::string& nume, const std::string& prenume, const std::string& numarTelefon, const std::string& functie, int salariu) :
        Persoana(nume, prenume, numarTelefon), functie(functie), salariu(salariu)
{
    ///
}

Angajat::Angajat(const Angajat& b) :
    Persoana(b), functie(b.functie), salariu(b.salariu)
{

}

Angajat& Angajat::operator=(const Angajat& b)
{
    if (this != &b)
    {
        Persoana::operator=(b);
        Angajat temp(b);

        std::swap(this->functie, temp.functie);
        std::swap(this->salariu, temp.salariu);
    }

    return *this;
}

std::istream& operator>>(std::istream& in, Angajat& a)
{
    in >> a.nume >> a.prenume >> a.numarTelefon;

    in >> a.functie >> a.salariu;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Angajat& a)
{
    out << "Angajatul " << a.nume << " " << a.prenume << '\n';
    out << "are numarul de telefon " << a.numarTelefon << '\n';

    out << "ocupa functia de " << a.functie << '\n';
    out << "si are salariul de " << a.salariu << '\n';

    return out;
}

bool Angajat::operator==(const Angajat& b) const
{
    if (!Persoana::operator==(b))
        return false;

    /// return this->functie == b.functie && this->salariu == b.salariu;

    return true;
}

bool Angajat::operator!=(const Angajat& b) const
{
    return !Angajat::operator==(b);
}

std::shared_ptr<Persoana> Angajat::cloneaza() const
{
    return std::make_shared<Angajat>(*this);
}

void Angajat::afiseaza(std::ostream& out) const
{
    out << "Angajatul " << this->nume << " " << this->prenume << '\n';
    out << "are numarul de telefon " << this->numarTelefon << '\n';

    out << "ocupa functia de " << this->functie << '\n';
    out << "si are salariul de " << this->salariu << '\n';
}
