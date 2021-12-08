
#include "Driver.h"


using std::cout; using std::cin;
using std::endl; using std::vector;


    Driver::Driver(){
        list={};
        teams={};
        startTime=0;
        elapsed=0;

    }
    void Driver:: CalcTeamWinProb(string TeamA,string TeamB){
        
        TeamA+=".csv";
        TeamB+=".csv";
        Team A;
        A.setName(TeamA);
        Team B;
        B.setName(TeamB);
        vector<int> varsA;
        vector<int> varsB;
        fstream myFile;
        myFile.open("/home/saoja/expanse/Project/teams"+TeamA,ios::in);
            if(myFile.is_open()){
            string line;
            
          
            while(getline(myFile,line)){
               
                stringstream iss(line);

              

                while (iss.good()){
                    string substr;
                    getline(iss,substr,',');
                    if(substr==""){}
                    else{
                        stringstream s;
                        int n;
                        s<<substr;
                        s>>n;
                        varsA.push_back(n);
                    }
                    
                }
                
            }
            myFile.close();

        }
            myFile.open("teams/"+TeamB,ios::in);
            if(myFile.is_open()){
            string line;
            while(getline(myFile,line)){
               
                stringstream iss(line);
                while (iss.good()){
                    string substr;
                    getline(iss,substr,',');
                    if(substr==""){}
                    else{
                        stringstream s;
                        int n;
                        s<<substr;
                        s>>n;
                        varsB.push_back(n);
                    }
                    
                }
            }
            myFile.close();

        }
      
        int n;
         //Team A
               
              
                A.setWins(varsA[0]);
               
                A.setYardsAllowed(varsA[4]);
               
                A.setTotalPts(varsA[5]);
              
                A.setPtsAllowed(varsA[4]);
             
                A.setYds(varsA[6]);
        //Team B
              
                B.setWins(varsB[0]);
               
                B.setYardsAllowed(varsB[4]);
              
                B.setTotalPts(varsB[5]);
              
                B.setPtsAllowed(varsB[4]);
               
                B.setYds(varsB[6]);
       
    
         double probA = A.calcWinProb(A,B);
         double probB = 1- probA;
        cout<< "prob: A-"<< probA << " B-" << probB <<endl;
    }
    void Driver::CalcAllTeamMatches(string Matchups){
        vector<string> matches;   
        //open team.csv files and push data into vector<Team> Matches
        fstream myFile;
       
                myFile.open(Matchups,ios::in);
                if(myFile.is_open()){
                    string line;
                    while(getline(myFile,line)){
                  
                    stringstream iss(line);
                    while (iss.good()){
                        string substr;
                        getline(iss,substr,',');
                        if(substr==""){}
                        else{
                        matches.push_back(substr);
                        }
                    }
                    }
                    myFile.close();

                }
                
        int start=omp_get_wtime();
       
        
        #pragma parrallel for
        for(int j = 0 ; j<matches.size();j++){
            if(j+1>=matches.size()){break;}
            CalcTeamWinProb(matches[j],matches[j+1]);
        }
        int elapsed=omp_get_wtime();
        int finish=elapsed-start();
        cout<<"Time recorded: "<<finish<<endl;
    }
    

  
    void Driver:: Players(string playerFolder){
        DIR *dir; struct dirent *diread;
        vector<string> files;

        if ((dir = opendir("players")) != nullptr) {
            while ((diread = readdir(dir)) != nullptr) {
                files.push_back(diread->d_name);
            }
            closedir (dir);
        } else {
            perror ("opendir");
            return;
        }
    //to get rid of 2 files that are just "."'s
    files.erase (files.begin());
    files.erase (files.begin());
    
    #pragma parrallel for
    for (auto file : files) {
       
        fstream myFile;
        myFile.open("players/"+file,ios::in);
            if(myFile.is_open()){
            string line;
          
            vector<string> vars={""};
            while(getline(myFile,line)){
                stringstream iss(line);
               while (iss.good()){
                    string substr;
                    getline(iss,substr,',');
                    
                    vars.push_back(substr);
                    }
                }

                if(vars.size()>3){
                    
                    Player temp;
                    string name= file;
                    //removing ".csv" from file name
                    name.resize(name.size() - 4);
                    temp.setName(name);
                    temp.setRecivingTargets(vars[1]);
                    temp.setRecvingYards(vars[3]);
                    temp.setRoutesRun(vars[2]);
                    list.push_back(temp);
                }
            }
            myFile.close();

        }

        insertionSort(list);
        #pragma parrallel for
        for(int i=0; i<list.size();i++){
            cout<<list[i].getName()<<" Age:"<< list[i].getAge()<<" recvTargets: "<< list[i].getrecvTargets()<<" recvYards: "<< list[i].getrecvYards()<<" routesRun: "<< list[i].getroutesRun()<<endl;
        }
    }
    
void  Driver::insertionSort( vector<Player> arr){
        //key should the comparable variable that ranks the players. 
        int i,j;
        Player key;
        int size= arr.size();
         int start=omp_get_wtime();
        #pragma parrallel for
        for(i=1;i<size-1;i++){
            key = arr[i];
            j=i-1;
        
            while(j>=0&& arr[j].getrecvYards()>key.getrecvYards()){
                arr[j+1]=arr[j];
                j=j-1;
            }
            arr[j+1]=key;
        }

        list=arr;
        int elapsed=omp_get_wtime();
        int finish=elapsed-start();
        cout<<"Time recorded: "<<finish<<endl;

}



