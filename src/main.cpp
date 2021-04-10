#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<int> times(const std::string&);
std::vector<int> setups(std::fstream&, std::string&);

// TODO Hacer la lectura de líneas más robusta, asegurarte de cuando parar de
// leer Pi y pasar a Sij y demás
int main() {
  std::fstream fichero;
  fichero.open("I40j_2m_S1_1.txt", std::ios::in);
  if (!fichero)
  {
    throw "No se ha podido cargar el programa";
  }
  std::string linea;
  while(getline(fichero, linea)) {
    // std::cout << "Linea: " << linea << '\n';
    // std::cin.get();
    switch(linea[0]) {
      case 'n': {
                  std::string n;
                  std::stringstream linea_stream(linea);
                  linea_stream >> n;
                  linea_stream >> n;
                  std::cout << "n: " << n << '\n';
                }
                break;
      case 'm': {
                  std::string m;
                  std::stringstream linea_stream(linea);
                  linea_stream >> m;
                  linea_stream >> m;
                  std::cout << "m: " << m << '\n';

                }
                break;
      case 'P': {
                  std::vector<int> tiempos = times(linea);
                  // std::cout << "Voy a mostrar los tiempos\n" << '\n';
                  // for (size_t i = 0; i < tiempos.size(); ++i) {
                  // std::cout << tiempos[i] << '\n';
                  // }
                }
                break;
      case 'S': {
                  std::vector<int> setup = setups(fichero, linea);
                  // std::cout << "Voy a mostrar los setups\n" << '\n';
                  // for (size_t i = 0; i < setup.size(); ++i) {
                  // std::cout << setup[i] << '\n';
                  // }
                }

      default:
                break;
    }
  }
  fichero.close();
  return 0;
}

std::vector<int> times(const std::string& linea) {
  std::vector<int> times;
  std::string numero;
  std::stringstream linea_stream(linea);
  while (linea_stream >> numero) {
    if(numero[numero.size() - 1] == ']') {
      break;
    }
    continue;
  }
  while(linea_stream >> numero) {
    times.emplace_back(std::stoi(numero));
  }
  return times;
}

std::vector<int> setups(std::fstream& fichero,std::string& linea) {
  std::vector<int> setups;
  std::string numero;
  std::stringstream linea_stream(linea);
  while (linea_stream >> numero) {
    if(numero[numero.size() - 1] == ']') {
      break;
    }
    continue;
  }
  while(linea_stream >> numero) {
    setups.emplace_back(std::stoi(numero));
  }
  while(getline(fichero ,linea)) {
    std::stringstream linea_stream(linea);
    while(linea_stream >> numero) {
      setups.emplace_back(std::stoi(numero));
    }

  }
  return setups;
}
