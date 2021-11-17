# NFL Stat Downloader
# Tre Blankenship
# 2021
# uses "pro-football-reference.com"
# program written from scratch

from re import match
from bs4 import BeautifulSoup
import requests
import csv
import os

players_directory = "./players"
teams_directory = "./teams"
matchups_directory = "./matchups"

# initialize folders to store the .csv files
try:
    os.mkdir(matchups_directory)
    os.mkdir(players_directory)
    os.mkdir(teams_directory)
except OSError as e:
    pass

# home page of the website in use
base_url = "https://www.pro-football-reference.com"

# reference to allow for functional searching of team web pages
teams = {
    "bills": "buf",
    "dolphins": "mia",
    "patriots": "nwe",
    "jets": "nyj",
    "ravens": "rav",
    "bengals": "cin",
    "browns": "cle",
    "steelers": "pit",
    "texans": "htx",
    "colts": "clt",
    "jaguars": "jax",
    "titans": "oti",
    "broncos": "den",
    "chiefs": "kan",
    "raiders": "rai",
    "chargers": "sdg",
    "cowboys": "dal",
    "giants": "nyg",
    "eagles": "phi",
    "football team": "was",
    "bears": "chi",
    "lions": "det",
    "packers": "gnb",
    "vikings": "min",
    "falcons": "atl",
    "panthers": "car",
    "saints": "nor",
    "buccaneers": "tam",
    "cardinals": "crd",
    "rams": "ram",
    "49ers": "sfo",
    "seahawks": "sea"
}

# function for getting the matchups (current week)
def fill_matchups():

    url = base_url + "/years/2021/games.htm"
    games = requests.get(url).content
    soupie = BeautifulSoup(games, "lxml")
    all_games = soupie.find("table", {"id": "games"})

    rows = all_games.findAll("tr")
    for row in rows:
        cells = row.findAll("td")
        if len(cells) > 0:
            team1 = cells[3].text
            team2 = cells[5].text
            out_file = open(matchups_directory + "/matchups.csv", "w")
            out_writer = csv.writer(out_file)


# function to get a player's season stats (or career)
# name input format : "Firstname Lastname QB"
def download_player_stats(name):
    # using the name, create the unique key
    # key could end in 00, 01, 21, or 99
    pass

# downloads all players with a last name initial
def download_all_players(letter):

    # to contain the unique portion of the
    # links to each player
    player_links = []

    # page of all players with the last name beginning with letter
    url = base_url + "/players/" + letter
    
    # open that page, parse with lxml parser from bs4
    players = requests.get(url).content
    soup = BeautifulSoup(players, "lxml")

    # navigate to the table containing all players
    all_players = soup.find("div", {"id": "div_players"})
    
    # loop to pull all unique tags
    for a in all_players.findAll("a", href=True):
        player_links.append(a["href"])
    
    # loop to download each players' stats
    # using player_links[]
    # absolute shenanigans please make it stop
    for link in player_links:

        # url specific to each player
        unique_url = base_url + link

        # soupify the information
        single_player = requests.get(unique_url).content
        soupier = BeautifulSoup(single_player, "lxml")
        table = soupier.find("table", {"id": "stats"})

        # player's position to determine which stats to pull
        try:
            pos = soupier.find("strong", text="Position").next_sibling.strip("\n : \n\t")
        except:
            pass
        player_name = soupier.find("h1", {"itemprop": "name"}).text.strip("\n : \n\t").split()
        
        try:
            player_fname = player_name[0]
            player_lname = player_name[1]
        except:
            player_fname = ""
            player_lname = player_name[0]

        if table.find("stats"):
            out_file = open(players_directory+ "/" + player_lname + player_fname + ".csv", "w")
            out_writer = csv.writer(out_file)
        

            if pos == "TE" or pos == "WR":

                rows = []
                try:
                    rows = table.findAll("tr")
                except:
                    pass
                for row in rows:
                    cells = row.findAll("td")
                    row_to_write = []
                    if len(cells) > 0:
                        try:
                            targets = cells[5].text
                            receptions = cells[6].text
                            rec_yards = cells[7].text
                            touchdowns = cells[9].text

                            row_to_write.append(targets)
                            row_to_write.append(receptions)
                            row_to_write.append(rec_yards)
                            row_to_write.append(touchdowns)
                            out_writer.writerow(row_to_write)
                        except:
                            pass
                    else:
                        pass

                    row_to_write = []
                    
            elif pos == "RB":
                rows = []
                try:
                    rows = table.findAll("tr")
                except:
                    pass
                for row in rows:
                    cells = row.findAll("td")
                    row_to_write = []
                    if len(cells) > 0:
                        try:
                            rushes = cells[6].text
                            rush_yds = cells[7].text
                            touchdowns = cells[9].text

                            row_to_write.append(rushes)
                            row_to_write.append(rush_yds)
                            row_to_write.append(touchdowns)
                            out_writer.writerow(row_to_write)
                        except:
                            pass
                    else:
                        pass

                    row_to_write = []

            elif pos == "QB":
                rows = []
                try:
                    rows = table.findAll("tr")
                except:
                    pass
                for row in rows:
                    cells = row.findAll("td")
                    row_to_write = []
                    if len(cells) > 0:
                        try:
                            completions = cells[6].text
                            attempts = cells[7].text
                            pass_yards = cells[9].text
                            pass_tds = cells[10].text
                            ints = cells[11].text

                            row_to_write.append(completions)
                            row_to_write.append(attempts)
                            row_to_write.append(pass_yards)
                            row_to_write.append(pass_tds)
                            row_to_write.append(ints)
                            out_writer.writerow(row_to_write)
                        except:
                            pass
                    else:
                        pass

                    row_to_write = []
            else:
                pass

