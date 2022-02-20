
#include <iostream>
#include "Cards.h"
#include <time.h>
#include <cstdlib>

using namespace std;
int main() {

/* initialize random seed: */
    srand (time(NULL));


cout <<endl;
cout <<endl;

    cout << "___________________________________________-"<< endl;
    cout << "___________________________________________-"<< endl;
    cout << "Instantiating the Card objects, with copy constructors and assignment operators" << endl;
    cout << "___________________________________________-"<< endl;
    cout << "___________________________________________-"<< endl;
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


    cout << "Copying Bomb objects -> bomb to b2 " << endl;
    b2 = bomb;
    b3 = Bomb(bomb);

    cout <<endl;
    cout <<endl;
Reinforcement reinforcement;
    Card* PointerReinforcement  =& reinforcement;

    Blockade blockade;

    Card* PointerBlockade  =& blockade;

    Airlift airlift ;

    Card* PointerAirlift  =& airlift;
    Diplomacy diplomacy;

    Card* PointerDiplomacy  =& diplomacy;

    cout << "Copying Reinforcement objects -> Reinforcement to r2 " << endl;
    r2 = reinforcement;
    r3 = Reinforcement(reinforcement);

    cout <<endl;
    cout <<endl;
    Blockade blockade;

    Card* PointerBlockade  =& blockade;

    Airlift airlift ;

    Card* PointerAirlift  =& airlift;
    Diplomacy diplomacy;

    Card* PointerDiplomacy  =& diplomacy;
    cout << "Copying Blockade objects -> Blockade to bb2 " << endl;
    bb2 = blockade;
    bb3= Blockade(blockade);

    cout <<endl;
    cout <<endl;


Airlift airlift ;

    Card* PointerAirlift  =& airlift;
    Diplomacy diplomacy;

    Card* PointerDiplomacy  =& diplomacy;
    cout << "Copying Airlift objects -> Airlift to a2 " << endl;
    a2 = airlift;
    a3 = Airlift(airlift);

    cout <<endl;
    cout <<endl;
    Diplomacy diplomacy,d1,d3;

    Card* PointerDiplomacy  =& diplomacy;

    cout << "Copying Diplomacy objects -> Diplomacy to d1 " << endl;
    d1 = diplomacy;
    d3= Diplomacy(diplomacy);
    cout <<endl;
    cout <<endl;

    cout << "___________________________________________-"<< endl;
    cout << "___________________________________________-"<< endl;
    cout << "Printing all the cards with their stream operators" << endl;
    cout << "___________________________________________-"<< endl;
    cout << "___________________________________________-"<< endl;
    cout << " "<< endl;

    cout << bomb << endl;
    cout << reinforcement << endl;
    cout << blockade << endl;
    cout << airlift << endl;
    cout << diplomacy << endl;

    cout << "___________________________________________-"<< endl;
    cout << "___________________________________________-"<< endl;


vector<int>  MyCollectionOfCard ;


    vector<Card *>  MyCollectionOfCards ;

    MyCollectionOfCards.push_back(PointerBomb);

    MyCollectionOfCards.push_back(PointerReinforcement);

    MyCollectionOfCards.push_back(PointerBlockade);

    MyCollectionOfCards.push_back(PointerAirlift);

    MyCollectionOfCards.push_back(PointerDiplomacy);

    cout << "___________________________________________-"<< endl;
    cout << "___________________________________________-"<< endl;
    cout << "Calling the constructors of Hand and Deck" << endl;
    cout << "___________________________________________-"<< endl;
    cout << "___________________________________________-"<< endl;
    Hand ZaHande (MyCollectionOfCards);

    Deck MyDeck (MyCollectionOfCards);

    cout <<endl;
    cout <<endl;
    std::cout << "*************************************************" << std::endl;
    cout << " Using the stream operators for Hand and Deck" << endl;
    std::cout << "*************************************************" << std::endl;
    cout <<endl;
    cout <<endl;

   std::cout << ZaHande << std::endl;
    std::cout << "*************************************************" << std::endl;
    std::cout << "*************************************************" << std::endl;
    std::cout << MyDeck << std::endl;

    cout <<endl;
    cout <<endl;

    std::cout << "*************************************************" << std::endl;
    cout << " Trying the different methods of Deck" << endl;
    std::cout << "*************************************************" << std::endl;
    ZaHande.printCollection();

    ZaHande.remove(PointerBlockade);
    ZaHande.printCollection();
    MyDeck.printDeck();
    std::cout << "*************************************************" << std::endl;
    cout << " Trying the draw method of Deck" << endl;
    std::cout << "*************************************************" << std::endl;
   Card* Picked = MyDeck.draw();
    cout << endl;
    cout <<"Here is the returned card from the Deck"<< endl;
     Picked->print();
    cout <<"Printing the Deck after returning a card"<< endl;
    MyDeck.printDeck();

    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << "Trying the copy constructor of Hand " <<endl;

    Hand copy = Hand (ZaHande);
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << "Printing the Hand after the copy constructor " <<endl;
    cout << endl;
    cout << endl;
    cout << "-------------------------------" << endl;
    cout << "This is the copy" << endl;
     copy.printCollection();
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    cout << endl;

    cout << "-------------------------------" << endl;
    cout << "This is the original" << endl;
    ZaHande.printCollection();
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    cout << endl;


    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << "Finishing Trying the copy constructor of Hand " <<endl;
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << "Finishing Trying the copy constructor of Deck " <<endl;
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;

    Deck Deckcopy = Deck (MyDeck);
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << "Printing the Deck after the copy constructor " <<endl;
    cout << endl;
    cout << endl;
    cout << "-------------------------------" << endl;
    cout << "This is the copy" << endl;
    Deckcopy.printDeck();
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    cout << endl;

    cout << "-------------------------------" << endl;
    cout << "This is the original" << endl;
    MyDeck.printDeck();
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    cout << endl;

    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << "Finishing Trying the copy constructor of Deck " <<endl;


    cout << endl;
    cout << endl;
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << "Now trying the play Method of Card" <<endl;
    cout << "-------------------------------" << endl;
    cout << "-------------------------------" << endl;
    cout << endl;
    cout << endl;

    Bomb bomb2;

    Card* PointerBomb2  =& bomb2;


    Blockade blockade2;

    Card* PointerBlockade2  =& blockade2;

    Airlift airlift2;

    Card* PointerAirlift2  =& airlift2;

    Diplomacy diplomacy2;

    Card* PointerDiplomacy2  =& diplomacy2;

    vector<Card *>  MyCollectionOfCards2 ;

    MyCollectionOfCards2.push_back(PointerBomb2);



    MyCollectionOfCards2.push_back(PointerAirlift2);

    MyCollectionOfCards2.push_back(PointerDiplomacy2);

    Hand ZaHande2 (MyCollectionOfCards2);


    Hand * HandPointer2 = &ZaHande2;

    string name ="Zidane";

    Deck MyDeck2 (MyCollectionOfCards2);



    Player p3 =  Player(HandPointer2);


    cout <<"---------------------------------------"<<endl;
    cout <<"Printing the Deck before play method" <<endl;
    cout <<"---------------------------------------"<<endl;
    MyDeck2.printDeck();
    cout <<"---------------------------------------"<<endl;
    cout <<"Printing the Player p3  Hand before play method" <<endl;
    cout <<"---------------------------------------"<<endl;
    p3.getHand()->printCollection();
    cout <<endl;
    cout <<endl;

    int index2 = 0;
    for(Card * i : p3.getHand()->GetCollection()){

        if(index2 ==1){
            cout<< "About to use play method " <<endl;
            MyDeck2.Add(*i->play(p3)) ;
        }
        index2++;
    }
    cout <<endl;
    cout <<endl;
    cout <<"Printing the Hand after play method" <<endl;
    p3.getHand()->printCollection();
    cout <<endl;
    cout <<endl;
    cout <<"---------------------------------------"<<endl;
    cout <<"Printing the Deck After play method" <<endl;
    cout <<"---------------------------------------"<<endl;
    MyDeck2.printDeck();

    cout <<"---------------------------------------"<<endl;
    cout <<"End" <<endl;
    cout <<"---------------------------------------"<<endl;

     delete(Picked);
    Picked = NULL;
    cout << endl;
    cout << endl;


    for(Card * c : MyCollectionOfCards){
        delete c;
        c =NULL;
    }
    MyCollectionOfCards.clear();

    for(Card * c : MyCollectionOfCards2){
        delete c;
        c =NULL;
    }
    MyCollectionOfCards2.clear();

    return 0;
}