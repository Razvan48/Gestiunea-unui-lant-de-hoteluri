#include <iostream>
#include <fstream>

#include "includes/client.h"
#include "includes/angajat.h"

#include "includes/cameraStandard.h"
#include "includes/cameraDubla.h"

#include "includes/hotel.h"

#include "includes/lantDeHoteluri.h"

int main()
{



    /// de refacut tot codul din main



    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    Hotel h[2];
    in >> h[0] >> h[1];

    out << h[0] << h[1] << '\n';

    CameraStandard cs[10];
    CameraDubla cd[5];

    cs[0].descriere(out);
    cd[0].descriere(out);

    for (int i = 0; i < 10; ++i)
    {
        in >> cs[i];

        try
        {
            h[0].adaugaCamera(cs[i]);
        }
        catch (const eroareCameraDejaExistenta& e)
        {
            std::cout << e.what() << '\n';
        }
    }

    std::cout << "Capacitate hotel: ";
    std::cout << h[0].getCapacitate() << '\n';

    for (int i = 0; i < 5; ++i)
    {
        in >> cd[i];

        try
        {
            h[1].adaugaCamera(cd[i]);
        }
        catch (const eroareCameraDejaExistenta& e)
        {
            std::cout << e.what() << '\n';
        }
    }

    std::cout << "Capacitate hotel: ";
    std::cout << h[1].getCapacitate() << '\n';

    std::cout << cs[4] << '\n';
    std::cout << cs[1] << '\n';

    std::cout << cs[4].getPret() << ' ' << cs[4].getCapacitate() << '\n';

    std::cout << h[0] << '\n';
    out << cs[4] << '\n';
    out << cs[1] << '\n';

    out << h[0] << '\n';

    try
    {
        h[0].elibereazaCamera(cs[0].getNumar(), cs[0].getEtaj());
    }
    catch (const eroareCameraNegasita& e)
    {
        std::cout << e.what() << '\n';
    }

    in >> h[1];

    Client cli[7];

    for (int i = 0; i < 7; i++)
    {
        in >> cli[i];

        try
        {
            h[0].rezervaCamera(std::vector{cli[i]});
        }
        catch (const eroareCamereInsuficientDeMari& e)
        {
            std::cout << e.what() << '\n';
        }
    }

    h[1] = h[0];

    cs[2] = cs[3];
    cli[2] = cli[3];

    out << cli[3] << '\n';
    out << cli[3] << '\n';

    Hotel h3(h[1]);

    h3.rezervaCamera(std::vector{cli[0]});
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

    try
    {
        h[1].angajeaza(a[0]);
        h[0].concediaza(a[0]);
    }
    /*
    catch (const eroareAngajatNegasit& e)
    {
        std::cout << e.what() << '\n';
    }
    */
    catch (const eroareAngajatDejaExistent& e)
    {
        std::cout << e.what() << '\n';
    }

    LantDeHoteluri::getInstanta().adaugaHotel(h[0]);
    //LantDeHoteluri::getInstanta().adaugaHotel(h[1]);

    /*
    try
    {
        LantDeHoteluri::getInstanta().adaugaHotel(h[0]);
    }
    catch (const eroareHotelDejaExistent& e)
    {
        std::cout << e.what() << '\n';
    }
    */

    LantDeHoteluri::getInstanta().eliminaHotel(h[0]);

    /*
    try
    {
        LantDeHoteluri::getInstanta().eliminaHotel(h[0]);
    }
    catch (const eroareHotelNegasit& e)
    {
        std::cout << e.what() << '\n';
    }
     */

    std::cout << "Press any key to continue." << '\n';
    std::cin.get();

    LantDeHoteluri::getInstanta().stergeInstanta();

    in.close();
    out.close();

    return 0;
}
