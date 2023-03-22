#include "../includes/hotel.h"

void Hotel::adaugaCamera(Camera* c)
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
            out << *h.camere[i];
    }

    return out;
}
