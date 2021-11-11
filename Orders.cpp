
#include "Orders.h"
#include <cstdlib>
#include <ctime>

//Order&Order ::operator = (const Order&O)
//{
//
//}

Order::Order() {
    // cout << "Inside default constructor Order class" << endl;

    bool valid;
    vector<string> vec_type2 = {"deploy", "advance", "Bombss", "Blockadess", "Airliftss", "negotiate"};
    int type_id;


    this->valid = true;
    this->type_id = 1;
    this->vec_type1 = vec_type2;

}


Order::Order(Player* player, Map * map) {

    cout << "Inside parameterized constructors for value semantics" << endl;

}
void Order::SetPlayer(Player *player) {

    //Assignment one pointer to another, memory leaks ??
    this->p = player;
}

void Order::SetMap(Map *map) {

    //Assignment one pointer to another, memory leaks ??
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
    // cout << "Inside default constructor Order class" << endl;


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
    cout << "888888" << endl;
    cout << "Right here" << endl;
    cout << "888888" << endl;

    int size= e.size();
    cout << "The vector list size is " <<  size << endl;
    for(Order * element :e ){
        cout << "888888" << endl;
        cout << "Right here" << endl;
        cout << "888888" << endl;
        bool valids = element->get_valid();
        vector<string> vec_types1 = element->get_List();
        int type_ids= element->get_ID();
        cout << "888888" << endl;
        cout << "Right here" << endl;
        cout << "888888" << endl;
        cout << valids<< endl;
        cout << type_ids<< endl;

        /**
         Deploy
-Advance
-Bombs
-Blockades
-Airlifts
-Negotiate
         */



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
    cout << "Inside Print All Method  of Order" << endl;

    cout << "Is it valid" << this->valid << endl;
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

    cout << "Inside stream operator  of Order" << endl;

    stream << "Is it valid" << e.valid << endl;
    int index = 1;
    for (auto element: e.vec_type1) {

        stream << "This is order number " << index << " with type" << element << endl;
        index++;
    }
    stream << "The type ID is " << e.type_id << endl;

    return stream;
}

Order::~Order() {
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
            cout << "  deleting the order: " << oneOrder->get_type() << endl;
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
    cout << "Inside default constructor Deploy class" << endl;
    set_type_id(0);
}

Deploy::Deploy(const Deploy &e) {
    cout << "Inside copy constructor of Deploy" << endl;
};

Deploy &Deploy::operator=(const Deploy &e) {
    cout << "Inside operator = of Deploy" << endl;

    return *this;
}

Deploy::~Deploy() {
};

Advance::Advance() {
    cout << "Inside default constructor Advance class" << endl;
    set_type_id(1);
}

Advance::Advance(const Advance &e) {
    cout << "Inside copy constructor of Advance" << endl;
};

Advance &Advance::operator=(const Advance &e) {
    cout << "Inside operator = of Advance" << endl;

    return *this;
}

Advance::~Advance() {
}

Bombs::Bombs() {
    cout << "Inside default constructor Bombs class" << endl;
    set_type_id(2);
}

Bombs::Bombs(const Bombs &e) {
    cout << "Inside copy constructor of Bombs" << endl;
};

Bombs &Bombs::operator=(const Bombs &e) {
    cout << "Inside operator = of Bombs" << endl;

    return *this;
}

Bombs::~Bombs() {
}

Blockades::Blockades() {
    cout << "Inside default constructor Blockades class" << endl;
    set_type_id(3);
}

Blockades::Blockades(const Blockades &e) {
    cout << "Inside copy constructor of Blockades" << endl;
};

Blockades &Blockades::operator=(const Blockades &e) {
    cout << "Inside operator = of Blockades" << endl;

    return *this;
}

std::ostream& operator<<(std::ostream& stream, const OrderList& e){

    cout << "Inside stream  operator of Order List"<< endl;
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
    cout << "Inside default constructor Airlifts class" << endl;
    set_type_id(4);
}

Airlifts::Airlifts(const Airlifts &e) {
    cout << "Inside copy constructor of Airlifts" << endl;
};

Airlifts &Airlifts::operator=(const Airlifts &e) {
    cout << "Inside operator = of Airlifts" << endl;

    return *this;
}

bool Airlifts ::validate() {

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

    cout << "Executing Airlifts Order" << endl;
    bool verif = this->validate();
    // Verify if the player can choose between all the teritories first
    // Check in Validate
   //Goku
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
                cout << "Random num 1 is " << index <<endl;
                cout << "i is " << i<<endl;
                cout << "Random num 2 is " << index2<<endl;
                cout <<endl;
                Territories2.push_back(Territories[i]);
            }
        }
