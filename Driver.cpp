

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
class Player{
    public:
    string name;
    string team;
    int age;
    int recivingYards;
    int recivingTargets;
    int routesRun;

    //calculations vars
    int yprr = 0;
    int ypt =0;
    
    string getName(){
        return name;
    }
    string getTeam(){
        return team;
    }
    int getAge(){
        return age;
    }
    int getrecvYards(){ return recivingYards;}
    int getrecvTargets(){ return recivingTargets;}
    int getroutesRun(){ return routesRun;}
    
    
    
    void setName(string name){
        this->name=name;
    }
     void setTeam(string team){
        this->team=team;
    }
    void setAge(int age){
        this->age=age;
    }
    void setRecvingYards(int recivingYards){this->recivingYards=recivingYards;}
    void setRecivingTargets(int recivingTargets){this->recivingTargets=recivingTargets;}
    void setRoutesRun(int routesRun){this->routesRun=routesRun;}
    
    //calculations vars
    //Yards per routes run
    int yprr (){
        yppr=recivingYards/routesRun;
        return yppr;
    }
    //yards per Target
    int ypt(){
        ypt =  recivingYards/ recivingTargets;
    return ypt;
}
    



};
class Team {
    public:
    vector<Player> members;
    string name;
    int totalWins;
    int yardsAllowed;
    int yds;
    int pts;
    int ptsA;
    double winProb;
    
    void addPlayer(Player p){
        members.push_back(p);
    }
    int getWins(){return totalWins;}
    int getYardsAll(){return yardsAllowed;}
    int getYds(){return yds;}
    int getPts(){return pts;}
    int getPtsA(){return ptsA;}
    string getName(){return name;}
    void setName(string name){this-> name=name;}
    void setWins(int totalWins){this->totalWins=totalWins;}
    void setYardsAllowed(int yardsAllowed){this->yardsAllowed=yardsAllowed;}
    void setYds(int yds){this->yds=yds;}
    void setTotalPts(int pts){this-> pts=pts;}
    void setPtsAllowed(int ptsA){this-> ptsA=ptsA;}
    
    //calc
    double calcWinProb(Team A, Team B){
        double predict=(    (A.getWins()*0.3)   +   (A.getYds()*.15)    +   (A.getYardsAllowed()*.25)   +   (A.getPts()*.15)    +   (A.getPtsA()*.15)   )  /
                       (    (B.getWins()*0.3)   +   (B.getYds()*.15)    +   (B.getYardsAllowed()*.25)   +   (B.getPts()*.15)    +   (B.getPtsA()*.15)   );
        
    }
    
    
};




int main(){
    int N = 1000;// size of lines in file 
    vector<Player> list;
    vector<Team> teams;

    //input data from csv file
    
    
    for(int i = 0; i<N;i++){
        Player temp;
       temp.setName(" ");
       temp.setTeam(" ");
       temp.setAge(25);
       temp.setrecivingTargets(10);
       temp.setRecvingYards(100);
       temp.setroutesRun(5);
       
       // calc for players
       temp.yppr();
       temp.ypt();
        
       list.push_back(temp);

    }
    //initialize all 32 teams. 
    
    //...etc
    
    
    //push players into correct teams
    for(int i =0; i< teams.size() ; i++){
        Team temp = Teams[i]; 
        for (int j = 0 ; j<list.size(); j++ ){
            if(temp.getName==list[j].getTeam()){
                temp.push_back(list[j]);
                }
            }
        
    }
       
    //sort list based on rating/a single stat
    insertionSort(list);
    

    return 0;
}
void CalcTeamWinProb(string TeamA,string TeamB){
    Team A , B;
    Team A.setName(TeamA);
    Team B.setName(TeamB);
    
    //open team.csv files and push data into team objects
    
    double probA = A.calcProb(A,B);
    double probB = 1- probA;
    cout<< "prob: A-"<<probA<<" B-"<<probB<<endl;
    
}
void CalcAllTeamMatches(vector<string> Matchups){

}
void insertionSort(vector<Player>arr){
//key should the comparable variable that ranks the players. 
int i,j, key;
int size= arr.size();
    //add #pragma parrallel for
    for(i=1;i<size-1;i++){
        key = arr[i];
        j=i-1;
        
        while(j>=0&& arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }

}
void Players(string playersFile){

vector<Player> list;
   //change to while loop
 for(int i = 0; i<N;i++){
        Player temp;
       temp.setName(" ");
       temp.setTeam(" ");
       temp.setAge(25);
       temp.setrecivingTargets(10);
       temp.setRecvingYards(100);
       temp.setroutesRun(5);
       
       // calc for players
       temp.yppr();
       temp.ypt();
        
       list.push_back(temp);

    }
 insertionSort(list);
 for(int i=0; i<list.size();i++){
    cout<<list[i].getName()<<" "<< list[i].getTeam()<<" "<< list[i].getAge()<<" "<< list[i].getRecivingTagerts()<<" "<< list[i].getRecvingYards()<<" "<< list[i].getRoutesRun()<<endl;
 
 }

   
}
