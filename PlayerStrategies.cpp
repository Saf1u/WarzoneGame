//
// Created by Safwan Ahmed on 2021-11-28.
//

#include "PlayerStrategies.h"
#include <iostream>
#include <string>
#include "Player.h"
using std::cout;
using std::cin;
using std::string;
using std::endl;

PlayerStrategies::PlayerStrategies(Player * p) {

    this->p=p;
}

void PlayerStrategies::SetStrategy(Player * p) {
    this->p=p;
}

PlayerStrategies::~PlayerStrategies() {
    delete p;
}
 vector<Territory*> HumanPlayer::toAttack(){

    // This boolean will return if the decision was to attack or no the enemy player
    bool toAttack =  this->Decision();
    int i=0;
     // Getting all the enemy Neighboors Territories
     if(toAttack) {
         this->p->FillNeighboors();
         vector<Territory *> array = this->p->Neighboors;
         for(Territory* t:this->p->territoriesList){
             for(Territory* t2:array){
                 if(t2->number==t->number){
                     array.erase(array.begin()+i);
                 }else{
                     i++;
                 }

             }
             i=0;
         }

//Ronaldo7
         //comparisons will be done n times
         for (int i = 0; i < array.size(); i++) {
             //compare elemet to the next element, and swap if condition is true
             for (int j = 0; j < array.size() - 1; j++) {
                 //Order By least amount of armies to attack
                 //Check swap Value
                 if (array[j]->numberOfArmies > array[j + 1]->numberOfArmies)
                     swap((array[j]), array[j + 1]);
             }
         }
         return array;
     }
     else
     {
         // We return an empty vector so it cannot attack
         vector<Territory *> array;
         return array;
     }
}
/**
 * There is no need to change that method of human
 * @return  a list of Territories to Defend
 */
vector<Territory*> HumanPlayer::toDefend(){

    vector<Territory *> array = this->p->territoriesList;
    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare element to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            //Order By least amount of armies
            //Check swap Value
            if (array[j]->numberOfArmies > array[j+1]->numberOfArmies)
                swap((array[j]), array[j+1]);
        }
    }
    return array;
}

// There is no need to change issue order for Human player, decision making of attack will take care of IT
 void HumanPlayer::issueOrder() {
    bool CanAdvance = false;
    bool SpecialOrder = false;

    this->p->FillNeighboors();

   //Returns list of enemy territories that are neighbors that we can attack
    toAttack();

    //Returns list of  territories that belong to the player that we can defend
    toDefend();
    bool deployExist=false;
    bool advanceExist=false;
for(auto o:this->p->orders->get_order_list_new()){
    if(o->get_type()=="Deploy"){
        deployExist=true;
    }
    if(o->get_type()=="Advance"){
        advanceExist=true;
    }
}

   //Check for deploy
   if(!deployExist) {
       Deploy *d = new Deploy;
       d->p= this->p;
       d->ListOfPlayers=this->p->Game->players;
       d->m=this->p->Game->map;
       d->deck=this->p->Game->gameDeck;

       d->Attach(p->Game->o);
       this->p->orders->Add(d);
       deployExist=true;
   }




    //Check for Advance
    if(!advanceExist) {
        bool AdvanceAttack = true;
        if (this->toAttack().size() == 0)
            AdvanceAttack = false;

        bool AdvanceDeploy = true;
        if (this->toDefend().size() == 0)
            AdvanceDeploy = false;

        if (AdvanceAttack || AdvanceDeploy) {
            Advance *d = new Advance;
            d->p= p;
            d->ListOfPlayers=this->p->Game->players;
            d->deck=this->p->Game->gameDeck;
            d->Attach(p->Game->o);
            d->m=this->p->Game->map;
            this->p->orders->Add(d);
            CanAdvance = true;
        }
    }


    //Verify for the Execution of a Special Order

    vector<Card *> Hand = this->p->getHand()->GetCollection();
//Monitor if we have already pushed a  Card

//Play will remove the Card from the player Hand
    string CardType;
    if(Hand.size() != 0) {
        for (Card *c: Hand) {

            CardType = c->GetType();

            if (CardType == "Bomb") {
                //Plays the Card
                c->play(CardType,p);
                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Airlift") {
                c->play(CardType,p);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Diplomacy") {
                c->play(CardType,p);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Blockade") {
                c->play(CardType,this->p);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }
            if (CardType == "Reinforcement") {
                c->play(CardType,p);
                // This breaks out of the loop so we can push one Card at a time
                break;
            }


        }
    }
    else {
        cout << "We have Used all the cards inside the player's hand" << endl;
        SpecialOrder = true;
    }
if(this->p->_name=="Neutral"&&(p->territoriesList.size()==0||advanceExist)&&p->hand->GetCollection().size()==0){
    this->p->FinishedIssueOrder = true;
}
    if(advanceExist  && SpecialOrder&&deployExist){
        this->p->FinishedIssueOrder = true;
        return;
    }
}

