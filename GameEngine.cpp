//
// Created by Eve Gagnon on 2021-09-26.


#include <iostream>

// Because this is the game engine, we need to import the various classes
#include "GameEngine.h"
#include "CommandProcessor.h"
#include "FileCommandProcessorAdapter.h"
#include "FileLineReader.h"
#include "PlayerStrategies.h"


// Implementation of class GameEngine
//Constructor and Destructor
GameEngine::GameEngine() {
    vector<Card*> cards;
    queue=new Queue;
    //Add Cards with the references for deck and its Player and also Reinforcement
    //We can loop through the deck to set the informations
    cards.push_back(new Bomb);
    cards.push_back(new Blockade);
    cards.push_back(new Airlift);
    cards.push_back(new Diplomacy);
    cards.push_back(new Reinforcement);
    cards.push_back(new Bomb);
    cards.push_back(new Blockade);
    cards.push_back(new Airlift);
    cards.push_back(new Diplomacy);
    cards.push_back(new Reinforcement);
    cards.push_back(new Bomb);
    cards.push_back(new Blockade);
    cards.push_back(new Airlift);
    cards.push_back(new Diplomacy);
    cards.push_back(new Reinforcement);
    cards.push_back(new Bomb);
    cards.push_back(new Blockade);
    cards.push_back(new Airlift);
    cards.push_back(new Diplomacy);
    cards.push_back(new Reinforcement);
map=new Map;
gameDeck=new Deck(cards);

//Giving the reference of the deck to all the cards
for( Card * c :gameDeck->GetDeck() ){
    c->SetDeck(gameDeck);
}
}
string GameEngine::stringToLog(){
    return LogMessage;
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
    this->LogMessage="The following Command effect occured: "+e;
    this->effect=e;
    Notify(*this);

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
void GameEngine::transition(string s) {
    LogMessage="Transition "+ s+ " was just made";
    this->c->makeTransition(s);
    Notify(*this);
}
void GameEngine::tournamentSetup(string command) {
    cout<<command<<endl;
    int z=command.find("-M");
    int j=command.find("P");


    string maps=command.substr(z+3,j-(z+5));
    z=command.find("P");
    j=command.find("G");
    string strategy=command.substr(z+2,j-(z+4));
    z=command.find("G");
    j=command.find("D");
    string gamesToPlay=command.substr(z+2,j-(z+4));
    z=command.find("D");
    string turns=command.substr(z+2,command.length()-1);

    vector<string> mapsToLoads=tokenize(maps);
    vector<string> strategiess= tokenize(strategy);
    for(int i=0;i<mapsToLoad.size();i++){
        mapsToLoad[i]="../"+mapsToLoad[i];
    }
    for(int i=0;i<mapsToLoads.size();i++){
      this->mapsToLoad.push_back(mapsToLoads[i]);

    }
    for(int i=0;i<strategiess.size();i++){
        this->strategies.push_back(strategiess[i]);
    }
    this->numberOfTurns= stoi(turns);
    this->numbersToPlay= stoi(gamesToPlay);
}
void GameEngine::startupphase() {

    bool startUp=true;
    bool tournament=false;
    string info;



    while(startUp){
        cout<<"readigng file"<<endl;
        Command *com=c->getCommand();
        if (com->name.find("tournament") == 0) {
            tournament= c->validate(com);
            if(tournament){
                isTournament=true;
                info=com->name;
                startUp= false;
                break;
            }else {
                cout << "NOT A VALID TOURNAMENT SETTING" << endl;
                exit(0);
            }

        }
        bool validity= c->validate(com);
        if(!validity){
            continue;
        }else {

            bool result;

            if (com->name.find("loadmap") == 0) {

                result = this->loadMap(com->name);
                if (result) {
                    com->saveEffect("map successfully loaded");

                    transition("loadmap");
                } else {
                    com->saveEffect("could not loadMap");

                    continue;
                }
            }


            if (com->name.find("addplayer") == 0) {

                result = addPlayer(com->name);
                if (result) {
                    com->saveEffect("player successfully added");

                    transition("addplayer");
                } else {
                    com->saveEffect("could not addplayer");

                    continue;
                }
            }

            if (com->name == "validatemap") {
                result= validateMap();
                if (result){
                    com->saveEffect("map successfully validated");
                    transition("validatemap");
                }else{
                    com->saveEffect("could not validate map");

                    continue;
                }

            }

            if (com->name == "gamestart") {
                if(players.size()<=1){
                    com->effect="could not start game not enough players";
                    continue;
                }
                startUp= false;
                gameStart();
                transition("gamestart");
                for(auto i:map->map){
                    i->maxNumberOfArmies=this->gameReinforcementPool;
                }


            }
        }
    }

    if(tournament) {

        tournamentSetup(info);
        for (int i = 0; i < numbersToPlay; i++) {
            for (int j = 0; j < mapsToLoad.size(); j++) {
                bool res = loadMap(mapsToLoad[j]);
                if (!res) {
                    cout << "one map was not valid" << endl;
                    exit(0);
                }
                res = validateMap();
                if (!res) {
                    cout << "one maps was not connected" << endl;
                    exit(0);
                }
                for (int i = 0; i < strategies.size(); i++) {
                    addPlayer(strategies[i]);
                }
                for (int i = 0; i < players.size(); i++) {
                    players[i]->turns = this->numberOfTurns;
                }
                gameStart();
                string result = mainGameLoop();
                string game = "game";
                game += to_string(i + 1);
                string map = "map";
                map += to_string(j + 1);
                gameBlock[game][map] = result;


                for (Player *p:players) {
                    for (Card *c:p->hand->GetCollection()) {
                        this->gameDeck->Add(c);
                        p->hand->remove(c);
                    }
                    int size = i < p->territoriesList.size();
                    for (int i = 0; i < size; i++) {
                        p->territoriesList.erase(p->territoriesList.begin());
                    }
                    size = i < p->Neighboors.size();
                    for (int i = 0; i < size; i++) {
                        p->Neighboors.erase(p->Neighboors.begin());
                    }
                }
                int index = players.size();
                for (int i = 0; i < index; i++) {
                    delete players[i];
                    if(players.size()!=0) {
                        players.erase(players.begin());
                    }
                }

            }
        }

        for (int i = 0; i < numbersToPlay; i++) {
            string game = "game";
            game += to_string(i + 1);

            this->LogMessage = "          " + game;
            Notify(*this);
        }
        this->LogMessage = "\n";
        Notify(*this);



            for(int j=0;j<mapsToLoad.size();j++){

                string map="map";
                map+=to_string(j+1);

                this->LogMessage=map+"          ";
                Notify(*this);

                for(int i=0;i<numbersToPlay;i++){
                    string game="game";
                    game+=to_string(i+1);

                    this->LogMessage=gameBlock[game][map]+"         ";
                    Notify(*this);
                }
                this->LogMessage="\n";
                Notify(*this);

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

bool GameEngine::loadMap(const string& x) {
    string fileLocation;
    // brings player to state = map loaded
    if(!isTournament) {
         fileLocation = x.substr(x.find(" ") + 1, x.length());
    }else{
          fileLocation=x;
    }
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
    player->getHand()->Add(gameDeck->draw());
    player->getHand()->Add(gameDeck->draw());
    // Here we can add  reference to the player from the cards
// Maybe loop with pointers instead of references ?
    for(Card * c : player->getHand()->GetCollection()){
        c->SetPlayer(player);
    }
    player->reinforcement_pool+=50;
    this->gameReinforcementPool-=50;
}



    //Adding a reference to the game engine

    // adds a new player w/ function new Player

    cout << "Command: addPlayer()" << endl;

        return true;
}
bool GameEngine::validateMap() {
   return map->validate();
    // brings player to state = map validated

}
string Command::stringToLog(){
    return "COMMAND LOG:"+LogMessage+"\n";
}

void startupPhase();

bool GameEngine::addPlayer(string x) {
    if (players.size() >= 5) {
        return false;
    }
    string player;
    // brings player to state = map loaded
    if (!isTournament) {
        player = x.substr(x.find(" ") + 1, x.length());
    } else {
        player = x;
    }

    Player *p = new Player;
    p->_name = player;
    //Adding a reference to the game engine
    p->SetGameEngine(this);
    p->orders->Attach(this->o);


    if (p->_name == "Human") {
        p->SetStrategy(new HumanPlayer(p));
    } else {
        if (p->_name == "Aggressive") {
            p->SetStrategy(new AggressivePlayer(p));
        } else {
            if (p->_name == "Benevolent") {
                p->SetStrategy(new BenevolentPlayer(p));
            } else {
                if (p->_name == "Cheater") {
                    //"change this"
                    p->SetStrategy(new CheaterPlayer(p));
                } else {
                    if (p->_name == "Neutral") {
                        p->SetStrategy(new NeutralPlayer(p));
                    }
                }
            }

        }
        //humanplayer,Neutral,Benevolent
        //human,cheater,aggressive
        //human,neutral,agressive

        players.push_back(p);
        // adds a new player w/ function new Player
        return true;
    }
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


string GameEngine::mainGameLoop() {
    cout << "you are in the main loop" << endl;
    while (true) {

        reinforcementPhase();
        issueOrdersPhase();
        executeOrdersPhase();
        int j = 0;
        verification();

        for (auto i:players) {
            if (isTournament) {
                i->turns--;
            }

            if (i->territoriesList.size() == 0) {
                players.erase(players.begin() + j);

            }
            j++;
        }
        if (players.size() == 1) {

            return players[0]->_name;
        }
        if (players.size() == 2 && (draw)) {
            return "draw";

        }
        int index = players.size();
        if (isTournament) {
            for (int i = 0; i < index;i++) {
                if (players[i]->turns <= 0) {

                    redistribute(players[i]);
                    for (Card *c:players[i]->hand->GetCollection()) {
                        gameDeck->Add(c);
                        players[i]->hand->remove(c);
                    }
                    Player *p=players[i];
                    this->RemovePlayer(players[i]);
                    delete p;

                }
            }


            if (players.size() == 1) {
                return players[0]->_name;
            }

            if (players.size() == 0) {
                return "draw";
            }

        }
    }
}

    bool GameEngine::redistribute(Player *p) { // brings player to state = map loaded
        int numOfTerritories=p->territoriesList.size();
        int numOfPlayers=players.size();
        if(numOfPlayers<=0){
            return true ;
        }
        int allocation=numOfTerritories/numOfPlayers;
        for(int i=0,playercount=0;i<numOfTerritories&&playercount<players.size();i=i+allocation,playercount++) {
            for (int j = i; j < i + allocation; j++) {
                if (j >= numOfTerritories) { break; }
                Territory *t = p->territoriesList[j];
                players.at(playercount)->addTerritory(t);
            }
        }
        int residue=numOfTerritories%numOfPlayers;

        if(residue!=0){
            for(int j=numOfTerritories-residue,playercount=0;j<numOfTerritories;j++,playercount++){
                Territory *t =  p->territoriesList[j];
                players.at(playercount%players.size())->addTerritory(t);
            }
        }

}

void GameEngine::reinforcementPhase() {
    if (gameReinforcementPool > 0) {
        for (auto player: players) {
            int territories = player->territoriesList.size();
            int reinforcement = territories / 3;
            if (reinforcement < 3 && reinforcement > 0) {
                player->reinforcement_pool += 3;
                gameReinforcementPool -= 3;
            } else {
                player->reinforcement_pool += reinforcement;
                gameReinforcementPool -= reinforcement;
            }
            vector<Territory *> t = map->continents;
            int i = 0;
            for (auto index: t) {
                for (auto j: player->territoriesList) {
                    if (index->number == j->number) {
                        i++;
                    }
                }

                if (i == t.size() - 1) {
                    this->map->continentBonus();
                    player->reinforcement_pool += index->Bonus;
                    gameReinforcementPool -= index->Bonus;
                }
            }
            player->ghostDeploys = player->reinforcement_pool;
        }
    }

}

Player* Queue::deQueue() {
    if(queue.size()==0){
        cout<<"attempt to deque empty list";
        exit(1);
    }
    Player* c=queue[0];
    queue.erase(queue.begin()+0);
    return c;
}
void Queue::enQueue(Player* player)
{
  queue.push_back(player);
}
void GameEngine::issueOrdersPhase() {

    cout << "issuing the orders now" << endl;
    int finished=true;
    //variable to indicate that the order has been finished

    bool finishedissue=false;
    //create a new queue and making in circular! but we have to give it a size

    for (auto i: players) {
       queue->enQueue(i);
    }

    while(!finishedissue){

        Player* c=queue->deQueue();
        c->IssueOrder();

        if(!c->FinishedIssueOrder){

            queue->enQueue(c);
        }
        if(queue->queue.size()==0){
            finishedissue=true;
        }
    }

    //once you removed all players, circular queue will be empty and we shall be done

}


void GameEngine::verification() {
   int size= players.size();
   int index=0;
   int j=0;
    for(Player *p:players){
        for(Territory *t:p->territoriesList){
            if(t->numberOfArmies==0){
                if(p!=players.at(index)) {
                    t->numberOfArmies=1;
                    players.at(index)->territoriesList.push_back(t);
                    index = (index + 1) % size;
                    p->territoriesList.erase(p->territoriesList.begin() + j);
                }
            }
            j++;
        }
        j=0;
    }
    index=0;
    for(Player *p:players){
        if(p->territoriesList.size()==1){
            Territory *t=p->territoriesList[0];
            p->territoriesList.erase(p->territoriesList.begin()+0);
            for(Player *play:players){
                if(play!=p){
                    play->territoriesList.push_back(t);
                    return;
                }
            }
        }
    }
}

bool GameEngine::executeOrdersPhase() {

    cout << "issuing the orders now" << endl;
    int finished=true;
    //variable to indicate that the order has been finished

    bool finishedissue=false;
    //create a new queue and making in circular! but we have to give it a size

    for (auto i: players) {
        queue->enQueue(i);
    }

    while(!finishedissue){

       Player *c=queue->deQueue();


       for(auto i:c->orders->get_order_list_new()){
           i->execute();
       }
        if(c->orders->get_order_list_new().size() != 0){
            queue->enQueue(c);
        }

        if(queue->queue.size()==0){
            finishedissue= true;
        }
    }

    //once you removed all players, circular queue will be empty and we shall be done

}