cout <<"Ter 1 " << endl;
      cout <<  *Territories2[0] << endl;
        cout <<"Ter 2 " << endl;
        cout <<  *Territories2[1] << endl;

        int Army1 = 0;

        int Army2 = 0;


        //source
        Army1 = Territories2[0]->numberOfArmies;


        int temp = Army1 * 0.3;

        //target
        Army2 = Territories2[1]->numberOfArmies;

        cout<< "Army1 before change " << Army1 << endl;

        cout<< "Army2 before change " << Army2 << endl;


        Army2 = Army2 + temp;



        // Adding
        Territories2[1]->SetNumberOfArmies(Army2);

        Army1 = Army1 - temp;

        cout<< "Army1 is " << Army1 << endl;

        cout<< "Army2 is " << Army2 << endl;

        //substracting


        Territories2[0]->SetNumberOfArmies(Army1);
        p->getOrdersList()->remove(this);

    }
    else
        cout<<"There is no Airlift Card for the Player who executed this order";

};

Airlifts::~Airlifts() {
}

bool Deploy::validate(){
    // checks if there are some armies to add to the reinforcement_pool
    if(!this->p->reinforcement_pool == 0)
        return true;
};

void Deploy::execute(){
cout<<"Execution of Deploy order" << endl;
    // places some armies from reinforcement pool -> target territory owned by player ONLY IF validate is true
    vector<Territory *> PlayerTerritories = this->p->territoriesList;
    int size = PlayerTerritories.size();
    int index = rand() % (size);
    if (validate()) {
        vector<Territory *> Target;
        for (int i = 0; i < size; i++) {
            if (i == index)
                Target.push_back(PlayerTerritories[i]);
        }
        // Add the number of armies to the reinforcement pool
        int NumberOfReceivedArmies = this->p->reinforcement_pool*0.40;
        int NumberOfArmiesInTerritorie = Target[0]->numberOfArmies;
        int NewNumberOfArmies = NumberOfArmiesInTerritorie + NumberOfReceivedArmies;
        Target[0]->SetNumberOfArmies(NewNumberOfArmies);
        this->p->reinforcement_pool -= NumberOfReceivedArmies;
        cout << "The territory received " << NumberOfReceivedArmies<< " armies." << endl;
        cout << "We deployed to the following territory" << endl;
        cout << *Target[0] << endl;
        cout << "^^^^^^^^^^^^^^^^" <<endl;
    }
};

void Order::setDeck(Deck * deck) {
    this->deck = deck;
}