HumanPlayer::HumanPlayer(Player * p): PlayerStrategies(p) {
    name="HumanPlayer";
this->p = p;
}

// This method will take the correct decision for the player
bool HumanPlayer::Decision() {
    bool completed = false;
    bool ToAttack =false;
    while(!completed) {
        cout<<endl;
        cout << "If given the option are we going to attack or no this turn choose yes or no ?" << endl;

        string decision = "";

       // cin >> decision;
       decision="yes";

        if (decision == "yes") {
            // Code to allow an attack
            completed = true;
            ToAttack = true;
            return ToAttack;
        }

        if (decision == "no") {
            // Code to stop the attack
            p->humanPlay=true;

            completed = true;

            ToAttack = false;
            return ToAttack;
        } else {
            cout << "Please enter a correct option " << endl;
        }
    }
}



//BenevolentPlayer Player
/*"----------------------------------------------------------------------------------------"*/

BenevolentPlayer::BenevolentPlayer(Player * p): PlayerStrategies(p) {
    name="BenevolentPlayer";
this->p=p;
}
/**
 * The Benevolent Player simply never attacks
 * @return
 */
vector<Territory*> BenevolentPlayer::toAttack(){

        // We just return an empty array because this player simply never Attacks , sufficient for it not to attack
        vector<Territory *> array;
        return array;

}
/**
 * There is no need to change that method of Benevolent Player
 * @return  a list of Territories to Defend
 */
vector<Territory*> BenevolentPlayer::toDefend(){

    vector<Territory *> array = this->p->territoriesList;
    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            //Order By most amount of armies
            //Check swap Value
            if (array[j]->numberOfArmies < array[j+1]->numberOfArmies)
                swap((array[j]), array[j+1]);
        }
    }
    return array;
}

