//
// Created by cemeg on 22/11/2022.
//

#include "tondeuse.h"

bool deplacementPossible(const Terrain &terrain, const size_t cordX, const size_t cordY){
    if(terrain[cordX][cordY] == Surface::X or terrain[cordX][cordY] == Surface::L){
        return false;
    }

    return true;
}

void affichage(Terrain &terrain){
   for(size_t i = 0; i < terrain.size(); ++i){
      for(size_t j = 0; j < terrain[i].size(); ++j){
         switch(terrain[i][j]){
            case Surface::L:
               std::cout << " " << SYMBOLE_LIMITE;
               break;
            case Surface::H:
               std::cout << " " << SYMBOLE_HERBE_HAUTE;
               break;
            case Surface::X:
               std::cout << " " << SYMBOLE_OBSTACLE;
               break;
            case Surface::h:
               std::cout << " " << SYMBOLE_HERBE_COUPE;
               break;
         }
      }
      std::cout << std::endl;
   }
}

bool deplacement(const Terrain &terrain, size_t &cordX, size_t &cordY){
    size_t  tempCordX = cordX,
            tempCordY = cordY;

    int random = 1 + (rand() % 4);
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

void tondre(Terrain terrain, Tondeuse &tondeuse, int nombreDeplacement, bool afficher){
    size_t  cordX = (size_t)tondeuse.front(),
            cordY = (size_t)tondeuse.back();

    for(int i = 0; i < nombreDeplacement; ++i) {
       system("clear");
       affichage(terrain);
       if(deplacement(terrain, cordX, cordY)){
          terrain[cordX][cordY] = Surface::h;
       }
    }
}




