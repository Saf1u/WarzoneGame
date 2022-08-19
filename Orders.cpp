
#include "Orders.h"
#include "PlayerStrategies.h"
#include <cstdlib>
#include <ctime>


Order::Order() {

    bool valid;
    vector<string> vec_type2 = {"Deploy", "Advance", "Bombs", "Blockadess", "Airliftss", "negotiate"};
    int type_id;


    this->valid = true;
    this->type_id = 1;
    this->vec_type1 = vec_type2;

}


Order::Order(Player* player, Map * map) {



}
void Order::SetPlayer(Player *player) {
    this->p = player;
}

void Order::SetMap(Map *map) {
    this->m= map;
}

void Order:: set_type_id(int num){

    this->type_id = num;
}
void Order:: set_valid(bool valid){

    this->valid = valid;
}

void Order:: set_vec_type1(vector<string> vec_type1 ){

    this->vec_type1 = vec_type1;
}

OrderList::OrderList() {


}

Airlifts ::Airlifts(bool valids, vector<string> vec_types1 ,int type_ids ) {

this->set_valid(valids);
this->set_vec_type1(vec_types1);
this->set_type_id(type_ids);

}

Bombs ::Bombs(bool valids, vector<string> vec_types1 ,int type_ids ) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}

Deploy ::Deploy(bool valids, vector<string> vec_types1 ,int type_ids ) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}


Advance ::Advance(bool valids, vector<string> vec_types1 ,int type_ids ) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}

Negotiate ::Negotiate(bool valids, vector<string> vec_types1 ,int type_ids ) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}

Blockades ::Blockades(bool valids, vector<string> vec_types1 ,int type_ids ) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}

OrderList::OrderList(vector<Order *> e){


    int size= e.size();

    for(Order * element :e ){

        bool valids = element->get_valid();
        vector<string> vec_types1 = element->get_List();
        int type_ids= element->get_ID();


    }

}

/**
 * assignment operator of OrderList
 */
OrderList& OrderList::operator=(const OrderList& e){
    for(Order * element : (e.vec_order_list )){
        bool valid = element->get_valid();
        vector<string> vec_type1 = element->get_List();
        int type_id= element->get_ID();

        string type = element->type;
        //STOP1
        if(type == "Airlifts") {
            Order * T1 = new Airlifts (valid,vec_type1,type_id);
            this->vec_order_list.push_back(T1);
        }

        if(type == "Deploy") {
            Order * T1 = new Deploy (valid,vec_type1,type_id);
            this->vec_order_list.push_back(T1);
        }

        if(type == "Bombs") {
            Order * T1 = new Bombs (valid,vec_type1,type_id);
            this->vec_order_list.push_back(T1);
        }

        if(type == "Negotiate") {
            Order * T1 = new Negotiate (valid,vec_type1,type_id);
            this->vec_order_list.push_back(T1);
        }

        if(type == "Blockades") {
            Order * T1 = new Blockades (valid,vec_type1,type_id);
            this->vec_order_list.push_back(T1);
        }

    }

    return *this;
}

void Order::PrintAllOrder() {

    int index = 1;
    for (auto element: this->vec_type1) {

        cout << "This is order number " << index << " with type" << element << endl;
        index++;
    }
    cout << "The type ID is " << this->type_id << endl;

    cout << "Now we will print the Player of this Order" << endl;
    cout <<"---------------------------------"<<endl;
    cout <<endl;
    cout <<endl;
    cout << *(this->p);
    cout <<endl;
    cout <<endl;
    cout <<"---------------------------------"<<endl;

    cout << "Now we will print the Map Used in the Game" << endl;
    cout <<"---------------------------------"<<endl;
    cout <<endl;
    cout <<endl;
    cout << *(this->m);
    cout <<endl;
    cout <<endl;
    cout <<"---------------------------------"<<endl;
    // e.m->printMap();

}

std::ostream &operator<<(std::ostream &stream, const Order &e) {




    int index = 1;
    for (auto element: e.vec_type1) {

        stream << "This is order number " << index << " with type" << element << endl;
        index++;
    }
    stream << "The type ID is " << e.type_id << endl;

    return stream;
}

