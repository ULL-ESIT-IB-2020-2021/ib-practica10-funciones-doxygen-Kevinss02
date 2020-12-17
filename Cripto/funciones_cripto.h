/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Kevin Salcedo
 * @date 16.diciembre.2020
 * @brief This file declares the "Help Text" constant and two functions
 *              
 */

#include <iostream>
using namespace std;

void Usage(int argc, char *argv[]);
string Lectura(string fichero_entrada);
string Encriptar(string texto, int k);
string Desencriptar(string texto, int k);
void Crear_archivo(string fichero_salida, string texto);
int Repeticiones(string texto);