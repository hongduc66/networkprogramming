#pragma once
#include "stream.h"

class Player {
public:
	int id;
	char username[USERNAME_LEN];
	int game_id;
	int team_id;
	int state;

	Player();
	Player(char * username);
	Player(int id, char* username, int game_id, int team_id, int state);
	~Player();

	void ready_request(Socket& socket);
	void unready_request(Socket& socket);
	void change_team_request(Socket& socket, int team_id);
	void attack_castle_request(Socket& socket, int castle_id, int question_id, int answer_id);

	void ready_response(char* payload);
	void unready_response(char* payload);
	void change_team_response(char* payload, int team_id);

};