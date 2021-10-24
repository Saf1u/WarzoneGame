//
// Created by Noor on 2021-09-28.
//
#include <iostream>
#include "Player.h"
#include <vector>
#include "Orders.h"
#include "Cards.h"
using namespace std;


int main(){
    //creating arbitary list of territories
  Territory *t1=new Territory("hhh",1,2,6);
  Territory *t2=new Territory("testttt",1,2,9);
  vector<Territory *> territoriesList={t1, t2};

  //creating arbitary list of orders
  OrderList orderList;

  bool a = true;
    bool b = true;

    int a1 = 1;
    int a2 = 2;

    vector<string> list1 = {"a"};
    vector<string> list2 = {"b"};


    Order * OpOINTER1 = new Order(a,list1,a1);

    Order * OpOINTER2 = new Order(b,list2,a2);
  //Order o1,o2;
  //Order * OpOINTER1 = &o1;
    //Order * OpOINTER2 = &o2;
    orderList.set_order_list(OpOINTER1);
    orderList.set_order_list(OpOINTER2);
    OrderList * ListPointer = new OrderList;
    ListPointer = &orderList;

  //creating arbitary card and then hand
    Bomb bomb2;

    Card* PointerBomb2  =& bomb2;
     vector<Card *>  MyCollectionOfCards2 ;

    MyCollectionOfCards2.push_back(PointerBomb2);

    //  MyCollectionOfCards2.push_back(PointerBlockade2);
    cout<<"hello"<<endl;

    Hand ZaHande2 (MyCollectionOfCards2);
    cout<<"hello2"<<endl;
    Hand *hdptr=&ZaHande2;

//creating  a player
    cout<<"hello3"<<endl;
  Player p1= Player(territoriesList, (ListPointer), hdptr, " Noor Hammodi  ");

    cout<<"hello4"<<endl;

cout<<p1;



 /* cout << "----------------------" << endl;
    cout << "Printing to Defend" << endl;
    cout << "----------------------" << endl;

  for (Territory * t : p1.toDefend() ){

      cout << (*t) << endl;
  }

    cout << "----------------------" << endl;
    cout << "Printing to Attack" << endl;
    cout << "----------------------" << endl;

    for (Territory * t : p1.toAttack() ){
        cout << (*t) << endl;
    }
*/

  /*vector<Territory*> td =p1->toDefend();

cout<<"territory to defend"<<endl;
    for (int i=0;i<td.size();i++){
        *td[i];
    }
*/


return 0;
}





