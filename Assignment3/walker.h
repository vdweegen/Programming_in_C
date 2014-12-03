/* File: walker.h
 *
 * Assignment 3
 *
 * Author: Cas van der Weegen
 * UvANetID: 6055338
 *
 * Date: Sat Feb 25 (25/02/2012)
 */

#ifndef WALKER_H
#define WALKER_H

/* Incomplete type declaration. */
typedef struct walker_t
{
    int row, column;
    int dir;
} walker_t;


/* Incomplete declarations of the support functions. */
walker_t* init_walker(maze_t * maze);
int move_walker(maze_t * maze, walker_t * walker, int dir);
int at_exit(maze_t * maze, walker_t * walker);
int check_move(maze_t * maze, walker_t * walker, int dir);
void cleanup_walker(maze_t * maze, walker_t * walker);

#endif
