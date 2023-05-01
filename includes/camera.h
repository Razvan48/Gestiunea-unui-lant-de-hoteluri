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

    int numar;
    int etaj;

    bool rezervat;
    std::vector<Client> clienti;

    static const int pret = 1000;

public:
    Camera(int numar = -1, int etaj = -1, bool rezervat = false) : numar(numar), etaj(etaj), rezervat(rezervat)
    {

    }

    Camera(const Camera& b) : numar(b.numar), etaj(b.etaj), rezervat(b.rezervat)
    {
        this->clienti.clear();
        for (size_t i = 0; i < b.clienti.size(); i++)
            this->clienti.push_back(b.clienti[i]);
    }

    virtual int getPret() const
    {
        return Camera::pret;
    }

    virtual void descriere(std::ostream& out) const
    {
        out << "Aceasta este o camera standard." << '\n';
    }

    int getNumar()
    {
        return this->numar;
    }

    int getEtaj()
    {
        return this->etaj;
    }

    virtual Camera* cloneaza() const
    {
        return new Camera(*this);
    }

    Camera& operator=(const Camera& b);

    friend std::istream& operator>>(std::istream& in, Camera& obj);
    friend std::ostream& operator<<(std::ostream& out, const Camera& obj);

    bool getRezervat() const
    {
        return this->rezervat;
    }

    void rezerva()
    {
        if (!this->rezervat)
        {
            this->rezervat = true;
            return;
        }

        std::cout << "Camera este deja rezervata!" << '\n';
    }

    void rezerva(Client& c)
    {
        if (!this->rezervat)
        {
            this->rezervat = true;
            this->clienti.push_back(c);
            return;
        }

        std::cout << "Camera este deja rezervata!" << '\n';
    }

    void rezerva(const std::vector<Client>& c);

    void elibereaza()
    {
        this->rezervat = false;
        this->clienti.clear();
    }

    virtual ~Camera()
    {
        
    }
};

#endif
