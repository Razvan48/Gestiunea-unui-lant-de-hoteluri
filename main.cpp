#include <iostream>

#include "includes/hotel.h"
#include "includes/camera.h"

int main()
{
    Hotel* h = new Hotel("Hotel", 5);

    std::cout << *h << '\n';

    Camera* c1 = new Camera(1, 1);
    Camera* c2 = new Camera(2, 1);
    Camera* c3 = new Camera(3, 1);
    Camera* c4 = new Camera(4, 1);
    Camera* c5 = new Camera(5, 1);
    h->adaugaCamera(c1);
    h->adaugaCamera(c5);
    h->adaugaCamera(c4);
    h->adaugaCamera(c3);
    h->adaugaCamera(c2);

    std::cout << *c5 << '\n';
    std::cout << *c2 << '\n';

    std::cout << *h << '\n';

    delete h;
    

    return 0;
}
