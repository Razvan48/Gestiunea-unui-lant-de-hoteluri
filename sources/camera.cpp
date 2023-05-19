#include "../includes/camera.h"

Camera::Camera(int numar, int etaj) : numar(numar), etaj(etaj), rezervat(false)
{

}

Camera::Camera(const Camera& b) : numar(b.numar), etaj(b.etaj), rezervat(b.rezervat)
{

}

Camera& Camera::operator=(const Camera& b)
{
    if (this != &b)
    {
        ///Camera temp(b); /// Camera este clasa abstracta.

        ///std::swap(this->numar, temp.numar);
        ///std::swap(this->etaj, temp.etaj);
        ///std::swap(this->rezervat, temp.rezervat);

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

int Camera::getPret()
{
    return Camera::pret;
};

int Camera::getCapacitate()
{
    return Camera::capacitate;
};

void Camera::elibereaza()
{
    this->rezervat = false;
}

int Camera::getNumar() const
{
    return this->numar;
}

int Camera::getEtaj() const
{
    return this->etaj;
}

bool Camera::getRezervat() const
{
    return this->rezervat;
}

Camera::~Camera()
{

}
