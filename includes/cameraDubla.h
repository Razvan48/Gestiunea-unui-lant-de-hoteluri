#ifndef OOP_CAMERADUBLA_H
#define OOP_CAMERADUBLA_H

#include "camera.h"

class CameraDubla : public Camera
{
private:

public:

    CameraDubla* cloneaza() const override
    {
        return new CameraDubla(*this);
    }

    int getPret() const override
    {
        return 2 * Camera::getPret();
    }

    void descriere(std::ostream& out) const override
    {
        out << "Aceasta este o camera dubla." << '\n';
    }
};

#endif
