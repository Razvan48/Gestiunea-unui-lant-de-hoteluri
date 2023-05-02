#ifndef CAMERASTANDARD_H
#define CAMERASTANDARD_H

#include "camera.h"

class CameraStandard : public Camera // Camera standard poate gazdui maxim un client.
{
private:

    std::shared_ptr<Client> client;

public:

    CameraStandard(int numar = -1, int etaj = -1) : Camera(numar, etaj), client(nullptr) {};

    CameraStandard(const CameraStandard& b) : Camera(b)
    {
        if (client == nullptr)
            this->client = nullptr;
        else
            this->client = std::shared_ptr<Client>(client->cloneaza());
    }

    CameraStandard& operator=(const CameraStandard& b);
    friend std::istream& operator>>(std::istream& in, CameraStandard& obj);
    friend std::ostream& operator<<(std::ostream& out, const CameraStandard& obj);

    CameraStandard* cloneaza() const override { return new CameraStandard(*this); }

    void afiseaza(std::ostream& out) const override;
    void descriere(std::ostream& out) const override;
    int getPret() const override;
    int getCapacitate() const override;
    void rezerva(const std::vector<Client>& c) override;
    void elibereaza() override;

    ~CameraStandard() {}
};

#endif
