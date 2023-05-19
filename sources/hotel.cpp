#include "../includes/hotel.h"

Hotel::Hotel(const std::string& nume, int nrStele) :
        nume(nume), nrStele(nrStele), numarCamereStandard(0), numarCamereDuble(0), capacitate(0)
{

}

Hotel::Hotel(const Hotel& b) : nume(b.nume), nrStele(b.nrStele)
{
    for (size_t i = 0; i < b.camere.size(); ++i)
    {
        if (b.camere[i] != nullptr)
            this->camere.push_back(b.camere[i]->cloneaza());
        else
            this->camere.push_back(nullptr);
    }
    for (size_t i = 0; i < b.angajati.size(); ++i)
    {
        if (b.angajati[i] != nullptr)
            this->angajati.push_back(std::dynamic_pointer_cast<Angajat>(b.angajati[i]->cloneaza()));
        else
            this->angajati.push_back(nullptr);
    }
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

void operator+=(Hotel& h, Camera& c)
{
        h.adaugaCamera(c);
}

void operator-=(Hotel& h, Camera& c)
{
    h.eliminaCamera(c);
}

std::string Hotel::getNume() const
{
    return this->nume;
}

int Hotel::getNrStele() const
{
    return this->nrStele;
}

int Hotel::getCapacitate() const
{
    return this->capacitate;
}

std::shared_ptr<Hotel> Hotel::cloneaza() const
{
    return std::make_shared<Hotel>(*this);
}

void Hotel::adaugaCamera(Camera& c)
{
    bool cameraDejaExistenta = false;

    for (size_t i = 0; i < this->camere.size() && !cameraDejaExistenta; ++i)
        if (this->camere[i]->getNumar() == c.getNumar() && this->camere[i]->getEtaj() == c.getEtaj())
            cameraDejaExistenta = true;

    if (!cameraDejaExistenta)
    {
        CameraStandard* cs = dynamic_cast<CameraStandard*>(&c);
        if (cs)
        {
            ++this->numarCamereStandard;
            this->capacitate += cs->getCapacitate();
        }
        CameraDubla* cd = dynamic_cast<CameraDubla*>(&c);
        if (dynamic_cast<CameraDubla *>(cd))
        {
            ++this->numarCamereDuble;
            this->capacitate += cd->getCapacitate();
        }

        this->camere.push_back(std::shared_ptr<Camera>(c.cloneaza()));
    }
    else
        throw eroareCameraDejaExistenta("camera ce trebuia adaugata in cadrul unui hotel deja exista");
}

void Hotel::eliminaCamera(Camera& c)
{
    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        if (this->camere[i]->getNumar() == c.getNumar() && this->camere[i]->getEtaj() == c.getEtaj())
        {
            CameraStandard* cs = dynamic_cast<CameraStandard*>(&c);
            if (cs)
            {
                --this->numarCamereStandard;
                this->capacitate -= cs->getCapacitate();
            }
            CameraDubla* cd = dynamic_cast<CameraDubla*>(&c);
            if (dynamic_cast<CameraDubla*>(cd))
            {
                --this->numarCamereDuble;
                this->capacitate -= cd->getCapacitate();
            }

            std::swap(this->camere[i], this->camere.back());
            this->camere.pop_back();

            return;
        }
    }

    throw eroareCameraNegasita("camera ce trebuia eliminata din cadrul unui hotel nu a fost gasita");
}

void Hotel::rezervaCamera(const std::vector<Client>& c)
{
    bool preaMultiClienti = true;

    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        if ((int)c.size() <= this->camere[i]->getCapacitate())
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
        throw eroareCamereInsuficientDeMari("nu s-au putut caza atat de multi clienti in aceeasi camera");

    std::cout << "Hotelul nu poate oferi nicio camera in acest moment!" << '\n'; // Acesta ar fi doar un warning.
    return;
}

void Hotel::elibereazaCamera(int numar, int etaj)
{
    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        if (this->camere[i]->getNumar() == numar && this->camere[i]->getEtaj() == etaj)
        {
            this->camere[i]->elibereaza();

            return;
        }
    }

    throw eroareCameraNegasita("camera ce trebuia eliberata in cadrul unui hotel nu a fost gasita");
}

template<typename T> void Hotel::elibereazaCamera()
{
    bool existaTipCamera = false;

    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        if (dynamic_cast<T*>(this->camere[i].get()))
        {
            existaTipCamera = true;

            if (this->camere[i]->getRezervat())
            {
                this->camere[i]->elibereaza();

                return;
            }
        }
    }

    if (!existaTipCamera)
        throw eroareTipCameraNegasit("tipul de camera ce trebuia eliberat in cadrul unui hotel nu a fost gasit");
}

template void Hotel::elibereazaCamera<CameraStandard>();
template void Hotel::elibereazaCamera<CameraDubla>();

void Hotel::angajeaza(const Angajat& a)
{
    bool angajatDejaExistent = false;

    for (size_t i = 0; i < this->angajati.size() && !angajatDejaExistent; ++i)
        if ((*(this->angajati[i])) == a)
            angajatDejaExistent = true;

    if (!angajatDejaExistent)
        this->angajati.push_back(std::dynamic_pointer_cast<Angajat>(a.cloneaza()));
    else
        throw eroareAngajatDejaExistent("noul angajat nu a putut fi adaugat in cadrul unui hotel, deoarece acesta deja exista");
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

    // throw eroareAngajatNegasit("angajatul ce trebuia concediat din cadrul unui hotel nu a fost gasit");
}
