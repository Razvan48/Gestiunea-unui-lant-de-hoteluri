#include "../includes/lantDeHoteluri.h"

LantDeHoteluri* LantDeHoteluri::instanta = nullptr;

void LantDeHoteluri::adaugaHotel(Hotel& h)
{
    bool hotelDejaExistent = false;

    for (size_t i = 0; i < this->hoteluri.size() && !hotelDejaExistent; ++i)
        if (this->hoteluri[i]->getNume() == h.getNume() && this->hoteluri[i]->getNrStele() == h.getNrStele())
            hotelDejaExistent = true;

    if (!hotelDejaExistent)
        this->hoteluri.push_back(std::shared_ptr<Hotel>(h.cloneaza()));
    else
        throw eroareHotelDejaExistent("hotelul ce trebuia adaugat in cadrul lantului de hoteluri deja exista");
}

void LantDeHoteluri::eliminaHotel(Hotel& h)
{
    for (size_t i = 0; i < this->hoteluri.size(); ++i)
    {
        if (this->hoteluri[i]->getNume() == h.getNume() && this->hoteluri[i]->getNrStele() == h.getNrStele())
        {
            std::swap(this->hoteluri[i], this->hoteluri.back());
            this->hoteluri.pop_back();

            return;
        }
    }

    throw eroareHotelNegasit("hotelul ce trebuia eliminat din cadrul lantului de hoteluri nu a fost gasit");
}
