#include <iostream>
#include <fstream>

#include "includes/hotel.h"
#include "includes/camera.h"

int main()
{
    /// std::ifstream in("tastatura.in");

    Hotel h = Hotel();
    std::cin >> h;

    std::cout << h << '\n';

    Camera c[5];

    for (size_t i = 0; i < 5; i++)
    {
        std::cin >> c[i];
        h.adaugaCamera(c[i]);
    }

    std::cout << c[4] << '\n';
    std::cout << c[1] << '\n';

    std::cout << h << '\n';

    h.rezervaCamera();
    h.rezervaCamera();
    h.rezervaCamera();
    h.rezervaCamera();
    h.rezervaCamera();
    h.rezervaCamera();

    h.elibereazaCamera(c[0].getNumar(), c[0].getEtaj());

    h.rezervaCamera();
    h.rezervaCamera();

    return 0;
}
