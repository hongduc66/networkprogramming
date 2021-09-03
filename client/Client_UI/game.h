#pragma once

#include "team.h"
#include "mine.h"
#include "lobby.h"
#include "qdebug.h"

/* Store game infomation
    * @param	id              id of the game
    * @param	day	            control time of the game
    * @param	team_number     number of team plays
    * @param	teams           each team infomation
    * @param	castles         each castle infomation
    * @param	mines           each mine infomation
    
*/
class Game {
public:
    unsigned long long id;
    int day;
    int team_number;
    Team teams[MAX_TEAM_OF_GAME];
    Mine mines[MAX_MINE_OF_GAME];
    Castle castles[MAX_CASTLE_OF_GAME];

    Game();
    Game(unsigned long long id, int team_number, Player* players, int player_size);
    
    /* Init the infomation for game
        * @param	id              id of the game
        * @param	team_number     number of team plays
        * @param	players         array of player infomation
        * @param	player_number   length of the players
        * @return   NULL
    */
    void init_game(unsigned long long id, int team_number, Player* players, int player_number);
    
    /* Get update infomation by time from server
        * @param	payload     data from server
        * @return   NULL
    */
    void update_timely_response(char* payload);
    
    /* Get update infomation from server
        * @param	payload     data from server
        * @param	lobby       lobby information
        * @param	player      players information
        * @return   NULL
    */
    void update_game_response(char * payload, Lobby& lobby, Player& player);

    /*  Sort rank by score
        * @param	t1     first score
        * @param	t2     second score
        * @return   true if t1 > t2, 0 otherwise
    */
    bool rank_sort(int t1, int t2 );
};
