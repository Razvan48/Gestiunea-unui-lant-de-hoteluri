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

        for (size_t i = 0; i < this->client.size(); i++)
            delete this->client[i];
        this->client.clear();

        for (size_t i = 0; i < b.client.size(); i++)
            this->client.push_back(b.client[i]);
    }

    return *this;
}