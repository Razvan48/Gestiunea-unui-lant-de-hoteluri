#ifndef CAMERADUBLA_H
#define CAMERADUBLA_H

#include <vector>
#include <array>

#include "camera.h"

class CameraDubla : public Camera // Camera dubla poate gazdui maxim doi clienti.
{
private:

    std::array<std::shared_ptr<Client>, 2>clienti;

public:

    CameraDubla(int numar = -1, int etaj = -1) : Camera(numar, etaj), clienti{nullptr, nullptr} {}

    CameraDubla(const CameraDubla& b) : Camera(b)
    {
        if (b.clienti[0] != nullptr)
            this->clienti[0] = std::dynamic_pointer_cast<Client>(b.clienti[0]->cloneaza());
        else
            this->clienti[0] = nullptr;

        if (b.clienti[1] != nullptr)
            this->clienti[1] = std::dynamic_pointer_cast<Client>(b.clienti[1]->cloneaza());
        else
            this->clienti[1] = nullptr;
    }

    CameraDubla& operator=(const CameraDubla& b);
    friend std::istream& operator>>(std::istream& in, CameraDubla& obj);
    friend std::ostream& operator<<(std::ostream& out, const CameraDubla& obj);

    std::shared_ptr<Camera> cloneaza() const override { return std::make_shared<CameraDubla>(*this); }

    void afiseaza(std::ostream& out) const override;
    void descriere(std::ostream& out) const override;

    static int getPret() { return 2 * Camera::pret; }
    static int getCapacitate() { return 2 * Camera::capacitate; }

    void rezerva(const std::vector<Client>& c) override;
    void elibereaza() override;

    ~CameraDubla() {}
};

#endif
