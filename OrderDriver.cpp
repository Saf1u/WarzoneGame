#include "Orders.h"
#include <time.h>

using namespace std;

int main() {
    cout << "Testing Order Driver\n" << endl;
    OrderList anOrderList;
/* initialize random seed: */
    srand (time(NULL));
    //creating objects of all types using default constructors
    cout << "Creating objects of all types using default constructors" << endl;
    //Deploy deploy1;
   // Advance advance1;
   // Bombs bomb1;
   Blockades blockade1;
    Airlifts airlift1;


    cout  << "------------------------" << endl;
    cout  << "Creating Territories" << endl;
    cout  << "------------------------" << endl;


    int CanadaNum = 11;
    int AmericaNum = 12;
    int MexicoNum =13;
    int NorthAmerica = 1;
    int numberOfArmies = 10;

    string Canada = "Canada";
    string America = "America";
    string Mexico = "Mexico";
    Territory * Territory0 =  new Territory(Mexico,MexicoNum,2,NorthAmerica);
    int FranceNum = 111;
    int GermanyNum = 122;
    int Europe = 2;
    string France = "France";
    string Germany = "Germany";

    int AlgeriaNum = 1111;
    int MorrocoNum = 1222;
    int Africa = 3;
    string Algeria = "Algeria";
    string Morroco = "Morroco";

    // Creating territories
    // Watchout for memory leaks perhaps delete the pointers
    Territory * Territory1 =  new Territory(Canada,CanadaNum,3,NorthAmerica);



    Territory * Territory2 =  new  Territory(America,AmericaNum,2,NorthAmerica);

    // Adding America as a Neighboor to Canada
    Territory1->edges.push_back(Territory2);

    // Adding Canada as a Neighboor to America
    Territory2->edges.push_back(Territory1);

    // Adding Mexico as a Neighboor to America
    Territory2->edges.push_back(Territory0);

    Territory * Territory3 =  new  Territory(France,FranceNum,2,Europe);

    Territory * Territory4 =  new  Territory(Germany,FranceNum,2,Europe);


    // Adding France as a Neighboor to Germany
    Territory4->edges.push_back(Territory3);

    // Adding Germany as a Neighboor to France
    Territory3->edges.push_back(Territory4);


    Territory * Territory5 =  new  Territory(Algeria,AlgeriaNum,2,Africa);

    Territory * Territory11 =  new  Territory(Morroco,MorrocoNum,2,Africa);

    // Adding Morroco as a Neighboor to Algeria
    Territory5->edges.push_back(Territory11);

    // Adding Algeria as a Neighboor to Morroco
    Territory11->edges.push_back(Territory5);

    string EuropeName ="Europe";
    int EuropeNameNum = 1242;
    int EuropeContinent = 124234;

    Territory * Territory6 =  new  Territory(EuropeName,EuropeNameNum,2,EuropeContinent);

    string NorthAmericaName ="Europe";
    int NorthAmericaNameNum = 1242;
    int NorthAmericaContinent = 124234;

    Territory * Territory7 =  new  Territory(NorthAmericaName,NorthAmericaNameNum,2,NorthAmericaContinent);


    Bomb bomb ;

    Card* PointerBomb  =& bomb;

    Reinforcement reinforcement;
    Card* PointerReinforcement  =& reinforcement;

    Blockade blockade;

    Card* PointerBlockade  =& blockade;

    Airlift airlift ;

    Card* PointerAirlift  =& airlift;
    Diplomacy diplomacy;

    Card* PointerDiplomacy  =& diplomacy;
    vector<Card *>  MyCollectionOfCards ;

    MyCollectionOfCards.push_back(PointerBomb);

    MyCollectionOfCards.push_back(PointerReinforcement);

    MyCollectionOfCards.push_back(PointerBlockade);

    MyCollectionOfCards.push_back(PointerAirlift);

    MyCollectionOfCards.push_back(PointerDiplomacy);

    Deck MyDeck (MyCollectionOfCards);
    // Creating a map

    // pushing the territories
    vector<Territory*> map;
    map.push_back(Territory1);
    map.push_back(Territory2);
    map.push_back(Territory3);
    map.push_back(Territory4);
    map.push_back(Territory5);
    map.push_back(Territory0);
    map.push_back(Territory11);

    vector<Territory*> map2;
    map2.push_back(Territory2);
    map2.push_back(Territory4);
    map2.push_back(Territory11);

    //Pushing the continents
    vector<Territory*> continents;
    continents.push_back(Territory6);
    continents.push_back(Territory7);

    bool valid = false;
    vector<string> vec_type1 = {"Ronaldo", "Zidane", "Messi", "Lewandoski", "Salah", "Benzema"};
    int type_id = 5;
    Airlifts * airlift2 =  new Airlifts(valid,vec_type1,type_id);
    cout << airlift1 << endl;
  cout  << "------------------------" << endl;
    cout << *airlift2 << endl;
    cout  << "------------------------" << endl;


    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout  << "------------------------" << endl;
    cout  << "Trying to create a Player" << endl;
    cout  << "------------------------" << endl;

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
    vector<string> list3 = {"c"};


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
    Blockade blockade2;
    Card* PointerBomb2  =& bomb2;
    Card* PointerBomb3  =& blockade2;
    vector<Card *>  MyCollectionOfCards2 ;

    MyCollectionOfCards2.push_back(PointerBomb2);
    MyCollectionOfCards2.push_back(PointerBomb3);

    //  MyCollectionOfCards2.push_back(PointerBlockade2);
    cout<<"hello"<<endl;

    Hand ZaHande2 (MyCollectionOfCards2);
    cout<<"hello2"<<endl;
    Hand *hdptr=&ZaHande2;

//creating  a player
    cout<<"hello3"<<endl;


    cout << "The mapz Territory" << endl;

    int is = 1;
    for(Territory * t : map){
        cout << "Territory " << is <<endl;
        cout << *t << endl;
        is++;
    }

    //Handle the memory leak here
    Player   p1=  Player(map2, (ListPointer), hdptr, " Noor Hammodi  ");

    p1.toDefend();

    p1.PrintToDefend();
    p1.PrintToAttack();
   // p1.PrintNeighboors();
 Player * ptr2 = &p1;
    //Player Lisr
    vector<Player *> PlayerList;
    PlayerList.push_back(ptr2);
    p1.Setreinforcement_pool(50);
// Why is player territories doubled
    cout << "The player Territorys" << endl;
    int is2 =1;
    for(Territory * t : p1.territoriesList){
        cout << "Territory " << is2 <<endl;
        cout << *t << endl;
        is2++;
    }

    cout<<"hello4"<<endl;

    cout<<endl;
    cout<<endl;

    cout  << "------------------------" << endl;
    cout  << "Trying to print a Player" << endl;
    cout  << "------------------------" << endl;
      // cout << p1 << endl;
    cout  << "------------------------" << endl;
    cout  << "Finishing printing the Player" << endl;
    cout  << "------------------------" << endl;


    Map * GameMap = new Map(continents,map);

   // Airlifts * Air = new Airlifts(a,list3,a1);
   // Deploy * Air = new Deploy(a,list3,a1);
   // Blockades * Air = new Blockades(a,list3,a1);
    Advance * Air = new Advance(a,list3,a1);
   Player * ptr = & p1;
    Air->SetPlayer(ptr);
    Air->SetMap(GameMap);
    Air->SetListOfPlayers(PlayerList);

    // What is the deference between that and new
    Deck * DeckPrt = &MyDeck;
    Air->setDeck(DeckPrt);
//Why territories is doubled
    //cout << *Airlifts << endl;
  // Here try your methods

  cout << "Printing the an Order Completely" << endl;
    cout << "------------------------------" << endl;
    cout << "------------------------------" << endl;
    cout << endl;
    cout << endl;
    Air->PrintAllOrder();
    cout << "------------------------------" << endl;
    cout << "------------------------------" << endl;
    cout << endl;
    cout << endl;

    Air->execute();
    cout << endl;
    cout << endl;
    cout << "Printing the an Order Completely After Execute" << endl;
    cout << "------------------------------" << endl;
    cout << "------------------------------" << endl;
    cout << endl;
    cout << endl;
   // Air->PrintAllOrder();
    cout << "------------------------------" << endl;
    cout << "------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout<<endl;
    cout<<endl;
   // Negotiate negotiate1;


   /*
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

*/
}