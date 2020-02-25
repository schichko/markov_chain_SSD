// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
#include <vector>
#include <map>
using namespace std;



int main () {
  map <string,map<string,int>> myMap;

  //myMap["hello"] = map<string,int>("ass",4);
  //myMap.insert(pair<4, unordered_map<4,4>>);

  myMap["Hello"].insert(make_pair("ek",3));

    for (auto x : myMap) {
         cout << x.first <<endl; 
         for (auto y: x.second){
             cout << y.first<<":"<< y.second<<endl; 
         }
     }

cout<<myMap.find("Hello")->first<<endl;
  //  cout<< myMap["Hello"]->second <<endl;
}