bool Advance::validate(){
    //Add implementation
  cout <<" Inside Advance Validate" << endl;
    /**
     * • If the source territory does not belong to the player that issued the order, the order is invalid.
• If the target territory is not adjacent to the source territory, the order is invalid.
• If the source and target territory both belong to the player that issued the order, the army units are moved
from the source to the target territory.
• If the target territory belongs to another player than the player that issued the advance order, an attack is
simulated when the order is executed. An attack is simulated by the following battle simulation
mechanism:
     */

    // Getting Source from one country
    vector<Territory *> PlayerTerritories = this->p->territoriesList;

// Check if the territories are adjacent

    int size = PlayerTerritories.size();
    int size2 = PlayerTerritories.size();
    int index = rand() % (size);
    int index2 = rand() % (size2);

    if(index == index2){

        bool equal = true;

        while(equal){
            index2 = rand() % (size);
            if(index != index2)
                equal = false;
        }
    }

    vector<Territory *> Source;
    // Getting the source Territory
    for(int i = 0 ; i  < size ; i++){

        if(i  == index)
            Source.push_back(PlayerTerritories[i]);
    }
    cout<<"We are here just before executing attack " << endl;
    // Source Territory
    PlayerTerritories[0];

    // Now get the Adjacent  territories
    vector<Territory *> Neighboors = Source[0]->edges;


    int size3 = Neighboors.size();
    int index3 = rand() % (size3);

    // Now get the Target Territory from the List of Neighboors
    for(int i = 0 ; i  < size3 ; i++){

        if(i  == index3)
            Source.push_back(Neighboors[i]);
    }
 // how to verify if they both belong to the same player ?



  bool Adjacent = true;
  bool BothBelongToPlayer = false;


    // Now to  Verify if the Target territory  belongs to the player as well
    for(int i = 0 ; i  < size ; i++){

        if(PlayerTerritories[i]->number ==  Source[1]->number )
        BothBelongToPlayer = true;
    }

    // Target belongs to enemy territory

    cout <<"Are the two terretory Adjacent ? " << Adjacent << " are they both to the same player ?" << BothBelongToPlayer << endl;
    if(Adjacent && BothBelongToPlayer == false ){

        cout << "We are trying an Attack" << endl;
      // 60% chance of winning if attack
      //70% of Winning if Defend
// Source Territory army Supply
       int AttackerArmy =  Source[0]->numberOfArmies;
        // Target Territory army suply
        int DefenseArmy = Source[1]->numberOfArmies;

        bool defeatedTarget = true;
for(int i = 1 ; i <= AttackerArmy ; i++ ) {
 cout <<"During attack , attacker armies are " << AttackerArmy << " and Defender armies " << DefenseArmy <<endl;
    int value1 = rand() % 10 + 1;     // value1 in the range 1 to 10
    int value2 = rand() % 10 + 1;     // value2 in the range 1 to 10

    // 60% chance that value 1 is from 1 to 6
    //70% chance that value 2 is from 1 to 7
    if (value1 <= 6 && value2 <= 7) {
        // This means there is attack and Defense happening
        // To determine who wins we compare the two values

        if (value1 > value2) {
            //The attacks win
            AttackerArmy++;
            DefenseArmy--;
        }

        if (value2 > value1) {
            DefenseArmy++;
            AttackerArmy--;
            // The defender wins
        }
    }

    if (6 < value1 && value2 <= 7) {
        DefenseArmy++;
        AttackerArmy--;
        //Dense wins
    }

    if (value1 <= 6 && value2 > 7) {
        AttackerArmy++;
        DefenseArmy--;
        //Attacks wins
    }
            if(DefenseArmy ==0){
                cout << "The Target territory has lost all its territories the source player will take over"<< endl;
                // Source Territory
                Source[0];
 //

                // Loop through the list of players and locate the player that has this territory
                //Then loop  through the territory of each player and locate the specific player
                for(Player *p : this->ListOfPlayers){
                    for(Territory * t  : p->territoriesList){
                        if(t->number ==Source[1]->number )
                            //Removing the Territories
                            p->RemoveTerritory(t);
                    }

                }

                // Now we add this new Conquered Territory to the source Player
                this->p->territoriesList.push_back(Source[1]);
                cout << "This player has advanced and conquered a new territory " << endl;
                cout << "--------------------------------------------------- " << endl;
                cout << "--------------------------------------------------- " << endl;
                cout  <<endl;
                cout << *(this->p) <<endl;
                cout << "--------------------------------------------------- " << endl;
                cout << "--------------------------------------------------- " << endl;
                cout  <<endl;
                cout << "The Source territory is" << endl;
                cout << *Source[0] << endl;
                cout << "The added territory is" << endl;
                cout << *Source[1] << endl;

                //Attacker armies leaving the source territory
                Source[0]->numberOfArmies-=AttackerArmy;
                // We need to remove this target Territory from the Target Player list
                // and add it to the source Player list
                // Target Territory
                //Attacking Armies occupying the new Territories
                Source[1]->numberOfArmies+=AttackerArmy;

                //Then player needs to Pick one Card From the Deck
                // Player that issues this order picks a new Card from the DECK
                this->p->hand->Add(*(this->deck->draw()));
                //Vegeto
            }

}

cout << "The defender armies are not 0 " << endl;
cout << *Source[0] <<endl;
cout << *Source[1] <<endl;
        //Updating the attacking and defending Armies
        Source[0]->numberOfArmies=AttackerArmy;
        // We need to remove this target Territory from the Target Player list
        // and add it to the source Player list
        // Target Territory
        //Attacking Armies occupying the new Territories
        Source[1]->numberOfArmies=DefenseArmy;

    }
    // Botth Territories Belong to the same Player
    if(Adjacent && BothBelongToPlayer ){
 cout << "The two territories belong to the same player the armies will move" << endl;

 cout << "This is before moving " << endl;
 cout << "-------------------------------------"<< endl;
 cout << "-------------------------------------"<< endl;
 cout << endl;
 cout << endl;
 cout<< *Source[0] << endl;
 cout<< *Source[1] << endl;
 cout << "-------------------------------------"<< endl;
 cout << "-------------------------------------"<< endl;
 cout << endl;
 cout << endl;
 cout << "This is before moving " << endl;

 // Moving 50% of the army units
        int MovingArmies = Source[0]->numberOfArmies*0.5;
          Source[0]->numberOfArmies -= MovingArmies;
          Source[1]->numberOfArmies += MovingArmies;
// Call Deploy Order on those two, or implement logic from moving to territory A to territory B

        cout << "This is after moving " << endl;
        cout << "-------------------------------------"<< endl;
        cout << "-------------------------------------"<< endl;
        cout << endl;
        cout << endl;
        cout<< *Source[0] << endl;
        cout<< *Source[1] << endl;
        cout << "-------------------------------------"<< endl;
        cout << "-------------------------------------"<< endl;
        cout << endl;
        cout << endl;
        cout << "This is after moving " << endl;
    }

    //  Check if target territory is not adjacent
    p->getOrdersList()->remove(this);
    return true;
};

