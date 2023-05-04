#ifndef EXCEPTIE_H
#define EXCEPTIE_H

#include <stdexcept>
#include <string>

class eroareAplicatie : public std::runtime_error
{
    using std::runtime_error::runtime_error;
};

class eroareAngajat : public eroareAplicatie
{
public:
    explicit eroareAngajat(const std::string& mesaj) :
    eroareAplicatie("Eroare ANGAJAT: " + mesaj) {};
};

class eroareCamera : public eroareAplicatie
{
public:
    explicit eroareCamera(const std::string& mesaj) :
    eroareAplicatie("Eroare CAMERA: " + mesaj) {};
};

class eroareClient : public eroareAplicatie
{
public:
    explicit eroareClient(const std::string& mesaj) :
    eroareAplicatie("Eroare CLIENT: " + mesaj) {};
};

class eroareHotel : public eroareAplicatie
{
public:
    explicit eroareHotel(const std::string& mesaj) :
    eroareAplicatie("Eroare HOTEL: " + mesaj) {}
};

class eroarePersoana : public eroareAplicatie
{
public:
    explicit eroarePersoana(const std::string& mesaj) :
    eroareAplicatie("Eroare PERSOANA: " + mesaj) {};
};

class eroareCameraStandard : public eroareAplicatie
{
public:
    explicit eroareCameraStandard(const std::string& mesaj) :
            eroareAplicatie("Eroare CAMERA STANDARD: " + mesaj) {};
};

class eroareCameraDubla : public eroareAplicatie
{
public:
    explicit eroareCameraDubla(const std::string& mesaj) :
    eroareAplicatie("Eroare CAMERA DUBLA: " + mesaj) {};
};

class eroarePreaMultiClienti : public eroareCamera
{
public:
    explicit eroarePreaMultiClienti(const std::string& mesaj) :
    eroareCamera("prea multi clienti: " + mesaj) {};
};

class eroareCamereInsuficientDeMari : public eroareHotel
{
public:
    explicit eroareCamereInsuficientDeMari(const std::string& mesaj) :
    eroareHotel("camere insuficient de mari: " + mesaj) {};
};

class eroareCameraRezervataDe0Clienti : public eroareCamera
{
public:
    explicit eroareCameraRezervataDe0Clienti(const std::string& mesaj) :
    eroareCamera("camera rezervata de 0 clienti: " + mesaj) {};
};

class eroareCameraDejaExistenta : public eroareHotel
{
public:
    explicit eroareCameraDejaExistenta(const std::string& mesaj) :
    eroareHotel("camera deja existenta: " + mesaj) {};
};

class eroareCameraNegasita : public eroareHotel
{
public:
    explicit eroareCameraNegasita(const std::string& mesaj) :
    eroareHotel("camera negasita: " + mesaj) {};
};

/*
class eroareAngajatNegasit : public eroareHotel
{
public:
    explicit eroareAngajatNegasit(const std::string& mesaj) :
    eroareHotel("angajat negasit: " + mesaj) {};
};
*/

class eroareAngajatDejaExistent : public eroareHotel
{
public:
    explicit eroareAngajatDejaExistent(const std::string& mesaj) :
    eroareHotel("angajat deja existent: " + mesaj) {};
};

#endif
