#ifndef CAMERASTANDARD_H
#define CAMERASTANDARD_H

#include "camera.h"

class CameraStandard : public Camera // Camera standard poate gazdui maxim un client.
{
private:

    static const int NUMAR_CLIENTI = 1;

    Client* client;

public:

    CameraStandard(int numar = -1, int etaj = -1) : Camera(numar, etaj), client(nullptr)
    {

    }

    CameraStandard(const CameraStandard& b) : Camera(b)
    {
        if (client == nullptr)
            this->client = nullptr;
        else
            this->client = client->cloneaza();
    }

    int getPret() const override
    {
        return Camera::pret;
    }

    void descriere(std::ostream& out) const override
    {
        out << "Aceasta este o camera standard." << '\n';
    }

    CameraStandard* cloneaza() const override
    {
        return new CameraStandard(*this);
    }

    void afiseaza(std::ostream& out) const override;

    CameraStandard& operator=(const CameraStandard& b);

    friend std::istream& operator>>(std::istream& in, CameraStandard& obj);
    friend std::ostream& operator<<(std::ostream& out, const CameraStandard& obj);

    void rezerva()
    {
        if (!this->rezervat)
        {
            this->rezervat = true;
            return;
        }

        std::cout << "Camera standard este deja rezervata!" << '\n';
    }

    void rezerva(const Client& c)
    {
        if (!this->rezervat)
        {
            this->rezervat = true;
            this->client = c.cloneaza();
            return;
        }

        std::cout << "Camera standard este deja rezervata!" << '\n';
    }

    void elibereaza() override
    {
        this->rezervat = false;

        if (this->client != nullptr)
            delete this->client;

        this->client = nullptr;
    }

    virtual ~CameraStandard()
    {
        if (this->client != nullptr)
            delete this->client;
    }
};

#endif
