#include <iostream>
#include <string>
#include <vector>
#include "imovel.h"

using namespace std;

// valor inicial da static int
int Imovel::nextId = 1;

//construtor parametrizado
Imovel::Imovel(Tipo tipo, int proprietarioId, double lat, double lng, string endereco, double preco): id(nextId++), tipo(tipo), proprietarioId(proprietarioId), lat(lat), lng(lng), endereco(endereco), preco(preco) {}

//destrutor
Imovel::~Imovel() {}

//métodos getter 
int Imovel::getId() {
    return this->id;
}

Tipo Imovel::getTipo() {
    return this->tipo;
}

int Imovel::getProprietarioId() {
    return this->proprietarioId;
}

double Imovel::getLat() {
    return this->lat;
}

double Imovel::getLng() {
    return this->lng;
}

string Imovel::getEndereco() {
    return this->endereco;
}

double Imovel::getPreco() {
    return this->preco;
}