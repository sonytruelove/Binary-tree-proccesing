#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
bool user;
struct Detail {
  string code;          
  string title;
  double price;
  double weight;  
};
struct dstructure {

  Detail detail;           

  dstructure *left;  

  dstructure *right; 

};
void badWeightCheck(string *weight){*weight="dsada";}
void bigWeightCheck(string *weight){*weight="1000000000000000";};
void zeroWeightCheck(string *weight){*weight="0";};