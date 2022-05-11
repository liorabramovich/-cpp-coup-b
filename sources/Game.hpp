#pragma once
#include "vector"
#include <string>
const int MAXPLAYERS = 6;
namespace coup{
    class Player;

    class Game{

        private:
        Player *gameWinner;

        public:
        int status = -1; // -1 = game did not start yet / 0 = game started / 1 = game over
        unsigned int totalPlayers = 0;
        unsigned int currTurn;
        Game();
        std::vector<std::string> players(); 
        std::vector<Player*> playersList;
        std::string turn();
        std::string winner();
        void Add_P(Player *p);
        static void Remove_P(Player &p);
        static void returnToGame(Player &p);
        void isOver();
        void endTurn();
    };

}