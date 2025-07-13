#include <iostream>
#include <string>
#include <vector>
#include "imovel.h"
#include "cliente.h"
#include "corretor.h"
#include "gerenciamento.h"
#include "agenda.h"

using namespace std;


int main() {
    Gerenciamento g;
    string linha;

    // Ler corretores
    int numCorretores;
    cin >> numCorretores;
    for (int i = 0; i < numCorretores; ++i) {
        // ler telefone, avaliador, lat, lon
        string telefone; int avaliador; double lat, lon;
        cin >> telefone >> avaliador >> lat >> lon;
        // ler nome
        string nome;
        getline(cin >> ws, nome);

        Corretor corretor(telefone, avaliador, lat, lon, nome);
        g.addCorretor(corretor);
    }

    //Pegar linha vazia
    getline(cin, linha);

    // Ler clientes
    int numClientes;
    cin >> numClientes;
    for (int i = 0; i < numClientes; ++i) {
        // ler telefone
        string telefone;
        cin >> telefone;
        // ler nome
        string nome;
        getline(cin >> ws, nome);

        Cliente cliente(telefone, nome);
        g.addCliente(cliente);
    }

    //Pegar linha vazia
    getline(cin, linha);

    // Ler imóveis
    int numImoveis;
    cin >> numImoveis;
    for (int i = 0; i < numImoveis; ++i) {
        // ler tipo, propId, lat, lon, preco
        string tipo; int propId; double lat, lon, preco;
        cin >> tipo >> propId >> lat >> lon >> preco;
        // ler endereco
        string endereco;
        getline(cin >> ws, endereco);

        Imovel imovel(tipo, propId, lat, lon, preco, endereco);
        g.addImovel(imovel);
    }
    
    gerarAgenda(g);
    
    return 0;
}