# parallelism will speedup the hell outta this though
def download_teams_serial():

    # perform the download for each team (32 teams)
    # also write to a csv file with the mascot name as the file name
    # i.e. bills.csv contains the bills' data

    for team in teams:

        # csv creation / instantiation
        out_file = open(teams_directory + "/" + team + ".csv", "w")
        out_writer = csv.writer(out_file)

        # record (w, l, d)
        wins = 0
        loss = 0
        draw = 0

        # url unique to each team
        url = base_url + "/teams/" + teams[team] + "/2021.htm"

        # acquire the parsable html page, parse with BeautifulSoup's 'lxml' parser
        page = requests.get(url).content
        souped = BeautifulSoup(page, "lxml")

        # finds all of the data required for the formulas
        # format : w, l, d, pts_for, pts_agnst, yds_for, yds_agnst
        all_games = souped.find("div", {"id":"all_games"})
        points_for = all_games.findAll("td", {"data-stat":"pts_off"})
        points_against = all_games.findAll("td", {"data-stat":"pts_def"})
        yards_for = all_games.findAll("td", {"data-stat":"yards_off"})
        yards_against = all_games.findAll("td", {"data-stat":"yards_def"})

        # iterates through the html "td"s
        # extracts the actual information
        for i in range(len(points_for)):
            
            # array to hold data (easier to write to file)
            data_to_write = []

            if points_for[i].text > points_against[i].text:
                wins += 1
            elif points_for[i].text < points_against[i].text:
                loss += 1
            elif points_for[i].text > str(0) and points_for[i].text == points_against[i].text:
                draw += 1

            data_to_write.append(wins)
            data_to_write.append(loss)
            data_to_write.append(draw)
            data_to_write.append(points_for[i].text)
            data_to_write.append(points_against[i].text)
            data_to_write.append(yards_for[i].text)
            data_to_write.append(yards_against[i].text)

            # write to the file
            out_writer.writerow(data_to_write)
        
        # close out the file for security
        out_file.close()

# simple testing (as to not spam website) ((and test functionality))
# this function is actual magic I've been awake too long
def test(name):

    # list of known possible tags
    tags = ["00", "01", "20", "21", "99"]

    # using Davante Adams, example player
    # create unique key
    tag_found = False
    split_name = name.split(" ")
    lname = split_name[1]
    fname = split_name[0]
    key = lname[0:4] + fname[0:2]
    # find the correct tag (00, 01, etc.)
    for tag in tags:
        # player specific url
        url = base_url + "/players/" + lname[0] + "/" + key + tag + ".htm"

        # find the correct player's webpage
        page = requests.get(url).content
        soup = BeautifulSoup(page, "lxml")
        title = soup.find("h1", {"itemprop": "name"})
        try:    # .text throws error on objects that don't exist
            full_name = fname + " " + lname
            # exact match
            # if full_name == title.text.strip("\n"):
        except:
            pass
    
    # player's position
    pos = split_name[2]

fill_matchups()
download_teams_serial()
# test("Davante Adams WR")
download_all_players("A")