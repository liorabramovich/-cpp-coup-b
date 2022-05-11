#include "Player.hpp"
using namespace std;
namespace coup{
    class Captain : public Player{
        public:
        Captain(Game &g ,const string &name);
        void steal(Player &player);
        static void block(Player &player);  
    };
}