Order::~Order() {
     deck= nullptr;
    p= nullptr;
    //Add GameEngine Player
    m= nullptr;
    for(int i=0;i<ListOfPlayers.size();i++){
        ListOfPlayers[i]= nullptr;
    }
}
//Copy Constructor
Order::Order(const Order& O)
{
    this->valid = O.valid;
    this->vec_type1 = O.vec_type1;
    this->type_id = O.type_id;
}


string Order::get_type() {
    return vec_type1.at(type_id);
}

bool Order::get_valid() {
    return this->valid;
}

vector<string> Order::get_List() {
    return  this->vec_type1;
}

int Order::get_ID() {
    return this->type_id;
}

Order::Order(bool b, vector<string> vector1, int i) {

    this->valid = b;
    this->vec_type1 = vector1;
    this->type_id = i;
}

void OrderList::set_order_list(Order *i) {
    bool valid = i->get_valid();
    vector<string> vec_type1 = i->get_List();
    int type_id= i->get_ID();

    string type = i->type;
    //STOP2
    if(type == "Airlifts") {
        Order * T1 = new Airlifts (valid,vec_type1,type_id);
        this->vec_order_list.push_back(T1);
    }

    if(type == "Deploy") {
        Order * T1 = new Deploy (valid,vec_type1,type_id);
        this->vec_order_list.push_back(T1);
    }

    if(type == "Bombs") {
        Order * T1 = new Bombs (valid,vec_type1,type_id);
        this->vec_order_list.push_back(T1);
    }

    if(type == "Negotiate") {
        Order * T1 = new Negotiate (valid,vec_type1,type_id);
        this->vec_order_list.push_back(T1);
    }

    if(type == "Blockades") {
        Order * T1 = new Blockades (valid,vec_type1,type_id);
        this->vec_order_list.push_back(T1);
    }
}

vector<Order *> *OrderList::get_order_list() {
    return &vec_order_list;
}

void OrderList::remove(Order *oneOrder) {
    for (int i = 0; i < vec_order_list.size(); i++) {
        if (oneOrder->get_type() == vec_order_list.at(i)->get_type()) {
            vec_order_list.erase(vec_order_list.begin() + i);
            return;
        }
    }
}

void OrderList::move(int position, int new_position) {
    if (position >= 0 && position < vec_order_list.size() && new_position >= 0 &&
        new_position < vec_order_list.size()) {
        vec_order_list.insert(vec_order_list.begin() + new_position, vec_order_list.at(position));
        vec_order_list.erase(vec_order_list.begin() + position);
    } else if (new_position == vec_order_list.size()) {
        vec_order_list.push_back(vec_order_list.at(position));
        vec_order_list.erase(vec_order_list.begin() + position);
    } else {
        cout << "\n not valid position" << endl;
    }
}


Deploy::Deploy() {

    set_type_id(0);
}

Deploy::Deploy(const Deploy &e) {

};

Deploy &Deploy::operator=(const Deploy &e) {


    return *this;
}

Deploy::~Deploy() {
};

Advance::Advance() {

    set_type_id(1);
}

Advance::Advance(const Advance &e) {

};

Advance &Advance::operator=(const Advance &e) {


    return *this;
}

Advance::~Advance() {
}

Bombs::Bombs() {

    set_type_id(2);
}

Bombs::Bombs(const Bombs &e) {

};

Bombs &Bombs::operator=(const Bombs &e) {


    return *this;
}

Bombs::~Bombs() {
}

Blockades::Blockades() {

    set_type_id(3);
}

Blockades::Blockades(const Blockades &e) {

};

Blockades &Blockades::operator=(const Blockades &e) {


    return *this;
}

std::ostream& operator<<(std::ostream& stream, const OrderList& e){


    int index = 1;
    for (Order * element: e.vec_order_list) {

        stream << "This is card number: " << index << " ,the type of this card is "   << element << " " << endl;

        index++;
    }
    return stream;

}

Blockades::~Blockades() {
}

Airlifts::Airlifts() {

    set_type_id(4);
}

Airlifts::Airlifts(const Airlifts &e) {

};

