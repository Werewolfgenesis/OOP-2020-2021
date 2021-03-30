#include "Team.h"

Team::Team(){
	strcpy(team_name, "Barca");
	for (size_t i = 0; i < 5; i++)
	{
		games[i] = '-';
	}
}

Team::Team(char team_name[], Player player[], char games[])
{
	strcpy(this->team_name, team_name);
	strcpy(this->games, games);
	for (size_t i = 0; i < 20;i++)
	{
		this->players[i] = player[i];
	}
}

void Team::print() const
{
	std::cout << "Team name: " << team_name << std::endl;
    //for(Player player : players) 
    for (int i = 0; i < 20; ++i) {
        players[i].print();
    }
    
}

double Team::calcPercents() const
{
    int counter = 0;
    for(int i = 0; i < 6; i++)
    {
        if(games[i] == 'W') counter++;
    }
    return (100*counter)/5;
}

void Team::winner_forecast(const Team &other)
{
    double firstTeamPerc, secondTeamPerc;
    firstTeamPerc = this->calcPercents();
    secondTeamPerc = other.calcPercents();
    
    
    double difference = (firstTeamPerc > secondTeamPerc) ? firstTeamPerc - secondTeamPerc : secondTeamPerc - firstTeamPerc;
    firstTeamPerc = 100 - difference;
    secondTeamPerc = difference;

    double x = (firstTeamPerc > secondTeamPerc) ? 0.25 * firstTeamPerc + 0.75 * secondTeamPerc : 0.25*secondTeamPerc + 0.75*firstTeamPerc;

    if (firstTeamPerc > secondTeamPerc) {
        firstTeamPerc -= 0.25*firstTeamPerc;
        secondTeamPerc -= 0.75*secondTeamPerc;
    }
    else
    {
        firstTeamPerc -= 0.75*firstTeamPerc;
        secondTeamPerc -= 0.25*secondTeamPerc;
    }
	std::cout << "Suggested winner: " << (firstTeamPerc > secondTeamPerc) ? this->team_name : other.team_name;
    std::cout<<"1 - "<<100/firstTeamPerc<<"\nX - "<<100/x<<"\n2 - "<<100/secondTeamPerc;
}