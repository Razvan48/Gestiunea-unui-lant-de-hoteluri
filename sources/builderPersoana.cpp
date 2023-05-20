#ifndef BUILDERPERSOANA_CPP
#define BUILDERPERSOANA_CPP

#include "../includes/builderPersoana.h"

template <typename T> builderPersoana<T>& builderPersoana<T>::nume(const std::string& nume)
{
    this->p.nume = nume;
    return *this;
}

template <typename T> builderPersoana<T>& builderPersoana<T>::prenume(const std::string& prenume)
{
    this->p.prenume = prenume;
    return *this;
}

template <typename T> builderPersoana<T>& builderPersoana<T>::numarTelefon(const std::string& numarTelefon)
{
    this->p.numarTelefon = numarTelefon;
    return *this;
}

template <typename T> T builderPersoana<T>::build()
{
    return this->p;
}

#endif