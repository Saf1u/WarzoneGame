//
// Created by Safwan Ahmed on 2021-09-23.
//
#include "Map.h"
#include <fstream>
#include <iostream>

//You want in to be a pointer so that its the same player!
//constructor for Territory class initializes all members except borders;
Territory::Territory(string name, int num,int numberOfArmies,int continent) {
    this->name=name;
    this->number=num;
    this->continentNumber=continent;
    this->numberOfArmies=numberOfArmies;
}

//Default constructor
Territory::Territory() {

}
Map::~Map(){
    for(auto & i : map){
        if (i!= nullptr){
            delete i;
            i= nullptr;
        }

    }
    for(auto & continent : continents){
        if(continent!= nullptr){
            delete continent;
            continent= nullptr;
        }
    }
}
//Copy constructor
//First makes a plane copy of all territories in the list and then adds all corresponding borders.
//Does this due to recursive nature of Map.
Territory::Territory(const Territory &t) {
    unordered_map<int,vector<int>> neighbours;
    Territory *p=t.edges[0];



    map<int,Territory*>   list=p->makeTerritoryCopies(neighbours);
    for(int i=1;i<list.size();i++){
        vector<int> adjacent=neighbours[list[i]->number];
        for(int j=0;j<adjacent.size();j++){
            list[i]->edges.push_back(list[adjacent[j]]);
        }
    }
    this->name=list[t.number]->name;
    this->edges=list[t.number]->edges;
    this->number=list[t.number]->number;
    this->numberOfArmies=list[t.number]->numberOfArmies;
    this->continentNumber=list[t.number]->continentNumber;



}
//Helper function that allows copying of territories and returning map to territory number
map<int,Territory*>  Territory::makeTerritoryCopies( unordered_map<int,vector<int>> &neighbours) {
    unordered_map<int,bool> store;
    map<int,Territory*>   list;
    reursiveCopy(store,this,list,neighbours);

    return list;
}

//aS WE ARE UNABLE TO ACCESS THE MAP CLASS FROM WITHIN THE TERRITORY CLASS, THIS HELPER FUNCTION ALLOWS A RECURSIVE COPY OF all possible territories by executing a sort of dfs starting from the passed in territory
//all subsequent territories would be reached as the map is a valid connected graph.
void reursiveCopy( unordered_map<int,bool> &store,Territory *t, map<int,Territory*> &list,unordered_map<int,vector<int>> &neighbours){
    if(store[t->number]){
        return;
    }
    store[t->number]=true;
    Territory *a= new Territory;
    a->name=t->name;
    a->number=t->number;
    a->numberOfArmies=t->numberOfArmies;
    a->continentNumber=t->continentNumber;
    list[a->number]=a;
    for(int i=0;i<t->edges.size();i++){
        neighbours[t->number].push_back(t->edges[i]->number);
        reursiveCopy(store,t->edges[i],list,neighbours);
    }
}





//Assignment operator
Territory& Territory::operator=(const Territory &t) {
    Territory b(t);
    this->name=b.name;
    this->edges=b.edges;
    this->number=b.number;
    this->numberOfArmies=b.numberOfArmies;
    this->continentNumber=b.continentNumber;
    return *this;
}

//helper free function that facilitates the copy of an entire map.
void mapCopy(vector<Territory*> &list,unordered_map<int,bool> &check,Territory *t){
    if (check[t->number]){
        return;
    }
    check[t->number]=true;
    list.push_back(t);
    for(int i=0;i<t->edges.size();i++){
        mapCopy(list,check,t->edges[i]);
    }

}
//Map copy constructor that copies a whole map by first copying a single territory (thereby copying a whole map) and then adding the copied territories to the respective continents (without
//copying continents as this would make the sub-graph and main graph refer to different objects.
Map::Map(const Map& m) {
    vector<Territory*> countryList;
    unordered_map<int,bool> countryCheck;
    vector<Territory*> continentList;
    Territory *a=new Territory(*m.map[0]);
    mapCopy(countryList,countryCheck,a);
    this->map=countryList;
    for(int i=0;i<m.continents.size();i++){
        continentList.push_back(new Territory());
        continentList[i]->name=m.continents[i]->name;
        continentList[i]->number=m.continents[i]->number;
        //will be changed after getting player class';
        continentList[i]->numberOfArmies=m.continents[i]->numberOfArmies;
        continentList[i]->continentNumber=m.continents[i]->continentNumber;
        for(int j=0;j<countryList.size();j++){
            if((countryList[j]->continentNumber)==continentList[i]->number){
                continentList[i]->edges.push_back(countryList[j]);
            }
        }
        this->continents=continentList;
    }


}
//Added for testing

