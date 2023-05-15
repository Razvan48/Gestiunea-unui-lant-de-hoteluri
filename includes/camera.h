#ifndef CAMERA_H
#define CAMERA_H

#include <vector>

#include <iostream>
#include <istream>
#include <ostream>

#include <memory>

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
    static const int capacitate = 1;

public:

    Camera(int numar = -1, int etaj = -1) : numar(numar), etaj(etaj), rezervat(false) {};

    Camera(const Camera& b) : numar(b.numar), etaj(b.etaj), rezervat(b.rezervat) {};

    Camera& operator=(const Camera& b);

    virtual std::shared_ptr<Camera> cloneaza() const = 0;
    virtual void afiseaza(std::ostream& out) const = 0;
    virtual void descriere(std::ostream& out) const = 0;

    static int getPret() { return Camera::pret; };
    static int getCapacitate() { return Camera::capacitate; };

    virtual void rezerva(const std::vector<Client>& c) = 0;
    virtual void elibereaza() = 0;

    int getNumar() { return this->numar; }
    int getEtaj() { return this->etaj; }
    bool getRezervat() const { return this->rezervat; }

    virtual ~Camera() {};
};

#endif
