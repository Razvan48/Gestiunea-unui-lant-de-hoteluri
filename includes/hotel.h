#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <string>

#include <iostream>
#include <istream>
#include <ostream>

#include "camera.h"

class Hotel
{
private:

    std::string nume;
    int nrStele;
    std::vector<Camera*> camera;

public:
    Hotel(const std::string& nume, int nrStele) : nume(nume), nrStele(nrStele)
    {

    }

    friend std::istream& operator>>(std::istream& in, Hotel& h);
    friend std::ostream& operator<<(std::ostream& out, const Hotel& h);

    void adaugaCamera(Camera* c);

    friend void operator+=(Hotel& h, Camera* c);

    Camera* rezervaCamera();
    void elibereazaCamera(const Camera* c);

    ~Hotel()
    {
        for (size_t i = 0; i < this->camera.size(); i++)
            delete this->camera[i];
    }
};

#endif