// There is no need to change issue order for Human player, decision making of attack will take care of IT
void BenevolentPlayer::issueOrder() {
    bool CanAdvance = false;
    bool SpecialOrder = false;

    this->p->FillNeighboors();

    //Returns list of enemy territories that are neighbors that we can attack
    toAttack();

    //Returns list of  territories that belong to the player that we can defend
    toDefend();
    bool deployExist=false;
    bool advanceExist=false;
    for(auto o:this->p->orders->get_order_list_new()){
        if(o->get_type()=="Deploy"){
            deployExist=true;
        }
        if(o->get_type()=="Advance"){
            advanceExist=true;
        }
    }

    //Check for dpeloy
    if(!deployExist) {
        Deploy *d = new Deploy;
        d->p= this->p;
        d->ListOfPlayers=this->p->Game->players;
        d->m=this->p->Game->map;
        d->deck=this->p->Game->gameDeck;

        d->Attach(p->Game->o);
        this->p->orders->Add(d);
        deployExist=true;
    }




    //Check for Advance
    if(!advanceExist) {
        bool AdvanceAttack = true;
        if (this->toAttack().size() == 0)
            AdvanceAttack = false;

        bool AdvanceDeploy = true;
        if (this->toDefend().size() == 0)
            AdvanceDeploy = false;

        if (AdvanceAttack || AdvanceDeploy) {
            Advance *d = new Advance;
            d->p= p;
            d->ListOfPlayers=this->p->Game->players;
            d->deck=this->p->Game->gameDeck;
            d->Attach(p->Game->o);
            d->m=this->p->Game->map;
            this->p->orders->Add(d);
            CanAdvance = true;
        }
    }


    //Verify for the Execution of a Special Order

    vector<Card *> Hand = this->p->getHand()->GetCollection();
//Monitor if we have already pushed a  Card

//Play will remove the Card from the player Hand
    string CardType;
    if(Hand.size() != 0) {
        for (Card *c: Hand) {

            CardType = c->GetType();

            if (CardType == "Bomb") {
                //Plays the Card
                c->play(CardType,p);
                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Airlift") {
                c->play(CardType,p);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Diplomacy") {
                c->play(CardType,p);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Blockade") {
                c->play(CardType,this->p);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }
            if (CardType == "Reinforcement") {
                c->play(CardType,p);
                // This breaks out of the loop so we can push one Card at a time
                break;
            }


        }
    }
    else {
        cout << "We have Used all the cards inside the player's hand" << endl;
        SpecialOrder = true;
    }
    if(this->p->_name=="Neutral"&&(p->territoriesList.size()==0||advanceExist)&&p->hand->GetCollection().size()==0){
        this->p->FinishedIssueOrder = true;
    }
    if(advanceExist  && SpecialOrder&&deployExist){
        this->p->FinishedIssueOrder = true;
        return;
    }
}

/**
 * ----------------------------------------------------------------------------------------------------------------------
 * The aggressive player will always deploy on their strongest country,
 * attack with their strongest country, and if it can, move their armies to their strongest country.
 * Maybe modify the Advance method for this type of Player or use boolean
 */


AggressivePlayer::AggressivePlayer(Player * p): PlayerStrategies(p) {
    name="AggressivePlayer";
    // To tell to the player pointer that it is an agressive player
    this->p = p;
p->AgressivePlayer = true;
}

vector<Territory*> AggressivePlayer::toAttack(){

    // Getting all the enemy Neighboors Territories


    vector<Territory *> array;
      // Gets the Neighboors of the strongest Territory so we could Attack
      if(this->p->toDefend().size()!=0) {
          int i=0;
          vector<Territory *> array = this->p->toDefend()[0]->edges;
          for(Territory* t:this->p->territoriesList){
              for(Territory* t2:array){
                  if(t->number==t2->number){
                      array.erase(array.begin()+i);
                      //Ronaldo
                  }else {
                      i++;
                      //another analysis of our index use being weird
                  }
              }
              i=0;
          }
          //comparisons will be done n times


          for (int i = 0; i < array.size(); i++) {
              //compare elemet to the next element, and swap if condition is true
              for (int j = 0; j < array.size() - 1; j++) {
                  //Order By least amount of armies to attack
                  //Check swap Value
                  if (array[j]->numberOfArmies > array[j + 1]->numberOfArmies)
                      swap((array[j]), array[j + 1]);
              }
          }
          if(array.size()==0&&this->p->Game->players.size()==2){
              this->p->Game->numberOftimesHecannotattack++;
              if( this->p->Game->numberOftimesHecannotattack>=25){
                  this->p->Game->draw=true;
              }
          }
          return array;

      }
    return array;
    }

/**
 * There is no need to change that method of human
 * @return  a list of Territories to Defend
 */
vector<Territory*> AggressivePlayer::toDefend(){
 // Verify if it does return indeed the strongest Territory
    vector<Territory *> array = this->p->territoriesList;
    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            //Order By most amount of armies
            //Check swap Value
            if (array[j]->numberOfArmies < array[j+1]->numberOfArmies)
                swap((array[j]), array[j+1]);
        }
    }

    return array;
}

