//
// Created by cemeg on 22/11/2022.
//

#include "tondeuse.h"
#include  <cstdlib>
#include <iostream>

bool deplacementPossible(const Terrain &terrain, const int cordX, const int cordY){
    if(terrain[cordX][cordY] == Surface::X or terrain[cordX][cordY] == Surface::L){
        return false;
    }

    return true;
}

void affichage(Terrain terrain){
   for(size_t i = 0; i < terrain.size(); ++i){
      for(size_t j = 0; j < terrain.size(); ++j){
         switch(terrain[i][j]){
            case Surface::L:
               std::cout << " " << "L";
               break;
            case Surface::H:
               std::cout << " " << "~";
               break;
            case Surface::X:
               std::cout << " " << "X";
               break;
            case Surface::h:
               std::cout << " " << ".";
               break;
         }
      }
      std::cout << std::endl;
   }
}

bool deplacement(const Terrain &terrain, int &cordX, int &cordY){
    int  tempCordX = cordX,
         tempCordY = cordY;

    unsigned int random = 1 + (rand() % 4);
    switch (random) {
        case 1:
            tempCordX += 1;
            break;
        case 2:
            tempCordY += 1;
            break;
        case 3:
            tempCordX -= 1;
            break;
        case 4:
            tempCordY -= 1;
            break;
        default :
            std::cout << "error";
    }

    if(deplacementPossible(terrain, tempCordX, tempCordY)){
       cordX = tempCordX;
       cordY = tempCordY;
       return true;
    }

   return false;
}

void tondre(Terrain terrain, Tondeuse &tondeuse, unsigned int nombreDeplacement, bool afficher){
    int  cordX = tondeuse.front(),
         cordY = tondeuse.back(),
         ancienneCordX,
         ancienneCordY;

    for(int i = 0; i < nombreDeplacement; ++i) {
       affichage(terrain);
       if(deplacement(terrain, cordX, cordY)){
          terrain[cordX][cordY] = Surface::h;
       }
       system("clear");
    }
}




