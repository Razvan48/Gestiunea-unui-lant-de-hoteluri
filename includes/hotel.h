#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <string>

#include <iostream>
#include <istream>
#include <ostream>

#include <memory>

#include "client.h"
#include "angajat.h"

#include "camera.h"
#include "cameraStandard.h"
#include "cameraDubla.h"

#include "exceptie.h"

class Hotel
{
private:

    std::string nume;
    int nrStele;

    std::vector<std::shared_ptr<Camera>> camere;
    std::vector<std::shared_ptr<Angajat>> angajati;

    int numarCamereStandard;
    int numarCamereDuble;

    int capacitate;

public:
    Hotel(const std::string& nume = "-", int nrStele = -1) :
        nume(nume), nrStele(nrStele), numarCamereStandard(0), numarCamereDuble(0), capacitate(0) {}

    Hotel(const Hotel& b) : nume(b.nume), nrStele(b.nrStele)
    {
        for (size_t i = 0; i < b.camere.size(); ++i)
        {
            if (b.camere[i] != nullptr)
                this->camere.push_back(std::shared_ptr<Camera>(b.camere[i]->cloneaza()));
            else
                this->camere.push_back(nullptr);
        }
        for (size_t i = 0; i < b.angajati.size(); ++i)
        {
            if (b.angajati[i] != nullptr)
                this->angajati.push_back(std::shared_ptr<Angajat>(b.angajati[i]->cloneaza()));
            else
                this->angajati.push_back(nullptr);
        }
    }

    Hotel& operator=(const Hotel& b);
    friend std::istream& operator>>(std::istream& in, Hotel& h);
    friend std::ostream& operator<<(std::ostream& out, const Hotel& h);

    friend void operator+=(Hotel& h, Camera& c) { h.adaugaCamera(c); }
    friend void operator-=(Hotel& h, Camera& c) { h.eliminaCamera(c); }

    int getCapacitate() const { return this->capacitate; }

    void adaugaCamera(Camera& c);
    void eliminaCamera(Camera& c);
    void rezervaCamera(const std::vector<Client>& c);
    void elibereazaCamera(int numar, int etaj);

    void angajeaza(const Angajat& a);
    void concediaza(const Angajat& a);

    ~Hotel() {}
};

#endif
