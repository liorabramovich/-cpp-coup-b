// #include "Player.hpp"
// #include "Duke.hpp"
// #include "Assassin.hpp"
// #include "Ambassador.hpp"
// #include "Captain.hpp"
// #include "Contessa.hpp"
// #include "Game.hpp"
// using namespace coup;

// #include <iostream>
// #include <stdexcept>
// #include <vector>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     Game g1;
//     Duke duke{g1, "shalom"};
//     Assassin assassin{g1, "shlomi"};
//     Captain captain{g1, "shlomo"};
//     for (int i = 0; i < 7; i++) {
//         duke.income();
//         assassin.income();
//         captain.income();
//     }
//     cout << duke.coins() << endl;
//     cout << g1.turn() << endl;
//     cout << duke.isAlive << endl;

//     duke.coup(captain);
//     cout << duke.coins() << endl;
//     cout << g1.turn() << endl;
//     cout << captain.isAlive << endl;

//     cout << g1.playersList.size() << endl;
// }
