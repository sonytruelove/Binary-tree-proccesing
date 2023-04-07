#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct Detail {
  string code;          
  string title;
  double price;
  double weight;  
};
double maxWeight=0;
bool checkWeight(string weight){return (stod(weight)<maxWeight);}
string chooseData(){
cout<<"Выберите способ ввода данных \t консольный - user \t из файла - имя файла(файл должен находиться в одной папке с программой)\nChoose a way of input \t console - user \t file - file name(in directory with program)";
  string input;
  ifstream file;
  cin>>input;
   file.open(input);
  while(input!="user" and !file){
    if(input=="user") return input;
   file.open(input);
     if(!file)
      cout << "Нет данного файла: / File not exist " << input<<endl;
    else 
       return input;
    cin>>input;}
  return input;
}
bool checkDoubleData(string s){    
  if(s.size()==0) return false;
    for(int i=0;i<s.size();i++) {
        if(!(s[i]>='0' && s[i]<='9' or s[i]=='.')) {
            return false;
        }
    }
    return true;
}
void userInput(vector<Detail> &v){
  cout<<"Введите данные детали через пробел Шифр Наименование Цена Вес и любую клавишу- для продолжения n - для конца ввода/ Input detail data Code Title Price Weight ,after push any button to continue or n to end"<<endl;
  string input="1";
  int i=-1;
  while(input!="n"){
    Detail detail;
    i++;
    v.push_back(detail);
    cin>> v[i].code;
    cin>>v[i].title;
    cin>>input;
    if (checkDoubleData(input))  v[i].price=stod(input); else {
      cout<<"Неправильный ввод/Input error";
      i--;
       v.erase(v.end());
      continue;
    }
      cin>>input;
    if (checkDoubleData(input))  v[i].weight=stod(input); else {
      cout<<"Неправильный ввод/Input error";
      i--;
       v.erase(v.begin()+i);
      continue;
    }
    if (maxWeight<v[i].weight) maxWeight=v[i].weight;
     cout<<"Дальше?/Next? ";
     cin>>input;
  }
}
void fileInput(vector<Detail> &v,string type){
  ifstream fin(type);
  int i=-1;
  string input;
  cout<<"Формат строки в файле : Шифр Наименование Цена Вес/ Format line in file: Code Title Price Weigth "<<endl;
  while(!fin.eof()){
    i++;
    Detail detail;
    v.push_back(detail);
    fin>>v[i].code;
    fin>>v[i].title;
    fin>>input;
      if (checkDoubleData(input))  v[i].price=stod(input); else {
      cout<<"Неправильный ввод цена строка/Input price error "<<i+1;
      break;
    }
    fin>>input;
     if (checkDoubleData(input))  v[i].weight=stod(input); else {
      cout<<"Неправильный ввод вес строка/Input weight error "<<i+1;
     break;
    }
        if (maxWeight<v[i].weight) maxWeight=v[i].weight;
  };
}

void inputData(vector<Detail> &v){
  string type=chooseData();
if(type=="user") userInput(v);
else fileInput(v,type);
}