Airlifts &Airlifts::operator=(const Airlifts &e) {


    return *this;
}

bool Airlifts ::validate() {
    if(this->p->toDefend().size()==0){
        return false;
    }
    // The player thas is calling this order, has a hand of cards
    vector<Card*>  _collection = this->p->getHand()->GetCollection();

    for(Card* c : _collection){
        // Compare two strings to verify
        if(c->GetType()=="Airlift")
            return true;
    }
    return false;
};

void Airlifts ::execute() {


    bool verif = this->validate();
    // Verify if the player can choose between all the teritories first
    // Check in Validate
    if(verif) {
        vector<Territory *> Territories = this->p->territoriesList;
        int size = Territories.size();
        int index = rand() % (size);
        int index2 = rand() % (size);

        if(index == index2){

            bool equal = true;

                    while(equal){
                         index2 = rand() % (size);
                         if(index != index2)
                             equal = false;
                    }
        }

        vector<Territory *> Territories2;
        for (int i = 0; i < Territories.size(); i++) {
            //target and source
            if (i == index || i == index2 )
            {
                cout <<endl;
                cout <<endl;
                Territories2.push_back(Territories[i]);
            }
        }




        //source
        int Army1 = Territories2[0]->numberOfArmies;
        if (Army1 >= 0) {
            int temp = Army1 * 1/2;

            //target
            int Army2 = Territories2[1]->numberOfArmies;

            // Adding
            Army2 = Army2 + temp;
            Territories2[1]->SetNumberOfArmies(Army2);

            // removing from source territory
            Army1 = Army1 - temp;

            Territories2[0]->SetNumberOfArmies(Army1);


            p->getOrdersList()->remove(this);


        }

    }
    else{

        p->getOrdersList()->remove(this);
    }



    this->LogMessage="Player: "+this->p->GetName()+" has called Airlift order";
    Notify(*this);
};

Airlifts::~Airlifts() {
}

bool Deploy::validate(){
    if(this->p->toDefend().size()==0){
        return false;
    }
    // checks if there are some armies to add to the reinforcement_pool
    if(!(this->p->reinforcement_pool == 0))
        return true;
};

void Deploy::execute(){


    // places some armies from reinforcement pool -> target territory owned by player ONLY IF validate is true
    if (validate()) {
        vector<Territory *> PlayerTerritories = this->p->toDefend();
        int size = PlayerTerritories.size();
        //Trying to pick the First Index always
        //int index = rand() % (size);
        int index = 0;
        vector<Territory *> Target;
        for (int i = 0; i < size; i++) {
            if (i == index)
                Target.push_back(PlayerTerritories[i]);
        }
        // Add the number of armies to the reinforcement pool


        int NumberOfReceivedArmies;

        if (this->p->reinforcement_pool > 0) {
            if (this->p->reinforcement_pool >= 10) {
                NumberOfReceivedArmies = 10;
                Target[0]->numberOfArmies += 10; //deploys 10 armies
                this->p->reinforcement_pool -= 10;
            } else {

                Target[0]->numberOfArmies += this->p->reinforcement_pool;
                this->p->reinforcement_pool -= this->p->reinforcement_pool;
            }
        }




        p->getOrdersList()->remove(this);

        this->LogMessage="Player: "+this->p->GetName()+" has called deploy order";
        Notify(*this);
    } else{

        p->getOrdersList()->remove(this);
    }
};
string Deploy::stringToLog() {
   return "DEPLOY ORDER LOG:"+LogMessage+"\n";
}
string Advance::stringToLog() {
    return "ADVANCE ORDER LOG:"+LogMessage+"\n";
}
string Bombs::stringToLog() {
    return "BOMB ORDER LOG:"+LogMessage+"\n";
}
string Blockades::stringToLog() {
    return "BLOCKADE ORDER LOG:"+LogMessage+"\n";
}
string Airlifts::stringToLog() {
    return "AIRLIFT ORDER LOG:"+LogMessage+"\n";
}
string Negotiate::stringToLog() {
    return "NEGOTIATE ORDER LOG:"+LogMessage+"\n";
}



void Order::setDeck(Deck * deck) {
    this->deck = deck;
}

