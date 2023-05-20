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

    Hotel(const std::string& nume = "-", int nrStele = -1);
    Hotel(const Hotel& b);
    Hotel& operator=(const Hotel& b);
    friend std::istream& operator>>(std::istream& in, Hotel& h);
    friend std::ostream& operator<<(std::ostream& out, const Hotel& h);
    friend void operator+=(Hotel& h, Camera& c);
    friend void operator-=(Hotel& h, Camera& c);
    std::string getNume() const;
    int getNrStele() const;
    int getCapacitate() const;
    std::shared_ptr<Hotel> cloneaza() const;
    void adaugaCamera(Camera& c);
    void eliminaCamera(Camera& c);
    void rezervaCamera(const std::vector<Client>& c);
    void elibereazaCamera(int numar, int etaj);
    template<typename T> void elibereazaCamera(); ///Elibereaza prima camera rezervata de tipul T gasita in lista de camere.
    void angajeaza(const Angajat& a);
    void concediaza(const Angajat& a);
};

#include "sabloaneHotel.h"

#endif
