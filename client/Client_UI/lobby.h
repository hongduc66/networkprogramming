#pragma once
#include "stream.h"
#include "auth.h"
#include "player.h"


 /* Store lobby information
        * @param	id	    	   	Id of the lobby
        * @param	host		   	Id of the host        
        * @param	team_number		Number of team in a game
        * @param	team_players	The team's id of each player
        * @param	players     	Each player's information        
        * @param    state           
 */
class Lobby {
public:
    unsigned long long id;
    int host;
    int team_number;
    int player_number;
    int team_players[MAX_NUM_PLAYER];
    Player players[MAX_NUM_PLAYER];
    int state;

    Lobby();
    Lobby(unsigned long long id);
    Lobby(unsigned long long id, int team_number);
    ~Lobby();

    /* Send create lobby request to server
        * @param	socket		    [IN]	Socket to communicate to server
        * @param	team_number		[IN]	Number of team in a game
        * @return	NULL
    */
    void create_lobby_request(Socket& socket, int team_number);
    
    /* Send request to get lobby list from server
        * @param	socket		    [IN]	Socket to communicate to server
        * @return	NULL
    */
    void get_lobby_request(Socket& socket);
    
    /* Send join lobby request to server
        * @param	socket		    [IN]	Socket to communicate to server
        * @param	game_id		    [IN]	Id of the game
        * @param	team_id		    [IN]	Id of the team to join
        * @return	NULL
    */
    void join_lobby_request(Socket& socket, unsigned long long game_id, int team_id);
    
    /* Send quit lobby request to server
        * @param	socket		    [IN]	Socket to communicate to server
        * @return	NULL
    */
    void quit_lobby_request(Socket& socket);
    
    /* Send start game request to server
        * @param	socket		    [IN]	Socket to communicate to server
        * @return	NULL
    */
    void start_game_request(Socket& socket);
    
    /* Kick player out of the lobby         
        * @param	socket		    [IN]	Socket to communicate to server
        * @param    player_id       [IN]    Id of the kicked player
        * @return	NULL
    */
    void kick_request(Socket& socket, int player_id);

    /*  Get lobby infomation from server 
        * @param	payload		    [IN]	Socket to communicate to server
        * @param    player_id       [IN]    Player's id
        * @return	Player                  Player's infomation
    */
    Player create_lobby_response(char* payload, char* username);
    
    /*  Get list lobby infomation from server 
        * @param	payload		    [IN]	Socket to communicate to server
        * @param    lobbies         [OUT]   List of lobbies
        * @param	size            [OUT]   Size of the list
        * @return   NULL
    */
    void get_lobby_response(char* payload, Lobby* lobbies, int& size);
    
    /*  Get lobby and player infomation from join request 
        * @param	payload		    [IN]	Socket to communicate to server
        * @param    username        [IN]    User name 
        * @param	team_id         [OUT]   Size of the list
        * @return   Player                  Player's infomation
    */
    Player join_lobby_response(char* payload, char* username, int& team_id, int& team_number);
    
    /*  Get result from quit request
        * @param	payload		    [IN]	Socket to communicate to server
        * @return	NULL
    */
    int quit_lobby_response(char* payload);
    
    /*  Get result from start game request
        * @param	payload		    [IN]	Socket to communicate to server
        * @return	NULL
    */
    void start_game_response(char* payload);
    
    /*  Update lobby infomation
        * @param	payload		    [IN]	Socket to communicate to server
        * @return	NULL
    */
    void update_lobby_response(char* payload);
    
    /*  Get result from kick player request
        * @param	payload		    [IN]	Socket to communicate to server
        * @param    player_id       [IN]    Player's id
        * @return	NULL
    */
    void kick_response(char* payload, int player_id);
};
