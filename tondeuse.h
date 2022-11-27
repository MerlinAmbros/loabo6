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
#ifndef UNTITLED5_TONDEUSE_H
#define UNTITLED5_TONDEUSE_H

#include "vector"
#include  <cstdlib>
#include <iostream>
#include "random"

// Déclaration de l'enum des éléments du terrain
enum Surface {L, X, H, h};

// Définition d'using afin de simplifier le code
using Data = Surface;
using Ligne = std::vector<Data>;
using Terrain = std::vector<Ligne>;

using Tondeuse = std::vector<int>;

// Déclaration et initialisation des variables qui seront affichées
const char SYMBOLE_LIMITE        = 'L';
const char SYMBOLE_OBSTACLE      = 'X';
const char SYMBOLE_HERBE_HAUTE   = '~';
const char SYMBOLE_HERBE_COUPE   = '.';


/**
 * @brief   Fonction pour afficher le terrain
 *
 * @param   vector<vector<Surface>>&
 *          vecteur contenant les éléments du terrain
 * @return  retourne rien
 */
void affichage(Terrain &terrain);

/**
 * @brief   Fonction pour récupérer un nombre aléatoire entre un minimum et maximum
 *
 * @param   int min
 *          valeur minimum
 *
 *          int max
 *          valeur maximum
 * @return  retourne rien
 */
int numAleatoire(int min, int max);

/**
 * @brief   Fonction pour contrôler que le déplacement de la tondeuse soit possible
 *
 * @param   vector<vector<Surface>>&
 *          vecteur contenant les éléments du terrain
 *
 *          size_t cordX
 *          cordonnée du point en X à contrôler
 *
 *          size_t cordY
 *          cordonnée du point en Y à contrôler
 * @return  retourne si l'opération est possible
 */
bool deplacementPossible(const Terrain &terrain, size_t cordX, size_t cordY);


/**
 * @brief   Fonction pour calculer les nouvelles cordonnées si le déplacement est possible
 *
 * @param   vector<vector<Surface>>&
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
 *          demande d'affichage des opérations
 * @return  retourne rien
 */
void tondre(Terrain terrain, Tondeuse &tondeuse, int nombreDeplacement, bool afficher);

#endif //UNTITLED5_TONDEUSE_H
