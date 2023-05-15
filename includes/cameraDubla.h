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

    CameraDubla(int numar = -1, int etaj = -1);
    CameraDubla(const CameraDubla& b);
    CameraDubla& operator=(const CameraDubla& b);
    friend std::istream& operator>>(std::istream& in, CameraDubla& obj);
    friend std::ostream& operator<<(std::ostream& out, const CameraDubla& obj);
    std::shared_ptr<Camera> cloneaza() const override;
    void afiseaza(std::ostream& out) const override;
    void descriere(std::ostream& out) const override;
    static int getPret();
    static int getCapacitate();
    void rezerva(const std::vector<Client>& c) override;
    void elibereaza() override;
};

#endif
