#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
public:
    int getId() const;
    std::string getTelefone() const;
    std::string getNome() const;

    Cliente(std::string telefone, std::string nome);

private:
    static int proximoId;
    int id;
    std::string telefone;
    std::string nome;
};

#endif
