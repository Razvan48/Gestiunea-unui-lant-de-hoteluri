#include "../includes/camera.h"

void Camera::afiseaza(std::ostream& out) const
{
    out << "Camera " << this->numar << ", aflata la etajul " << this->etaj << ", care ";

    if (!this->rezervat)
        out << "nu ";

    out << "este rezervata" << '\n';
}

void Camera::descriere(std::ostream& out) const
{
    out << "Aceasta este o camera." << '\n';
}

int Camera::getPret() const
{
    return Camera::pret;
}

int Camera::getCapacitate() const
{
    return Camera::capacitate;
}

void Camera::rezerva(const std::vector<Client>& c)
{
    if (!this->rezervat)
    {
        this->rezervat = true;
        return;
    }

    std::cout << "Camera este deja rezervata!" << '\n';
}

void Camera::elibereaza()
{
    this->rezervat = false;
}
