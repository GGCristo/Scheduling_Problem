// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "../include/greedy_TCT.hpp"

Solution GreedyTCT::run(int m) {
  assert(!Data::getInstance().isTaskTaken(0));
  std::vector<Machine> machines = preprocessing(m);
  if (Data::getInstance().getN() < m) {
    return Solution(machines);
  }
  for (int i = 0; i < Data::getInstance().getN() - m; ++i) {
    std::vector<Task> aux;
    aux.reserve(machines.size());
    for (size_t j = 0; j < machines.size(); ++j) {
      aux.emplace_back(getTask(machines[j].getIdLastTask()));
    }
    unsigned long auxMinSum = machines[0].peekTCT(aux[0]);
    int minPosition = 0;
    for (size_t j = 1; j < aux.size(); ++j) {
      if (machines[j].peekTCT(aux[j]) < auxMinSum) {
        minPosition = j;
        auxMinSum = machines[j].peekTCT(aux[j]);
      }
    }
    machines[minPosition].add(aux[minPosition]);
  }
  return Solution(machines);
}
