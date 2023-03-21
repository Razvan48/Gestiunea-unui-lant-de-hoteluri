#include "../includes/camera.h"

std::istream& operator>>(std::istream& in, Camera& c)
{
    in >> c.numar >> c.etaj;

    return in;
}

std::ostream& operator<<(std::ostream& out, Camera& c)
{
    out << "Camera " << c.numar << ", aflata la etajul " << c.etaj << '\n';

    return out;
}