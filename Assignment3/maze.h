/* File: maze.h
 *
 * Assignment 3
 *
 * Author: Cas van der Weegen
 * UvANetID: 6055338
 *
 * Date: Sat Feb 25 (25/02/2012)
 */

/* Contains function related to the maze map of the game. */

#ifndef MAZE_H
#define MAZE_H

#define BUFFERSIZE (1000)

#define NORTH 0
#define EAST  1
#define SOUTH 2
#define WEST  3

#define WALL    '#'
#define START   'S'
#define EXIT    'E'

/* Incomplete type declaration. */
typedef struct maze_t
{
    int rows,
        columns,
        startx,
        starty;
    char ** themaze;
} maze_t;


/* Incomplete declarations of the support functions. */
maze_t* init_maze(int rows, int columns);
maze_t* read_maze(char * filename);
void print_maze(maze_t * maze);
void cleanup_maze (maze_t * maze);

#endif
