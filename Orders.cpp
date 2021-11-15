
#include "Orders.h"
#include <cstdlib>
#include <ctime>


Order::Order() {
    // cout << "Inside default constructor Order class" << endl;

    bool valid;
    vector<string> vec_type2 = {"Deploy", "Advance", "Bombs", "Blockadess", "Airliftss", "negotiate"};
    int type_id;


    this->valid = true;
    this->type_id = 1;
    this->vec_type1 = vec_type2;

}


Order::Order(Player *player, Map *map) {

    cout << "Inside parameterized constructors for value semantics" << endl;

}

void Order::SetPlayer(Player *player) {

    //Assignment one pointer to another, memory leaks ??
    this->p = player;
}

void Order::SetMap(Map *map) {

    //Assignment one pointer to another, memory leaks ??
    this->m = map;
}

void Order::set_type_id(int num) {

    this->type_id = num;
}

void Order::set_valid(bool valid) {

    this->valid = valid;
}

void Order::set_vec_type1(vector<string> vec_type1) {

    this->vec_type1 = vec_type1;
}

OrderList::OrderList() {
    // cout << "Inside default constructor Order class" << endl;


}

Airlifts::Airlifts(bool valids, vector<string> vec_types1, int type_ids) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}

Bombs::Bombs(bool valids, vector<string> vec_types1, int type_ids) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}

Deploy::Deploy(bool valids, vector<string> vec_types1, int type_ids) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}

Advance::Advance(bool valids, vector<string> vec_types1, int type_ids) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}

Negotiate::Negotiate(bool valids, vector<string> vec_types1, int type_ids) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}

Blockades::Blockades(bool valids, vector<string> vec_types1, int type_ids) {

    this->set_valid(valids);
    this->set_vec_type1(vec_types1);
    this->set_type_id(type_ids);

}