// There is no need to change issue order for Human player, decision making of attack will take care of IT
void AggressivePlayer::issueOrder() {
    bool CanAdvance = false;
    bool SpecialOrder = false;

    this->p->FillNeighboors();

    //Returns list of enemy territories that are neighbors that we can attack
    toAttack();

    //Returns list of  territories that belong to the player that we can defend
    toDefend();
    bool deployExist=false;
    bool advanceExist=false;
    for(auto o:this->p->orders->get_order_list_new()){
        if(o->get_type()=="Deploy"){
            deployExist=true;
        }
        if(o->get_type()=="Advance"){
            advanceExist=true;
        }
    }

    // We have to push a secial type of Deploy Order and overwite its execute method
    if(!deployExist) {
        Deploy *d = new Deploy;
        d->p= this->p;
        d->ListOfPlayers=this->p->Game->players;
        d->m=this->p->Game->map;
        d->deck=this->p->Game->gameDeck;

        d->Attach(p->Game->o);
        this->p->orders->Add(d);
        deployExist=true;
    }


    //Check for Advance
    if(!advanceExist) {
        bool AdvanceAttack = true;
        if (this->toAttack().size() == 0)
            AdvanceAttack = false;

        bool AdvanceDeploy = true;
        if (this->toDefend().size() == 0)
            AdvanceDeploy = false;

        if (AdvanceAttack || AdvanceDeploy) {
            Advance *d = new Advance;
            d->p= p;
            d->ListOfPlayers=this->p->Game->players;
            d->deck=this->p->Game->gameDeck;
            d->Attach(p->Game->o);
            d->m=this->p->Game->map;
            this->p->orders->Add(d);
            CanAdvance = true;
        }
    }


    //Verify for the Execution of a Special Order

    vector<Card *> Hand = this->p->getHand()->GetCollection();
//Monitor if we have already pushed a  Card

//Play will remove the Card from the player Hand
    string CardType;
    if(Hand.size() != 0) {
        for (Card *c: Hand) {

            CardType = c->GetType();

            if (CardType == "Bomb") {
                //Plays the Card
                c->play(CardType,p);
                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Airlift") {
                c->play(CardType,p);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Diplomacy") {
                c->play(CardType,p);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }

            if (CardType == "Blockade") {
                c->play(CardType,this->p);

                // This breaks out of the loop so we can push one Card at a time
                break;
            }
            if (CardType == "Reinforcement") {
                c->play(CardType,p);
                // This breaks out of the loop so we can push one Card at a time
                break;
            }


        }
    }
    else {
        cout << "We have Used all the cards inside the player's hand" << endl;
        SpecialOrder = true;
    }
    if(this->p->_name=="Neutral"&&(p->territoriesList.size()==0||advanceExist)&&p->hand->GetCollection().size()==0){
        this->p->FinishedIssueOrder = true;
    }
    if(advanceExist  && SpecialOrder&&deployExist){
        this->p->FinishedIssueOrder = true;
        return;
    }
}

/**
 * ---------------------------------------------------------------------------------------------------------------------
* This where we start the Neutral player
*/



NeutralPlayer::NeutralPlayer(Player * p): PlayerStrategies(p) {
    name="NeutralPlayer";
    // To tell to the player pointer that it is an Neutral player
    this->p =p;
    p->NeutralPlayer = true;
}

vector<Territory*> NeutralPlayer::toAttack(){

    // Neutral Player returns an empty array
    vector<Territory *> array;

    return array;
}

/**
 * There is no need to change that method of human
 * @return  a list of Territories to Defend
 */
vector<Territory*> NeutralPlayer::toDefend(){
    // Verify if it does return indeed the strongest Territory
    vector<Territory *> array = this->p->territoriesList;
    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            //Order By most amount of armies
            //Check swap Value
            if (array[j]->numberOfArmies > array[j+1]->numberOfArmies)
                swap((array[j]), array[j+1]);
        }
    }
    return array;
}

