#ifndef _DRIVER_H
#define _DRIVER_H
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include"Team.cpp"
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>
#include<math.h>
#include<omp.h>

#include <dirent.h>

class Driver{
    public:
        Driver();
        void CalcTeamWinProb(string TeamA,string TeamB);
        void CalcAllTeamMatches(string Matchups);
        void Players(string playerFolder);
        void insertionSort(vector<Player> arr);
    private:
    vector<Player> list;
    vector<Team> teams;
    double startTime;
    double elapsed;
};

#endif