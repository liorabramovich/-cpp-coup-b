#include "Player.hpp"
using namespace coup;

Player::Player(Game &game, const string &name)
{
    this->name = name;
    this->coin = 0;
    this->game = &game;
    this->playerID = game.totalPlayers;
    this->isAlive = true;
    this->game->Add_P(this);
    this->target = NULL;
}

void Player::income()
{
    if (getGame()->currTurn != playerID) {
        throw "not your turn";
    }
    if (getGame()->totalPlayers >= 2 and getGame()->status == -1) {
        getGame()->status = 0;
    }
    if (getGame()->status == -1) {
        throw "cant play alone";
    }
    if (coins() >= MUST_COUP) {
        throw "must coup if you have 10 or more coins";
    }
    this->increment(1);
    this->setLastTurn("income");
    getGame()->endTurn();
}

void Player::foreign_aid()
{
    if (getGame()->currTurn != playerID) {
        throw "not your turn";
    }
    if (getGame()->totalPlayers >= 2 and getGame()->status == -1) {
        getGame()->status = 0;
    }
    if (getGame()->status == -1) {
        throw "cant play alone";
    }
    if (coins() >= MUST_COUP) {
        throw "must coup if you have 10 or more coins";
    }
    this->increment(2);
    this->setLastTurn("foreign aid");
    getGame()->endTurn();
}
void Player::coup(Player &p)
{
    if (coins() < CAN_COUP) {
        throw "not enough coins to coup";
    }
    if (getGame()->currTurn != playerID) {
        throw "not your turn";
    }
    if (!p.isAlive) {
        throw "player already died";
    }
    decrement(CAN_COUP);
    setLastTurn("coup");
    setTarget(p);
    Game::Remove_P(p);
    getGame()->isOver();
    getGame()->endTurn();
}

Game *Player::getGame()
{
    return this->game;
}
int Player::coins() const
{
    return this->coin;
}
string Player::role() const
{
    return this->playerRole;
}

string Player::Player_name()
{
    return this->name;
}
std::string Player::getLastTurn(){return this->lastTurn;}

void Player::setLastTurn(const string &LT){this->lastTurn=LT;}

void Player::increment(int amount){this->coin+=amount;}

void Player::decrement(int amount){this->coin-=amount;}

void Player::setRole(const string &role) {
    this->playerRole = role;
}

Player *Player::getTarget() {
    return this->target;
}

void Player::setTarget(Player &p) {
    this->target = &p;
}
