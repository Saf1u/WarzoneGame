//
// Created by Eve Gagnon on 2021-09-26.


#include <iostream>

// Because this is the game engine, we need to import the various classes
#include "GameEngine.h"
#include "CommandProcessor.h"
#include "FileCommandProcessorAdapter.h"
#include "FileCommandProcessor.h"


// Implementation of class GameEngine
//Constructor and Destructor
GameEngine::GameEngine() {
    vector<Card*> cards;
    cards.push_back(new Bomb);
    cards.push_back(new Blockade);
    cards.push_back(new Airlift);
    cards.push_back(new Diplomacy);
    cards.push_back(new Bomb);
    cards.push_back(new Blockade);
    cards.push_back(new Airlift);
    cards.push_back(new Diplomacy);
    cards.push_back(new Bomb);
    cards.push_back(new Blockade);
    cards.push_back(new Airlift);
    cards.push_back(new Diplomacy);
    cards.push_back(new Bomb);
    cards.push_back(new Blockade);
    cards.push_back(new Airlift);
    cards.push_back(new Diplomacy);
map=new Map;
gameDeck=new Deck(cards);
}

GameEngine::~GameEngine() {
    delete map;
    map= nullptr;
    delete gameDeck;
    gameDeck= nullptr;
    for(auto & i : players){
        if (i!= nullptr){
            delete i;
            i= nullptr;
        }

    }
}
GameEngine::GameEngine(const GameEngine& g) {
   map=new Map(*(g.map));
    for(int i=0;i<g.players.size();i++){
        this->players.push_back(new Player);
        this->players[i]=new Player(*(g.players[i]));
    }
    gameDeck=new Deck(*(g.gameDeck));

}

GameEngine& GameEngine::operator=(const GameEngine &g) {
   this->map=g.map;
   this->gameDeck=g.gameDeck;
    for(int i=0;i<g.players.size();i++){
        this->players.push_back(new Player);
        this->players[i]=g.players[i];
    }
    return *this;
}
Command::Command(string a) {
    name=a;
}
void Command::saveEffect(string e) {
    this->effect=e;
}
ostream& operator <<(ostream &strm,const Command&t) {
    return strm<<"name:"+t.name<<","<<"effect:"+t.effect<<endl;
}
ostream& operator <<(ostream &strm,const GameEngine&t) {
    strm<<"Current map:"<<t.map;
    strm<<"Players:"<<endl;
    for(auto & i : t.players){
        strm<<i<<endl;
    }
    strm<<t.gameDeck<<endl;
    return strm;
}
void GameEngine::startupphase() {
    bool startUp=true;

    CommandProcessor *c;
    if (this->readFromFile){
        c= new FileCommandProcessorAdapter(new FileCommandProcessor(this->filename));
    }else{
        c=new CommandProcessor;
    }
    while(startUp){
        Command *com=c->getCommand();
       bool validity= c->validate(com);
       if(!validity){
           cout<<"invalid state transition"<<endl;
           continue;
       }else {

           bool result;

           if (com->name.find("loadmap") == 0) {

               result = this->loadMap(com->name);
               if (result) {
                   com->saveEffect("map successfully loaded");
                   cout<<com->effect<<endl;
                   c->makeTransition("loadmap");
               } else {
                   com->saveEffect("could not loadMap");
                   cout<<com->effect<<endl;
                   continue;
               }
           }


           if (com->name.find("addplayer") == 0) {
               result = addPlayer(com->name);
               if (result) {
                   com->saveEffect("player successfully added");
                   cout<<com->effect<<endl;
                   c->makeTransition("addplayer");
               } else {
                   com->saveEffect("could not addplayer");
                   cout<<com->effect<<endl;
                   continue;
               }
           }

           if (com->name == "validatemap") {
               result= validateMap();
               if (result){
                   com->saveEffect("map successfully validated");
                   cout<<com->effect<<endl;
                   c->makeTransition("validatemap");
               }else{
                   com->saveEffect("could not validate map");
                   cout<<com->effect<<endl;
                   continue;
               }

           }

           if (com->name == "gamestart") {
               startUp= false;
               gameStart();

           }
           }


       }





}












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

void GameEngine::start() { // starts the game -> brings the player to state = start
    cout << "Command: start()" << endl;
}

bool GameEngine::loadMap(const string& x) { // brings player to state = map loaded
    string fileLocation=x.substr(x.find(" ")+1,x.length());
    fileLocation="../"+fileLocation;
    fstream  file(fileLocation);
    delete this->map;
    this->map=new Map;
    MapLoader *loader=new MapLoader(this->map);
   bool res= loader->loadMaps(file);
    return  res;
}
bool GameEngine::quit() { // brings player to state = map loaded

    cout << "Command: loadMap()" << endl;
}

bool GameEngine::replay() { // brings player to state = map loaded

    cout << "Command: loadMap()" << endl;
}
bool GameEngine::gameStart() { // brings player to state = map loaded
    int numOfTerritories=map->map.size();
    int numOfPlayers=players.size();
    int allocation=numOfTerritories/numOfPlayers;
    for(int i=0,playercount=0;i<numOfTerritories&&playercount<players.size();i=i+allocation,playercount++) {
        for (int j = i; j < i + allocation; j++) {
            if (j >= numOfTerritories) { break; }
            Territory *t = map->map.at(j);
            players.at(playercount)->addTerritory(t);
        }
    }
    int residue=numOfTerritories%numOfPlayers;

    if(residue!=0){
        for(int j=numOfTerritories-residue,playercount=0;j<numOfTerritories;j++,playercount++){
            Territory *t = map->map.at(j);
            players.at(playercount%players.size())->addTerritory(t);
        }
    }
for(auto & player : players){
    player->getHand()->Add(*gameDeck->draw());
    player->getHand()->Add(*gameDeck->draw());
    player->reinforcmentPool+=50;
}

        return true;


}
bool GameEngine::validateMap() {
   return map->validate();
    // brings player to state = map validated

}

void startupPhase();

bool GameEngine::addPlayer(string x) {
    string player=x.substr(x.find(" ")+1,x.length());
    Player *p=new Player;
    p->_name=player;
    players.push_back(p);
    // adds a new player w/ function new Player

    cout << "Command: addPlayer()" << endl;
    return true;
}

bool GameEngine::assignCountries() { //

    cout << "Command: assignCountries()" << endl;
}

void GameEngine::issueOrder() {

    cout << "Command: issueOrders()" << endl;
}

void GameEngine::endIssueOrders() {

    cout << "Command: endIssueOrders" << endl;
}

void GameEngine::execOrder() {

    cout << "Command: executeOrders" << endl;
}

void GameEngine::endExecOrders() {

    cout << "Command: endExecOrders" << endl;
}

void GameEngine::win() {
    cout << "Command: win" << endl;
}

void GameEngine::play() {

    cout << "Command: play" << endl;
}

void GameEngine::end() {
    cout << "Command: end" << endl;
}
