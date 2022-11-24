//
// Created by cemeg on 22/11/2022.
//

#include "tondeuse.h"
#include  <cstdlib>
#include <iostream>

bool deplacementPossible(const Terrain &terrain, const Tondeuse &tondeuse){
    const int cordX = tondeuse.front();
    const int cordY = tondeuse.back();

    if(terrain[cordX][cordY] == Surface::X or terrain[cordX][cordY] == Surface::L){
        return false;
    }

    return true;
}

void affichage(Terrain terrain){
  for (vector<int>::iterator i = terrain[i][0]; i != v.end(); ++i){
        for(vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    }

}

void deplacement(int &cordX, int &cordY){
    unsigned int random = rand() % 4 + 1;
    switch (random) {
        case 1:
            cordX + 1;
            break;
        case 2:
            cordY + 1;
            break;
        case 3:
            cordX - 1;
            break;
        case 4:
            cordY - 1;
        default :
            std::cout << "error";
    }
}

void  tondre(Terrain terrain, Tondeuse tondeuse, unsigned int nombredeplacement, bool afficher){


    int cordX = tondeuse.front();
    int cordY = tondeuse.back();

    for(int i = 0; i<nombredeplacement; ++i) {
            do {
                //couper l'herbe manque
                deplacement(cordX, cordY);

                afficher(terrain);

            } while (deplacementPossible(terrain, tondeuse));
        }
}




