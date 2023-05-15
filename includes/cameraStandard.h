#ifndef CAMERASTANDARD_H
#define CAMERASTANDARD_H

#include "camera.h"

class CameraStandard : public Camera // Camera standard poate gazdui maxim un client.
{
private:

    std::shared_ptr<Client> client;

public:

    CameraStandard(int numar = -1, int etaj = -1);
    CameraStandard(const CameraStandard& b);
    CameraStandard& operator=(const CameraStandard& b);
    friend std::istream& operator>>(std::istream& in, CameraStandard& obj);
    friend std::ostream& operator<<(std::ostream& out, const CameraStandard& obj);
    std::shared_ptr<Camera> cloneaza() const override;
    void afiseaza(std::ostream& out) const override;
    void descriere(std::ostream& out) const override;
    static int getPret();
    static int getCapacitate();
    void rezerva(const std::vector<Client>& c) override;
    void elibereaza() override;
};

#endif
