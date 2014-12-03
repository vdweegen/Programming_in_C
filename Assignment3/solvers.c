/* File: solvers.c
 *
 * Assignment 3
 *
 * Author: Cas van der Weegen
 * UvANetID: 6055338
 *
 * Date: Sat Feb 25 (25/02/2012)
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "maze.h"
#include "walker.h"
#include "solvers.h"

/* Will contain the definitions of the maze solver functions. */
int randomwalker(maze_t * maze, walker_t * walker)
{
    srand (time(NULL));
    return (rand() % 3);
}

int righthandwalker(maze_t * maze, walker_t * walker)
{
    if((walker -> dir) == 0)
    {
        if((check_move(maze, walker, 1)) == 0 || ((walker -> dir) == 3))
        {
            if(((check_move(maze, walker, 2)) == 0) || ((walker -> dir) == 0))
            {
                if((check_move(maze, walker, 0)) == 0)
                {
                    if((check_move(maze, walker, 3)) == 0)
                    {
                        if((walker -> dir) == 2)
                            return 0;
                        else if ((walker -> dir) == 3)
                            return 1;
                        else if ((walker -> dir) == 0)
                            return 2;
                        else if ((walker -> dir) == 1)
                            return 3;
                    }
                    return 3;
                }
                return 0;
            }
            return 2;
        }
        return 1;
    }
    else if((walker -> dir) == 2)
    {
        if((check_move(maze, walker, 3)) == 0 || ((walker -> dir) == 1))
        {
            if(((check_move(maze, walker, 0)) == 0) || ((walker -> dir) == 2))
            {
                if((check_move(maze, walker, 2)) == 0)
                {
                    if((check_move(maze, walker, 1)) == 0)
                    {
                        if((walker -> dir) == 0)
                            return 2;
                        else if ((walker -> dir) == 1)
                            return 3;
                        else if ((walker -> dir) == 2)
                            return 0;
                        else if ((walker -> dir) == 3)
                            return 1;
                    }
                    return 1;
                }
                return 2;
            }
            return 0;
        }
        return 3;
    }
    else if((walker -> dir) == 1)
    {
        if((check_move(maze, walker, 2)) == 0 || ((walker -> dir) == 0))
        {
            if(((check_move(maze, walker, 3)) == 0) || ((walker -> dir) == 1))
            {
                if((check_move(maze, walker, 1)) == 0)
                {
                    if((check_move(maze, walker, 0)) == 0)
                    {
                        if((walker -> dir) == 3)
                            return 1;
                        else if ((walker -> dir) == 0)
                            return 2;
                        else if ((walker -> dir) == 1)
                            return 3;
                        else if ((walker -> dir) == 2)
                            return 0;
                    }
                    return 0;
                }
                return 1;
            }
            return 3;
        }
        return 2;
    }
    else if((walker -> dir) == 3)
    {
        if((check_move(maze, walker, 0)) == 0 || ((walker -> dir) == 2))
        {
            if(((check_move(maze, walker, 1)) == 0) || ((walker -> dir) == 3))
            {
                if((check_move(maze, walker, 3)) == 0)
                {
                    if((check_move(maze, walker, 2)) == 0)
                    {
                        if((walker -> dir) == 1)
                            return 3;
                        else if ((walker -> dir) == 2)
                            return 0;
                        else if ((walker -> dir) == 3)
                            return 1;
                        else if ((walker -> dir) == 0)
                            return 2;
                    }
                    return 2;
                }
                return 3;
            }
            return 1;
        }
        return 0;
    }
    else
    {
        return -1;
    }
}