void Advance::execute() {


    bool validate = this->validate();

    if(validate) {
        // Getting Source from one country
        vector<Territory *> PlayerTerritories = this->p->toDefend();

        // Getting Enemy Territory that is Adjacent
        vector<Territory *> PlayerTerritoriesAttack = this->p->toAttack();
        if(this->p->toAttack().size()==0){
            p->getOrdersList()->remove(this);
            return;
        }

        PlayerTerritories.size();

        // Check if the territories are adjacent
        int size = PlayerTerritories.size();
        int size2 = PlayerTerritoriesAttack.size();
        //Forcing the Territorie to be the strongest Territory

        vector<Territory *> Source;

        int index = 0;
bool checkers= false;
        // Getting the source Territory
        for (int i = 0; i < size&&!checkers; i++) {
            // Adding Source Territory
            if ( (PlayerTerritories[i]->numberOfArmies != 0)){

                for(int j=0;j<this->p->territoriesList.size()&&!checkers;j++){
                    bool inside=false;
                    for(int z=0;z<PlayerTerritories[i]->edges.size();z++){
                        if(PlayerTerritories[i]->edges[z]->number==this->p->territoriesList[j]->number){
                            inside=true;
                        }
                    }
                    if(!inside){
                        checkers=true;
                        Source.push_back(PlayerTerritories[i]);
                        break;
                    }


                }

            }

        }
        if(Source.size() == 0)
        {
            cout << "All territories have 0 armies, this player cannot attack" << endl;
            this->p->orders->remove(this);
            return;
        }

        int index2 = rand() % (size2);





        // Source Territory
        PlayerTerritories[0];

        // Now get the Adjacent  territories We need to make sure that it is also an enemy territory

        vector<Territory *> Neighboors ;
        int z=0;
for(int i=0;i<Source.size();i++) {
    Neighboors = Source[i]->edges;
    for (Territory *t:this->p->territoriesList) {
        for (Territory *t2:Neighboors) {
            if (t2->number == t->number) {
                Neighboors.erase(Neighboors.begin() + z);
            } else {
                z++;
            }
        }
        z = 0;
    }
    if(Neighboors.size()!=0){
        break;
    }
}

        int index3=0;
        if(Neighboors.size()!=0) {

            int size3 = Neighboors.size();
             index3 = rand() % (size3);
        }else{
            p->getOrdersList()->remove(this);
            return;
        }

        // Now get the Target Territory from the List of Neighboors
        // We also check if it is also an ennemy territory
        int count = 0;
        for (Territory *t: Neighboors) {
            if (count == index3){
                Source.push_back(t);
                break;
            }

            count++;
        }

        // how to verify if they both belong to the same player ?
        bool Adjacent = true;
        bool BothBelongToPlayer = false;
        bool DiplomacyOrder = false;
        // Verifying if a Diplomacy order has been made between the two players

        if(this->p->negotiate == true){

            Player * enemy = this->p->enemynottoattack;

            //Check if attack Source Territory belongs to Player and target territory to enemy

            vector<Territory*> OwnTerritories = this->p->territoriesList;
            vector<Territory*> EnemyTerritories = enemy->territoriesList;

            bool SourceT = false;
            bool Target = false;


            for(Territory * t : OwnTerritories){

                if(t->number == Source[0]->number)
                    SourceT = true;
            }

            for(Territory * t : EnemyTerritories){

                if(t->number == Source[1]->number)
                    Target = true;
            }

            if(SourceT && Target)
                cout<<"There is a negotiate order between the two players involved "
                      "in this advance manoeuver , there will be no attack between "
                    << Source[0]->name << " and " << Source[1] ->name;

            this->p->negotiate = false;
            enemy->negotiate = false;
        }

        // Now to  Verify if the Target territory  belongs to the player as well
        for (int i = 0; i < size; i++) {

            if (PlayerTerritories[i]->number == Source[1]->number)
                BothBelongToPlayer = true;
        }


        //Because the Aggressive Player does not need to move armies from The Strongest territory
        /*
           * We need to verify here if the Attacked Player is the neutral Player
           * Then we turn it into an Aggressive Player
           *
           */
        int PlayerIndex = 0;
        for (Player *p: this->ListOfPlayers) {
            for (Territory *t: p->territoriesList) {
                if (t->number == Source[1]->number){

                    // Checking if the Player is a Neutral Player then we shift its type to Aggressive
                    if(p->NeutralPlayer){

                        // Using the Assignment Operator It will return a deep copy as an aggressive Player;

                        /*

*/

                        p->SetStrategy(new AggressivePlayer(p));

                        // Specifying that this it is no longer a Neutral Player

                    }
                }
            }
            PlayerIndex++;
        }

        if (Adjacent && BothBelongToPlayer == false ) {


            // Source Territory army Supply
            int AttackerArmy = Source[0]->numberOfArmies;
            // Target Territory army supply
            int DefenseArmy = Source[1]->numberOfArmies;




            bool defeatedTarget = true;
            cout << "During attack, attacker armies are " << AttackerArmy << " and Defender armies " << DefenseArmy
                 << endl;
            if(AttackerArmy==0){
                p->getOrdersList()->remove(this);
                return;
            }
            if(DefenseArmy==0){
                cout << "The Target territory has lost all its territories the source player will take over"
                     << endl;
                // Source Territory
                Source[0];

                // Loop through the list of players and locate the player that has this territory
                //Then loop  through the territory of each player and locate the specific player
                for (Player *p: this->ListOfPlayers) {
                    for (Territory *t: p->territoriesList) {
                        if (t->number == Source[1]->number)
                            //Removing the Territories
                            p->RemoveTerritory(t);
                    }

                }

                // Now we add this new Conquered Territory to the source Player
                this->p->territoriesList.push_back(Source[1]);
                cout << "This player has advanced and conquered a new territory " << endl;
                cout << "--------------------------------------------------- " << endl;
                cout << "--------------------------------------------------- " << endl;
                cout << endl;
                cout << (this->p->GetName()) << endl;
                cout << "--------------------------------------------------- " << endl;
                cout << "--------------------------------------------------- " << endl;
                cout << endl;
                cout << "The Source territory is" << endl;
                cout << *Source[0] << endl;
                cout << "The added territory is" << endl;
                cout << *Source[1] << endl;

                //Attacker armies leaving the source territory
                if (Source[0]->numberOfArmies > 0) {
                    if (Source[0]->numberOfArmies >= AttackerArmy)
                        Source[0]->numberOfArmies -= AttackerArmy;
                    else
                        Source[0]->numberOfArmies = 0;
                } else if (Source[0]->numberOfArmies <= 0)
                    Source[0]->numberOfArmies = 0;

                // We need to remove this target Territory from the Target Player list
                // and add it to the source Player list
                // Target Territory
                //Attacking Armies occupying the new Territories
                Source[1]->numberOfArmies += AttackerArmy;

                //Then player needs to Pick one Card From the Deck
                // Player that issues this order picks a new Card from the DECK
                this->p->hand->Add((this->deck->draw()));
                this->p->orders->remove(this);
                return;
            }
            for (int i = 1; i <= AttackerArmy; i++) {
                int value1 = rand() % 10 + 1;     // value1 in the range 1 to 10
                int value2 = rand() % 10 + 1;     // value2 in the range 1 to 10

                if (DefenseArmy <= 0) {
                    cout << "The Target territory has lost all its territories the source player will take over"
                         << endl;
                    // Source Territory
                    Source[0];

                    // Loop through the list of players and locate the player that has this territory
                    //Then loop  through the territory of each player and locate the specific player
                    for (Player *p: this->ListOfPlayers) {
                        for (Territory *t: p->territoriesList) {
                            if (t->number == Source[1]->number)
                                //Removing the Territories
                                p->RemoveTerritory(t);
                        }

                    }

                    // Now we add this new Conquered Territory to the source Player
                    this->p->territoriesList.push_back(Source[1]);
                    cout << "This player has advanced and conquered a new territory " << endl;
                    cout << "--------------------------------------------------- " << endl;
                    cout << "--------------------------------------------------- " << endl;
                    cout << endl;
                    cout << (this->p->GetName()) << endl;
                    cout << "--------------------------------------------------- " << endl;
                    cout << "--------------------------------------------------- " << endl;
                    cout << endl;
                    cout << "The Source territory is" << endl;
                    cout << *Source[0] << endl;
                    cout << "The added territory is" << endl;
                    cout << *Source[1] << endl;

                    //Attacker armies leaving the source territory
                    if (Source[0]->numberOfArmies > 0) {
                        if (Source[0]->numberOfArmies >= AttackerArmy)
                            Source[0]->numberOfArmies -= AttackerArmy;
                        else
                            Source[0]->numberOfArmies = 0;
                    } else if (Source[0]->numberOfArmies <= 0)
                        Source[0]->numberOfArmies = 0;

                    // We need to remove this target Territory from the Target Player list
                    // and add it to the source Player list
                    // Target Territory
                    //Attacking Armies occupying the new Territories
                    Source[1]->numberOfArmies += AttackerArmy;

                    //Then player needs to Pick one Card From the Deck
                    // Player that issues this order picks a new Card from the DECK
                    this->p->hand->Add((this->deck->draw()));
                    break;
                }else if (AttackerArmy <= 0) {

                    cout << "The attacker has lost all its territories and the defender will keep its territory" << endl;
                    break;
                }

                    // 60% chance that value 1 is from 1 to 6
                    //70% chance that value 2 is from 1 to 7
                else if (value1 <= 6 && value2 <= 7) {
                    // This means there is attack and Defense happening
                    // To determine who wins we compare the two values
                    AttackerArmy--;

                }
                else if (value1 > 6 && value2 <= 7) {
                    AttackerArmy--;
                    //Dense wins
                }
                else if (value1 <= 6 && value2 > 7) {
                    DefenseArmy--;
                    //Attacks wins
                }
            }

            if(DefenseArmy>0){
                if(AttackerArmy>=0)
                    Source[0]->numberOfArmies=AttackerArmy;

                Source[1]->numberOfArmies=DefenseArmy;

            }
            cout << "The defender armies are not 0 " << endl;
            cout << "The source territory" << endl;
            cout << *Source[0] << endl;
            cout << "The Target territory" << endl;
            cout << *Source[1] << endl;

            //Updating the attacking and defending Armies
            Source[0]->numberOfArmies = AttackerArmy;
            // We need to remove this target Territory from the Target Player list
            // and add it to the source Player list
            // Target Territory
            //Attacking Armies occupying the new Territories
            Source[1]->numberOfArmies = DefenseArmy;

        }
        // Botth Territories Belong to the same Player
        if (Adjacent && BothBelongToPlayer && this->p->AgressivePlayer == false) {
            cout << "The two territories belong to the same player the armies will move" << endl;

            cout << "This is before moving " << endl;
            cout << "-------------------------------------" << endl;
            cout << "-------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << *Source[0] << endl;
            cout << *Source[1] << endl;
            cout << "-------------------------------------" << endl;
            cout << "-------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << "This is before moving " << endl;

            // Moving 50% of the army units
            int MovingArmies = Source[0]->numberOfArmies * 0.5;


            if (MovingArmies > 0) {
                if (Source[0]->numberOfArmies >= MovingArmies){
                    Source[0]->numberOfArmies -= MovingArmies;
                    Source[1]->numberOfArmies += MovingArmies;
                }else{
                    int temp= Source[0]->numberOfArmies ;
                    Source[0]->numberOfArmies = 0;
                    Source[1]->numberOfArmies+=temp;
                }

            }



// Call Deploy Order on those two, or implement logic from moving to territory A to territory B

            cout << "This is after moving " << endl;
            cout << "-------------------------------------" << endl;
            cout << "-------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << *Source[0] << endl;
            cout << *Source[1] << endl;
            cout << "-------------------------------------" << endl;
            cout << "-------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << "This is after moving " << endl;
        }

        //  Check if target territory is not adjacent
        p->getOrdersList()->remove(this);
    } else{
        cout<<"There is no Advance Card for the Player who executed this order";
        p->getOrdersList()->remove(this);
    }
    this->LogMessage="Player: "+this->p->GetName()+" has called Adavnce order";
    Notify(*this);
};

