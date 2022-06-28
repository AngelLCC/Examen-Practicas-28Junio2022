/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Ángel Luis Caputo Coello
 * @brief Este programa lee un fichero con números racionales 
 * y vuelca en otro todas las operaciones posibles con cada 
 * uno de los pares de números del fichero de entrada.
 * @date 2022-06-28
 */

#include "clase_racional.h"


int main(int argc, char* argv[]) {
  Usage(argc, argv);
  const std::string kFicheroEntrada = argv[1]; 
  ArchivoConOperaciones(kFicheroEntrada);
  return 0;
}

