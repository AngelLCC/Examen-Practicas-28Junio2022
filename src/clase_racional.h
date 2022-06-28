/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file clase_racional.h
 * @author Caputo Coello Ángel Luis
 * @brief Declaraciones de la clase racional y de algunas funciones para el programa main
 * @date 2022-06-28
 * 
 */

 
#ifndef CLASE_RACIONAL_H
#define CLASE_RACIONAL_H

#include <iostream>

void Usage(int argc, char* argv[]);
void ArchivoConOperaciones(const std::string& kFicheroEntrada, const std::string& kFicheroSalida);

class Racional {
 public:
  Racional() : numerador_{0}, denominador_{1} {}  /// Constructor por defecto 
  Racional(const int kNumerador, const int kDenominador);
  
  /// Getters
  int get_numerador() const { return numerador_; } 
  int get_denominador() const { return denominador_; } 

  friend std::istream& operator>>(std::istream& entrada, Racional& numero);
 private:
  int numerador_, denominador_;
};

std::ostream& operator<<(std::ostream& salida, const Racional& numero);
Racional operator+(const Racional& primer_numero, const Racional& segundo_numero);
Racional operator-(const Racional& primer_numero, const Racional& segundo_numero);
Racional operator*(const Racional& primer_numero, const Racional& segundo_numero);
Racional operator/(const Racional& primer_numero, const Racional& segundo_numero);
bool operator==(const Racional& primer_numero, const Racional& segundo_numero);

 #endif