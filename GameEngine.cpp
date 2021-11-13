//
// Created by Eve Gagnon on 2021-09-26.


#include <iostream>

// Because this is the game engine, we need to import the various classes
#include "GameEngine.h"
#include "Player.h"
#include "CommandProcessor.h"
#include "FileCommandProcessorAdapter.h"
#include "FileCommandProcessor.h"
#include&lt;iostream&gt;
using namespace std;

// Implementation of class GameEngine
//Constructor and Destructor
GameEngine::GameEngine() {
    vector<Card*> cards;
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
for( Card * c :gameDeck ){
    c->SetDeck(gameDeck);
}
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
    // Here we can add  reference to the player from the cards
// Maybe loop with pointers instead of references ?
    for(Card * c : player->getHand()){
        c->SetPlayer(player);
    }
    player->reinforcmentPool+=50;
}


// Creation of the Neutral Player
    string player= "Neutral";
    Player *p=new Player;
    p->_name=player;
    //Adding a reference to the game engine
    p->SetGameEngine(this);
    players.push_back(p);
    // adds a new player w/ function new Player

    cout << "Command: addPlayer()" << endl;



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
    //Adding a reference to the game engine
    p->SetGameEngine(this);
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
void GameEngine::mainGameLoop(){
    cout<<"you are in the main loop" <<endl;

    void reinforcementPhase();
    void issueOrdersPhase();
    bool executeOrdersPhase();
//once all orders are executed go back to reinforcement
    if (executeOrdersPhase()==true){
        mainGameLoop();
    }

}

void GameEngine::reinforcementPhase() {
    for(Player* player){
        int territories=p->territoriesList.size();
        int reinforcement = territories/3;

        const int MIN_R = 0;
        if (reinforcement < MIN_R){
            reinforcement==MIN_R;
        }
    }

}

int Queue::deQueue() {
    if (front == -1) {
        cout <<"\nQueue is Empty"<<endl;
        return -1;
    }

    int data = circular_queue[front];
    circular_queue[front] = -1;
    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == size - 1)
        front = 0;
    else
        front++;

    return data;
}
void Queue::enQueue(Player* player)
{
    if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))  {
        cout <<"\nQueue is Full"<<endl;
        return;
    }
    else if (front == -1) {     /* Insert First Element */
        front = rear = 0;
        circular_queue[rear] = player;
    }
    else if (rear == size-1 & & front != 0) {
        rear = 0;
        circular_queue[rear] = player;
    }
    else {
        rear++;
        circular_queue[rear] = player;
    }
}
void GameEngine::issueOrdersPhase() {

    cout << "issuing the orders now" << endl;
    int finished=true;
    //variable to indicate that the order has been finished

    Queue q(players.size());
    //create a new queue and making in circular! but we have to give it a size

    for (auto i: players) {
        //loop through all the players
        q.enQueue(p);
        //adding a player into the queue
        p->IssueOrder();
        finished=false;

        if(finished=false){
            q.deQueue(p);
        }
        //after it adds the player in the circular queue and issues its order
        //it will alert us that its finish, hence we remove the player from the circular queue
        if(q.size==0){
            cout<<"you are done with issue Order phase!"; }
    }
    //once you removed all players, circular queue will be empty and we shall be done

}

bool GameEngine::executeOrdersPhase() {
    cout << "executing orders now!!!" << endl;
    Queue q2(players.size());

    //creating a new circular queue
    for (auto i: players) {
        //loop through all the players
        q2.enQueue(p);
        //adding player to the circular queue
        int size=i->orders->get_order_list()->size();
        int index=1;

        for(auto j:*i->orders->get_order_list()){
            j->execute();
            index++;
            if(index==size){
                //goes through the list of orders and executes them
                q2.deQueue();
                //once ur done with the order remove from the queue
            }
        }
        if(q2.size==0){
            cout<<"you are done with execute order phase!"; }
    }

    if (players.size()<=1){
        return 0;
    }else
        return true;
//Once all players orders have been executed return true
//if one player left nothing to be executed? so exit

}