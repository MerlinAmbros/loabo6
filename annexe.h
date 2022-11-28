//---------------------------------------------------------
// Fichier        : annexe.h
// Auteur(s)      : Gerber Cedric Merlin & Vasques Dario
// But            : Fichier permettant de calculer un nombre aléatoire dans un intervalle
// Modifications  :
// Remarque(s)    : -
// Compilation :
//    - Version C++ : 20
//    - Compilateur : Mingw-w64 g++ 12.2.0 (Cedric)
//                    Apple clang version 14.0.0 (Dario)
//---------------------------------------------------------

#ifndef LABO_06_K_ANNEXE_H
#define LABO_06_K_ANNEXE_H

#include "random"       //utilisation des fonctions pour générer un nombre random

/**
 * @brief   Fonction pour récupérer un nombre aléatoire entre un minimum et maximum
 *
 * @param   const int min
 *          valeur minimum
 *
 *          const int max
 *          valeur maximum
 * @return  retourne le nombre aléatoire
 */
int numAleatoire(int min, int max);


#endif //LABO_06_K_ANNEXE_H
