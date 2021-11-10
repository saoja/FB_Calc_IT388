#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;
class Player{
    public:
    string name;
    int age;
    int recivingYards;
    int recivingTargets;
    int roiutsRun;

    //calculations
    int yprr = 0;
    int ypt =0;



};
//basic Functions for calclations. Number of Calculations not final 
//Yards per routes run
int yprr (int recvYards,int routesRun){
    return recvYards/routesRun;
}
//yards per Target
int ypt(int recvYards, int recvTargets){
    return recvYards/ recvTargets;
}
int main(){
    int N = 1000;// size of list
    vector<Player> list;

    //input data from file
    for(int i = 0; i<N;i++){
        Player temp;
        temp.name= "";//all stats would be from file these are place holders
        temp.age= 25;
        temp.recivingYards= 100;
        temp.recivingTargets = 25;
        temp.roiutsRun = 10;
        //calculations
        temp.yprr=yprr(temp.recivingYards,temp.roiutsRun);
        temp.ypt=ypt(temp.recivingYards,temp.recivingTargets);

        list.push_back(temp);

    }
    
       
    //sort list based on rating/a single stat

    return 0;
}