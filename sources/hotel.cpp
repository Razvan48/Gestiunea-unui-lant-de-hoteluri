#include "../includes/hotel.h"

void Hotel::adaugaCamera(Camera& c)
{
    bool cameraDejaExistenta = false;

    /*
    for (size_t i = 0; i < this->camere.size() && !cameraDejaExistenta; ++i)
        if (this->camere[i]->getNumar() == c.getNumar() && this->camere[i]->getEtaj() == c.getEtaj())
            cameraDejaExistenta = true;
            */

    if (!cameraDejaExistenta)
        this->camere.push_back(c.cloneaza());
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

void operator+=(Hotel& h, CameraStandard& c)
{
    h.adaugaCamera(c);
}

/*
void operator-=(Hotel& h, CameraStandard& c)
{
    for (size_t i = 0; i < h.camere.size(); ++i)
    {
        if (h.camere[i]->getNumar() == c.getNumar() && h.camere[i]->getEtaj() == c.getEtaj())
        {
            std::swap(h.camere[i], h.camere.back());
            delete h.camere.back();
            h.camere.pop_back();

            return;
        }
    }

    std::cout << "Camera ce trebuia eliminata nu a fost gasita!" << '\n';
}
 */

void Hotel::rezervaCamera()
{
    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        /*
        if (!this->camere[i]->getRezervat())
        {
            this->camere[i]->rezerva();

            this->camere[i]->afiseaza(std::cout);
            std::cout  << "a fost rezervata!" << '\n';

            return;
        }
         */
    }

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n';
    return;
}

void Hotel::rezervaCamera(Client& c)
{
    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        /*
        if (!this->camere[i]->getRezervat())
        {
            this->camere[i]->rezerva(c);

            this->camere[i]->afiseaza(std::cout);
            std::cout << "a fost rezervata!" << '\n';

            return;
        }
         */
    }

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n';
    return;
}

void Hotel::rezervaCamera(const std::vector<Client>& c)
{
    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        /*
        if (!this->camere[i]->getRezervat())
        {
            this->camere[i]->rezerva(c);

            this->camere[i]->afiseaza(std::cout);
            std::cout << "a fost rezervata!" << '\n';

            return;
        }
         */
    }

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n';
    return;
}

void Hotel::elibereazaCamera(int numar, int etaj)
{
    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        /*
        if (this->camere[i]->getNumar() == numar && this->camere[i]->getEtaj() == etaj)
        {
            this->camere[i]->elibereaza();

            std::cout << "Camera a fost eliberata cu succes!" << '\n';

            return;
        }
         */
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

        for (size_t i = 0; i < this->camere.size(); ++i)
        {
            if (this->camere[i] != nullptr)
                delete this->camere[i];
            this->camere[i] = nullptr;
        }
        for (size_t i = 0; i < this->angajati.size(); ++i)
        {
            if (this->angajati[i] != nullptr)
                delete this->angajati[i];
            this->angajati[i] = nullptr;
        }
        this->camere.clear();
        this->angajati.clear();

        for (size_t i = 0; i < temp.camere.size(); ++i)
        {
            if (temp.camere[i] != nullptr)
                this->camere.push_back(temp.camere[i]->cloneaza());
            else
                this->camere.push_back(nullptr);
        }

        for (size_t i = 0; i < temp.angajati.size(); ++i)
        {
            if (temp.angajati[i] != nullptr)
                this->angajati.push_back(temp.angajati[i]->cloneaza());
            else
                this->angajati.push_back(nullptr);
        }
    }

    return *this;
}

void Hotel::angajeaza(const Angajat& a)
{
    bool angajatDejaExistent = false;

    for (size_t i = 0; i < this->angajati.size() && !angajatDejaExistent; i++)
        if ((*(this->angajati[i])) == a)
            angajatDejaExistent = true;

    if (!angajatDejaExistent)
        this->angajati.push_back(a.cloneaza());
    else
        std::cout << "Angajatul ce trebuia adaugat in cadrul hotelului deja exista!" << '\n';
}

void Hotel::angajeaza(const Persoana& p, const std::string& functie, int salariu)
{
    Angajat a(p.getNume(), p.getPrenume(), p.getNumarTelefon(), functie, salariu);

    this->angajeaza(a);
}

void Hotel::concediaza(const Angajat& a)
{
    for (size_t i = 0; i < this->angajati.size(); ++i)
    {
        if ((*(this->angajati[i]))== a)
        {
            std::swap(this->angajati[i], this->angajati.back());
            delete this->angajati.back();
            this->angajati.pop_back();

            return;
        }
    }

    std::cout << "Angajatul ce trebuia eliminat nu a fost gasit!" << '\n';
}

void Hotel::concediaza(const Persoana& p)
{
    Angajat a(p.getNume(), p.getPrenume(), p.getNumarTelefon());

    this->concediaza(a);
}
