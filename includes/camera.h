#ifndef CAMERA_H
#define CAMERA_H

#include <vector>

#include <istream>
#include <ostream>

#include "client.h"

class Camera
{
private:

    int numar;
    int etaj;

    bool rezervat;
    std::vector<Client> clienti;

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

    int getNumar()
    {
        return this->numar;
    }

    int getEtaj()
    {
        return this->etaj;
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
        this->rezervat = true;
    }

    void rezerva(Client& c)
    {
        this->rezervat = true;
        this->clienti.push_back(c);
    }

    void rezerva(const std::vector<Client>& c)
    {
        this->rezervat = true;

        for (size_t i = 0; i < c.size(); i++)
            this->clienti.push_back(c[i]);
    }

    void elibereaza()
    {
        this->rezervat = false;
        this->clienti.clear();
    }
};

#endif
