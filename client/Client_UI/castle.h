#pragma once

#include "constant.h"
#include "wall.h"
#include "question.h"

/* Store castle infomation
    * @param	id              id of the castle
    * @param	wall	        wall of the castle if exist
    * @param	occupied_by     team occupy the castle
    * @param	question        the question of the castle
*/
class Castle {
public:
    int id;
    Wall wall;
    int occupied_by;
    Question question;

    Castle();
    Castle(int id);
};
