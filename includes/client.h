#ifndef CLIENT_H
#define CLIENT_H

#include "persoana.h"

class Client : public Persoana
{
private:

public:

    Client(const std::string& nume = "-", const std::string& prenume = "-", const std::string& numarTelefon = "-");
    Client(const Client& b);
    Client& operator=(const Client& b);
    friend std::istream& operator>>(std::istream& in, Client& c);
    friend std::ostream& operator<<(std::ostream& out, const Client& c);
    bool operator==(const Client& b) const;
    bool operator!=(const Client& b) const;
    std::shared_ptr<Persoana> cloneaza() const override;
    void afiseaza(std::ostream& out) const override;
};

#endif
