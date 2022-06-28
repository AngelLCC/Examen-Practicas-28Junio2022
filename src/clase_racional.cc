/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @file clase_racional.h
 * @author Caputo Coello Ángel Luis
 * @brief Implementación de la clase racional
 * @date 2022-06-28
 * 
 */

#include "clase_racional.h"

#include <cassert>
#include <fstream>

/** Esta función indica cómo debe introducirse por línea de comandos
 *  los parámetros necesarios para el correcto funcionamiento del programa.
 *  @param[in] argc Número de parámetros.
 *  @param[in] argv Vector que contiene los parámetros.
 */

 void Usage(int argc, char* argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << " -- Números Racionales." << std::endl;
    std::cout << "Modo de uso: " << argv[0] << "fichero_entrada fichero_salida\n";
    std::cout << "Pruebe " << argv[0] << " --help para más información." << std::endl;
    exit(EXIT_SUCCESS);
  }
  std::string parametro{argv[1]};
  if (parametro == "--help") {
    std::cout << argv[0] << " -- Números Racionales." << std::endl;
    std::cout << "Modo de uso: " << argv[0] << "fichero_entrada fichero_salida" << std::endl;;
    std::cout << "fichero_entrada: Fichero de texto conteniendo líneas con un par de números racionales:" 
              << " 'a/b c/d' separados por un espacio\n";
    std::cout << "fichero_salida: Fichero de texto que contendrá líneas con las operaciones realizadas" 
              << " 'a/b + c/d = n/m\n"; 
    exit(EXIT_SUCCESS);
  }
}

/** Esta función crea un archivo con las operaciones respectivas
 *  a cada pareja de racionales del archivo de entrada.
 * @param[in] kArchivo Nombre del archivo a copiar.
 */
void ArchivoConOperaciones(const std::string& kFicheroEntrada, const std::string& kFicheroSalida) {
  std::ifstream archivo_entrada{ kFicheroEntrada };
  if (!archivo_entrada) {
    std::cerr << "Oh, no se pudo abrir " << kFicheroEntrada << " para su lectura.\n";
    exit(EXIT_SUCCESS);
  }
  std::ofstream archivo_salida{ kFicheroSalida };
  std::string linea;
  for (int i = 1; std::getline(archivo_entrada, linea); ++i) {
    Racional primer_numero{1, 2}, 
             segundo_numero{1, 2};
    archivo_salida << primer_numero << " + " << segundo_numero << " = " << primer_numero + segundo_numero << std::endl;
    archivo_salida << primer_numero << " - " << segundo_numero << " = " << primer_numero - segundo_numero << std::endl;
    archivo_salida << primer_numero << " * " << segundo_numero << " = " << primer_numero * segundo_numero << std::endl;
    archivo_salida << primer_numero << " / " << segundo_numero << " = " << primer_numero / segundo_numero << std::endl;
    archivo_salida << primer_numero << " == " << segundo_numero << " ? " << (primer_numero == segundo_numero ? "si" : "no") << std::endl;
  }
}

/**
 * @brief Constructor personalizado clase racional
 * @param kNumerador numerador 
 * @param kDenominador denominador
 */
Racional::Racional(const int kNumerador, const int kDenominador) {
  assert(kDenominador != 0);
  numerador_ = kNumerador;
  denominador_ = kDenominador;
}



/// Sobrecarga del operador de flujo de salida
std::ostream& operator<<(std::ostream& salida, const Racional& numero) {
  salida << numero.get_numerador() << "/" << numero.get_denominador();
  return salida;
}

/// Sobrecarga del operador de inseción o flujo de entrada
std::istream& operator>>(std::istream& entrada, Racional& numero) {
  entrada >> numero.numerador_;
  int denominador;
  entrada >> denominador;
  assert(denominador != 0);
  numero.denominador_ = denominador;
  return entrada;
}

/// Sorecarga para la suma de dos racionales
Racional operator+(const Racional& primer_numero, const Racional& segundo_numero) {
  int numerador, denominador;
  if (primer_numero.get_denominador() != segundo_numero.get_denominador()) {
    denominador = primer_numero.get_denominador() * segundo_numero.get_denominador();
    numerador = (primer_numero.get_denominador() / denominador * primer_numero.get_numerador()) + 
                (segundo_numero.get_denominador() / denominador * segundo_numero.get_numerador());
  } else {
    denominador = primer_numero.get_denominador();
    numerador =  primer_numero.get_numerador() + segundo_numero.get_numerador();
  }
  
  Racional resultado{numerador, denominador};
  return resultado;
}

/// Sobrecarga para la resta de dos racionales 
Racional operator-(const Racional& primer_numero, const Racional& segundo_numero) {
  int numerador, denominador;
  if (primer_numero.get_denominador() != segundo_numero.get_denominador()) {
    denominador = primer_numero.get_denominador() * segundo_numero.get_denominador();
    numerador = (primer_numero.get_denominador() / denominador * primer_numero.get_numerador()) - 
                (segundo_numero.get_denominador() / denominador * segundo_numero.get_numerador());
  } else {
    denominador = primer_numero.get_denominador();
    numerador =  primer_numero.get_numerador() - segundo_numero.get_numerador();
  }
  
  Racional resultado{numerador, denominador};
  return resultado;
}

/// Sobrecarga multiplicación de racionales
Racional operator*(const Racional& primer_numero, const Racional& segundo_numero) {
  return Racional {primer_numero.get_numerador() * segundo_numero.get_numerador(),
                   primer_numero.get_denominador() * segundo_numero.get_denominador()};
}


Racional operator/(const Racional& primer_numero, const Racional& segundo_numero) {
 return Racional {primer_numero.get_numerador() * segundo_numero.get_denominador(),
                  primer_numero.get_denominador() * segundo_numero.get_numerador()};
}

/// Sobrecarga comparación de racionales
bool operator==(const Racional& primer_numero, const Racional& segundo_numero) {
  return (primer_numero.get_numerador() == segundo_numero.get_numerador()) &&
          (primer_numero.get_denominador() == segundo_numero.get_denominador());
}