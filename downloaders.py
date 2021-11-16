from bs4 import BeautifulSoup
import requests
import csv

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

# array for a week of matchups (filled with matchups)

# array for the current season (filled with weeks)

# parallelism will speedup the hell outta this though
def download_teams_serial():

    # perform the download for each team (32 teams)
    # also write to a csv file with the mascot name as the file name
    # i.e. bills.csv contains the bills' data

    for team in teams:

        # csv creation / instantiation
        out_file = open(team + ".csv", "w")
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
def test():

    # using steelers, as they are only team with draw
    out_file = open("steelers.csv", "w")
    out_writer = csv.writer(out_file)

    wins = 0
    loss = 0
    draw = 0
    url = base_url + "/teams/" + teams["steelers"] + "/2021.htm"
    page = requests.get(url).content
    souped = BeautifulSoup(page, "lxml")
    all_games = souped.find("div", {"id":"all_games"})
    points_for = all_games.findAll("td", {"data-stat":"pts_off"})
    points_against = all_games.findAll("td", {"data-stat":"pts_def"})
    yards_for = all_games.findAll("td", {"data-stat":"yards_off"})
    yards_against = all_games.findAll("td", {"data-stat":"yards_def"})
    for i in range(len(points_for)):
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

        out_writer.writerow(data_to_write)

        # print(str(wins) + ",", end='')
        # print(str(loss) + ",", end='')
        # print(str(draw) + ",", end='')
        # print(points_for[i].text + ",", end='')
        # print(points_against[i].text + ",", end='')
        # print(yards_for[i].text + ",", end='')
        # print(yards_against[i].text)

    out_file.close()



download_teams_serial()
# test()