#include "Orders.h"

using namespace std;

int main() {
    cout << "Testing Order Driver\n" << endl;
    OrderList anOrderList;

    //creating objects of all types using default constructors
    cout << "Creating objects of all types using default constructors" << endl;
    Deploy deploy1;
    Advance advance1;
    Bomb bomb1;
    Blockade blockade1;
    Airlift airlift1;
    Negotiate negotiate1;

    Order o;
    cout << "\n" << endl;
    cout << bomb1 << endl;


    cout << "Copying objects using copy constructor \n" << endl;
    Deploy d2 = deploy1;
    Advance a3 = advance1;

    cout << "\nMoving objects in list...." << endl;

    anOrderList.set_order_list(&deploy1);
    anOrderList.set_order_list(&advance1);
    anOrderList.set_order_list(&bomb1);
    anOrderList.set_order_list(&blockade1);
    anOrderList.set_order_list(&airlift1);
    anOrderList.set_order_list(&negotiate1);


    //print orderlist
    cout << "\n the orderlist contains: " << endl;
    for (int i = 0; i < anOrderList.get_order_list()->size(); i++) {
        cout << "  " << anOrderList.get_order_list()->at(i)->get_type() << endl;
    }
    cout << "\n Removing orders from list..." << endl;
    //delete an order
    anOrderList.remove(&deploy1);
    anOrderList.remove(&advance1);
    //anOrderList.remove(&bomb1);

    //print orderlist
    cout << "\nOrderlist contains: " << endl;
    for (int i = 0; i < anOrderList.get_order_list()->size(); i++) {
        cout << "  " << anOrderList.get_order_list()->at(i)->get_type() << endl;
    }

    cout << "\nMoving orders within list" << endl;
    //move an order
    anOrderList.move(0, 4);
    anOrderList.move(1, 3);
    //anOrderList.move(0, 8);//invalid
    //print orderlist
    cout << "\nOrderlist contains: " << endl;
    for (int i = 0; i < anOrderList.get_order_list()->size(); i++) {
        cout << "  " << anOrderList.get_order_list()->at(i)->get_type() << endl;
    }


}