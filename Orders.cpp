
#include "Orders.h"

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



OrderList::OrderList() {
    // cout << "Inside default constructor Order class" << endl;


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
        Order * T1 = new Order (valids,vec_types1,type_ids);
        this->vec_order_list.push_back(T1);
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
        Order * T1 = new Order (valid,vec_type1,type_id);
        this->vec_order_list.push_back(T1);
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


void Order::set_type_id(int num) {
    type_id = num;
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
    Order * T1 = new Order (valid,vec_type1,type_id);
    cout << "Before pushing the order" << endl;
    vec_order_list.push_back(T1); //add an order
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

string *Deploy::get_type() {
    return &type1;
}

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

Airlifts::~Airlifts() {
}

Negotiate::Negotiate() {
    cout << "Inside default constructor Negotiate class" << endl;
    set_type_id(5);
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
