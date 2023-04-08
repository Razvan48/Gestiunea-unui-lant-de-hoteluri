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
        out << "nicio camera inregistrata" << '\n';
    else
    {
        out << "urmatoarele camere:" << '\n';

        for (size_t i = 0; i < h.camere.size(); i++)
            out << h.camere[i];
    }

    if (h.angajati.empty())
        out << "si niciun angajat!" << '\n';
    else
    {
        out << "urmatorii angajati:" << '\n';

        for (size_t i = 0; i < h.angajati.size(); i++)
            out << h.angajati[i];
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

void operator-=(Hotel& h, Camera& c)
{
    for (size_t i = 0; i < h.camere.size(); i++)
    {
        if (h.camere[i].getNumar() == c.getNumar() && h.camere[i].getEtaj() == c.getEtaj())
        {
            std::swap(h.camere[i], h.camere.back());
            h.camere.pop_back();

            return;
        }
    }

    std::cout << "Camera ce trebuia eliminata nu a fost gasita!" << '\n';
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
        std::swap(this->angajati, temp.angajati);
    }

    return *this;
}

void Hotel::angajeaza(const Angajat& a)
{
    bool angajatDejaExistent = false;

    for (size_t i = 0; i < this->angajati.size() && !angajatDejaExistent; i++)
        if (this->angajati[i] == a)
            angajatDejaExistent = true;

    if (!angajatDejaExistent)
        this->angajati.emplace_back(a);
    else
        std::cout << "Angajatul ce trebuia adaugat in cadrul hotelului deja exista!" << '\n';
}

void Hotel::concediaza(const Angajat &a)
{
    for (size_t i = 0; i < this->angajati.size(); i++)
    {
        if (this->angajati[i] == a)
        {
            std::swap(this->angajati[i], this->angajati.back());
            this->angajati.pop_back();

            return;
        }
    }

    std::cout << "Angajatul ce trebuia eliminat nu a fost gasit!" << '\n';
}
