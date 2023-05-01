#include "../includes/cameraStandard.h"

std::istream& operator>>(std::istream& in, CameraStandard& c)
{
    in >> c.numar >> c.etaj;

    return in;
}

std::ostream& operator<<(std::ostream& out, const CameraStandard& c)
{
    out << "Camera standard " << c.numar << ", aflata la etajul " << c.etaj << ", care ";

    if (!c.rezervat)
        out << "nu ";

    out << "este rezervata" << '\n';

    return out;
}

CameraStandard& CameraStandard::operator=(const CameraStandard& b)
{
    if (this != &b)
    {
        CameraStandard temp(b);

        std::swap(this->numar, temp.numar);
        std::swap(this->etaj, temp.etaj);
        std::swap(this->rezervat, temp.rezervat);

        if (this->client != nullptr)
            delete this->client;

        if (temp.client != nullptr)
            this->client = temp.client->cloneaza();
        else
            this->client = nullptr;
    }

    return *this;
}

void CameraStandard::afiseaza(std::ostream& out) const
{
    out << "Camera standard " << this->numar << ", aflata la etajul " << this->etaj << ", care ";

    if (!this->rezervat)
        out << "nu ";

    out << "este rezervata" << '\n';
}