bool Advance::validate(){


    bool AdvanceAttack = true;
    if(this->p->toAttack().size() ==0)
        AdvanceAttack = false;

    bool AdvanceDeploy = true;
    if(this->p->toDefend().size() ==0)
        AdvanceDeploy = false;

    if(AdvanceAttack && AdvanceDeploy ){
        return true;
    }
    else
        return false;
};


bool Bombs::validate() {
    if(this->p->toAttack().size()==0){
        return false;
    }


    vector<Card *> _collection = this->p->getHand()->GetCollection();
  cout <<" Size of the hand is " << _collection.size() << endl;
    for (Card *c: _collection) {
        // Compare two strings to verify
        cout << c->GetType() << endl;
        if (c->GetType() == "Bomb")
            return true;
    }
    return false;
};



void Bombs::execute() {

    bool verifie = this->validate();
    // Verify if the player can choose between all the teritories first
    // Check in Validate
    if (verifie) {
        vector<Territory *> Territories = this->p->toAttack();
        int size = Territories.size();
        int index = rand() % (size);


        vector<Territory *> Territories2;
        for (int i = 0; i < Territories.size(); i++) {
            //target and source
            if (i == index) {
                cout << endl;
                cout << "Random num 1 is " << index << endl;
                cout << "i is " << i << endl;
                Territories2.push_back(Territories[i]);
            }
        }
        cout << "Territory to bomb " << endl;
        cout << *Territories2[0] << endl;


        int Army2 = 0;

        //dividing number of armies of the target in 2
        Army2 = Territories2[0]->numberOfArmies / 2;

        Territories2[0]->SetNumberOfArmies(Army2);
        cout<< "Territory after being bombed" << endl;
        cout << "---------------------------------------"<< endl;
        cout << *Territories2[0] << endl;
        cout << "---------------------------------------"<< endl;
        cout << "your enemy number is now " << Army2 << endl;

        p->getOrdersList()->remove(this);

    }  else{
        cout<<"There is no Bomb Card for the Player who executed this order";
        p->getOrdersList()->remove(this);
    }



    this->LogMessage="Player: "+this->p->GetName()+" has called Bomb order";
    Notify(*this);
}


