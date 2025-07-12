#include <vector>
#include "cliente.h"
#include "corretor.h"
#include "imovel.h"
#include "gerenciamento.h"

// Métodos de adição de valores
void Gerenciamento::addCliente(Cliente& cliente) {
    clientes.push_back(cliente);
}

void Gerenciamento::addCorretor(Corretor& corretor) {
    corretores.push_back(corretor);
}

void Gerenciamento::addImovel(Imovel& imovel) {
    imoveis.push_back(imovel);
}

// Métodos getters
const std::vector<Cliente>& Gerenciamento::getClientes() const {
    return clientes;
}

const std::vector<Corretor>& Gerenciamento::getCorretores() const {
    return corretores;
}

const std::vector<Imovel>& Gerenciamento::getImoveis() const {
    return imoveis;
}