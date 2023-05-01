#ifndef CAMERA_H
#define CAMERA_H

#include <vector>

#include <iostream>
#include <istream>
#include <ostream>

#include "client.h"

#include "exceptie.h"

class Camera
{
private:

protected:

    int numar;
    int etaj;

    bool rezervat;

    static const int pret = 1000;

public:

    Camera(int numar = -1, int etaj = -1) : numar(numar), etaj(etaj), rezervat(false)
    {

    }

    Camera(const Camera& b) : numar(b.numar), etaj(b.etaj), rezervat(b.rezervat)
    {

    }

    virtual Camera* cloneaza() const = 0;
    virtual void descriere(std::ostream& out) const = 0;
    virtual int getPret() const = 0;
    virtual void afiseaza(std::ostream& out) const = 0;
    virtual void elibereaza() = 0;

    int getNumar()
    {
        return this->numar;
    }

    int getEtaj()
    {
        return this->etaj;
    }

    bool getRezervat() const
    {
        return this->rezervat;
    }

    virtual ~Camera()
    {

    }
};

#endif
