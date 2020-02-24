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
  map <string,map<string,int> myMap;
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        cout<<line.length()<<endl;
        string strWords[line.length()];
        short counter = 0;

        for(short i=0;i<=line.length();i++){
            //strWords[counter] = line[i];
            cout<<line[i]<<endl;
            if(line[i] == ' ' ){
                counter++;
            }
            else if(line[i] == '.'){
                counter++;
                strWords[counter] += line[i];
                counter++;

            }
            else if(line[i]=='\n' || i == line.length()){
                cout<<"null terminator"<<endl;
                counter++;
            }
            else{
                strWords[counter] += line[i];
            }
        }

        cout<<counter<<endl;
        for(short i=0;i<counter;i++){
            cout<<strWords[i]<<endl;

// std::map< int,std::map<std::string,double> > map_data;

// std::map<std::string, double> data;

// data.emplace("window", 3.14);

// map_data.emplace(0, data);


            myMap[strWords[i]] = map<strWords[i],4>;

        }
    }

    myfile.close();
    for (auto x : myMap) {
        cout << x.first << " " << x.second << endl; 
    }
  }

  else cout << "Unable to open file"; 

  return 0;
}