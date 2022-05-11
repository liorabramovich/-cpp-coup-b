#include "Game.hpp"
#include <string>
#include <iostream>
#pragma once
using namespace std;
const int ACOUP = 3;
const int CAN_COUP= 7;
const int MUST_COUP = 10; 
namespace coup{
    class Game;
    class Player{

        private:
        string name;
        Game *game;
        string lastTurn;
        string playerRole;
        Player *target;
        public:
        Player(Game &g , const string &name);

        
        int coin;
        bool isAlive;
        unsigned int playerID;

        void income();
        void foreign_aid();
        void coup(Player &p);

        void increment(int amount);
        void decrement(int amount);

        string role() const;
        void setRole(const string &role);
        int coins() const;
        Game* getGame();
        string Player_name();
        string getLastTurn();
        void setLastTurn(const string &LT);
        Player *getTarget();
        void setTarget(Player &p);

    };
}