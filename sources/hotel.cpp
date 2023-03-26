#include "../includes/hotel.h"

void Hotel::adaugaCamera(Camera& c)
{
    this->camere.push_back(c);
}

std::istream& operator>>(std::istream& in, Hotel& h)
{
    in >> h.nume >> h.nrStele;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Hotel& h)
{
    out << "Hotelul " << h.nume << " are " << h.nrStele << " stele" << '\n';

    if (h.camere.empty())
        out << "si nicio camera inregistrata!" << '\n';
    else
    {
        out << "si urmatoarele camere:" << '\n';

        for (size_t i = 0; i < h.camere.size(); i++)
            out << h.camere[i];
    }

    return out;
}

void operator+=(Hotel& h, Camera& c)
{
    h.camere.push_back(c);
}

void Hotel::rezervaCamera()
{
    for (size_t i = 0; i < this->camere.size(); i++)
    {
        if (!this->camere[i].getRezervat())
        {
            this->camere[i].rezerva();

            std::cout << this->camere[i] << "a fost rezervata!" << '\n';

            return;
        }
    }

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n';
    return;
}

void Hotel::rezervaCamera(Client& c)
{
    for (size_t i = 0; i < this->camere.size(); i++)
    {
        if (!this->camere[i].getRezervat())
        {
            this->camere[i].rezerva(c);

            std::cout << this->camere[i] << "a fost rezervata!" << '\n';

            return;
        }
    }

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n';
    return;
}

void Hotel::rezervaCamera(const std::vector<Client>& c)
{
    for (size_t i = 0; i < this->camere.size(); i++)
    {
        if (!this->camere[i].getRezervat())
        {
            this->camere[i].rezerva(c);

            std::cout << this->camere[i] << "a fost rezervata!" << '\n';

            return;
        }
    }

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n';
    return;
}

void Hotel::elibereazaCamera(int numar, int etaj)
{
    for (size_t i = 0; i < this->camere.size(); i++)
    {
        if (this->camere[i].getNumar() == numar && this->camere[i].getEtaj() == etaj)
        {
            this->camere[i].elibereaza();

            std::cout << "Camera a fost eliberata cu succes!" << '\n';

            return;
        }
    }

    std::cout << "Camera nu exista in cadrul hotelului!" << '\n';
    return;
}

Hotel& Hotel::operator=(const Hotel& b)
{
    if (this != &b)
    {
        this->nume = b.nume;
        this->nrStele = b.nrStele;

        this->camere.clear();

        for (size_t i = 0; i < b.camere.size(); i++)
            this->camere.push_back(b.camere[i]);
    }

    return *this;
}
