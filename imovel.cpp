#include <iostream>
#include <string>
#include "imovel.h"

using namespace std;

// valor inicial da static int
int Imovel::nextId = 1;

//construtor parametrizado
Imovel::Imovel(std::string tipo, int proprietarioId, double lat, double lng, double preco, string endereco)
    : proprietarioId(proprietarioId), lat(lat), lng(lng), preco(preco), endereco(endereco) {
    setTipo(tipo);
    this->id = nextId++;
}

//destrutor
Imovel::~Imovel() {}

//métodos getter 
int Imovel::getId() const {
    return this->id;
}

Tipo Imovel::getTipo() const {
    return this->tipo;
}

int Imovel::getProprietarioId() const {
    return this->proprietarioId;
}

double Imovel::getLat() const {
    return this->lat;
}

double Imovel::getLng() const {
    return this->lng;
}

string Imovel::getEndereco() const {
    return this->endereco;
}

double Imovel::getPreco() const {
    return this->preco;
}

// Método setter
void Imovel::setTipo(string tipo_str) {
    if(tipo_str == "Casa") {
        this->tipo = Casa;
    } else if (tipo_str == "Apartamento") {
        this->tipo = Apartamento;
    } else if (tipo_str == "Terreno") {
        this->tipo = Terreno;
    }
}

