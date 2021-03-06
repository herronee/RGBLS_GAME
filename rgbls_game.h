//
//  rgbls_game.h
//  
//
//  Created by emherron on 11/30/17.
//
//

#ifndef rgbls_game_h
#define rgbls_game_h

#include <stdio.h>

#define MOVERIGHT = 2;
#define MOVELEFT = 1;

struct player myPlayer;
struct obstacles[MAX_OBSTACLES] obstacleArray;

int numObstacles = 0;

struct location {
    int x;
    int y;
};

struct player {
    struct location currPos;
};

struct obstacle {
    struct location currPos;
};


void controlPlayer(int i);

void updateObstacles();

void initObstacle(int i);

void initPlayer();

void detectCollision();

void displayGame();

void addObstacle();

void removeObstacle();

void rgbls_game_init();

#endif /* rgbls_game_h */
