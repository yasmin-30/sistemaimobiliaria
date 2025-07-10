#ifndef CORRETOR_H
#define CORRETOR_H

#include <string>

class Corretor {
public:
    int getId() const;
    std::string getTelefone() const;
    bool isAvaliador() const;
    double getLat() const;
    double getLon() const;
    std::string getNome() const;

    Corretor(std::string telefone, bool avaliador, double lat, double lon, std::string nome);

private:
    static int proximoId;
    int id;
    std::string telefone;
    bool avaliador;
    double lat, lon;
    std::string nome;
};

#endif
