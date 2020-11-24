#ifndef TYPES_H_   /* Include guard */
#define TYPES_H_

/*
 *  Pong game paddle
 */
typedef struct Paddle {
    int x, y, speed, score;
} Paddle;

/*
 *  Pong game moving ball
 */
typedef struct Ball {
    int x, y, speedX, speedY;
} Ball;

#endif // TYPES_H_