void Negotiate::execute() {

    //Add implementation
    // targets enemy player
    //player issuing and enemy cannot attack each other
    //if target is player issuing then its invalid
    //If the target is an enemy player, then the effect is that any attack that may be declared between territories
    //of the player issuing the negotiate order and the target player will result in an invalid order.
    bool verif = this->validate();
    if (verif) {
        vector<Player *> Players= this->ListOfPlayers;



        int size = Players.size();
        int index = rand() % (size);


        // Player verification

        int count =0;

        // Getting the index of the player who is calling the order
        int PlayerIndex =0;
        for(Player * p :Players ){

            if(p->GetName() == this->p->GetName() && p->id == this->p->id)
                PlayerIndex = count;

            count++;
        }

// Making sure that we are selecting two players
        if (index == PlayerIndex) {

            bool equal = true;

            while (equal) {
                index = rand() % (size);
                if (index != PlayerIndex)
                    equal = false;
            }
        }

        vector<Player *> Players2;
        for (int i = 0; i < Players.size(); i++) {
            //Enemy Player
            if (i == index ) {
                cout << endl;
                cout << endl;
                Players2.push_back(Players[i]);
            }
        }
        cout << "Printing the Enemy Player for Negotiate " << endl;
        cout << *Players2[0] << endl;


        // Stating that the two players will not attack each other , verify in advance
        Players2[0]->setNegotiate(this->p);
        this->p->setNegotiate(Players2[0]);
        p->getOrdersList()->remove(this);
        //return the card to deck

        // Make sure to verify this in advance order
       cout<< "The player " << this->p->_name << " and the player " << Players2[0]->_name << " will not attack each other next turn";

    }
    else{
        cout<<"There is no Airlift Card for the Player who executed this order";
        p->getOrdersList()->remove(this);
    }
    this->LogMessage="Player: "+this->p->GetName()+" has called negotiate order";
    Notify(*this);
};
bool Negotiate::validate() {
    if(this->p->territoriesList.size()==0){
        return false;
    }
    //Add implementation
    vector<Card *> _collection = this->p->getHand()->GetCollection();

    for (Card *c: _collection) {
        // Compare two strings to verify
        if (c->GetType() == "Diplomacy")
            return true;
    }
    return false;
};

