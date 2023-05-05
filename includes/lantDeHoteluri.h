#ifndef LANTDEHOTELURI_H
#define LANTDEHOTELURI_H

#include <vector>

#include "hotel.h"

#include "exceptie.h"

/// Singleton
class LantDeHoteluri
{
private:

    std::vector<std::shared_ptr<Hotel>> hoteluri;

    static LantDeHoteluri* instanta;

private:

    LantDeHoteluri() {}

    ~LantDeHoteluri() {};

    LantDeHoteluri(const LantDeHoteluri& b)             = delete;
    LantDeHoteluri& operator=(const LantDeHoteluri& b)  = delete;
    LantDeHoteluri(const LantDeHoteluri&& b)            = delete;
    LantDeHoteluri& operator=(const LantDeHoteluri&& b) = delete;

public:

    static LantDeHoteluri& getInstanta()
    {
        if (LantDeHoteluri::instanta == nullptr)
            LantDeHoteluri::instanta = new LantDeHoteluri();

        return *(LantDeHoteluri::instanta);
    }

    void adaugaHotel(const Hotel& h);
    void eliminaHotel(const Hotel& h);

    static void stergeInstanta()
    {
        if (LantDeHoteluri::instanta != nullptr)
            delete LantDeHoteluri::instanta;
    }
};

#endif
