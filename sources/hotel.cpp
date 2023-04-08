#include "../includes/hotel.h"

void Hotel::adaugaCamera(Camera& c)
{
    bool cameraDejaExistenta = false;

    for (size_t i = 0; i < this->camere.size() && !cameraDejaExistenta; i++)
        if (this->camere[i].getNumar() == c.getNumar() && this->camere[i].getEtaj() == c.getEtaj())
            cameraDejaExistenta = true;

    if (!cameraDejaExistenta)
        this->camere.emplace_back(c.getNumar(), c.getEtaj());
    else
        std::cout << "Camera ce trebuia adaugata in cadrul hotelului deja exista!" << '\n';
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
    bool cameraDejaExistenta = false;

    for (size_t i = 0; i < h.camere.size() && !cameraDejaExistenta; i++)
        if (h.camere[i].getNumar() == c.getNumar() && h.camere[i].getEtaj() == c.getEtaj())
            cameraDejaExistenta = true;

    if (!cameraDejaExistenta)
        h.camere.emplace_back(c.getNumar(), c.getEtaj());
    else
        std::cout << "Camera ce trebuia adaugata in cadrul hotelului deja exista!" << '\n';
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
        Hotel temp(b);

        std::swap(this->nume, temp.nume);
        std::swap(this->nrStele, temp.nrStele);
        std::swap(this->camere, temp.camere);
    }

    return *this;
}
