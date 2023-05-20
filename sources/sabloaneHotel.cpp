#include "../includes/hotel.h"

template<typename T> void Hotel::elibereazaCamera()
{
    //bool existaTipCamera = false;

    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        if (dynamic_cast<T*>(this->camere[i].get()))
        {
            //existaTipCamera = true;

            if (this->camere[i]->getRezervat())
            {
                this->camere[i]->elibereaza();

                return;
            }
        }
    }

    //if (!existaTipCamera)
    //    throw eroareTipCameraNegasit("tipul de camera ce trebuia eliberat in cadrul unui hotel nu a fost gasit");
}

template void Hotel::elibereazaCamera<CameraStandard>();
template void Hotel::elibereazaCamera<CameraDubla>();
