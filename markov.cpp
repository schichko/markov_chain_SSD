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
        if(line.length() >0){

            for(int i=0;i<=line.length();i++){
                
                if(line[i] == ' ' && strWords[counter]==""){
                    //cout<<"Empty"<<endl;
                }
                else if(line[i] == ' '){
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
                else if((i!= 0) && (line[i-1]!='.' && (line[i]=='\n'|| i == line.length()))){                    
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

            //  cout<<"MADE IT"<<endl;
            // cout<<counter<<endl;
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
    }
    myfile.close();
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
    bool generatingTweet = true;
    short tweetLength = 0;
    while(generatingTweet == true){
        bool loop = true;
        short sentenceLength=0; 
        string currentWord;
        while(loop == true){

            if(sentenceLength ==0 ){
                auto it = myMap.begin();
                std::advance(it, rand() % myMap.size());

            
                if(it->first[0] <91 ){
                    currentWord = it->first;
                    sentenceLength++;
                    cout<<currentWord<<" ";
                    
                }
            }
            else{
                // auto it = myMap[currentWord].begin();
                // std::advance(it, rand() % myMap[currentWord].size());
                map<string, int>::iterator it;
                double *weights = new double [myMap[currentWord].size()];
                string *words = new string [myMap[currentWord].size()];
                int count = 0;
                int totalWords = 0;
                for ( it = myMap[currentWord].begin(); it != myMap[currentWord].end(); it++ )
                {
                    //std::cout << it->first  << ':'<< it->second << std::endl;
                    totalWords = totalWords + it->second;
                    weights[count] = it->second;
                    words[count] = it->first;
                    count++;
                }

                for(int i = 0; i< myMap[currentWord].size();i++){
                    //cout<<weights[i]<<endl;
                    weights[i] = weights[i] / (double)totalWords;
                    //cout<<weights[i]<<endl;
                }
                
                bool didSelect = false;
                while(didSelect == false){
                    double r = ((double) rand() / (RAND_MAX));
                    //cout<<r<<endl;
                    for (int i = 0; i< myMap[currentWord].size();i++){
                        if(r <= weights[i]){
                            currentWord = words[i];
                            didSelect = true;
                            break;
                        }
                    }
                }

                
                sentenceLength++;
                tweetLength ++;
                cout<<currentWord<<" ";
                if(currentWord == "."){
                    cout<<endl;
                    loop = false;
                    if (tweetLength >= 155){
                        generatingTweet = false;
                    }
                    else if(.25 > ((double) rand() / (RAND_MAX))){
                        generatingTweet = false;
                    }
    
                }
                
                // for(int i=0;i<myMap[currentWord].size();i++){
                //     delete words[i];
                //     delete weights[i] ;
                // }
                delete[] words;
                delete[] weights;
            }
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