bool Blockades::validate(){
    //Add implementation
    if(this->p->toDefend().size()==0){
        return false;
    }
    vector<Card*>  _collection = this->p->getHand()->GetCollection();

    for(Card* c : _collection){
        // Compare two strings to verify
        if(c->GetType()=="Blockade")
            return true;
    }
    return false;
};

void Order::SetListOfPlayers(vector<Player *> list){
    this->ListOfPlayers = list;
}


void Blockades::execute(){

    bool verif = this->validate();
    // Verify if the player can choose between all the teritories first
    // Check in Validate
    if(verif) {
        vector<Territory *> Territories = this->p->toDefend();
        int size = Territories.size();
        int index = rand() % (size);

        vector<Territory *> Territories2;
        for (int i = 0; i < Territories.size(); i++) {
            //target and source
            if (i == index  )
            {
                       // Picking a territory that belongs to the player
                Territories2.push_back(Territories[i]);
            }
        }
        cout <<"Selected Territory  for blockade" << endl;
        cout <<  *Territories2[0] << endl;
     cout<< "----------------------------------------" << endl;
 cout <<endl;
        cout <<endl;
        cout<< "Printing the Original Player Territories before blockade" << endl;
        cout<<"----------------------------------------"<<endl;
        for(Territory * t : this->p->territoriesList){
            cout << *t << endl;
        }
        cout<<"----------------------------------------"<<endl;
        cout<<"----------------------------------------"<<endl;




        int Army1 = Territories2[0]->numberOfArmies;

        int Army2 = Army1 * 2;
        // Doubling the number of armies of this territory
        // Adding
        Territories2[0]->SetNumberOfArmies(Army2);

//Note neutral player
        cout<< "Army1 is " << Army1 << endl;

        vector<Player * > ListofPlayers = this->ListOfPlayers;
            vector<Player *> Neutral;
        for(Player *  p :ListofPlayers  ){
            // Transfering Ownerhsip
            if(p->GetName() == "Neutral"){
                // Removing the Territory from the player list of Terroteries
                this->p->RemoveTerritory(Territories2[0]);
                Neutral.push_back(p);
                // Ading the Terretorie to the Neutral Player
                 p->addTerritory(Territories2[0]);
            }
        }


        cout<< "Printing the Original Player Territories after blockade" << endl;
        cout<<"----------------------------------------"<<endl;
       for(Territory * t : this->p->territoriesList){
           cout << *t << endl;
       }
        cout<<"----------------------------------------"<<endl;
        cout<<"----------------------------------------"<<endl;

        cout<< endl;
        cout<< endl;
        cout<< "Printing the Neutral Player Territories after blockade" << endl;
        cout<<"----------------------------------------"<<endl;

        cout<<"----------------------------------------"<<endl;
        cout<<"----------------------------------------"<<endl;

        p->getOrdersList()->remove(this);
    } else{
        cout<<"There is no Blockade Card for the Player who executed this order";
        p->getOrdersList()->remove(this);
    }

    this->LogMessage="Player: "+this->p->GetName()+" has called blockade order";
    Notify(*this);
};

Negotiate::Negotiate() {

    set_type_id(5);
}

Negotiate::~Negotiate() {
}

vector<Order *>  OrderList::get_order_list_new() {

    return vec_order_list;
}


void OrderList::Add(Order * o){
    LogMessage="Order:"+o->get_type()+" was just issued";
   this->vec_order_list.push_back(o);
    Notify(*this);
}
string OrderList::stringToLog() {
    return "ORDERLIST ISSUEORDER LOG:"+LogMessage;
}

Negotiate::Negotiate(const Negotiate &e) {

};

Negotiate &Negotiate::operator=(const Negotiate &e) {


    return *this;
}
