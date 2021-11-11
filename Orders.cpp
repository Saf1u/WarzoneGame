
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

    vector<Card*>  _collection = this->p->getHand()->GetCollection();

    for(Card* c : _collection){
        // Compare two strings to verify
        if(c->GetType()=="Airlifts")
            return true;
    }
    return false;
};

void Airlifts ::execute() {

    // Verify if the player can choose between all the teritories first
    // Check in Validate
    vector<Territory*> Territories = this->p->territoriesList;
    int size = Territories.size();
    int index =  rand() % (size-2) + 0;
    int index2 =  rand() % (size-2) + 0;

    vector<Territory*> Territories2;
    for( int  i = 0 ; i < Territories.size() ; i++){
        //target
        if(i  ==  index);
        Territories2.push_back(Territories[i]);

        //source
        if(i  ==  index2);
        Territories2.push_back(Territories[i]);
    }

    Territory * t1  = Territories2[0];

    Territory * t2  = Territories2[1];

    int Army1 = 0;

    int Army2=0;

    //source
    Army1 = t1->numberOfArmies;


    int temp = Army1 *0.3;

    //target
    Army2 = t2->numberOfArmies;

    Army2 =  Army2 + temp;

    // Adding
    t2->numberOfArmies = Army2;
    Army1 = Army1 - temp;

    t1->numberOfArmies = Army1;

};

Airlifts::~Airlifts() {
}

bool Deploy::validate(){
    //Add implementation
    return true;
};

void Deploy::execute(){
cout<<"Execution of Deploy" << endl;
    //Add implementation
};

bool Advance::validate(){
    //Add implementation
    return true;
};

void Advance::execute(){
    cout<<"Execution of Advance" << endl;
    //Add implementation
};


bool Bombs::validate(){
    //Add implementation
    return true;
};

void Bombs::execute(){
    cout<<"Execution of Bombs" << endl;
    //Add implementation
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
    return true;
};

void Blockades::execute(){
    cout<<"Execution of Blockades" << endl;
    //Add implementation
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
