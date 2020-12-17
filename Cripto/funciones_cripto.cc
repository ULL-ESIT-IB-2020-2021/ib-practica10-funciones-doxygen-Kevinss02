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
#include <cstdlib>    // exit
#include <fstream>
#include <cstring> 
#include "funciones_cripto.h"    
#include <algorithm>
using namespace std;

/** Muestra el modo de uso correcto del programa
 *  En caso de que el uso no sea el correcto, muestra el mensaje y finaliza
 *  la ejecución del programa.
 *  El programa precisa de 5 parámetros.
 *
 *  @param[in] argc Number of command line parameters
 *  @param[in] argv Vector containing (char*) the parameters
 */
void Usage(int argc, char *argv[]) {
  string parameter;
  if(argv[1] != nullptr){
  parameter = argv[1];
  }
  if (parameter == "--help") {
    cout
    << argv[0] << " -- Cifrado de ficheros" << endl
    << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida método password operación" << endl
    << endl
    << "fichero_entrada: Fichero a codificar" << endl
    << "fichero_salida:  Fichero codificado" << endl
    << "método:          Indica el método de encriptado" << endl
    << "                    1: Cifrado xor" << endl
    << "                    2: Cifrado de César" << endl
    << "password:        Palabra secreta en el caso de método 1, Valor de K en el método 2" << endl
    << "operación:       Operación a realizar el fichero" << endl
    << "                    +: encriptar el fichero" << endl
    << "                    -: desencriptar el fichero" << endl;
    exit(EXIT_SUCCESS);
  }

  if (argc != 6) {
    cout 
    << argv[0] << " -- Cifrado de ficheros" << endl
    << "Modo de uso: " << argv[0] << " fichero_entrada fichero_salida método password operación" << endl
    << "Pruebe " << argv[0] << " --help para más información" << endl;
    exit(EXIT_SUCCESS);
  }   
}

string Lectura(string fichero_entrada){
  
  ifstream archivo;
  string texto;

  archivo.open(fichero_entrada, ios::in); //Abrimos el archivo en modo lectura

  if(archivo.fail()){
    cout << "No se pudo abrir el archivo" << endl;
    exit(1);
  }

  while(!archivo.eof()){ //Mientras no sea el final del archivo
    getline(archivo, texto);
    
    
  }

  archivo.close(); //Cerramos el archivo

  return texto;
}

string Encriptar(string texto, int k){

  char char_array[texto.length()];
  strcpy(char_array, texto.c_str());
  char char_array_encriptado[texto.length()];
 
 char alf[]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};

 string mensaje_encriptado;
 

for(int i = 0; i < texto.size(); i++){
  for(int j = 0; j < 52; j++){
    
    if(char_array[i] == ' '){
      char_array_encriptado[i] = ' ';
    }
    if(char_array[i] == alf[j]){
       
      if((j+k) >= 52){
        
        int pos = -52 + j + k ;
        char_array_encriptado[i] = alf[pos];
        
      }else{
      char_array_encriptado[i] = alf[j+k];
    }
    }
  }
  
}
 for (int i = 0; i < texto.size(); i++){
   mensaje_encriptado = mensaje_encriptado + char_array_encriptado[i];
   
   
 }

 return mensaje_encriptado;
}

string Desencriptar(string texto, int k){
  string mensaje_desencriptado;
char char_array[texto.length()];
strcpy(char_array, texto.c_str());
char char_array_desencriptado[texto.length()];

char alf[]={"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
for(int i = 0; i < texto.size(); i++){
  for(int j = 0; j < 52; j++){
    
    if(char_array[i] == ' '){
      char_array_desencriptado[i] = ' ';
    }
    if(char_array[i] == alf[j]){
       
      if((j-k) <= 0){
        
        int pos = -52 + j + k ;
        char_array_desencriptado[i] = alf[pos];
        
      }else{
      char_array_desencriptado[i] = alf[j-k];
    }
    }
  }
  
}
 for (int i = 0; i < texto.size(); i++){
   
   mensaje_desencriptado = mensaje_desencriptado + char_array_desencriptado[i];
   
 }
return mensaje_desencriptado;
}

void Crear_archivo(string fichero_salida, string texto){
  ofstream archivo;
  archivo.open(fichero_salida, ios::out);

  if(archivo.fail()){
    cout<<"No se pudo crear el archivo"<< endl;
    exit(1);
  } 

  archivo<<texto;
  archivo.close();

}
 