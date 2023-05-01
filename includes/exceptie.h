#ifndef OOP_EXCEPTIE_H
#define OOP_EXCEPTIE_H

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

class eroareCameraDubla : public eroareAplicatie
{
public:
    explicit eroareCameraDubla(const std::string& mesaj) :
    eroareAplicatie("Eroare CAMERA DUBLA: " + mesaj) {};
};

#endif
