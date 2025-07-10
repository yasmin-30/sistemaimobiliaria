#include "cliente.h"

int Cliente::proximoId = 1;

Cliente::Cliente(std::string telefone, std::string nome)
    : telefone(telefone), nome(nome) {
    id = proximoId++;
}

int Cliente::getId() const { return id; }
std::string Cliente::getTelefone() const { return telefone; }
std::string Cliente::getNome() const { return nome; }
