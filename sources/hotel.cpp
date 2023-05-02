#include "../includes/hotel.h"

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

        for (size_t i = 0; i < h.camere.size(); ++i)
            h.camere[i]->afiseaza(out);
    }

    if (h.angajati.empty())
        out << "si niciun angajat!" << '\n';
    else
    {
        out << "urmatorii angajati:" << '\n';

        for (size_t i = 0; i < h.angajati.size(); ++i)
            h.angajati[i]->afiseaza(out);
    }

    return out;
}

void Hotel::adaugaCamera(Camera& c)
{
    bool cameraDejaExistenta = false;

    for (size_t i = 0; i < this->camere.size() && !cameraDejaExistenta; ++i)
        if (this->camere[i]->getNumar() == c.getNumar() && this->camere[i]->getEtaj() == c.getEtaj())
            cameraDejaExistenta = true;

    if (!cameraDejaExistenta)
        this->camere.push_back(std::shared_ptr<Camera>(c.cloneaza()));
    else
        std::cout << "Camera ce trebuia adaugata in cadrul hotelului deja exista!" << '\n';
}

void Hotel::eliminaCamera(Camera& c)
{
    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        if (this->camere[i]->getNumar() == c.getNumar() && this->camere[i]->getEtaj() == c.getEtaj())
        {
            std::swap(this->camere[i], this->camere.back());
            this->camere.pop_back();

            return;
        }
    }

    std::cout << "Camera ce trebuia eliminata nu a fost gasita!" << '\n';
}

void Hotel::rezervaCamera(const std::vector<Client>& c)
{
    bool preaMultiClienti = true;

    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        if (c.size() <= this->camere[i]->getCapacitate())
            preaMultiClienti = false;

        if (!this->camere[i]->getRezervat())
        {
            this->camere[i]->rezerva(c);

            this->camere[i]->afiseaza(std::cout);
            std::cout << "a fost rezervata!" << '\n';

            return;
        }
    }

    if (preaMultiClienti)
        throw eroareCamereInsuficientDeMari("nu s-au putut caza atat de multi clienti in aceeasi camere");

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n';
    return;
}

void Hotel::elibereazaCamera(int numar, int etaj)
{
    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        if (this->camere[i]->getNumar() == numar && this->camere[i]->getEtaj() == etaj)
        {
            this->camere[i]->elibereaza();

            std::cout << "Camera a fost eliberata cu succes!" << '\n';

            return;
        }
    }

    std::cout << "Camera nu exista in cadrul hotelului!" << '\n';
    return;
}

void Hotel::angajeaza(const Angajat& a)
{
    bool angajatDejaExistent = false;

    for (size_t i = 0; i < this->angajati.size() && !angajatDejaExistent; ++i)
        if ((*(this->angajati[i])) == a)
            angajatDejaExistent = true;

    if (!angajatDejaExistent)
        this->angajati.push_back(std::shared_ptr<Angajat>(a.cloneaza()));
    else
        std::cout << "Angajatul ce trebuia adaugat in cadrul hotelului deja exista!" << '\n';
}

void Hotel::concediaza(const Angajat& a)
{
    for (size_t i = 0; i < this->angajati.size(); ++i)
    {
        if ((*(this->angajati[i])) == a)
        {
            std::swap(this->angajati[i], this->angajati.back());
            this->angajati.pop_back();

            return;
        }
    }

    std::cout << "Angajatul ce trebuia eliminat nu a fost gasit!" << '\n';
}
