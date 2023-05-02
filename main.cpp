#include <iostream>
#include <fstream>

#include "includes/Client.h"
#include "includes/Angajat.h"

#include "includes/CameraStandard.h"
#include "includes/cameraDubla.h"

#include "includes/hotel.h"

int main()
{
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    Hotel h[2];
    //std::cin >> h;
    in >> h[0];

    //std::cout << h << '\n';
    out << h[0] << '\n';

    CameraStandard c[5];

    for (int i = 0; i < 5; i++)
    {
        //std::cin >> c[i];
        in >> c[i];
        h[0].adaugaCamera(c[i]);
    }

    std::cout << c[4] << '\n';
    std::cout << c[1] << '\n';

    std::cout << h << '\n';
    out << c[4] << '\n';
    out << c[1] << '\n';

    out << h[0] << '\n';

    h[0].elibereazaCamera(c[0].getNumar(), c[0].getEtaj());

    in >> h[1];

    Client cli[7];

    for (int i = 0; i < 7; i++)
    {
        in >> cli[i];
        h[0].rezervaCamera(std::vector{cli[i]});
    }

    h[1] = h[0];

    c[2] = c[3];
    cli[2] = cli[3];

    Hotel hh(h[1]);

    hh.rezervaCamera(std::vector{cli[0]});
    h[1].rezervaCamera(std::vector{cli[0]});

    for (int i = 0 ; i < 5; i++)
    {
        h[0].elibereazaCamera(c[i].getNumar(), c[i].getEtaj());
    }

    for (int i = 0; i < 5; i++)
    {
        h[1].elibereazaCamera(c[i].getNumar(), c[i].getEtaj());
    }

    Angajat a[10];

    a[0] = Angajat("Popescu", "Ion", "-", "receptionist", 4000);

    h[1].angajeaza(a[0]);
    h[0].concediaza(a[0]);
    h[1].concediaza(a[0]);

    Angajat p[10];
    p[0] = Angajat("Popescu", "Pop", "-", "administrator", 5000);

    h[1].angajeaza(p[0]);
    h[1].concediaza(p[0]);
    h[1].concediaza(p[0]);

    std::cout << "Press any key to continue." << '\n';
    std::cin.get();

    in.close();
    out.close();

    return 0;
}
