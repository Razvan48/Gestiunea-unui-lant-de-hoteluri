#ifndef CAMERATRIPLA_H
#define CAMERATRIPLA_H

#include <vector>
#include <array>

#include "camera.h"

class CameraTripla : public Camera // Camera tripla poate gazdui maxim trei clienti.
{
private:

    std::array<std::shared_ptr<Client>, 3>clienti;

public:

    CameraTripla(int numar = -1, int etaj = -1);
    CameraTripla(const CameraTripla& b);
    CameraTripla& operator=(const CameraTripla& b);
    friend std::istream& operator>>(std::istream& in, CameraTripla& obj);
    friend std::ostream& operator<<(std::ostream& out, const CameraTripla& obj);
    std::shared_ptr<Camera> cloneaza() const override;
    void afiseaza(std::ostream& out) const override;
    void descriere(std::ostream& out) const override;
    static int getPret();
    static int getCapacitate();
    void rezerva(const std::vector<Client>& c) override;
    void elibereaza() override;
};

#endif
