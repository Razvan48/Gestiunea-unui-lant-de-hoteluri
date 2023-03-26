#include <iostream>
#include <fstream>

#include "includes/hotel.h"
#include "includes/camera.h"

int main()
{
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    Hotel h = Hotel();
    in >> h;

    out << h << '\n';

    Camera c[5];

    for (size_t i = 0; i < 5; i++)
    {
        in >> c[i];
        h.adaugaCamera(c[i]);
    }

    out << c[4] << '\n';
    out << c[1] << '\n';

    out << h << '\n';

    h.rezervaCamera();
    h.rezervaCamera();
    h.rezervaCamera();
    h.rezervaCamera();
    h.rezervaCamera();
    h.rezervaCamera();

    h.elibereazaCamera(c[0].getNumar(), c[0].getEtaj());

    h.rezervaCamera();
    h.rezervaCamera();

    in.close();
    out.close();

    return 0;
}
