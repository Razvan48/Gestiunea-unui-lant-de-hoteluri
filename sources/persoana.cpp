#include "../includes/persoana.h"

Persoana::Persoana(const std::string& nume, const std::string& prenume, const std::string& numarTelefon) :
    nume(nume), prenume(prenume), numarTelefon(numarTelefon)
{

}

Persoana::Persoana(const Persoana& b) : nume(b.nume), prenume(b.prenume), numarTelefon(b.numarTelefon)
{

}

Persoana& Persoana::operator=(const Persoana& b)
{
    if (this != &b)
    {
        /// Persoana temp(b); /// Persoana este clasa abstracta.

        ///std::swap(this->nume, temp.nume);
        ///std::swap(this->prenume, temp.prenume);
        ///std::swap(this->numarTelefon, temp.numarTelefon);

        this->nume = b.nume;
        this->prenume = b.prenume;
        this->numarTelefon = b.numarTelefon;
    }

    return *this;
}

std::istream& operator>>(std::istream& in, Persoana& p)
{
    in >> p.nume >> p.prenume >> p.numarTelefon;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Persoana& p)
{
    out << "Persoana " << p.nume << " " << p.prenume << '\n';
    out << "are numarul de telefon " << p.numarTelefon << '\n';

    return out;
}

bool Persoana::operator==(const Persoana& b) const
{
    return this->nume == b.nume && this->prenume == b.prenume && this->numarTelefon == b.numarTelefon;
}

bool Persoana::operator!=(const Persoana& b) const
{
    return !Persoana::operator==(b);
}

std::string Persoana::getNume() const
{
    return this->nume;
}

std::string Persoana::getPrenume() const
{
    return this->prenume;
};

std::string Persoana::getNumarTelefon() const
{
    return this->numarTelefon;
}

void Persoana::afiseaza(std::ostream& out) const
{
    out << "Persoana " << this->nume << " " << this->prenume << '\n';
    out << "are numarul de telefon " << this->numarTelefon << '\n';
}

Persoana::~Persoana()
{

}