Map::Map(vector<Territory*> map , vector<Territory*> continents) {
    this->map=map;
    this->map=continents;
}
Map::Map() {

}
//Map assignment operator
Map& Map::operator=(const Map &m) {
    Map *a=new Map(m);
    this->continents=a->continents;
    this->map=a->map;
    return *this;
}
//MapLoader copy constructor and assignment operator.
MapLoader::MapLoader(const MapLoader &m) {
    Map a(*(m.map));
    this->map=&a;
}

MapLoader& MapLoader::operator=(const MapLoader &m) {
    Map a(*(m.map));
    this->map=&a;
    return *this;
}

ostream& operator <<(ostream &strm,const Territory&t) {
    return strm<<t.name<<","<<t.number<<","<<t.numberOfArmies<<endl;
}

ostream& operator <<(ostream &strm,const Map&t) {
    strm<<"territories:"<<endl;
    for(auto & i : t.map){
        strm<<i<<endl;
    }
    strm<<"continents:"<<endl;
    for(auto & i : t.continents){
        strm<<i<<endl;
    }
    return  strm;
}






MapLoader::MapLoader(Map * map) {
    this->map=map;
}

//loadMaps is a function of Maploader class that simply loads valid map files(without validating) it rejects files that do not abide by the  schema but accepts files that may
// not logically meet the connected graph/subgraph requirement. It does this by reading the map in a predetermined format and fails by returning a boolean as opposed to runtime termination.
bool MapLoader::loadMaps(fstream &strm) {
    bool contCheck=false;
    bool countryCheck=false;
    bool borderCheck=false;

    string line;
    while (!strm.eof()) {
        getline(strm, line, '\n');
        line.pop_back();
        //checks for continents
        if (line=="[continents]"){
            contCheck=this->addContinents(strm);
            if (!contCheck){
                return false;
            }

        }
        //checks for countries
        if (line=="[countries]"){
            if (!contCheck){
                return false;
            }
            countryCheck=this->addCountries(strm);
            if (!countryCheck){
                return false;
            }
        }
        //validates borders to be added.
        if (line=="[borders]"){
            if(!countryCheck){
                return false;
            }
            borderCheck=this->addAdjacentTerritories(strm);
        }

    }

    if (!contCheck||!countryCheck||!borderCheck){
        return false;
    }else{
        return true;
    }

}

//Tokenize is a free function that allows lines of sstrings tp be parsed into individual values (while ignoring whitespace) it does this by reading the whole
//line and searching for occurences of space and delimiting the string across that
vector<string> tokenize(string c){
    vector<string> container;
    int j(c.find(" "));
    if(j==string::npos){
        container.push_back(c);
        return container;
    }
    int i(0);
    while (j!=string::npos){
        container.push_back(c.substr(i,(j-i)));
        i=j+1;
        j++;
        j=(c.find(" ",j));
        if (j==string::npos){
            container.push_back(c.substr(i,(j-i)));
        }
    }
    for(int i=container.size()-1;i>=0;i--){
        if(container[i].empty()){
            container.pop_back();
        }else{
            break;
        }
    }
    return  container;
}


