#ifndef CAMERADUBLA_H
#define CAMERADUBLA_H

#include <vector>

#include "camera.h"

class CameraDubla : public Camera // Camera dubla poate gazdui maxim doi clienti.
{
private:

    std::shared_ptr<Client> client0;
    std::shared_ptr<Client> client1;

public:

    CameraDubla(int numar = -1, int etaj = -1) : Camera(numar, etaj), client0(nullptr), client1(nullptr) {}

    CameraDubla(const CameraDubla& b) : Camera(b)
    {
        if (b.client0 != nullptr)
            this->client0 = std::shared_ptr<Client>(b.client0->cloneaza());
        else
            this->client0 = nullptr;

        if (b.client1 != nullptr)
            this->client1 = std::shared_ptr<Client>(b.client1->cloneaza());
        else
            this->client1 = nullptr;
    }

    CameraDubla& operator=(const CameraDubla& b);
    friend std::istream& operator>>(std::istream& in, CameraDubla& obj);
    friend std::ostream& operator<<(std::ostream& out, const CameraDubla& obj);

    CameraDubla* cloneaza() const override { return new CameraDubla(*this); }

    void afiseaza(std::ostream& out) const override;
    void descriere(std::ostream& out) const override;

    static int getPret() { return 2 * Camera::pret; }
    static int getCapacitate() { return 2 * Camera::capacitate; }

    void rezerva(const std::vector<Client>& c) override;
    void elibereaza() override;

    ~CameraDubla() {}
};

#endif
