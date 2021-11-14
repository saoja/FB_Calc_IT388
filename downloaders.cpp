#include <iostream>
#include <list>
#include <map>

using namespace std;

struct team{
    string city;
    string mascot;
};
struct player{
    string name;
    string position;
    int jersey_num;
};
struct matchup{
    string home_team;
    string away_team;
};

map<string, string> teams = {
    {"bills", "buffalo-bills"},
    {"dolphins", "miami-dolphins"},
    {"patriots", "new-england-patriots"},
    {"jets", "new-york-jets"},
    {"ravens", "baltimore-ravens"},
    {"bengals", "cincinnati-bengals"},
    {"browns", "cleveland-browns"},
    {"steelers", "pittsburg-steelers"},
    {"texans", "houston-texans"},
    {"colts", "indianapolis-colts"},
    {"jaguars", "jacksonville-jaguars"},
    {"titans", "tennessee-titans"},
    {"broncos", "denver-broncos"},
    {"chiefs", "kansas-city-chiefs"},
    {"raiders", "las-vegas-raiders"},
    {"chargers", "los-angeles-chargers"},
    {"cowboys", "dallas-cowboys"},
    {"giants", "new-york-giants"},
    {"eagles", "philadelphia-eagles"},
    {"football team", "washington-football-team"},
    {"bears", "chicago-bears"},
    {"lions", "detroit-lions"},
    {"packers", "green-bay-packers"},
    {"vikings", "minnesota-vikings"},
    {"falcons", "atlanta-falcons"},
    {"panthers", "carolina-panthers"},
    {"saints", "new-orleans-saints"},
    {"buccaneers", "tampa-bay-buccaneers"},
    {"cardinals", "arizona-cardinals"},
    {"rams", "los-angeles-rams"},
    {"49ers", "san-francisco-49ers"},
    {"seahawks", "seattle-seahawks"}
};

void update_weekly_matchups(matchup matchups[]);
void dl_single_team(string name);
void dl_player();

void update_weekly_matchups(matchup matchups[]){
    // confirm the weekly matchups
}
void dl_all_teams(){
    // download all teams (by team mascot name)
}

void dl_player(string name){
    // download the player by name
}