//A supporting maploader function that allows continents read from the map file to be parsed and added to the map to be loaded
bool MapLoader::addContinents(fstream &strm) {
    vector<string> a;
    string line;
    getline(strm, line, '\n');
    if (line.substr(0,1)==";"){
        getline(strm, line, '\n');
    }
    line.pop_back();
    int territoryNum=1;
    //Player will become a passed parameter in future used this for initialization
    while(!line.empty()&&!strm.eof()) {
        a=tokenize(line);
        if (a.size()!=3){
            return false;
        }else {
            int numOfArmies= stoi(a.at(1));
            Territory *continent=new Territory(a.at(0), territoryNum, numOfArmies,territoryNum);
            //leak not possible once out of this scope as all pointers are in the vector of the class!
            territoryNum++;
            map->continents.push_back(continent);
        }

        getline(strm, line, '\n');
        if (line.substr(0,1)==";"){
            getline(strm, line, '\n');
        }
        line.pop_back();
    }
    return true;
}

//Add adjacent territories reads the border portion of a map file and now looks through the initialized territory list in the map to add the respective
//edges acquired from tokenizing the border string in the map file.
bool MapLoader::addAdjacentTerritories(fstream &strm) {
    vector<string> a;
    string line;
    while(true) {
        if(strm.eof()){
            break;
        }
        getline(strm, line, '\n');
        if(line.empty()){
            continue;
        }
        if (line.substr(0,1)==";"){
            getline(strm, line, '\n');
        }
        line.pop_back();
        a=tokenize(line);
        if (a.size()<=0){
            return false;
        }else {
            int numOfTerritory= stoi(a.at(0));

            Territory *mainTerritory=map->map.at(mapNumToArrayIndex(numOfTerritory));
            if (mainTerritory==nullptr){
                return false;
            }
            int i=1;
            Territory *linkedTeritory;
            for(;i<a.size();i++) {
                try {
                    int x = stoi(a.at(i));
                    linkedTeritory = map->map.at(mapNumToArrayIndex(x));
                    if (linkedTeritory == nullptr) {
                        return false;
                    } else {
                        mainTerritory->edges.push_back(linkedTeritory);
                    }
                }
                    //parsed line may not be a valid num.
                catch(invalid_argument &e) {

                }
            }
        }


    }
    return true;
}

//Add countries basically does the same thing as add continents but the territories of focus are now territories not continents
bool MapLoader::addCountries(fstream &strm) {
    vector<string> a;
    string line;
    getline(strm, line, '\n');
    if (line.substr(0,1)==";"){
        getline(strm, line, '\n');
    }
    //I recurently pop a single string as some weird whitespace still lingers
    line.pop_back();
    int territoryNum=1;

    while(!line.empty()&&!strm.eof()) {
        a=tokenize(line);
        if (a.size()!=5){
            return false;
        }else {
            int numOfContinent= stoi(a.at(2));;
            Territory *country=new Territory(a.at(1), territoryNum, 0,numOfContinent);
            //leak not possible once out of this scope as all pointers are in the vector of the class!
            territoryNum++;
            Territory *tempTerritory=map->continents.at(mapNumToArrayIndex(numOfContinent));
            if (tempTerritory==nullptr){
                delete country;
                //Leak avoided
                return false;
            }else{
                tempTerritory->edges.push_back(country);
            }
            map->map.push_back(country);
        }

        getline(strm, line, '\n');
        if (line.substr(0,1)==";"){
            getline(strm, line, '\n');
        }
        line.pop_back();
    }
    return true;
}


//printMap is a replacement for the stream operator for a map as the structure is recursive and is not well suited to the operator
//this function loops over the map and pretty prints the map.
void Map::printMap(){
    int i;
    int j;
    for (i=0;i<map.size();i++){
        cout<<"territory is:"<<*(map[i])<<endl;
        cout<<"its members are:"<<endl;
        vector<Territory*> tempb=(map[i])->edges;
        for(j=0;j<tempb.size();j++){
            cout<<*(tempb[j])<<endl;
        }
    };
}



//Does the same as above but prints continents.
void Map::printContinents() {
    int i;
    int j;
    for (i=0;i<continents.size();i++){
        cout<<"territory is:"<<*(continents[i])<<endl;
        cout<<"its members are:"<<endl;
        vector<Territory*> tempb=(continents[i])->edges;
        for(j=0;j<tempb.size();j++){
            cout<<*(tempb[j])<<endl;
        }
    };
}

