#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include <string>

#include <iostream>
#include <istream>
#include <ostream>

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

    std::vector<Camera*> camere;

    std::vector<Angajat*> angajati;

public:
    Hotel(const std::string& nume = "-", int nrStele = -1) : nume(nume), nrStele(nrStele)
    {

    }

    Hotel(const Hotel& b) : nume(b.nume), nrStele(b.nrStele)
    {
        for (size_t i = 0; i < b.camere.size(); i++)
            this->camere.push_back(b.camere[i]->cloneaza());
        for (size_t i = 0; i < b.angajati.size(); i++)
            this->angajati.push_back(b.angajati[i]->cloneaza());
    }

    Hotel& operator=(const Hotel& b);

    friend std::istream& operator>>(std::istream& in, Hotel& h);
    friend std::ostream& operator<<(std::ostream& out, const Hotel& h);

    void adaugaCamera(Camera& c);

    friend void operator+=(Hotel& h, Camera& c);
    friend void operator-=(Hotel& h, Camera& c);

    void rezervaCamera();
    void rezervaCamera(Client& c);
    void rezervaCamera(const std::vector<Client>& c);
    void elibereazaCamera(int numar, int etaj);

    void angajeaza(const Angajat& a);
    void angajeaza(const Persoana& p, const std::string& functie, int salariu);
    void concediaza(const Angajat& a);
    void concediaza(const Persoana& p);

    ~Hotel()
    {
        for (size_t i = 0; i < this->camere.size(); ++i)
            delete this->camere[i];
        for (size_t i = 0; i < this->angajati.size(); ++i)
            delete this->angajati[i];
    }
};

#endif
