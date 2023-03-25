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
    std::vector<Client*> client;

public:
    Camera(int numar, int etaj, bool rezervat = false) : numar(numar), etaj(etaj), rezervat(rezervat)
    {

    }

    Camera(const Camera& b) : numar(b.numar), etaj(b.etaj), rezervat(b.rezervat)
    {
        for (size_t i = 0; i < b.client.size(); i++)
            this->client.push_back(b.client[i]);
    }

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

    void rezerva(Client* c)
    {
        this->rezervat = true;
        this->client.push_back(c);
    }

    void rezerva(const std::vector<Client*>& c)
    {
        this->rezervat = true;

        for (size_t i = 0; i < c.size(); i++)
            this->client.push_back(c[i]);
    }

    void adaugaClient(Client* c)
    {
        this->client.push_back(c);
    }

    void elibereaza()
    {
        this->rezervat = false;

        //Depinde ce vrem sa facem. Daca legam un client strict de camera unde e cazat, atunci da, putem sterge clientii odata ce eliberam camera.
        for (size_t i = 0; i < this->client.size(); i++)
            delete this->client[i];
        this->client.clear();
    }

    ~Camera()
    {
        //Depinde ce vrem sa facem. Daca legam un client strict de camera unde e cazat, atunci da, putem sterge clientii odata ce stergem camera.
        for (size_t i = 0; i < this->client.size(); i++)
            delete this->client[i];
        this->client.clear();
    }
};

#endif
