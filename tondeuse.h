//---------------------------------------------------------
// Fichier        : tondeuse.h
// Auteur(s)      : Gerber Cedric Merlin & Vasques Dario
// But            : Fichier permettant de déplacer la tondeuse
//                  et de remplacer l'herbe haute par de l'herbe coupée.
// Modifications  :
// Remarque(s)    : -
// Compilation :
//    - Version C++ : 20
//    - Compilateur : Mingw-w64 g++ 12.2.0 (Cedric)
//                    Apple clang version 14.0.0 (Dario)
//---------------------------------------------------------

#ifndef LABO_06_K_TONDEUSE_H
#define LABO_06_K_TONDEUSE_H

#include "vector"       //utilisation des vecteurs
#include <iostream>     //cout
#include "random"       //utilisation des fonctions pour générer un nombre random

// Déclaration de l'enum contenant les éléments du terrain
enum Surface {L, X, H, h};

// Types de données
using Data     = Surface;
using Ligne    = std::vector<Data>;
using Terrain  = std::vector<Ligne>;

using Tondeuse = std::vector<size_t>;

// Déclaration et initialisation des variables qui seront affichées
const char SYMBOLE_LIMITE        = 'L';
const char SYMBOLE_OBSTACLE      = 'X';
const char SYMBOLE_HERBE_HAUTE   = '~';
const char SYMBOLE_HERBE_COUPE   = '.';
const char ESPACE                = ' ';

/**
 * @brief   Fonction pour afficher le terrain
 *
 * @param   const vector<vector<Surface>>&
 *          vecteur contenant les éléments du terrain
 * @return  retourne rien
 */
void affichage(const Terrain &terrain);

/**
 * @brief   Fonction pour récupérer un nombre aléatoire entre un minimum et maximum
 *
 * @param   const int min
 *          valeur minimum
 *
 *          const int max
 *          valeur maximum
 * @return  retourne rien
 */
int numAleatoire(int min, int max);

/**
 * @brief   Fonction pour contrôler que le déplacement de la tondeuse soit possible
 *
 * @param   const vector<vector<Surface>>&
 *          vecteur contenant les éléments du terrain
 *
 *          const size_t cordX
 *          cordonnée du point en X à contrôler
 *
 *          const size_t cordY
 *          cordonnée du point en Y à contrôler
 * @return  retourne si l'opération est possible
 */
bool deplacementPossible(const Terrain &terrain, size_t cordX, size_t cordY);


/**
 * @brief   Fonction pour calculer les nouvelles cordonnées si le déplacement est possible
 *
 * @param   const vector<vector<Surface>>&
 *          vecteur contenant les éléments du terrain
 *
 *          size_t cordX
 *          cordonnée du point en X
 *
 *          size_t cordY
 *          cordonnée du point en Y
 * @return  retourne si le déplacement s'est correctement effectué
 */
bool deplacement(const Terrain &terrain, size_t &cordX, size_t &cordY);


/**
 * @brief   Fonction pour tondre l'herbe haute
 *
 * @param   vector<vector<Surface>>&
 *          vecteur contenant les éléments du terrain
 *
 *          vector<int>&
 *          vecteur contenant les cordonnées de départ de la tondeuse
 *
 *          int nombreDeplacement
 *          nombre de déplacement de la tondeuse
 *
 *          bool afficher
 *          demande d'affichage du terrain
 * @return  retourne rien
 */
void tondre(Terrain terrain, Tondeuse &tondeuse, int nombreDeplacement, bool afficher);

#endif //LABO_06_K_TONDEUSE_H