void Advance::execute(){
    cout<<"Execution of Advance" << endl;
    this->validate();
    //Add implementation
};


bool Bombs::validate(){
    //ComeBack
    cout << "executing Bomb Order" << endl;
    bool verif = false;
    // The player thas is calling this order, has a hand of cards
    vector<Card*>  _collection = this->p->getHand()->GetCollection();

    for(Card* c : _collection){
        // Compare two strings to verify
        if(c->GetType()=="Bomb")
             verif = true;
    }
    //Verifying if the player has the bomb Card

    // Verify if the player can choose between all the teritories first
    // Check in Validate

    if (verif) {
        vector<Territory *> PlayerTerritories = this->p->territoriesList;
        vector<Territory *> MapTerritories = this->m->map;

        int sizeofmap = MapTerritories.size();
        int Source = PlayerTerritories.size();
        //Extract form the map
        //push the terroritey to a list or store it
        // loop through the map and compare the numbers
        bool IsToplayer = false;

        for (int v = 0; sizeofmap; v++) {

            if (PlayerTerritories[0]->number == PlayerTerritories[v]->number) {
                return false;
            } else
                execute();


        }
    }
};

void Bombs::execute(){
    cout<<"after bombing the enemy has now "<<
        targetted_territory->get_numberOfArmies()/2 << " armies" << endl;


    p->getOrdersList()->remove(this);
};

bool Negotiate::validate(){
    //Add implementation
    return true;
};

