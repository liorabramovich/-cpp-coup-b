#include "Ambassador.hpp"
using namespace coup;
    Ambassador::Ambassador(Game &g ,const string &name) : Player(g,name){this->setRole("Ambassador");}

    void Ambassador::block(Player &player){
        if(player.getLastTurn() != "steal") {
            throw std::logic_error("last action was not steal");
        }
        Player *stealTarget = player.getTarget();
        if (stealTarget != NULL) {
            stealTarget->increment(2);
            player.decrement(2);
        }
    }
    void Ambassador::transfer(Player &player1 , Player &player2){
        if (player1.coins() == 0) {
            throw std::logic_error("cant transfer from player with 0 coins");
        }
        if (this->getGame()->currTurn != this->playerID) {
            throw std::logic_error("not your turn");
        }
        if (coins() >= MUST_COUP) {
            throw std::logic_error("player with 10 or more coins must coup on his turn");
        }
        player1.decrement(1);
        player2.increment(1);
        this->setLastTurn("transfer");
        this->getGame()->endTurn();
    }
