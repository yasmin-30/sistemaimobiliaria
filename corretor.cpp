#include "corretor.h"

int Corretor::proximoId = 1;

Corretor::Corretor(std::string telefone, bool avaliador, double lat, double lon, std::string nome)
    : telefone(telefone), avaliador(avaliador), lat(lat), lon(lon), nome(nome) {
    id = proximoId++;
}

int Corretor::getId() const { return id; }
std::string Corretor::getTelefone() const { return telefone; }
bool Corretor::isAvaliador() const { return avaliador; }
double Corretor::getLat() const { return lat; }
double Corretor::getLon() const { return lon; }
std::string Corretor::getNome() const { return nome; }
