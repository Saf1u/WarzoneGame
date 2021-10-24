//
// Created by Eve Gagnon on 2021-09-26.


#include <iostream>

// Because this is the game engine, we need to import the various classes
#include "GameEngine.h"

// Implementation of class GameEngine
//Constructor and Destructor
GameEngine::GameEngine() {
    quit = false;
}

GameEngine::~GameEngine() {
    quit = true;
}
// Accessors
const bool& GameEngine::getQuit() const {
    return this->quit;
}
string GameEngine::getState() {
    return state;
}
// Modifiers
void GameEngine::setQuit() {
    quit = true;
}
void GameEngine::setState(string currentState) {
    this->state = currentState;
}
//Functions
void GameEngine::printMenu() { //prints the menu
    cout << "--- MAIN MENU ---" << "\n" << "\n"
         << "What do you want to do? " << "\n"
         << " 1. start" << "\n"
         << " 2. loadMap" << "\n"
         << " 3. validateMap" << "\n"
         << " 4. addPlayer" << "\n"
         << " 5. assignCountries" << "\n"
         << " 6. issueOrder" << "\n"
         << " 7. endIssueOrder" << "\n"
         << " 8. execOrder" << "\n"
         << " 9. endExecOrder" << "\n"
         << " 10. win" << "\n"
         << " 11. end" << "\n"
         << " 12. play" << endl;
    // Play and End are not part of the main menu. If the user is in the State "Win", then they'll have
    // the option of picking either
}

// This is the Commands section.

Command::Command() = default;
Command::~Command()= default;

void Command::start() { // starts the game -> brings the player to state = start
    cout << "Command: start()" << endl;
}

void Command::loadMap() { // brings player to state = map loaded

    cout << "Command: loadMap()" << endl;
}

void Command::validateMap() { // brings player to state = map validated
    cout << "Command: validateMap()" << endl;
}

void Command::addPlayer() { // adds a new player w/ function new Player

    cout << "Command: addPlayer()" << endl;
}

void Command::assignCountries() { //

    cout << "Command: assignCountries()" << endl;
}

void Command::issueOrder() {

    cout << "Command: issueOrders()" << endl;
}

void Command::endIssueOrders() {

    cout << "Command: endIssueOrders" << endl;
}

void Command::execOrder() {

    cout << "Command: executeOrders" << endl;
}

void Command::endExecOrders() {

    cout << "Command: endExecOrders" << endl;
}

void Command::win() {
    cout << "Command: win" << endl;
}

void Command::play() {

    cout << "Command: play" << endl;
}

void Command::end() {
    cout << "Command: end" << endl;
}
