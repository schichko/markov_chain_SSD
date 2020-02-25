// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

map<string,map<string,int>> generateMap (string fileName)
{
  string line;
  ifstream myfile (fileName);
  map <string,map<string,int>> myMap;

  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
        //cout<<line.length()<<endl;
        string strWords[line.length()];
        int counter = 0;

        for(int i=0;i<=line.length();i++){
            //cout<<line[i]<<endl;
            if(line[i] == ' '){
                counter++;
            }
            else if(line[i] == '.'){
                if(i+1 <= line.length() && line[i+1] == ' '){
                    counter++;
                    strWords[counter] += line[i];
                    counter++;
                    i++;
                }
                else{
                    counter++;
                    strWords[counter] += line[i];
                    counter++;
                }
            }
            else if(line[i-1]!='.' && (line[i]=='\n'|| i == line.length())){
                cout<<"Null"<<endl;
                
                strWords[counter] += line[i];
                counter++;
                strWords[counter]+= '.';
                counter++;
            }
            else if(line[i]=='\n' || i == line.length()){
                counter++;
            }
            else{
                strWords[counter] += line[i];
            }
        }

        //cout<<counter<<endl;
        //cout<<strWords[2]<<endl;
        for(int i=0;i<counter;i++){
            //cout<<strWords[i]<<endl;
            if(strWords[i] != "."){

                if(myMap.find(strWords[i]) == myMap.end() && i+1<counter){
                    //cout <<"First Event"<<endl;
                    myMap[strWords[i]].insert(make_pair(strWords[i+1],1));
                }
                
                else if( i+1<counter){                
                    myMap[strWords[i]][strWords[i+1]]++;
                }
            }

        }
    }

    myfile.close();
    //cout<<"File Closed\n"<<endl;
    for (auto x : myMap) {
        // cout << x.first <<endl; 
         for (auto y: x.second){
          //   cout << y.first<<":"<< y.second<<endl; 
         }
        // cout<<endl;
     }
     return myMap;
  }


  else{
       cout << "Unable to open file"; 
       return myMap;
  }

}

void generateStory(map<string,map<string,int>> myMap){
    //cout << myMap.size()<< endl; 
    //int r = (rand() % myMap.size());
    //cout<<r<<endl;

    bool loop = true;
    while(loop == true){

        auto it = myMap.begin();
        std::advance(it, rand() % myMap.size());

        
        if(it->first[0] <91){
            cout<<it->first<<endl;
            loop = false;
        }
        else{
            
        }
    }

    //cout<<myMap.length<<cout<<endl;
}

int main () {
  srand((unsigned)time(0)); 
  map<string,map<string,int>> generatedMap;
  generatedMap = generateMap("sample.txt");

//   for (auto x : generatedMap) {
//          cout << x.first <<endl; 
//          for (auto y: x.second){
//              cout << y.first<<":"<< y.second<<endl; 
//          }
//          cout<<endl;
//      }

    generateStory(generatedMap);
  return 0;
}