//
// Created by cemeg on 22/11/2022.
//

#ifndef UNTITLED5_TONDEUSE_H
#define UNTITLED5_TONDEUSE_H

#include "vector"
#include  <cstdlib>
#include <iostream>

enum Surface {L, X, H, h};

using Data = Surface;
using Ligne = std::vector<Data>;
using Terrain = std::vector<Ligne>;

using Tondeuse = std::vector<int>;

const char SYMBOLE_LIMITE        = 'L';
const char SYMBOLE_OBSTACLE      = 'X';
const char SYMBOLE_HERBE_HAUTE   = '~';
const char SYMBOLE_HERBE_COUPE   = '.';

void affichage(Terrain &terrain);
bool deplacementPossible(const Terrain &terrain, size_t cordX, size_t cordY);
bool deplacement(const Terrain &terrain, size_t &cordX, size_t &cordY);
void tondre(Terrain terrain, Tondeuse &tondeuse, int nombreDeplacement, bool afficher);

#endif //UNTITLED5_TONDEUSE_H
