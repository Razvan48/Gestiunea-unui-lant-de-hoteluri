#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <string>

#include <iostream>
#include <istream>
#include <ostream>

#include "camera.h"
#include "client.h"

class Hotel
{
private:

    std::string nume;
    int nrStele;
    std::vector<Camera*> camera;

public:
    Hotel(const std::string& nume = "", int nrStele = -1) : nume(nume), nrStele(nrStele)
    {

    }

    Hotel(const Hotel& b) : nume(b.nume), nrStele(b.nrStele)
    {
        for (size_t i = 0; i < b.camera.size(); i++)
            this->camera.push_back(b.camera[i]);
    }

    Hotel& operator=(const Hotel& b);

    friend std::istream& operator>>(std::istream& in, Hotel& h);
    friend std::ostream& operator<<(std::ostream& out, const Hotel& h);

    void adaugaCamera(Camera* c);

    friend void operator+=(Hotel& h, Camera* c);

    Camera* rezervaCamera();
    Camera* rezervaCamera(Client* c);
    Camera* rezervaCamera(const std::vector<Client*>& c);
    void elibereazaCamera(const Camera* c);

    ~Hotel()
    {
        for (size_t i = 0; i < this->camera.size(); i++)
            delete this->camera[i];
        this->camera.clear();
    }
};

#endif
