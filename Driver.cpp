
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
//#include "Player.cpp"
#include"Team.cpp"
#include <sstream>
using namespace std;
class Driver{
public:
    vector<Player> list;
    vector<Team> teams;
    double startTime=0;
    double elapsed=0;


    Driver(){}
    void CalcTeamWinProb(string TeamA,string TeamB){
        Team A;
        Team B;
        //open team.csv files and push data into team objects
        fstream myFile;
        myFile.open(TeamA,ios::in);
            if(myFile.is_open()){
            string line;
            //parralelize later
            bool flag=true;
            while(getline(myFile,line)){
                if(flag==true){
                   //this is to get rid of weird char as begining of file
                   flag=false;}
               else{
                stringstream iss(line);

                vector<string> vars = { };

                while (iss.good()){
                    string substr;
                    getline(iss,substr,',');
                    vars.push_back(substr);
                }
                //iterate through vars and initialize team 
                A.setName(vars[0]);// etc

                }
            }
            myFile.close();

        }
            myFile.open(TeamB,ios::in);
            if(myFile.is_open()){
            string line;
            //parralelize later
            bool flag =true;
            while(getline(myFile,line)){
                if(flag==true){
                   //this is to get rid of weird char as begining of file
                   flag=false;}
               else{
                stringstream iss(line);

                vector<string> vars = { };

                while (iss.good()){
                    string substr;
                    getline(iss,substr,',');
                    vars.push_back(substr);
                }
                //iterate through vars and initialize team 
                B.setName(vars[0]);// etc
            }
            }
            myFile.close();

        }
    
       
    
         double probA = A.calcWinProb(A,B);
         double probB = 1- probA;
        cout<< "prob: A-"<< probA << " B-" << probB <<endl;
    
    }
    void CalcAllTeamMatches(vector<string> Matchups){
        vector<Team> matches;     
        //open team.csv files and push data into vector<Team> Matches
        fstream myFile;
        //parralelize later
        for(int i = 0 ; i< Matchups.size();i++){
                myFile.open(Matchups[i],ios::in);
                if(myFile.is_open()){
                    string line;
                    bool flag=true;
                    while(getline(myFile,line)){
                        if(flag==true){
                         //this is to get rid of weird char as begining of file
                        flag=false;}
                        else{
                    stringstream iss(line);

                    vector<string> vars = { };
                    Team temp;

                    while (iss.good()){
                        string substr;
                        getline(iss,substr,',');
                        vars.push_back(substr);
                    }
                    //iterate through vars and initialize team 
                    temp.setName(vars[0]);// etc
                    matches.push_back(temp);

                }   }
                myFile.close();

                }

        }
        //parralelize later
        for(int j = 0 ; j<matches.size();j+2){
            if(j+1>=matches.size()){break;}
            double probA = matches[j].calcWinProb(matches[j],matches[j+1]);
            double probB = 1- probA;
            cout<< "prob: "<<matches[j].getName()<<"-"<< probA <<matches[j+1].getName()<<"-"<< probB <<endl;
        }
    }
    

  
    void Players(string playersFile){

        vector<Player> list;
        //change to while loop
        fstream myFile;
        myFile.open(playersFile,ios::in);
            if(myFile.is_open()){
            string line;
            //parralelize later
            bool flag=true;
            while(getline(myFile,line)){
                if(flag==true){
                   //this is to get rid of weird char as begining of file
                   flag=false;}
               else{
                stringstream iss(line);

                vector<string> vars = { };

               while (iss.good()){
                    string substr;
                    getline(iss,substr,',');
                    vars.push_back(substr);
                }
                //iterate through vars and initialize player
                Player temp;
                temp.setName(vars[0]);
                // etc


                list.push_back(temp);

            }}
            myFile.close();

        }
        insertionSort(list);
        for(int i=0; i<list.size();i++){
            cout<<list[i].getName()<<" "<< list[i].getTeam()<<" "<< list[i].getAge()<<" "<< list[i].getrecvTargets()<<" "<< list[i].getrecvYards()<<" "<< list[i].getroutesRun()<<endl;
 
        }
    }

      void insertionSort(vector<Player>arr){
        //key should the comparable variable that ranks the players. 
        int i,j;
        Player key;
        int size= arr.size();
        //add #pragma parrallel for
        for(i=1;i<size-1;i++){
            key = arr[i];
            j=i-1;
        
            while(j>=0&& arr[j].getrecvYards()>key.getrecvYards()){
                arr[j+1]=arr[j];
                j=j-1;
            }
            arr[j+1]=key;
        }

    }





 
};


