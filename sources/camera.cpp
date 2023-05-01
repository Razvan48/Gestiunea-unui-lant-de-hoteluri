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

        std::swap(this->numar, temp.numar);
        std::swap(this->etaj, temp.etaj);
        std::swap(this->rezervat, temp.rezervat);
        std::swap(this->clienti, temp.clienti);
    }

    return *this;
}

void Camera::rezerva(const std::vector<Client>& c)
{
    if (!this->rezervat)
    {
        this->rezervat = true;

        for (size_t i = 0; i < c.size(); i++)
        {
            bool clientDejaAdaugat = false;

            for (size_t j = 0; j < this->clienti.size() && !clientDejaAdaugat; j++)
                if (this->clienti[j] == c[i])
                    clientDejaAdaugat = true;

            if (!clientDejaAdaugat)
                this->clienti.push_back(c[i]);
        }

        return;
    }

    std::cout << "Camera este deja rezervata!" << '\n';
}
