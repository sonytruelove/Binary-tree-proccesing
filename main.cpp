#include <iostream>
#include <vector>
#include "treefunctions.h"
#include "tests.h"
#include "dataprocessing.h"
using namespace std;

int main() {
  vector<Detail> v; 
  inputData(v);
  dstructure* details=new dstructure();
  details->detail.code=v[0].code;
  details->detail.title=v[0].title;
  details->detail.price=v[0].price;
  details->detail.weight=v[0].weight;
  for (int i=1;i<v.size();i++){
    addNode(v[i],details);
  }
   treeCoutRecursively(details,"");
  cout<<"Запустить тесты?\t y-да \n Tests on? y-yes"<<endl;
  string test;
  cin>>test;
  cout<<"Задайте вес для удаления деталей легче данного/Input weight for delete details lighter"<<endl;
 string weight="0";
if(test!="y"){
    do{
   cin>>weight;}while(!checkDoubleData(weight) or !checkWeight(weight));
   deleteLowerWeight(details, stod(weight));}
    
else{
  cout<<"Выберите тест \n 1. Неверное представление веса \n 2. Выход за диапазон внутреннего представления переменной веса \n 3. Нулевое представление веса\n  Choose test \n 1. Wrong input\n 2. Big internal representation\n 3. Zero weight"<<endl;
  string num;
  do{
  cin>>num;}while(!checkDoubleData(num));
  if(stod(num)<1 or stod(num)>3 or stod(num)!=stoi(num)){cout<<"Выбран неверный вариант/Wrong way input";}
  else{
(num=="1")?badWeightCheck(&weight):(num=="2")?bigWeightCheck(&weight):zeroWeightCheck(&weight);
  }
  if(!checkDoubleData(weight)){cout<<"Не числовое значение,уберите лишние знаки(+,- и т.д)/No number (remove +,- etc)"<<endl;return 0;}
  if(!checkWeight(weight)){cout<<"Число не соотвествует диапазону/Out of range"<<endl;return 0;}
     deleteLowerWeight(details, stod(weight));
  }
 treeCoutRecursively(details,""); 
  cout<<"Обход в ширину/Breadth-first search"<<endl;
  BFS(details);
  cout<<endl<<"Прямой обход в глубину/Straight Depth-first search"<<endl;
  NLR(details);
  cout<<endl<<"Обратный обход в глубин/Reverse Depth-first searchу"<<endl;
  LRN(details);
   cout<<endl<<"Центрированный обход в глубину/Center Depth-first search"<<endl;
  LNR(details);
  findCode(details,"221a");
}