#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
public:
    static int proximoId;
    int id;
    std::string telefone;
    std::string nome;

    Cliente(std::string telefone, std::string nome);
};

#endif
