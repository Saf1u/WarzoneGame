//
// Created by Safwan Ahmed on 2021-09-22.
//

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>

#ifndef PREP_MAPLOADER_H
#define PREP_MAPLOADER_H

#endif //PREP_MAPLOADER_H
using namespace  std;


class Territory{
public:
    string name;
    int number;
    int maxNumberOfArmies;
    int continentNumber;
    int numberOfArmies;
    int Bonus;
    int get_numberOfArmies();
    void SetNumberOfArmies(int numberOfArmies);
    std::vector<Territory*> edges;
    Territory(string,int,int,int);
    Territory(const Territory &b);
    Territory();
    void verifyTerritory();
    map<int,Territory*> makeTerritoryCopies(unordered_map<int,vector<int>> &neighbours);
    Territory& operator =(const Territory &t);
};

void reursiveCopy( unordered_map<int,bool>&,Territory *t, map<int,Territory*> &,unordered_map<int,vector<int>>&);
void mapCopy(vector<Territory*>&,unordered_map<int,bool>&,Territory *t);


ostream& operator <<(ostream &strm,const Territory&t) ;


class Map{
public:
    vector<Territory*> map;
    vector<Territory*> continents;


    //Added for testing
    Map(  vector<Territory*> map , vector<Territory*> continents);

    Map( const Map &m);
    Map();
    Map& operator =(const Map &m);
    bool validate() const;
    bool checkContinents() const;
    void printMap();
    void printContinents();
    ~Map();

    void continentBonus();
};
ostream& operator <<(ostream &strm,const Map&t) ;
class MapLoader{
public:
    bool loadMaps(fstream &strm);
    explicit MapLoader(Map*);
    MapLoader(const MapLoader &m);
    MapLoader& operator =(const MapLoader &m);
private:
public:
    Map *map;
    bool addCountries(fstream &strm);
    bool addContinents(fstream &strm);
    bool addAdjacentTerritories(fstream &strm);


};

vector<string> tokenize(string);
int mapNumToArrayIndex(int i);
void dfs(vector<bool>&,Territory*);
void dfsSubGraph(vector<bool>&,Territory*,int);
bool checkConnectedGraph(vector<Territory*>);
void clearBoolArray(vector<bool>&,int);
bool checkBoolArray(vector<bool>&);
vector<int> getTerritoryNumbers(Territory *t);
bool checkBoolArraySubGraph(vector<bool>&,vector<int>);
bool checkSubGraphConnected(vector<Territory*>,int);