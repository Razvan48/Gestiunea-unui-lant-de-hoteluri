#include <iostream>

#include "includes/hotel/hotel.h"
#include "includes/camera/camera.h"

int main()
{
    Hotel* h = new Hotel("Hotel", 5);
    Camera c1 = Camera(1, 1);
    Camera c2 = Camera(2, 1);
    Camera c3 = Camera(3, 1);
    Camera c4 = Camera(4, 1);
    Camera c5 = Camera(5, 1);
    h->adaugaCamera(c1);
    h->adaugaCamera(c5);
    h->adaugaCamera(c4);
    h->adaugaCamera(c3);
    h->adaugaCamera(c2);

    std::cout << c5 << '\n';
    std::cout << c2 << '\n';

    std::cout << h << '\n';

    return 0;
}
