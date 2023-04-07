#ifndef treefunctions.h
#define treefunctions.h
#include <iostream>
#include <vector>
using namespace std;
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
void addNode(Detail detail, dstructure* root);
void treeCoutRecursively(dstructure* tree, string move);
void deleteLowerWeight(dstructure* tree,double weight);
dstructure* findWithParent(string x, dstructure* tree, dstructure** outParent);
void deleteNode(dstructure* tree,string code);
void BFS(dstructure* tree);
void LRN(dstructure* tree);
void LNR(dstructure* tree);
void NLR(dstructure* tree);
void findCode(dstructure* tree,string code);
#endif