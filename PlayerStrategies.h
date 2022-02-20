//
// Created by Safwan Ahmed on 2021-11-28.
//

#ifndef WARZONEGAME2_PLAYERSTRATEGIES_H
#define WARZONEGAME2_PLAYERSTRATEGIES_H

class Player;

class Territory;

#include <vector>
#include <string>

using std::vector;
using std::string;

class PlayerStrategies {
public:
    Player *p;

    PlayerStrategies(Player *);

    string name;

    ~PlayerStrategies();

    virtual void issueOrder() = 0;

    //pure virtual methods
    virtual vector<Territory *> toAttack() = 0;

    virtual vector<Territory *> toDefend() = 0;

    void SetStrategy(Player *);
};

class HumanPlayer : public PlayerStrategies {
public:
    Player *p;

    HumanPlayer(Player *);

    void issueOrder();

    vector<Territory *> toAttack();

    vector<Territory *> toDefend();

    bool Decision();
};

class CheaterPlayer : public PlayerStrategies {
public:
    Player *p;

    CheaterPlayer(Player *);

    void issueOrder();

    vector<Territory *> toAttack();

    vector<Territory *> toDefend();
};


class AggressivePlayer : public PlayerStrategies {
public:
    Player *p;

    AggressivePlayer &operator=(const Player &p);

    AggressivePlayer(Player *);

    void issueOrder();

    vector<Territory *> toAttack();

    vector<Territory *> toDefend();
};

class NeutralPlayer : public PlayerStrategies {
public:

    Player *p;

    NeutralPlayer(Player *);

    void issueOrder();

    vector<Territory *> toAttack();

    vector<Territory *> toDefend();
};

class BenevolentPlayer : public PlayerStrategies {
public:
    Player *p;

    void issueOrder();

    BenevolentPlayer(Player *);

    vector<Territory *> toAttack();

    vector<Territory *> toDefend();
};


#endif //WARZONEGAME2_PLAYERSTRATEGIES_H