// There is no need to change issue order for Human player, he will issue no order
void NeutralPlayer::issueOrder() {
    this->p->FinishedIssueOrder = true;
    p->FinishedIssueOrder= true;
}

// Using = operator to return an Aggressive Player form a neutral Player
AggressivePlayer &AggressivePlayer::operator=(const Player &p) {

    AggressivePlayer * a = new AggressivePlayer(new Player(p));
    return *a;
}


/**
 * -----------------------------------------------------------------------------------------------------------
* This is for the cheater player
*/

CheaterPlayer::CheaterPlayer(Player *p) : PlayerStrategies(p){
    name="CheaterPlayer";
    this->p = p;
    //To specify that it is a cheater player
  this->p->CheaterPlayer = true;
}
vector<Territory*> CheaterPlayer::toAttack(){

    // This boolean will return if the decision was to attack or no the enemy player

    // Getting all the enemy Neighboors Territories

        vector<Territory *> array = this->p->Neighboors;

        //comparisons will be done n times
        for (int i = 0; i < array.size(); i++) {
            //compare elemet to the next element, and swap if condition is true
            for (int j = 0; j < array.size() - 1; j++) {
                //Order By least amount of armies to attack
                //Check swap Value
                if (array[j]->numberOfArmies > array[j + 1]->numberOfArmies)
                    swap((array[j]), array[j + 1]);
            }
        }
        return array;

}
/**
 * There is no need to change that method of human
 * @return  a list of Territories to Defend
 */
vector<Territory*> CheaterPlayer::toDefend(){

    vector<Territory *> array = this->p->territoriesList;
    //comparisons will be done n times
    for (int i = 0; i < array.size(); i++)
    {
        //compare elemet to the next element, and swap if condition is true
        for(int j = 0; j < array.size() - 1; j++)
        {
            //Order By least amount of armies
            //Check swap Value
            if (array[j]->numberOfArmies > array[j+1]->numberOfArmies)
                swap((array[j]), array[j+1]);
        }
    }
    return array;
}

// There is no need to change issue order for Human player, decision making of attack will take care of IT
void CheaterPlayer::issueOrder() {
    bool advanceExist  = true;
    bool SpecialOrder  = true;
    bool deployExist  = true;

    // List of all Neighboor Territorie that we can attack
    vector<Territory *> TerritoriesToAttack =this->toAttack();

      // the Cheater Player is like the Corona virus it spreads everywhere
    vector<Territory *> CheaterTerritories =p->territoriesList;

    // All the players in the game
    vector<Player * > PlayersList = this->p->Game->players;

    int index = 0;
    //Looping through all the players in the game
        for(Player * p : this->p->Game->players){
            // All the territories of the Player we are currently looping on
            vector<Territory *> PlayerT = p->territoriesList;
            // Looping through the list territories in all Players
            for(Territory * t1 :p->territoriesList ){
                //Making sure that the Cheater player does not compare to itself
                if(p->CheaterPlayer == false) {
                    //Looping the the list of territories that we can attack
                    for (Territory *t2: this->toAttack()) {
                        // Verifying if territory of enemy player is in that list
                        if (t1->number == t2->number) {
                            //Pushing back the territory to the list of Cheater Player

                            // erasing the territory of the enemy list
                            if(index<p->territoriesList.size()){
                                this->p->territoriesList.push_back(t1);
                                p->territoriesList.erase(p->territoriesList.begin() + index);
                                index--;
                                //lets analyse
                                if(p->NeutralPlayer== true){
                                    p->SetStrategy(new AggressivePlayer(p));
                                }
                            }else{

                            }

                        }
                    }
                    index++;
                }
            }
            index =0;
        }


        this->p->FinishedIssueOrder = true;
        return;

}