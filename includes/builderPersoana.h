#ifndef BUILDERPERSOANA_H
#define BUILDERPERSOANA_H

#include <string>

template<typename T> class builderPersoana
{
private:

    T p;

public:

    builderPersoana() = default;
    builderPersoana& nume(const std::string& nume);
    builderPersoana& prenume(const std::string& prenume);
    builderPersoana& numarTelefon(const std::string& numarTelefon);
    T build();
};

#include "../sources/builderPersoana.cpp"

#endif
