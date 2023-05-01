#ifndef CAMERADUBLA_H
#define CAMERADUBLA_H

#include <vector>

#include "camera.h"

class CameraDubla : public Camera // Camera dubla poate gazdui maxim doi clienti.
{
private:

    static const int NUMAR_CLIENTI = 2;

    bool rezervat;
    std::vector<Client*> clienti;

public:

    CameraDubla(int numar = -1, int etaj = -1) : Camera(numar, etaj)
    {
        this->clienti.resize(CameraDubla::NUMAR_CLIENTI, nullptr);
    }

    CameraDubla(const CameraDubla& b) : Camera(b)
    {
        for (size_t i = 0; i < CameraDubla::NUMAR_CLIENTI; ++i)
        {
            if (b.clienti[i] == nullptr)
                this->clienti[i] = nullptr;
            else
                this->clienti[i] = b.clienti[i]->cloneaza();
        }
    }

    CameraDubla* cloneaza() const override
    {
        return new CameraDubla(*this);
    }

    int getPret() const override
    {
        return 2 * Camera::pret;
    }

    void descriere(std::ostream& out) const override
    {
        out << "Aceasta este o camera dubla." << '\n';
    }

    CameraDubla& operator=(const CameraDubla& b);

    friend std::istream& operator>>(std::istream& in, CameraDubla& obj);
    friend std::ostream& operator<<(std::ostream& out, const CameraDubla& obj);

    void rezerva()
    {
        if (!this->rezervat)
        {
            this->rezervat = true;
            return;
        }

        std::cout << "Camera dubla este deja rezervata!" << '\n';
    }

    void afiseaza(std::ostream& out) const override;

    void rezerva(const std::vector<Client*> clienti);

    void rezerva(const Client* c0, const Client* c1 = nullptr)
    {
        if (!this->rezervat)
        {
            this->rezervat = true;

            this->clienti[0] = c0->cloneaza();
            if (c1 != nullptr)
                this->clienti[1] = c1->cloneaza();

            return;
        }

        std::cout << "Camera dubla este deja rezervata!" << '\n';
    }

    void elibereaza() override
    {
        this->rezervat = false;

        for (size_t i = 0; i < CameraDubla::NUMAR_CLIENTI; ++i)
        {
            if (this->clienti[i] != nullptr)
                delete this->clienti[i];

            this->clienti[i] = nullptr;
        }
    }

    ~CameraDubla()
    {
        for (size_t i = 0; i < CameraDubla::NUMAR_CLIENTI; ++i)
            if (this->clienti[i] != nullptr)
                delete this->clienti[i];
    }
};

#endif
