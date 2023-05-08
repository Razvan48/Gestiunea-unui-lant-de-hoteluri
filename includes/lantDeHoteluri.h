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
        static LantDeHoteluri instanta;

        return instanta;
    }

    void adaugaHotel(const Hotel& h);
    void eliminaHotel(const Hotel& h);
};

#endif
