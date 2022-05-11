#include "Contessa.hpp"
using namespace coup;

    Contessa::Contessa(Game &g,const string &name):Player(g,name) {this->setRole("Contessa");}

    void Contessa::block(Player &p) {
        if (p.getLastTurn() != "AssassinCoup") {
            throw "last turn was not coup";
        }
        Game::returnToGame(*p.getTarget());
    }