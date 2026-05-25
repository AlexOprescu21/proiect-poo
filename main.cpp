#include "game.h"

int main(){
srand(time(NULL));

game* g = game::getInstance();
g->meniu();

}