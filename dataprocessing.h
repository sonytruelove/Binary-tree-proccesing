#include <iostream>
#include <vector>
#ifndef dataproccesing.h
#define dataproccesing.h
using namespace std;
void inputData(vector<Detail> &v);
void userInput(vector<Detail> &v);
string chooseData();
bool checkDoubleData(string s);
bool checkWeight(string weight);
void fileInput(vector<Detail> &v,string type);
#endif