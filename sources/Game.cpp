#include "Game.hpp"
#include "vector"
#include <string>
#include "Player.hpp"
using namespace coup;

Game::Game()
{
    this->currTurn = 0;
    this->gameWinner = NULL;
}

vector<string> Game::players()
{
    vector<string> OnlineUsers;
    for (unsigned int i = 0; i < playersList.size(); i++)
    {   
        if (playersList[i]->isAlive) {
            OnlineUsers.push_back(playersList[i]->Player_name());
        }
    }
    return OnlineUsers;
}



void Game::Add_P(Player *p)
{
    if (totalPlayers == MAXPLAYERS) {
        throw std::out_of_range("players overflow");
    }
    if (status == 0) {
        throw std::logic_error("game in progress");
    }
    playersList.push_back(p);
    this->totalPlayers++;
}

void Game::Remove_P(Player &p)
{
    p.isAlive = false;
}

void Game::returnToGame(Player &p) {
    p.isAlive = true;
}

string Game::turn()
{
    return playersList[currTurn]->Player_name();
}

string Game::winner()
{
    if (status == -1 or status == 0) {
        throw std::logic_error("game is still in progress");
    }
    return this->gameWinner->Player_name();
}

void Game::isOver() {
    int playersAlive = 0;
    for (unsigned int i = 0; i < playersList.size(); i++) {
        if (playersList[i]->isAlive) {
            playersAlive++;
        }
    }
    if (playersAlive == 1) {
        for (unsigned int i = 0; i < playersList.size(); i++) {
            if (playersList[i]->isAlive) {
                gameWinner = playersList[i];
                status = 1;
                break;
            }
        }
    }
}

void Game::endTurn() {
    // cout << "inside turn func" << endl;
    currTurn++;
    if (currTurn == playersList.size()) {
        currTurn = 0;
    }
    while (!playersList[currTurn]->isAlive) {

        currTurn++;
        if (currTurn == playersList.size()) {
            currTurn = 0;
        }
    }
    // cout << "exiting turn func" << endl;
}