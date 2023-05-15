#include "../includes/cameraDubla.h"

CameraDubla& CameraDubla::operator=(const CameraDubla& b)
{
    if (this != &b)
    {
        CameraDubla temp(b);

        std::swap(this->numar, temp.numar);
        std::swap(this->etaj, temp.etaj);
        std::swap(this->rezervat, temp.rezervat);

        std::swap(this->clienti[0], temp.clienti[0]);
        std::swap(this->clienti[1], temp.clienti[1]);
    }

    return *this;
}

std::istream& operator>>(std::istream& in, CameraDubla& c)
{
    in >> c.numar >> c.etaj;

    return in;
}

std::ostream& operator<<(std::ostream& out, const CameraDubla& c)
{
    out << "Camera dubla " << c.numar << ", aflata la etajul " << c.etaj << ", care ";

    if (!c.rezervat)
        out << "nu ";

    out << "este rezervata" << '\n';

    return out;
}

void CameraDubla::afiseaza(std::ostream& out) const
{
    out << "Camera dubla " << this->numar << ", aflata la etajul " << this->etaj << ", care ";

    if (!this->rezervat)
        out << "nu ";

    out << "este rezervata" << '\n';
}

void CameraDubla::descriere(std::ostream& out) const
{
    out << "Aceasta este o camera dubla. Poate gazdui simultan cel mult doi clienti. Costul acestei camere este de doua ori costul camerei de baza, adica " << this->getPret() << "." << '\n';
}

void CameraDubla::rezerva(const std::vector<Client>& c)
{
    if (c.size() > 2)
        throw eroarePreaMultiClienti("Camera Dubla");
    if (c.empty())
        throw eroareCameraRezervataDe0Clienti("Camera Dubla");

    if (!this->rezervat) {
        this->rezervat = true;

        if (c.size() == 1)
        {
            this->clienti[0] = std::dynamic_pointer_cast<Client>(c[0].cloneaza());
            this->clienti[1] = nullptr;
        }
        else
        {
            this->clienti[0] = std::dynamic_pointer_cast<Client>(c[0].cloneaza());
            this->clienti[1] = std::dynamic_pointer_cast<Client>(c[1].cloneaza());
        }

        return;
    }

    std::cout << "Camera dubla este deja rezervata!" << '\n';
}

void CameraDubla::elibereaza()
{
    this->rezervat = false;

    this->clienti[0] = nullptr;
    this->clienti[1] = nullptr;
}
