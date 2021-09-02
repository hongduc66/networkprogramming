#pragma once
#include "stream.h"


/* Store player infomation
    * @param    id          Id of the player
    * @param    username    User name
    * @param    team_id     Id of the player's team
    * @param    state       
*/
class Player {
public:
    int id;
    char username[USERNAME_LEN];
    int team_id;
    int state;

    Player();
    Player(char * username);
    Player(int id, char* username, int team_id, int state);

    ~Player();
    
    /* Send ready request to server
        * @param    socket          [IN]    Socket to communicate to server
        * @return   NULL
    */
    void ready_request(Socket& socket);
    
    /* Send unready request to server
        * @param    socket          [IN]    Socket to communicate to server
        * @return   NULL
    */
    void unready_request(Socket& socket);
    
    /* Send change team request to server
        * @param    socket          [IN]    Socket to communicate to server
        * @param    team_id         [IN]    Id team to change
        * @return   NULL
    */
    void change_team_request(Socket& socket, int team_id);
    
    /* Send attack castle request to server
        * @param    socket          [IN]    Socket to communicate to server
        * @param    castle_id       [IN]    Id castle to attack
        * @param    question_id     [IN]    question id of the castle
        * @param    asnwer_id       [IN]    answer id of the question
        * @return   NULL
    */
    void attack_castle_request(Socket& socket, int castle_id, int question_id, int answer_id);
    
    /* Send attack castle request to server
        * @param    socket          [IN]    Socket to communicate to server
        * @param    mine_id         [IN]    Id mine to attack
        * @param    type            [IN]    type of resource
        * @param    question_id     [IN]    question id of the castle
        * @param    asnwer_id       [IN]    answer id of the question
        * @return   NULL
    */
    void attack_mine_request(Socket& socket, int mine_id, int type, int question_id, int answer_id);
    
    /* Send buy weapon request to server
        * @param    socket          [IN]    Socket to communicate to server
        * @param    weapon_id       [IN]    Weapon id to get
        * @return   NULL
    */
    void buy_weapon_request(Socket& socket, int weapon_id);
    
    /* Send buy wall request to server
        * @param    socket          [IN]    Socket to communicate to server
        * @param    wall_id         [IN]    Wall id to get
        * @param    wall_id         [IN]    Castle id to equip
        * @return   NULL
    */
    void buy_wall_request(Socket& socket, int wall_id, int caslte_id);
    
    /* Send cheat request to server
        * @param    socket          [IN]    Socket to communicate to server
        * @return   NULL
    */
    void cheat_request(Socket& socket);

    /* Get ready result from server
        * @param    payload         [IN]    Data from server
        * @return   NULL
    */
    void ready_response(char* payload);
    
    
    /* Get unready result from server
        * @param    payload         [IN]    Data from server
        * @return   NULL
    */
    void unready_response(char* payload);
    
    
    /* Get change_team result from server
        * @param    payload         [IN]    Data from server
        * @param    team_id         [IN]    Id team to change
        * @return   NULL
    */
    void change_team_response(char* payload, int team_id);
    
    /* Get attack result from server
        * @param    payload         [IN]    Data from server
        * @return   NULL
    */
    void attack_castle_response(char* payload);
    
    /* Get mine result from server
        * @param    payload         [IN]    Data from server
        * @return   NULL
    */
    void attack_mine_response(char* payload);
    
    /* Get buy weapon result from server
        * @param    payload         [IN]    Data from server
        * @return   NULL
    */
    void buy_weapon_response(char* payload);
    
    /* Get buy wall result from server
        * @param    payload         [IN]    Data from server
        * @return   NULL
    */
    void buy_wall_response(char* payload);
    
    /* Get cheat request result from server
        * @param    payload         [IN]    Data from server
        * @return   NULL
    */
    void cheat_response(char* payload);
};
