/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Kevin Salcedo
 * @date 16.diciembre.2020
 * @brief Programa que encripta y/o desencripta ficheros de text usando dos métodos: cifrado xor 
 *        y cifrado de César.
 *              
 */

#include <iostream>
#include <cstdlib>    /// exit

#include "funciones_cripto.h"    
#include <fstream>
using namespace std;

/** Main function
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
int main (int argc, char* argv[]) {
  Usage(argc, argv);
  string limit = argv[5];

  string fichero_entrada = argv[1];
  string fichero_salida = argv[2];
  string texto = Lectura(fichero_entrada);
  cout << texto << endl << endl;
  int k = atoi(argv[4]);
  if(atoi(argv[3]) == 1){
    string texto_encriptado = Encriptar(texto, k);
    cout << "El mensaje encriptado es: " << endl << texto_encriptado << endl;
  }
  if(atoi(argv[3]) == 2){
    string texto_desencriptar = Desencriptar(texto, k);
    cout << "El mensaje desencriptado es: " << endl << texto_desencriptar << endl;
    Crear_archivo(fichero_salida, texto_desencriptar);
  }
  return 0;
}
