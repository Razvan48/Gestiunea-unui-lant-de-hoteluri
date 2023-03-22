#ifndef CAMERA_H
#define CAMERA_H

#include <istream>
#include <ostream>

class Camera
{
private:

    int numar;
    int etaj;
    bool rezervat;

public:
    Camera(int numar, int etaj, bool rezervat = false) : numar(numar), etaj(etaj), rezervat(rezervat)
    {

    }

    friend std::istream& operator>>(std::istream& in, Camera& obj);
    friend std::ostream& operator<<(std::ostream& out, const Camera& obj);

    bool getRezervat() const
    {
        return this->rezervat;
    }

    void setRezervat(bool rezervat)
    {
        this->rezervat = rezervat;
    }

    ~Camera() = default;
};

#endif
