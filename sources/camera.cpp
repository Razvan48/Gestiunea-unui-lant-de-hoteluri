#include "../includes/camera.h"

Camera& Camera::operator=(const Camera& b)
{
    if (this != &b)
    {
        /// Camera temp(b); /// Camera este clasa abstracta.

        this->numar = b.numar;
        this->etaj = b.etaj;
        this->rezervat = b.rezervat;
    }

    return *this;
}

void Camera::afiseaza(std::ostream& out) const
{
    out << "Camera " << this->numar << ", aflata la etajul " << this->etaj << ", care ";

    if (!this->rezervat)
        out << "nu ";

    out << "este rezervata" << '\n';
}

void Camera::descriere(std::ostream& out) const
{
    out << "Aceasta este o camera de baza. Costul acestei camere este de " << this->getPret() << "." << '\n';
}

void Camera::elibereaza()
{
    this->rezervat = false;
}
