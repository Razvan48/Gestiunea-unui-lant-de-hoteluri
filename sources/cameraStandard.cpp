#include "../includes/cameraStandard.h"

CameraStandard& CameraStandard::operator=(const CameraStandard& b)
{
    if (this != &b)
    {
        CameraStandard temp(b);

        std::swap(this->numar, temp.numar);
        std::swap(this->etaj, temp.etaj);
        std::swap(this->rezervat, temp.rezervat);

        std::swap(this->client, temp.client);
    }

    return *this;
}

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

void CameraStandard::afiseaza(std::ostream& out) const
{
    out << "Camera standard " << this->numar << ", aflata la etajul " << this->etaj << ", care ";

    if (!this->rezervat)
        out << "nu ";

    out << "este rezervata" << '\n';
}

void CameraStandard::descriere(std::ostream& out) const
{
    out << "Aceasta este o camera standard." << '\n';
}

int CameraStandard::getPret() const
{
    return Camera::pret;
}

int CameraStandard::getCapacitate() const
{
    return Camera::capacitate;
}

void CameraStandard::rezerva(const std::vector<Client>& c)
{
    if (c.size() > 1)
        throw eroarePreaMultiClienti("Camera Standard");
    if (c.empty())
        throw eroareCameraRezervataDe0Clienti("Camera Standard");

    if (!this->rezervat)
    {
        this->rezervat = true;

        this->client = std::shared_ptr<Client>(c[0].cloneaza());

        return;
    }

    std::cout << "Camera standard este deja rezervata!" << '\n';
}

void CameraStandard::elibereaza()
{
    this->rezervat = false;

    this->client = nullptr;
}
