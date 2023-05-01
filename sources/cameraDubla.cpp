#include "../includes/cameraDubla.h"

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

CameraDubla& CameraDubla::operator=(const CameraDubla& b)
{
    if (this != &b)
    {
        CameraDubla temp(b);

        std::swap(this->numar, temp.numar);
        std::swap(this->etaj, temp.etaj);
        std::swap(this->rezervat, temp.rezervat);

        for (size_t i = 0; i < b.clienti.size(); ++i)
            if (this->clienti[i] != nullptr)
                delete this->clienti[i];

        for (size_t i = 0; i < b.clienti.size(); ++i)
        {
            if (temp.clienti[i] != nullptr)
                this->clienti[i] = temp.clienti[i]->cloneaza();
            else
                this->clienti[i] = nullptr;
        }
    }

    return *this;
}

void CameraDubla::rezerva(const std::vector<Client*> clienti)
{
    if (clienti.size() >= CameraDubla::NUMAR_CLIENTI)
        throw eroarePreaMultiClienti("Nu s-au putut rezerva toti clientii in aceeasi camera!\n");

    if (clienti.size() == 0)
        this->rezerva();
    else if (clienti.size() == 1)
        this->rezerva(clienti[0]);
    else
        this->rezerva(clienti[0], clienti[1]);
}

void CameraDubla::afiseaza(std::ostream& out) const
{
    out << "Camera dubla " << this->numar << ", aflata la etajul " << this->etaj << ", care ";

    if (!this->rezervat)
        out << "nu ";

    out << "este rezervata" << '\n';
}
