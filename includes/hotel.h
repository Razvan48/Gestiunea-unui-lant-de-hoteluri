#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <string>

#include <istream>
#include <ostream>

#include "camera.h"

class Hotel
{
private:

    std::string nume;
    int nrStele;
    std::vector<Camera*> camere;

public:
    Hotel(std::string nume, int nrStele) : nume(nume), nrStele(nrStele)
    {

    }

    friend std::istream& operator>>(std::istream& in, Hotel& h);
    friend std::ostream& operator<<(std::ostream& out, const Hotel& h);

    void adaugaCamera(Camera* c);

    ~Hotel()
    {
        for (size_t i = 0; i < this->camere.size(); i++)
            delete this->camere[i];
    }
};

#endif