//Helper function to allow indexing by country number (array offset of 0)
int mapNumToArrayIndex(int i){
    return i-1;
}

//dfs executes a dfs search starting from a particular node bu recursively calling itself and keeping track on previous locations.
void dfs( vector<bool> &cond,Territory *t){
    if(!cond[mapNumToArrayIndex(t->number)]){
        cond[mapNumToArrayIndex(t->number)]=true;

    }else{
        return;
    }
    int i=0;
    vector<Territory*> temp=t->edges;
    for (i=0;i<temp.size();i++){

        dfs(cond,  (temp[i]));
    }
}

//helper function to set all bool to false and maintian size;
void clearBoolArray(vector<bool>&checker,int size){
    int i;
    if (checker.size()!=0){
        checker.clear();
    }
    for(i=0;i<size;i++){
        checker.push_back(false);
    }
}


//check if graph is connected be executing a dfs search on each territory on the map list.
bool checkConnectedGraph(vector<Territory*> territories){
    vector<bool> checker;
    int i;
    bool check;
    clearBoolArray(checker,territories.size());
    for(i=0;i<territories.size();i++){
        dfs(checker,territories[i]);
        check=checkBoolArray(checker);
        if (!check){
            return false;
        }
        clearBoolArray(checker,territories.size());
    }
    return true;
}

//This function returns a list of call neigbouring territories for a passed in territory
vector<int> getTerritoryNumbers(Territory *t){
    vector <int> numbers;
    int i;
    vector<Territory*> territories=t->edges;
    for(i=0;i<territories.size();i++){
        numbers.push_back(mapNumToArrayIndex(territories[i]->number));
    }
    return numbers;
}

//Iterates array after a subgraph check to assert all entries are visited.
bool checkBoolArraySubGraph(vector<bool>& check,vector<int> list){
    int i;
    for(i=0;i<list.size();i++){
        if (!check.at(list[i])){
            return false;
        }
    }
    return true;

}
//does the same as above but for whole graph
bool checkBoolArray(vector<bool>&checker){
    int i;
    for(i=0;i<checker.size();i++){
        if(checker[i]==0){
            return  false;
        }
    }
    return true;
}

//carries out a dfs on each subcontinent but assures that all paths reached miust be from territories within the continent.
bool checkSubGraphConnected(vector<Territory*> territories,int size){
    vector<bool> checker;
    vector<int> numbers;
    int i;
    bool check;
    clearBoolArray(checker,size);
    for(i=0;i<territories.size();i++){
        dfsSubGraph(checker,territories[i]->edges[0],territories[i]->continentNumber);
        numbers=getTerritoryNumbers(territories[i]);
        check=checkBoolArraySubGraph(checker,numbers);
        if (!check){
            return false;
        }
        clearBoolArray(checker,size);
    }
    return true;
}
//validate calls all 3 validation options(single continent, connected graph, connected subgraph) and returns false if any fails;
bool Map::validate() const {
    bool validContinents=this->checkContinents();
    bool connectedGraph= checkConnectedGraph(map);
    bool connectedSubGraph= checkSubGraphConnected(continents,map.size());
    return connectedGraph&&connectedSubGraph&&validContinents;
}

//checks each territory belongs to only 1 continent
bool Map::checkContinents() const {
    unordered_map<int,bool> checker;
    int i;
    for(i=0;i<continents.size();i++){
        for(int j=0;j<continents[i]->edges.size();j++){
            if (checker[continents[i]->edges[j]->number]){
                return  false;
            }else{
                checker[continents[i]->edges[j]->number]=true;
            }
        }
    }
    return  true;
}

//Dfs sub-graph is a modified dfs that checks to ensure that all reachable territories follow paths within the continent only.
void dfsSubGraph( vector<bool> &cond,Territory *t,int j){
    if((!cond[mapNumToArrayIndex(t->number)])&&(t->continentNumber==j)){

        cond[mapNumToArrayIndex(t->number)]=true;

    }else{

        return;
    }
    int i=0;
    vector<Territory*> temp=t->edges;
    for (i=0;i<temp.size();i++){
        dfsSubGraph(cond,(temp[i]),j);
    }
}