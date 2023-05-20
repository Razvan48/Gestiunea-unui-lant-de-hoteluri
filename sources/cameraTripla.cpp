#include "../includes/cameraTripla.h"

CameraTripla::CameraTripla(int numar, int etaj) : Camera(numar, etaj), clienti{nullptr, nullptr, nullptr}
{

}

CameraTripla::CameraTripla(const CameraTripla& b) : Camera(b)
{
    if (b.clienti[0] != nullptr)
        this->clienti[0] = std::dynamic_pointer_cast<Client>(b.clienti[0]->cloneaza());
    else
        this->clienti[0] = nullptr;

    if (b.clienti[1] != nullptr)
        this->clienti[1] = std::dynamic_pointer_cast<Client>(b.clienti[1]->cloneaza());
    else
        this->clienti[1] = nullptr;

    if (b.clienti[2] != nullptr)
        this->clienti[2] = std::dynamic_pointer_cast<Client>(b.clienti[2]->cloneaza());
    else
        this->clienti[2] = nullptr;
}

CameraTripla& CameraTripla::operator=(const CameraTripla& b)
{
    if (this != &b)
    {
        Camera::operator=(b);
        CameraTripla temp(b);

        std::swap(this->clienti[0], temp.clienti[0]);
        std::swap(this->clienti[1], temp.clienti[1]);
        std::swap(this->clienti[2], temp.clienti[2]);
    }

    return *this;
}

std::istream& operator>>(std::istream& in, CameraTripla& c)
{
    in >> c.numar >> c.etaj;

    return in;
}

std::ostream& operator<<(std::ostream& out, const CameraTripla& c)
{
    out << "Camera tripla " << c.numar << ", aflata la etajul " << c.etaj << ", care ";

    if (!c.rezervat)
        out << "nu ";

    out << "este rezervata" << '\n';

    return out;
}

std::shared_ptr<Camera> CameraTripla::cloneaza() const
{
    return std::make_shared<CameraTripla>(*this);
}

void CameraTripla::afiseaza(std::ostream& out) const
{
    out << "Camera tripla " << this->numar << ", aflata la etajul " << this->etaj << ", care ";

    if (!this->rezervat)
        out << "nu ";

    out << "este rezervata" << '\n';
}

void CameraTripla::descriere(std::ostream& out) const
{
    out << "Aceasta este o camera tripla. Poate gazdui simultan cel mult trei clienti. Costul acestei camere este de trei ori costul camerei de baza, adica " << this->getPret() << "." << '\n';
}

int CameraTripla::getPret()
{
    return 3 * Camera::pret;
}

int CameraTripla::getCapacitate()
{
    return 3 * Camera::capacitate;
}

void CameraTripla::rezerva(const std::vector<Client>& c)
{
    if (c.size() > 3)
        throw eroarePreaMultiClienti("Camera Tripla");
    if (c.empty())
        throw eroareCameraRezervataDe0Clienti("Camera Tripla");

    if (!this->rezervat) {
        this->rezervat = true;

        if (c.size() == 1)
        {
            this->clienti[0] = std::dynamic_pointer_cast<Client>(c[0].cloneaza());
            this->clienti[1] = nullptr;
            this->clienti[2] = nullptr;
        }
        else if (c.size() == 2)
        {
            this->clienti[0] = std::dynamic_pointer_cast<Client>(c[0].cloneaza());
            this->clienti[1] = std::dynamic_pointer_cast<Client>(c[1].cloneaza());
            this->clienti[2] = nullptr;
        }
        else
        {
            this->clienti[0] = std::dynamic_pointer_cast<Client>(c[0].cloneaza());
            this->clienti[1] = std::dynamic_pointer_cast<Client>(c[1].cloneaza());
            this->clienti[2] = std::dynamic_pointer_cast<Client>(c[2].cloneaza());
        }

        return;
    }

    std::cout << "Camera tripla este deja rezervata!" << '\n';
}

void CameraTripla::elibereaza()
{
    this->rezervat = false;

    this->clienti[0] = nullptr;
    this->clienti[1] = nullptr;
    this->clienti[2] = nullptr;
}