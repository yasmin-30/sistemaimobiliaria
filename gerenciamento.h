#ifndef GERENCIAMENTO_H_
#define GERENCIAMENTO_H_

#include <vector>
#include "cliente.h"
#include "corretor.h"
#include "imovel.h"


class Gerenciamento {
    private:
        std::vector<Cliente> clientes;
        std::vector<Corretor> corretores;
        std::vector<Imovel> imoveis;
    public:
        void addCliente(Cliente& cli);
        void addCorretor(Corretor& co);
        void addImovel(Imovel& im);
        
        const std::vector<Cliente>& getClientes() const;
        const std::vector<Corretor>& getCorretores() const;
        const std::vector<Imovel>& getImoveis() const;
};

#endif
