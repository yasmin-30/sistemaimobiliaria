#ifndef AGENDA_H
#define AGENDA_H

#include "gerenciamento.h"

double haversine(double lat1, double lon1, double lat2, double lon2);
void gerarAgenda(const Gerenciamento& g);

#endif
