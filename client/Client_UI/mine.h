#pragma once
#include "constant.h"
#include "question.h"

/* Store mine infomation
* @param	id		    mine id
* @param	type	    mine type
* @param	wood	    wood amount
* @param	stone	    stone amount
* @param	iron	    iron amount
* @param	question    question of the mine
*/
class Mine {
public:
    int id;
    int type;
    int wood;
    int stone;
    int iron;
    Question question[TYPE_MINE_SIZE];

    Mine();
    Mine(int id, int type);
};