OrderList::OrderList(vector<Order *> e) {
    cout << "888888" << endl;
    cout << "Right here" << endl;
    cout << "888888" << endl;

    int size = e.size();
    cout << "The vector list size is " << size << endl;
    for (Order *element: e) {
        cout << "888888" << endl;
        cout << "Right here" << endl;
        cout << "888888" << endl;
        bool valids = element->get_valid();
        vector<string> vec_types1 = element->get_List();
        int type_ids = element->get_ID();
        cout << "888888" << endl;
        cout << "Right here" << endl;
        cout << "888888" << endl;
        cout << valids << endl;
        cout << type_ids << endl;

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
OrderList &OrderList::operator=(const OrderList &e) {
    for (Order *element: (e.vec_order_list)) {
        bool valid = element->get_valid();
        vector<string> vec_type1 = element->get_List();
        int type_id = element->get_ID();

        string type = element->type;
        //STOP1
        if (type == "Airlifts") {
            Order *T1 = new Airlifts(valid, vec_type1, type_id);
            this->vec_order_list.push_back(T1);
        }

        if (type == "Deploy") {
            Order *T1 = new Deploy(valid, vec_type1, type_id);
            this->vec_order_list.push_back(T1);
        }

        if (type == "Bombs") {
            Order *T1 = new Bombs(valid, vec_type1, type_id);
            this->vec_order_list.push_back(T1);
        }

        if (type == "Negotiate") {
            Order *T1 = new Negotiate(valid, vec_type1, type_id);
            this->vec_order_list.push_back(T1);
        }

        if (type == "Blockades") {
            Order *T1 = new Blockades(valid, vec_type1, type_id);
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
    cout << "---------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << *(this->p);
    cout << endl;
    cout << endl;
    cout << "---------------------------------" << endl;

    cout << "Now we will print the Map Used in the Game" << endl;
    cout << "---------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << *(this->m);
    cout << endl;
    cout << endl;
    cout << "---------------------------------" << endl;
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
Order::Order(const Order &O) {
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
    return this->vec_type1;
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
    int type_id = i->get_ID();

    string type = i->type;
    //STOP2
    if (type == "Airlifts") {
        Order *T1 = new Airlifts(valid, vec_type1, type_id);
        this->vec_order_list.push_back(T1);
    }

    if (type == "Deploy") {
        Order *T1 = new Deploy(valid, vec_type1, type_id);
        this->vec_order_list.push_back(T1);
    }

    if (type == "Bombs") {
        Order *T1 = new Bombs(valid, vec_type1, type_id);
        this->vec_order_list.push_back(T1);
    }

    if (type == "Negotiate") {
        Order *T1 = new Negotiate(valid, vec_type1, type_id);
        this->vec_order_list.push_back(T1);
    }

    if (type == "Blockades") {
        Order *T1 = new Blockades(valid, vec_type1, type_id);
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

std::ostream &operator<<(std::ostream &stream, const OrderList &e) {

    cout << "Inside stream  operator of Order List" << endl;
    int index = 1;
    for (Order *element: e.vec_order_list) {

        stream << "This is card number: " << index << " ,the type of this card is " << element << " " << endl;

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

bool Airlifts::validate() {
    if (this->p->toDefend().size() == 0) {
        return false;
    }
    // The player thas is calling this order, has a hand of cards
    vector<Card *> _collection = this->p->getHand()->GetCollection();

    for (Card *c: _collection) {
        // Compare two strings to verify
        if (c->GetType() == "Airlift")
            return true;
    }
    return false;
};

void Airlifts::execute() {

    cout << "Executing Airlifts Order" << endl;
    bool verif = this->validate();
    // Verify if the player can choose between all the territories first
    // Check in Validate
    //Goku
    if (verif) {
        vector<Territory *> Territories = this->p->territoriesList;
        int size = Territories.size();
        int index = rand() % (size);
        int index2 = rand() % (size);

        if (index == index2) {

            bool equal = true;

            while (equal) {
                index2 = rand() % (size);
                if (index != index2)
                    equal = false;
            }
        }

        vector<Territory *> Territories2;
        for (int i = 0; i < Territories.size(); i++) {
            //target and source
            if (i == index || i == index2) {
                cout << endl;
                cout << endl;
                Territories2.push_back(Territories[i]);
            }
        }
        cout << "Source Territory before change  " << endl;
        cout << *Territories2[0] << endl;
        cout << "Target Territory before change " << endl;
        cout << *Territories2[1] << endl;


        //source
        int Army1 = Territories2[0]->numberOfArmies;
        if (Army1 >= 0) {
            int temp = Army1 * 1 / 2;

            //target
            int Army2 = Territories2[1]->numberOfArmies;

            // Adding
            Army2 = Army2 + temp;
            Territories2[1]->SetNumberOfArmies(Army2);

            // removing from source territory
            Army1 = Army1 - temp;

            Territories2[0]->SetNumberOfArmies(Army1);

            cout << "Source Territory after change  " << endl;
            cout << *Territories2[0] << endl;
            cout << "Target Territory after change " << endl;
            cout << *Territories2[1] << endl;
            p->getOrdersList()->remove(this);


        }

    } else {
        cout << "There is no Airlift Card for the Player who executed this order";
        p->getOrdersList()->remove(this);
    }


    this->LogMessage = "Player: " + this->p->GetName() + " has called Airlift order";
    Notify(*this);
};

Airlifts::~Airlifts() {
}

bool Deploy::validate() {
    if (this->p->toDefend().size() == 0) {
        return false;
    }
    // checks if there are some armies to add to the reinforcement_pool
    if (!(this->p->reinforcement_pool == 0))
        return true;
};

void Deploy::execute() {

    cout << "Execution of Deploy order" << endl;
    // places some armies from reinforcement pool -> target territory owned by player ONLY IF validate is true
    if (validate()) {
        vector<Territory *> PlayerTerritories = this->p->toDefend();
        int size = PlayerTerritories.size();
        int index = rand() % (size);
        vector<Territory *> Target;
        for (int i = 0; i < size; i++) {
            if (i == index)
                Target.push_back(PlayerTerritories[i]);
        }
        // Add the number of armies to the reinforcement pool
        cout << "This territory will receive armies because of a deploy order" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "---------------------------------------------" << endl;
        cout << *Target[0] << endl;
        cout << "---------------------------------------------" << endl;
        cout << "---------------------------------------------" << endl;

        int NumberOfReceivedArmies;

        if (this->p->reinforcement_pool > 0) {
            if (this->p->reinforcement_pool >= 10) {
                NumberOfReceivedArmies = 10;
                Target[0]->numberOfArmies += NumberOfReceivedArmies; //deploys 10 armies
                this->p->reinforcement_pool -= NumberOfReceivedArmies;
            } else {
                NumberOfReceivedArmies = this->p->reinforcement_pool;
                Target[0]->numberOfArmies += NumberOfReceivedArmies;
                this->p->reinforcement_pool -= NumberOfReceivedArmies;
            }
        }

        cout << "The territory received " << NumberOfReceivedArmies << " armies." << endl;
        cout << "We deployed to the following territory" << endl;
        cout << *Target[0] << endl;


        p->getOrdersList()->remove(this);

        this->LogMessage = "Player: " + this->p->GetName() + " has called deploy order";
        Notify(*this);
    } else {
        cout << "There is no Deploy order for the Player who executed this order";
        p->getOrdersList()->remove(this);
    }
};

string Deploy::stringToLog() {
    return "DEPLOY ORDER LOG:" + LogMessage;
}

string Advance::stringToLog() {
    return "ADVANCE ORDER LOG:" + LogMessage;
}

string Bombs::stringToLog() {
    return "BOMB ORDER LOG:" + LogMessage;
}

string Blockades::stringToLog() {
    return "BLOCKADE ORDER LOG:" + LogMessage;
}

string Airlifts::stringToLog() {
    return "AIRLIFT ORDER LOG:" + LogMessage;
}

string Negotiate::stringToLog() {
    return "NEGOTIATE ORDER LOG:" + LogMessage;
}


void Order::setDeck(Deck *deck) {
    this->deck = deck;
}

void Advance::execute() {
    cout << " Inside Advance Validate" << endl;

    bool validate = this->validate();

    if (validate) {
        // Getting Source from one country
        vector<Territory *> PlayerTerritories = this->p->toDefend();

        // Getting Enemy Territory that is Adjacent
        vector<Territory *> PlayerTerritoriesAttack = this->p->toAttack();

        PlayerTerritories.size();

        // Check if the territories are adjacent
        int size = PlayerTerritories.size();
        int size2 = PlayerTerritoriesAttack.size();
        int index = rand() % (size);
        int index2 = rand() % (size2);


        vector<Territory *> Source;
        // Getting the source Territory
        for (int i = 0; i < size; i++) {

            if (i == index)
                Source.push_back(PlayerTerritories[i]);
        }
        cout << "We are here just before executing attack " << endl;
        // Source Territory
        PlayerTerritories[0];

        // Now get the Adjacent  territories We need to make sure that it is also an enemy territory
        vector<Territory *> Neighboors = Source[0]->edges;


        int size3 = Neighboors.size();
        int index3 = rand() % (size3);

        // Now get the Target Territory from the List of Neighboors
        // We also check if it is also an ennemy territory
        int count = 0;
        for (Territory *t: Neighboors) {
            if (count == index3)
                Source.push_back(t);
            count++;
        }

        // how to verify if they both belong to the same player ?
        bool Adjacent = true;
        bool BothBelongToPlayer = false;
        bool DiplomacyOrder = false;
        // Verifying if a Diplomacy order has been made between the two players

        if (this->p->negotiate == true) {

            Player *enemy = this->p->enemynottoattack;

            //Check if attack Source Territory belongs to Player and target territory to enemy

            vector<Territory *> OwnTerritories = this->p->territoriesList;
            vector<Territory *> EnemyTerritories = enemy->territoriesList;

            bool SourceT = false;
            bool Target = false;


            for (Territory *t: OwnTerritories) {

                if (t->number == Source[0]->number)
                    SourceT = true;
            }

            for (Territory *t: EnemyTerritories) {

                if (t->number == Source[1]->number)
                    Target = true;
            }

            if (SourceT && Target)
                cout << "There is a negotiate order between the two players involved "
                        "in this advance manouever , there will be no attack between "
                     << Source[0]->name << " and " << Source[1]->name;

            this->p->negotiate = false;
            enemy->negotiate = false;

        }


        // Now to  Verify if the Target territory  belongs to the player as well
        for (int i = 0; i < size; i++) {

            if (PlayerTerritories[i]->number == Source[1]->number)
                BothBelongToPlayer = true;
        }

        // Target belongs to enemy territory

        cout << "Are the two territories Adjacent ? " << Adjacent << " are they both to the same player ?"
             << BothBelongToPlayer << endl;
        if (Adjacent && BothBelongToPlayer == false) {

            cout << "We are trying an Attack" << endl;
            // 60% chance of winning if attack
            //70% of Winning if Defend
            // Source Territory army Supply
            int AttackerArmy = Source[0]->numberOfArmies;
            // Target Territory army supply
            int DefenseArmy = Source[1]->numberOfArmies;

            bool defeatedTarget = true;
            cout << "During attack, attacker armies are " << AttackerArmy << " and Defender armies " << DefenseArmy
                 << endl;
            for (int i = 1; i <= AttackerArmy; i++) {
                int value1 = rand() % 10 + 1;     // value1 in the range 1 to 10
                int value2 = rand() % 10 + 1;     // value2 in the range 1 to 10

                if (DefenseArmy <= 0) {
                    cout << "The Target territory has lost all its territories the source player will take over"
                         << endl;
                    // Source Territory
                    Source[0];
                    //

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
                    //Vegeto
                    break;
                } else if (AttackerArmy <= 0) {

                    cout << "The attacker has lost all its territories and the defender will keep its territory"
                         << endl;
                    break;
                }




                    // 60% chance that value 1 is from 1 to 6
                    //70% chance that value 2 is from 1 to 7
                else if (value1 <= 6 && value2 <= 7) {
                    // This means there is attack and Defense happening
                    // To determine who wins we compare the two values


                    AttackerArmy--;

                } else if (value1 > 6 && value2 <= 7) {

                    AttackerArmy--;
                    //Dense wins
                } else if (value1 <= 6 && value2 > 7) {

                    DefenseArmy--;
                    //Attacks wins
                }


            }


            if (DefenseArmy > 0) {
                if (AttackerArmy >= 0)
                    Source[0]->numberOfArmies = AttackerArmy;

                Source[1]->numberOfArmies = DefenseArmy;

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
        if (Adjacent && BothBelongToPlayer) {
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
                if (Source[0]->numberOfArmies >= MovingArmies) {
                    Source[0]->numberOfArmies -= MovingArmies;
                    Source[1]->numberOfArmies += MovingArmies;
                } else {
                    int temp = Source[0]->numberOfArmies;
                    Source[0]->numberOfArmies = 0;
                    Source[1]->numberOfArmies += temp;
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
    } else {
        cout << "There is no Advance Card for the Player who executed this order";
        p->getOrdersList()->remove(this);
    }
    this->LogMessage = "Player: " + this->p->GetName() + " has called Adavnce order";
    Notify(*this);
};

bool Advance::validate() {
    cout << "Check for execution of Advance" << endl;

    bool AdvanceAttack = true;
    if (this->p->toAttack().size() == 0)
        AdvanceAttack = false;

    bool AdvanceDeploy = true;
    if (this->p->toDefend().size() == 0)
        AdvanceDeploy = false;

    if (AdvanceAttack && AdvanceDeploy) {
        return true;
    } else
        return false;
    //Add implementation
};


bool Bombs::validate() {
    if (this->p->toAttack().size() == 0) {
        return false;
    }
    cout << "validating Bomb" << endl;

    vector<Card *> _collection = this->p->getHand()->GetCollection();
    cout << " Size of the hand is " << _collection.size() << endl;
    for (Card *c: _collection) {
        // Compare two strings to verify
        cout << c->GetType() << endl;
        if (c->GetType() == "Bomb")
            return true;
    }
    return false;
};


void Bombs::execute() {
    cout << "you are now executing bomb order " << endl;
    bool verifie = this->validate();
    // Verify if the player can choose between all the territories first
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
        cout << "Territory after being bombed" << endl;
        cout << "---------------------------------------" << endl;
        cout << *Territories2[0] << endl;
        cout << "---------------------------------------" << endl;
        cout << "your enemy number is now " << Army2 << endl;

        p->getOrdersList()->remove(this);

    } else {
        cout << "There is no Bomb Card for the Player who executed this order";
        p->getOrdersList()->remove(this);
    }


    this->LogMessage = "Player: " + this->p->GetName() + " has called Bomb order";
    Notify(*this);
}

//nOTEfIND

void Negotiate::execute() {
    cout << "Execution of Negotiate" << endl;
    //Add implementation
    // targets enemy player
    //player issuing and enemy cannot attack each other
    //if target is player issuing then its invalid
    //If the target is an enemy player, then the effect is that any attack that may be declared between territories
    //of the player issuing the negotiate order and the target player will result in an invalid order.
    bool verif = this->validate();
    if (verif) {
        vector<Player *> Players = this->ListOfPlayers;


        int size = Players.size();
        int index = rand() % (size);


        // Player verification

        int count = 0;

        // Getting the index of the player who is calling the order
        int PlayerIndex = 0;
        for (Player *p: Players) {

            if (p->GetName() == this->p->GetName() && p->id == this->p->id)
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
            if (i == index) {
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
        cout << "The player " << this->p->_name << " and the player " << Players2[0]->_name
             << " will not attack each other next turn";

    } else {
        cout << "There is no Airlift Card for the Player who executed this order";
        p->getOrdersList()->remove(this);
    }
    this->LogMessage = "Player: " + this->p->GetName() + " has called negotiate order";
    Notify(*this);
};

bool Negotiate::validate() {
    if (this->p->territoriesList.size() == 0) {
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

bool Blockades::validate() {
    //Add implementation
    if (this->p->toDefend().size() == 0) {
        return false;
    }
    vector<Card *> _collection = this->p->getHand()->GetCollection();

    for (Card *c: _collection) {
        // Compare two strings to verify
        if (c->GetType() == "Blockade")
            return true;
    }
    return false;
};

void Order::SetListOfPlayers(vector<Player *> list) {
    this->ListOfPlayers = list;
}


void Blockades::execute() {
    cout << "Execution of Blockades" << endl;
    //Add implementation
    bool verif = this->validate();
    // Verify if the player can choose between all the teritories first
    // Check in Validate

    if (verif) {

        vector<Territory *> Territories = this->p->toDefend();
        int size = Territories.size();
        int index = rand() % (size);

        vector<Territory *> Territories2;
        for (int i = 0; i < Territories.size(); i++) {
            //target and source
            if (i == index) {
                // Picking a territory that belongs to the player
                Territories2.push_back(Territories[i]);
            }
        }
        cout << "Selected Territory  for blockade" << endl;
        cout << *Territories2[0] << endl;

        cout << "----------------------------------------" << endl;
        cout << endl;
        cout << endl;

        cout << "Printing the Original Player Territories before blockade" << endl;
        cout << "----------------------------------------" << endl;
        for (Territory *t: this->p->territoriesList) {
            cout << *t << endl;
        }
        cout << "----------------------------------------" << endl;
        cout << "----------------------------------------" << endl;


        int Army1 = Territories2[0]->numberOfArmies;

        int Army2 = Army1 * 2;
        // Doubling the number of armies of this territory
        //target



        // Adding
        Territories2[0]->SetNumberOfArmies(Army2);
        //
//Note neutral player
        cout << "Army1 is " << Army1 << endl;


        vector<Player *> ListofPlayers = this->ListOfPlayers;
        vector<Player *> Neutral;
        for (Player *p: ListofPlayers) {
            // Transferring Ownership
            if (p->GetName() == "Neutral") {
                // Removing the Territory from the player list of Terroteries
                this->p->RemoveTerritory(Territories2[0]);
                Neutral.push_back(p);
                // Adding the Territories to the Neutral Player
                p->addTerritory(Territories2[0]);
                //Naruto
            }
        }


        cout << "Printing the Original Player Territories after blockade" << endl;
        cout << "----------------------------------------" << endl;
        for (Territory *t: this->p->territoriesList) {
            cout << *t << endl;
        }
        cout << "----------------------------------------" << endl;
        cout << "----------------------------------------" << endl;

        cout << endl;
        cout << endl;
        cout << "Printing the Neutral Player Territories after blockade" << endl;
        cout << "----------------------------------------" << endl;

        cout << "----------------------------------------" << endl;
        cout << "----------------------------------------" << endl;


        p->getOrdersList()->remove(this);
    } else {
        cout << "There is no Blockade Card for the Player who executed this order";
        p->getOrdersList()->remove(this);
    }

    this->LogMessage = "Player: " + this->p->GetName() + " has called blockade order";
    Notify(*this);
};

Negotiate::Negotiate() {
    cout << "Inside default constructor Negotiate class" << endl;
    set_type_id(5);
}

Negotiate::~Negotiate() {
}

vector<Order *> OrderList::get_order_list_new() {
    cout << "Inside Order List get order method" << endl;
    return vec_order_list;
}


void OrderList::Add(Order *o) {
    LogMessage = "Order:" + o->get_type() + " was just issued";
    this->vec_order_list.push_back(o);
    Notify(*this);

}

string OrderList::stringToLog() {
    return "ORDERLIST ISSUEORDER LOG:" + LogMessage;
}

Negotiate::Negotiate(const Negotiate &e) {
    cout << "Inside copy constructor of Negotiate" << endl;
};

Negotiate &Negotiate::operator=(const Negotiate &e) {
    cout << "Inside operator = of Negotiate" << endl;

    return *this;
}
