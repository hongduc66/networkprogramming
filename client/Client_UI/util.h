#include "response.h"
#include "qstring.h"
#include "string.h"
#include "thread_receive.h"
#include "game.h"
#include "qdebug.h"

/* Pack all info of a packet
    * @param	code            [IN]    code of the packet
    * @param	payload	        [IN]    data of the packet
    * @param	mess            [OUT]   message to send to server
    * @return NULL
*/
void pack(char* code, char* payload, char* mess);

//Payload

/* Pack auth to a payload
    * @param	username        [IN]    User name
    * @param	password        [IN]    Password
    * @param	payload	        [OUT]   Data packed
    * @return NULL
*/
void auth_payload(char* username, char* password, char* payload);

/* Pack join_lobby_request to a payload
    * @param	game_id        [IN]    Lobby id
    * @param	team_id        [IN]    Team id
    * @param	payload	       [OUT]   Data packed
    * @return NULL
*/
void join_lobby_payload(char* game_id, char* team_id, char* payload);

/* Pack attack_castle_request to a payload
    * @param	castle_id       [IN]    Castle id
    * @param	question_id     [IN]    Question id
    * @param	answer_id       [IN]    Answer id
    * @param	payload	        [OUT]   Data packed
    * @return NULL
*/
void attack_castle_payload(char* castle_id, char* question_id, char* answer_id, char* payload);


/* Pack join_lobby_request to a payload
    * @param	mine_id         [IN]    Mine id
    * @param	question_id     [IN]    Question id
    * @param	answer_id       [IN]    Answer id
    * @param	payload	        [OUT]   Data packed
    * @return NULL
*/
void attack_mine_payload(char* mine_id, char* type, char* question_id, char* answer_id, char* payload);

// Binding attributes when switching stage
void bindSocket(Socket* currentSocket, Socket* newSocket);
void bindLobby(Lobby*,Lobby*);
void bindUser(User*,User*);
void bindPlayer(Player*,Player*);

// UI helper
QString getQuestText(Question);

// For login and signup
Auth auth_data(char* payload);

// Lobby activities


/*  Unpack data from create_lobby response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Create_lobby create_lobby_data(char* payload);

/*  Unpack data from get_lobby response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Get_lobby get_lobby_data(char* payload);

/*  Unpack data from join_lobby response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Join_lobby join_lobby_data(char* payload);

/*  Unpack data from quit_lobby response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Quit_lobby quit_lobby_data(char* payload);

/*  Unpack data from start_game response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Start_game start_game_data(char* payload);

/*  Unpack data from kick response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Kick kick_data(char* payload);

void resolve_team_player_str(char* string, int team_number, int team_player[]);

/*  Unpack data from update_lobby response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Update_lobby update_lobby_data(char* payload);

// Player update

/*  Unpack data from change_team response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Change_team change_team_data(char* payload);

/*  Unpack data from ready response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Ready ready_data(char* payload);

/*  Unpack data from  unready response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Unready unready_data(char* payload);

/*  Unpack data from buy_weapon response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Buy_weapon buy_weapon_data(char* payload);

/*  Unpack data from buy_wall response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Buy_wall buy_wall_data(char* payload);

/*  Unpack data from attack_castle response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Attack_castle attack_castle_data(char* payload);

/*  Unpack data from attack_mine response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Attack_mine attack_mine_data(char* payload);

Cheat cheat_data(char* payload);

// Update game

/*  Unpack data from update_game response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Update_game update_game_data(char* payload);

/*  Unpack data from update_castle_ques response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Update_castle_ques update_castle_ques_data(char* payload);

/*  Unpack data from update_mine_ques response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Update_mine_ques update_mine_ques_data(char* payload);

/*  Unpack data from update_castle_attack response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Update_castle_attack update_castle_attack_data(char* payload);

/*  Unpack data from update_mine_attack response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Update_mine_attack update_mine_attack_data(char* payload);

/*  Unpack data from update_buy_weapon response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Update_buy_weapon update_buy_weapon_data(char* payload);

/*  Unpack data from update_buy_wall response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Update_buy_wall update_buy_wall_data(char* payload);


/*  Unpack data from update_timely response
    * @param	payload       IN]    Data from response packet
    * @return response info
*/
Update_timely update_timely_data(char* payload);

Update_cheat update_cheat_data(char* payload);
