#include "Duke.hpp"
using namespace coup;

    Duke::Duke(Game &g,const string &name) : Player(g,name) {this->setRole("Duke");}

    void Duke::tax() {
        if (getGame()->currTurn != this->playerID) {
            throw "not your turn";
        }
        if (coins() >= MUST_COUP) {
            throw "mus coup if you have 10 or more coins";
        }
        this->increment(3);
        setLastTurn("tax");
        getGame()->endTurn();
    }

    void Duke::block(Player &player) {
        if(player.getLastTurn() != "foreign aid"){
            throw ("last turn was not foreign aid");
        }
        player.decrement(2);
    }

