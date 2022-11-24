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

//void affichage(Terrain terrain){
//  for (vector<int>::iterator i = terrain[i][0]; i != v.end(); ++i){
 //       for(vector<int>::iterator i = v.begin(); i != v.end(); ++i)
  //  }

//}

void deplacement(int &cordX, int &cordY, const Terrain &terrain){
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

    //if(deplacementPossible(terrain)){
    //   cordX = tempCordX;
    //   cordY = tempCordY;
    //}
}

void tondre(Terrain terrain, Tondeuse &tondeuse, unsigned int nombreDeplacement, bool afficher){
    int  cordX = tondeuse.front(),
         cordY = tondeuse.back(),
         ancienneCordX,
         ancienneCordY;

    for(int i = 0; i < nombreDeplacement; ++i) {
       //deplacement(cordX, cordY);
       if(deplacementPossible(terrain, tondeuse)){
          terrain[cordX][cordY] = Surface::h;
       }

       ancienneCordX = cordX;
       ancienneCordY = cordY;
    }
}




