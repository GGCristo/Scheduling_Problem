// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/parallelInterface.hpp"

#include "../include/datos.hpp"

Tarea ParallelInterface::getTask(int previousTask) {
  // std::cout << "El anterior es: " << previousTask << '\n';
  int auxMinSum;
  int minPosition;
  Tarea tarea;
  Datos* datos = &Datos::getInstance();
  size_t i = 0;
  for (; i < datos->getTimes().size(); ++i) {
    if (!datos->getTimes()[i].second) {
      auxMinSum = datos->getTimes()[i].first +
        datos->getSetups()[previousTask + 1][i + 1];
      minPosition = i;
      break;
    }
  }
  for(++i; i < datos->getTimes().size(); ++i) {
    if (!datos->getTimes()[i].second &&
        datos->getTimes()[i].first + datos->getSetups()[previousTask + 1][i + 1] <
        auxMinSum) {
      auxMinSum = datos->getTimes()[i].first +
        datos->getSetups()[previousTask + 1][i + 1];
      minPosition = i;
    }
  }
  // std::cout << "La tarea[i]: " << minPosition << " con valor: " << auxMinSum << '\n';
  return Tarea(minPosition, auxMinSum);
}
