

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
    void setrecivingTargets(int recivingTargets){this->recivingTargets=recivingTargets;}
    void setroutesRun(int routesRun){this->routesRun=routesRun;}
    
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
    double winProb;
    
    void addPlayer(Player p){
        members.push_back(p);
    }
    
    //calc
    double calcWinProb(Team A, Team B){
        return 0;
    }
    
    
};
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
    Team Bears;
    Bears.setName("Bears");
    teams.push_back(Bears);
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
