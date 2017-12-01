//
//  rgbls_game.c
//  
//
//  Created by emherron on 11/30/17.
//
//
#include <stdlib.h>
#include <unistd.h>
#include "rgbls_game.h"


#define MAX_OBSTACLES = 15;
#define RIGHTBORDER = 3;
#define LEFTBORDER = 0;
#define TOP = 60;
#define WIDTH = 4;

struct player myPlayer;
struct obstacles[MAX_OBSTACLES] obstacleArray;

int numObstacles = 0;

void moveRight();
void moveLeft();
//move the player left and right with buttons
void controlPlayer(int i) {
    
    //check if right button has been pressed
    if (i == 2) {
        moveRight();
    }
    //check if left button has been pressed
    if (i == 1) {
        moveLeft();
    }
    //if no button has been pressed - do nothing
    
}
void moveRight() {
    
    if (myPlayer.currPos.x < RIGHTBORDER) {
        (myPlayer.currPos.x)++;
    }
    
}
void moveLeft() {
    
    if (myPlayer.currPos.x > LEFTBORDER) {
        (myPlayer.currPos.x)--;
    }
    
}

//move the obstacles down the playing board
void updateObstacles() {
    
    for (int i = 0; i < numObstacles; ++i) {
        if (obstacleArray[i].currPos.y > 0) {
            (obstacleArray[i].currPos.y)--;
        } else {
            initObstacle(i);
        }
    }
    
}

//initialize an obstacle at its starting location
void initObstacle(int i) {
    
    struct obstacle tmp;
   
        int r = rand() % WIDTH;
        tmp.currPos.x = r;
        tmp.currPos.y = TOP-1;
        obstacleArray[i] = tmp;
    
}

void initPlayer() {
    
    myPlayer.currPos.x = 0;
    myPlayer.currPos.y = 3;
    myPlayer.lives = 3;
    
}


void detectCollision() {
    
    for (int i = 0; i < numObstacles; ++i) {
        if (obstacleArray[i].currPos.x == myPlayer.currPos.x && obstacleArray[i].currPos.y == myPlayer.currPos.y) {
            (myPlayer.lives)--;
            if (myPlayer.lives == 0) {
                initPlayer();
                numObstacles = 0;
            }
        }
    }
    
}


void displayGame() {
    
    //might need this to work with the lights, but i am not sure how to do this
    
}

void addObstacle() {
    
    if (numObstacles < MAX_OBSTACLES) {
        numObstacles++;
        initObstacle(numObstacles-1);
    }
    
}

void removeObstacle() {
    
    if (numObstacle > 0) {
        numObstacle--;
    }
    
}

/*int main(void) {
    
    //initialize player
    initPlayer();
    
    //initialize obstacles
    
    
    while (myPlayer.lives != 0) {
        diplayGame() //?
        usleep(500);
        detectCollision();
        controlPlayer();
        updateObstacles();
    }
    
} */


void rgbls_game_init () {
    
    initPlayer();
    
}
