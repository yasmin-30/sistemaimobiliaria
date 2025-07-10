#ifndef _IMOVEL_H_
#define _IMOVEL_H_

#include <string>

enum Tipo {Casa, Apartamento, Terreno};

class Imovel{
    private:
        static int nextId;
        int id;
        Tipo tipo; 
        int proprietarioId;
        double lat;
        double lng;
        std::string endereco;
        double preco;

    public:
        Imovel(Tipo tipo, int proprietarioId, double lat, double lng, std::string endereco, double preco);
        ~Imovel();
        int getId();
        Tipo getTipo();
        int getProprietarioId();
        double getLat();
        double getLng();
        std::string getEndereco();
        double getPreco();
};

#endif
