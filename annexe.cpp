//---------------------------------------------------------
// Fichier        : annexe.cpp
// Auteur(s)      : Gerber Cedric Merlin & Vasques Dario
// But            : Fichier contenant l'agorithme de calcul d'un nombre aléatoire
// Modifications  :
// Remarque(s)    : -
// Compilation :
//    - Version C++ : 20
//    - Compilateur : Mingw-w64 g++ 12.2.0 (Cedric)
//                    Apple clang version 14.0.0 (Dario)
//---------------------------------------------------------

#include "annexe.h"

int numAleatoire(const int min, const int max){
   // Algorithme de génération d'un nombre aléatoire dans un intervalle donné en paramètre
   // Source : https://cplusplus.com/reference/random/default_random_engine
   std::random_device                  rand_dev;
   std::default_random_engine          generator(rand_dev());
   std::uniform_int_distribution<int>  distr(min, max);

   int num = distr(generator);
   return num;
}