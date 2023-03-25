#include "../includes/hotel.h"

void Hotel::adaugaCamera(Camera* c)
{
    this->camera.push_back(c);
}

std::istream& operator>>(std::istream& in, Hotel& h)
{
    in >> h.nume >> h.nrStele;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Hotel& h)
{
    out << "Hotelul " << h.nume << " are " << h.nrStele << " stele" << '\n';

    if (h.camera.empty())
        out << "si nicio camera inregistrata!" << '\n';
    else
    {
        out << "si urmatoarele camere:" << '\n';

        for (size_t i = 0; i < h.camera.size(); i++)
            out << *h.camera[i];
    }

    return out;
}

void operator+=(Hotel& h, Camera* c)
{
    h.camera.push_back(c);
}

Camera* Hotel::rezervaCamera()
{
    for (size_t i = 0; i < this->camera.size(); i++)
    {
        if (!this->camera[i]->getRezervat())
        {
            this->camera[i]->rezerva();

            std::cout << *this->camera[i] << "a fost rezervata!" << '\n';

            return this->camera[i];
        }
    }

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n';
    return nullptr;
}

Camera* Hotel::rezervaCamera(Client* c)
{
    for (size_t i = 0; i < this->camera.size(); i++)
    {
        if (!this->camera[i]->getRezervat())
        {
            this->camera[i]->rezerva(c);

            std::cout << *this->camera[i] << "a fost rezervata!" << '\n';

            return this->camera[i];
        }
    }

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n';
    return nullptr;
}

Camera* Hotel::rezervaCamera(const std::vector<Client*>& c)
{
    for (size_t i = 0; i < this->camera.size(); i++)
    {
        if (!this->camera[i]->getRezervat())
        {
            this->camera[i]->rezerva(c);

            std::cout << *this->camera[i] << "a fost rezervata!" << '\n';

            return this->camera[i];
        }
    }

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n';
    return nullptr;
}

void Hotel::elibereazaCamera(const Camera* c)
{
    for (size_t i = 0; i < this->camera.size(); i++)
    {
        if (this->camera[i] == c)
        {
            this->camera[i]->elibereaza();

            std::cout << "Camera a fost eliberata cu succes!" << '\n';

            return;
        }
    }

    std::cout << "Camera nu exista in cadrul hotelului!" << '\n';
}


