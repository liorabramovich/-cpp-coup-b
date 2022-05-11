#include "Captain.hpp"
using namespace coup;
    Captain::Captain(Game &g  ,const string &name) : Player(g,name){this->setRole("Captain");}

    void Captain::steal(Player &player) {
        if (getGame()->currTurn != this->playerID) {
            throw "not your turn";
        }
        if (coins() >= MUST_COUP) {
            throw "must coup at 10 or more coins";
        }
        if (player.coins() == 0) {
            return;
        }
        if (player.coins() == 1) {
            this->increment(1);
            player.decrement(1);
        }
        if (player.coins() >= 2) {
            this->increment(2);
            player.decrement(2);
        }
        this->setTarget(player);;
        this->setLastTurn("steal");
        this->getGame()->endTurn();
    }

    void Captain::block(Player &player) {
        if (player.getLastTurn() != "steal") {
            throw "last turn was not steal";
        }
        Player *stealTarget = player.getTarget();
        if (stealTarget != NULL) {
            stealTarget->increment(2);
            player.decrement(2);
        }
    }
