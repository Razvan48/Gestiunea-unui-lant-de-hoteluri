#ifndef OOP_CAMERA_H
#define OOP_CAMERA_H

#include <istream>
#include <ostream>

class Camera
{
private:

    int numar;
    int etaj;

public:
    Camera(int numar, int etaj) : numar(numar), etaj(etaj)
    {

    }

    friend std::istream& operator>>(std::istream& in, Camera& obj);
    friend std::ostream& operator<<(std::ostream& out, Camera& obj);

    ~Camera() = default;
};

#endif
