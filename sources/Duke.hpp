
#include "Player.hpp"
using namespace std;
namespace coup{
    class Duke : public Player
    {
        public:
        Duke(Game &g ,const string &name);
        void tax();
        static void block(Player &player);
        
    };
}