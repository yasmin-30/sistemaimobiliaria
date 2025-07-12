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
        double preco;
        std::string endereco;

    public:
        Imovel(std::string tipo, int proprietarioId, double lat, double lng, double preco, std::string endereco);
        ~Imovel();
        int getId() const;
        Tipo getTipo() const;
        int getProprietarioId() const;
        double getLat() const;
        double getLng() const;
        std::string getEndereco() const;
        double getPreco() const;
        void setTipo(std::string tipo);
};

#endif
