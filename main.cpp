#include <iostream>
#include <fstream>

#include "includes/hotel.h"
#include "includes/camera.h"

int main()
{
    std::ifstream in("tastatura.txt");

    Hotel* h = new Hotel();
    in >> *h;

    std::cout << *h << '\n';

    Camera* c1 = new Camera();
    Camera* c2 = new Camera();
    Camera* c3 = new Camera();
    Camera* c4 = new Camera();
    Camera* c5 = new Camera();

    in >> *c1 >> *c2 >> *c3 >> *c4 >> *c5;

    h->adaugaCamera(c1);
    h->adaugaCamera(c5);
    h->adaugaCamera(c4);
    h->adaugaCamera(c3);
    h->adaugaCamera(c2);

    std::cout << *c5 << '\n';
    std::cout << *c2 << '\n';

    std::cout << *h << '\n';

    h->rezervaCamera();
    h->rezervaCamera();
    h->rezervaCamera();
    h->rezervaCamera();
    h->rezervaCamera();
    h->rezervaCamera();

    h->elibereazaCamera(c1);

    h->rezervaCamera();
    h->rezervaCamera();

    delete h;

    //Nu dam delete manual la camerele atasate la hotel, deoarece vor fi sterse de destructorul hotelului.

    in.close();

    return 0;
}
