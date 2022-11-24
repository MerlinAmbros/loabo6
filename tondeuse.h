//
// Created by cemeg on 22/11/2022.
//

#ifndef UNTITLED5_TONDEUSE_H
#define UNTITLED5_TONDEUSE_H

#include "vector"

enum Surface {L, X, H};

using Data = Surface;
using Ligne = std::vector<Data>;
using Terrain = std::vector<Ligne>;

using Tondeuse = std::vector<int>;

void tondre(Terrain terrain, Tondeuse tondeuse, unsigned int nombredeplacement, bool afficher);

#endif //UNTITLED5_TONDEUSE_H
