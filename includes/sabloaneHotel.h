#ifndef SABLOANEHOTEL_H
#define SABLOANEHOTEL_H

#include "hotel.h"

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

template<typename T> void Hotel::elibereazaToateCamerele()
{
    //bool existaTipCamera = false;

    for (size_t i = 0; i < this->camere.size(); ++i)
    {
        if (dynamic_cast<T*>(this->camere[i].get()))
        {
            //existaTipCamera = true;

            this->camere[i]->elibereaza();
        }
    }

    //if(!existaTipCamera)
    //    throw eroareTipCameraNegasit("tipul de camere ce trebuiau eliberate in cadrul unui hotel nu au fost gasite");
}

#endif
