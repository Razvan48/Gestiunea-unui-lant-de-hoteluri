#include "../includes/cameraStandard.h"

CameraStandard::CameraStandard(int numar, int etaj) : Camera(numar, etaj), client(nullptr)
{

}

CameraStandard::CameraStandard(const CameraStandard& b) : Camera(b)
{
    if (b.client == nullptr)
        this->client = nullptr;
    else
        this->client = std::dynamic_pointer_cast<Client>(b.client->cloneaza());
}

CameraStandard& CameraStandard::operator=(const CameraStandard& b)
{
    if (this != &b)
    {
        Camera::operator=(b);
        CameraStandard temp(b);

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

std::shared_ptr<Camera> CameraStandard::cloneaza() const
{
    return std::make_shared<CameraStandard>(*this);
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
    out << "Aceasta este o camera standard. Poate gazdui un singur client. Costul acestei camere este costul camerei de baza, adica " << this->getPret() << "." << '\n';
}

int CameraStandard::getPret()
{
    return Camera::pret;
}

int CameraStandard::getCapacitate()
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

        this->client = std::dynamic_pointer_cast<Client>(c[0].cloneaza());

        return;
    }

    std::cout << "Camera standard este deja rezervata!" << '\n';
}

void CameraStandard::elibereaza()
{
    this->rezervat = false;

    this->client = nullptr;
}
