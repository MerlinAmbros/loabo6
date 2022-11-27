//---------------------------------------------------------
// Fichier        : tondeuse.cpp
// Auteur(s)      : Gerber Cedric Merlin & Vasques Dario
// But            : Fichier contenant l'algorithme de déplacement
//                  de la tondeuse et de découpe de l'herbe haute.
// Modifications  :
// Remarque(s)    : -
// Compilation :
//    - Version C++ : 20
//    - Compilateur : Mingw-w64 g++ 12.2.0 (Cedric)
//                    Apple clang version 14.0.0 (Dario)
//---------------------------------------------------------

#include "tondeuse.h"

bool deplacementPossible(const Terrain &terrain, const size_t cordX, const size_t cordY){
   // Si l'élément à la position à contrôler est un obstacle ou une limite, le déplacement est impossible
    if(terrain[cordX][cordY] == Surface::X or terrain[cordX][cordY] == Surface::L){
        return false;
    }

    return true;
}

void affichage(Terrain &terrain){
   // Boucle for pour itérer sur le terrain
   for(size_t i = 0; i < terrain.size(); ++i){
      //boucle for pour itérer dans chaque ligne du terrain
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

int numAleatoire(const int min, const int max){
   // Algorithme de génération d'un nombre aléatoire dans une intervalle donnée
   // Source : https://cplusplus.com/reference/random/default_random_engine
   std::random_device                  rand_dev;
   std::default_random_engine          generator(rand_dev());
   std::uniform_int_distribution<int>  distr(min, max);

   int num = distr(generator);
   return num;
}

bool deplacement(const Terrain &terrain, size_t &cordX, size_t &cordY){
    // Définition et initialisation de cordonées temporaires
    size_t  tempCordX = cordX,
            tempCordY = cordY;

    // Définition et initialisation de l'intervale du nombre aléatoire
    const int MIN    = 1;
    const int MAX    = 4;

    int random = numAleatoire(MIN,MAX);

    // Par rapport au nombre aléatoire il y aura une incrémentation ou décrémentation de x ou y
    // qui sont en réalités des cordonnées temporaires
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

    // Test si le deplacement à la position des cordonnées temporaires est possible
    if(deplacementPossible(terrain, tempCordX, tempCordY)){
       cordX = tempCordX;
       cordY = tempCordY;
       return true;
    }

   return false;
}

void tondre(Terrain terrain, Tondeuse &tondeuse, int nombreDeplacement, bool afficher){
    // Définition et initialisation des cordonnées de départ de la tondeuse
    size_t  cordX = (size_t)tondeuse.front(),
            cordY = (size_t)tondeuse.back();

    // Boucle for pour itérer le nombre de déplacement
    for(int i = 0; i < nombreDeplacement; ++i) {
       system("clear");
       if(afficher){
          affichage(terrain);
       }

       // Test si le déplacement s'est correctement effectué
       if(deplacement(terrain, cordX, cordY)){
          terrain[cordX][cordY] = Surface::h;
       }
    }
}




