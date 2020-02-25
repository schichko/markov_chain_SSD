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
  //std::map< int,std::map<std::string,double> > map_data;
  map <string,map<string,int>> myMap;
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
            
//               myMap["Hello"].insert(make_pair("ek",3));



// cout<<myMap.find("Hello")->first<<endl;
            if(myMap.find(strWords[i]) == myMap.end() && i+1>counter){
                cout <<"BAD"<<endl;
                myMap[strWords[i]].insert(make_pair(strWords[i+1],1));
            }


            // myMap[strWords[i]] = map<strWords[i],4>;

            // myMap[strWords[i]].insert(make_pair("ek",3)
        }
    }

    myfile.close();
    for (auto x : myMap) {
         cout << x.first <<endl; 
         for (auto y: x.second){
             cout << y.first<<":"<< y.second<<endl; 
         }
     }
  }


  else cout << "Unable to open file"; 

  return 0;
}