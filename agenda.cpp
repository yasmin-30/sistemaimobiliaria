#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>
#include <cmath>
#include "agenda.h"

constexpr double EARTH_R = 6371.0;

double haversine(double lat1, double lon1, double lat2, double lon2) {
    const double PI = 3.141592653589793;
    auto deg2rad = [PI](double d) { return d * PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = pow(sin(dlat / 2), 2) +
               cos(deg2rad(lat1)) * cos(deg2rad(lat2)) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return EARTH_R * c;
}

void gerarAgenda(const Gerenciamento& g) {
    std::vector<const Corretor*> avaliadores;
    for (const auto& c : g.getCorretores()) {
        if (c.isAvaliador())
            avaliadores.push_back(&c);
    }

    std::vector<const Imovel*> imoveis;
    for (const auto& im : g.getImoveis()) {
        imoveis.push_back(&im);
    }

    std::vector<std::vector<const Imovel*>> designacao(avaliadores.size());
    for (size_t i = 0; i < imoveis.size(); ++i) {
        designacao[i % avaliadores.size()].push_back(imoveis[i]);
    }

    for (size_t i = 0; i < avaliadores.size(); ++i) {
        const Corretor* c = avaliadores[i];
        const std::vector<const Imovel*>& lista = designacao[i];
        std::vector<bool> visitado(lista.size(), false);

        std::cout << "Corretor " << c->getId() << std::endl;

        double atualLat = c->getLat();
        double atualLon = c->getLon();
        int hora = 9, minuto = 0;

        for (size_t j = 0; j < lista.size(); ++j) {
            double menorDist = std::numeric_limits<double>::max();
            int indiceProximo = -1;

            for (size_t k = 0; k < lista.size(); ++k) {
                if (!visitado[k]) {
                    double d = haversine(atualLat, atualLon,
                                         lista[k]->getLat(), lista[k]->getLng());
                    if (d < menorDist) {
                        menorDist = d;
                        indiceProximo = k;
                    }
                }
            }

            const Imovel* prox = lista[indiceProximo];
            double dist = haversine(atualLat, atualLon, prox->getLat(), prox->getLng());
            int tempoDeslocamento = static_cast<int>((dist * 2));

            minuto += tempoDeslocamento;
            hora += minuto / 60;
            minuto %= 60;

            std::cout << std::setfill('0') << std::setw(2) << hora << ":"
                      << std::setw(2) << minuto << " Imóvel " << prox->getId() << std::endl;

            minuto += 60;
            hora += minuto / 60;
            minuto %= 60;


            atualLat = prox->getLat();
            atualLon = prox->getLng();
            visitado[indiceProximo] = true;
        }

        std::cout << std::endl;
    }
}