void Negotiate::execute(){
    cout<<"Execution of Negotiate" << endl;
    //Add implementation
};

bool Blockades::validate(){
    //Add implementation
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
    cout<<"Execution of Blockades" << endl;
    //Add implementation
    bool verif = this->validate();
    // Verify if the player can choose between all the teritories first
    // Check in Validate

    if(verif) {

        vector<Territory *> Territories = this->p->territoriesList;
        int size = Territories.size();
        int index = rand() % (size);

        vector<Territory *> Territories2;
        for (int i = 0; i < Territories.size(); i++) {
            //target and source
            if (i == index  )
            {

                Territories2.push_back(Territories[i]);
            }
        }
        cout <<"Selected Territory for bloackde " << endl;
        cout <<  *Territories2[0] << endl;

        int Army1 = 0;

        int Army2=0;
        //source
        Army1 = Territories2[0]->numberOfArmies;

        int temp = Army1 * 2;

        //target

        Army1 = temp;

        // Adding
        Territories2[0]->SetNumberOfArmies(Army1);
        //
//Note neutral player
        cout<< "Army1 is " << Army1 << endl;
        if(!neutral){
            Territory *t1=new Territory("hhh",1,2,6);
            Territory *t2=new Territory("testttt",1,2,9);
            vector<Territory *> territoriesList={t1, t2};

            //creating arbitary list of orders
            OrderList orderList;

            bool a = true;
            bool b = true;

            int a1 = 3;
            int a2 = 4;

            vector<string> list1 = {"ronaldo"};
            vector<string> list2 = {"messi"};
            vector<string> list3 = {"pepe"};


            Airlifts * OpOINTER1 = new Airlifts(a,list1,a1);

            Airlifts * OpOINTER2 = new Airlifts(b,list2,a2);
            //Order o1,o2;
            //Order * OpOINTER1 = &o1;
            //Order * OpOINTER2 = &o2;
            orderList.set_order_list(OpOINTER1);
            orderList.set_order_list(OpOINTER2);
            OrderList * ListPointer = new OrderList;
            ListPointer = &orderList;

            //creating arbitary card and then hand
            Airlift bomb2;

            Card* PointerBomb2  =& bomb2;
            vector<Card *>  MyCollectionOfCards2 ;

            MyCollectionOfCards2.push_back(PointerBomb2);

            //  MyCollectionOfCards2.push_back(PointerBlockade2);
            cout << "Blockades Check 3 " << endl;

            Hand ZaHande2 (MyCollectionOfCards2);
            cout<<"hello2"<<endl;
            Hand *hdptr=&ZaHande2;
            Player   p1=  Player(Territories2, (ListPointer), hdptr, " Neutral  ");

            Player* ptr = &p1;
            //Remove ownership from the actual  player and add it to neutral

            int inDex = 0;
            for(Territory * t : Territories){
                if(t->number ==Territories2[0]->number )
                    Territories.erase(Territories.begin()+inDex);
                    inDex++;
            }
            //Prnt the list
            //Remove the territory from the vector list of Player
            // Add Neutral Player to the lsit of players
            this->ListOfPlayers.push_back(ptr);
            cout<<"end of blockade execute"<<endl;
        }


        //substracting

    }
    else
        cout<<"There is no Blockade Card for the Player who executed this order";
};

Negotiate::Negotiate() {
    cout << "Inside default constructor Negotiate class" << endl;
    set_type_id(5);
}

Negotiate::~Negotiate() {
}

vector<Order *>  OrderList::get_order_list_new() {
    cout<< "Inside Order List get order method" << endl;
    return vec_order_list;
}


void OrderList::Add(Order * o){
    this->set_order_list(o);
}

Negotiate::Negotiate(const Negotiate &e) {
    cout << "Inside copy constructor of Negotiate" << endl;
};

Negotiate &Negotiate::operator=(const Negotiate &e) {
    cout << "Inside operator = of Negotiate" << endl;

    return *this;
}
