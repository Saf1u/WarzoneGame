//
// Created by Eve Gagnon on 2021-10-08.
//

#include <iostream>
#include <unordered_map>
#include "GameEngine.h"

using namespace std;

int main() {
    // welcome message
    cout << "Welcome to a game of Risk." << "\n" << "\n";


        GameEngine game;
    string startState = "start";

        //Game loop
        while (!game.getQuit()) {
            GameEngine::printMenu();
            string command;


            // All the possible transitions
            unordered_map<string, unordered_map<string, string>> transitions;
            transitions["start"]["loadMap"] = "mapLoaded";
            transitions["mapLoaded"]["loadMap"] = "mapLoaded";
            transitions["mapLoaded"]["validateMap"] = "mapValidated";
            transitions["mapValidated"]["addPlayer"] = "playerAdded";
            transitions["playerAdded"]["addPlayer"] = "playerAdded";
            transitions["playerAdded"]["assignCountries"] = "assignReinforcement";
            transitions["assignReinforcement"]["issueOrder"] = "issueOrder";
            transitions["issueOrder"]["issueOrder"] = "issueOrder";
            transitions["issueOrder"]["endIssueOrder"] = "execOrder";
            transitions["execOrder"]["execOrder"] = "execOrder";
            transitions["execOrder"]["endExecOrder"] = "assignReinforcement";
            transitions["execOrder"]["win"] = "win";
            transitions["win"]["end"] = "quit";
            transitions["win"]["play"] = "start";

            getline(cin, command);
            if (transitions[startState][command] == "") {
                cout << "The command entered is invalid. Please try again." << endl;
            } else {
                cout << "Current state: " << startState << endl;
                startState = transitions[startState][command];
                if (command == "loadMap")
                    Command::loadMap();
                else if (command == "validateMap")
                    Command::validateMap();
                else if (command == "addPlayer")
                    Command::addPlayer();
                else if (command == "assignCountries")
                    Command::assignCountries();
                else if (command == "issueOrder")
                    Command::issueOrder();
                else if (command == "endIssueOrders")
                    Command::endIssueOrders();
                else if (command == "execOrders")
                    Command::execOrder();
                else if (command == "endExecOrders")
                    Command::endExecOrders();
                else if (command == "win")
                    Command::win();
                else if (command == "play")
                    Command::play();
                else
                    Command::end();

                cout << "Transitioning to state " << startState << endl;

            }
        }

    system("PAUSE");

    return 0; // exits the program
}