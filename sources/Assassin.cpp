#include "Assassin.hpp"
using namespace coup;
    Assassin::Assassin(Game &g ,const string &name) : Player(g,name){this->setRole("Assassin");}
    
    void Assassin::coup(Player &p){
        if (this->getGame()->currTurn != this->playerID) {
            throw "not your turn";
        }
        if(coins()<ACOUP){
            throw ("need at least 3 coins");
        }
        if (!p.isAlive) {
        throw "player already died";
        }
        if(coins()>=ACOUP && coins()<CAN_COUP){
            this->setLastTurn("AssassinCoup");
            this->setTarget(p);
            this->decrement(ACOUP);
           Game::Remove_P(p);
            getGame()->isOver();
            this->getGame()->endTurn();
        }
        else if (coins() >= CAN_COUP) {
            Player::coup(p);
        }
    }
