#include <iostream>
#include <fstream>

#include "includes/client.h"
#include "includes/angajat.h"

#include "includes/cameraStandard.h"
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

    CameraStandard cs[5];
    CameraDubla cd[10];

    cs[0].descriere(out);
    cd[0].descriere(out);

    for (int i = 0; i < 5; ++i)
    {
        //std::cin >> c[i];
        in >> cs[i];
        h[0].adaugaCamera(cs[i]);
    }

    for (int i = 0; i < 5; ++i)
    {
        h[1].adaugaCamera(cd[i]);
    }

    std::cout << cs[4] << '\n';
    std::cout << cs[1] << '\n';

    std::cout << cs[4].getPret() << ' ' << cs[4].getCapacitate() << '\n';

    std::cout << h << '\n';
    out << cs[4] << '\n';
    out << cs[1] << '\n';

    out << h[0] << '\n';

    h[0].elibereazaCamera(cs[0].getNumar(), cs[0].getEtaj());

    in >> h[1];

    Client cli[7];

    for (int i = 0; i < 7; i++)
    {
        in >> cli[i];
        h[0].rezervaCamera(std::vector{cli[i]});
    }

    h[1] = h[0];

    cs[2] = cs[3];
    cli[2] = cli[3];

    Hotel hh(h[1]);

    hh.rezervaCamera(std::vector{cli[0]});
    h[1].rezervaCamera(std::vector{cli[0]});

    for (int i = 0 ; i < 5; i++)
    {
        h[0].elibereazaCamera(cs[i].getNumar(), cs[i].getEtaj());
    }

    for (int i = 0; i < 5; i++)
    {
        h[1].elibereazaCamera(cs[i].getNumar(), cs[i].getEtaj());
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
