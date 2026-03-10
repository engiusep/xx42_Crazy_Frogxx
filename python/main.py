from flask import Flask, render_template
import requests

app = Flask(__name__)
app.jinja_env.add_extension('jinja2.ext.do')

@app.route('/')
def home():
    
    fd_url = "https://api.football-data.org/v4/competitions/FL1/matches?status=SCHEDULED"# ?dateFrom=2026-02-28&dateTo=2026-03-03"
    fd_headers = {"X-Auth-Token": "7b362b6ab0ae49259e7e56877633ea01"}
    
    odds_url = "https://api.the-odds-api.com/v4/sports/soccer_france_ligue_one/odds?regions=eu&markets=h2h&apiKey=1b1e767cb06147b5259bdaaba97f83c8"

    try:
        fd_res = requests.get(fd_url, headers=fd_headers)
        fd_data = fd_res.json()
        matches = fd_data.get('matches', [])
        comp = fd_data.get('competition')

        odds_res = requests.get(odds_url)
        odds_data = odds_res.json() if odds_res.status_code == 200 else []

        for match in matches:
            home_team = match['homeTeam']['name']
            for odd_match in odds_data:
                if odd_match['home_team'] in home_team or home_team in odd_match['home_team']:
                    bookmaker = next((b for b in odd_match['bookmakers'] if b['key'] == 'winamax_fr'), None)
                    if bookmaker:
                        match['bookmaker_odds'] = bookmaker['markets'][0]['outcomes']
                    break

        return render_template('index.html', matches=matches, comp=comp)

    except Exception as e:
        return f"Erreur : {str(e)}"

if __name__ == '__main__':
    app.run(debug=True)