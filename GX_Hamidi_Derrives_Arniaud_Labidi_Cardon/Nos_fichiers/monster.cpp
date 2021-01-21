/**
 * @file    monster.cpp
 * @authors Ines Hamidi, Thomas Cardon
 * @date    11 janvier 2020
 * @version 1.0
 * @brief   Définition des méthodes de la classe monster.h
 **/

#include "type.h"

#include "monster.h"
#include "cooldowns.h"

#include "definitions.h"

using namespace nsGame;

Monster::Monster(unsigned behaviourId) {
    this->behaviourId = behaviourId;
}

std::string Monster::getEntityId() {
    return "Monster" + std::to_string(this->behaviourId);
}

void Monster::spawn() {
    this->pos.setX(15);
    this->pos.setY(1 * behaviourId);
}

void Monster::damage() {
    this->kill();
}

void Monster::load() {
    std::cout << "[Monster#" << getEntityId() + "] Loading" << std::endl;

    this->movementSpeed = 0.35;
    Cooldowns::createCooldown(getEntityId() + "_move", this->_getDelay());

    for (int i = 1; i <= 6; i++) {
        this->top.sprites.push_back(nsGui::Sprite(RES_PATH + "/entities/monsters/" + std::to_string(this->behaviourId) + "/" + std::to_string(this->behaviourId) + "-" + std::to_string(i) + ".i2s"));
    }

    this->spawn();
}

void Monster::update(unsigned delta, CMat & mat, Player &p1, Player &p2)
{
    if (slain) return;

    canMove = Cooldowns::isCooldownOver(getEntityId() + "_move");
    if (!canMove) return;

    //std::cout << "[Monster#" << getEntityId() + "] Position: x= " << this->getPosition().getY() << ", y= " << this->getPosition().getY() << std::endl;

<<<<<<< HEAD
<<<<<<< HEAD
    if (this->behaviourId == 1) //Behaviour 1 : follow outer walls
=======
    if (this->behaviourId == 1) //Behaviour 1 : follow outer walls || Behaviour 2 : follow a little wall
>>>>>>> main
=======
    if (this->behaviourId == 1) //Behaviour 1 : Follow outer walls
>>>>>>> main
    {
        unsigned x = this->getPosition().getX(), y = this->getPosition().getY();

        if (!this->inCollision(mat, x + 1, y) && y == 1) {
            this->pos.setX(x + 1);
        }
        else if (!this->inCollision(mat, x, y - 1) && x == 1) {
            this->pos.setY(y - 1);
        }
        else if (!this->inCollision(mat, x - 1, y) && y == mat.size() - 2) {
            this->pos.setX(x - 1);
        }

        else if (!this->inCollision(mat, x, y + 1) && y <= mat.size() - 2) {
            this->pos.setY(y + 1);
        }
    }
    else if (this->behaviourId == 2) //Behaviour 2 : Follow a little wall
    {


<<<<<<< HEAD

    else if (this->behaviourId == 3) // Behaviour : if player close : flees to back right, else, move in random circle
{
    unsigned x = this->getPosition().getX(), y = this->getPosition().getY();

    if (p1)
    //random circles
    bool circleID = rand() % 1;

    if (circleID == 1) //circle to the left
    {
        if ((x + 1 <= mat[y].size() - 1) && !this->inCollision(mat, x + 1, y))
        {
            this->pos.setX(x + 1);
        };

        else if ((y + 1 <= mat.size() - 1) && !this->inCollision(mat, x, y + 1))
        {
            this->pos.setY(y + 1);
        };

        else if ((x - 1 >= 0) && !this->inCollision(mat, x - 1, y))
        {
            this->pos.setX(x - 1);
        };

        else if ((y - 1 >= 0) && !this->inCollision(mat, x, y - 1))
        {
             this->pos.setY(y - 1);
        };
    }//fi

    else
    {

        if ((x - 1 >= 0) && !this->inCollision(mat, x - 1, y))
        {
            this->pos.setX(x - 1);
        }

        else if ((y - 1 >= 0) && !this->inCollision(mat, x, y - 1))
        {
            this->pos.setY(y - 1);
        }

        else if ((x + 1 <= mat[y].size() - 1) && !this->inCollision(mat, x + 1, y))
        {
            this->pos.setX(x + 1);
        }

        else if ((y + 1 <= mat.size() - 1) && !this->inCollision(mat, x, y + 1))
        {
            this->pos.setY(y + 1);
        }
    }
}//end of behaviour 3

>>>>>>> main
    else if (false) { // this->behaviourId == 4) { // Behaviour 4 => Random
        int move = rand() % 4 + 1;
        unsigned x = this->getPosition().getX(), y = this->getPosition().getY();
        std::cout << move << std::endl;

        if (move == 0 && (x + 1 <= mat[y].size() - 1) && !this->inCollision(mat, x + 1, y)) {
            this->pos.setX(x + 1);
        }
        else if (move == 1 && (x - 1 >= 0) && !this->inCollision(mat, x - 1, y)) {
            this->pos.setX(x - 1);
        }
        else if (move == 2 && (y + 1 <= mat.size() - 1) && !this->inCollision(mat, x, y + 1)) {
            this->pos.setY(y + 1);
        }
        else if ((y - 1 >= 0) && !this->inCollision(mat, x, y - 1)) {
            this->pos.setY(y - 1);
        }
    }
};

void Monster::render(MinGL &window) {
    if (slain) return;

    this->top.setPosition(this->getCoordinates());
    this->top.render(window);
}
