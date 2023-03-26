#include "../includes/camera.h"

std::istream& operator>>(std::istream& in, Camera& c)
{
    in >> c.numar >> c.etaj;

    return in;
}

std::ostream& operator<<(std::ostream& out, const Camera& c)
{
    out << "Camera " << c.numar << ", aflata la etajul " << c.etaj << '\n';

    return out;
}

Camera& Camera::operator=(const Camera& b)
{
    if (this != &b)
    {
        this->numar = b.numar;
        this->etaj = b.etaj;

        this->rezervat = b.rezervat;

        this->clienti.clear();

        for (size_t i = 0; i < b.clienti.size(); i++)
            this->clienti.push_back(b.clienti[i]);
    }

    return *this;
}