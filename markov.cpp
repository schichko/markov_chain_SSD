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
  string line;
  ifstream myfile ("sample.txt");
  map <string,map<string,int> > myMap;

  if (myfile.is_open()){
    while ( getline (myfile,line) ) {
        string strWords[line.length()];
        short counter = 0;

        for(short i=0;i<=line.length();i++){

            if(line[i] == ' ' ){
                counter++;
            }
            else if(line[i] == '.'){
                counter++;
                strWords[counter] += line[i];
                counter++;

            }
            else if(line[i]=='\n' || i == line.length()){
                counter++;
            }
            else{
                strWords[counter] += line[i];
            }
        }

        for(short i=0;i<counter;i++){
            // First time seeing word, add it to first part of map with its second word associated
            if(myMap.find(strWords[i]) == myMap.end() && i+1<counter){
                myMap[strWords[i]].insert(make_pair(strWords[i+1],1));
            }
            // Found another instance of the word so increase the given value
            else if( i+1<counter){
                myMap[strWords[i]][strWords[i + 1]] += 1;
            }
        }
    }
    myfile.close();

    cout << "File Closed" << endl;

    for(auto x : myMap) {
        cout << x.first << endl;
        for(auto y : x.second) {
            cout << y.first << ": " << y.second << endl;
        }
        cout << endl;
    }
  } else {
        cout << "Unable to open file" << endl; 
    }

  return 0;
}