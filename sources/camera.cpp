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
        Camera temp(b);
        std::swap(*this, temp);
    }

    return *this;
}