/* File: walker.c
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

#include "maze.h"
#include "walker.h"

/* Incomplete definitions of the walker support function . */
int check_move(maze_t * maze, walker_t * walker, int dir)
{
    if(dir == 0) /* Check North */
    {
        if(maze -> themaze[((walker -> row)-1)][walker -> column] != '#')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(dir == 1) /* Check East */
    {
        if(maze -> themaze[walker -> row][((walker -> column)+1)] != '#')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(dir == 2) /* Check South */
    {
        if(maze -> themaze[((walker -> row)+1)][walker -> column] != '#')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(dir == 3) /* Check West */
    {
        if(maze -> themaze[walker -> row][((walker -> column)-1)] != '#')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("Invalid direction!\n");
        exit(EXIT_FAILURE);
    }
}

int at_exit(maze_t * maze, walker_t * walker)
{
    if((maze -> themaze[(walker -> row)][(walker -> column)]) == 'E')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

walker_t* init_walker(maze_t * maze)
{
    walker_t * temp;
    
    /* Initialize Walker */
    if(!(temp = (walker_t *)malloc(sizeof(struct walker_t))))
    {
        printf("Couldn't allocate memory for walker\n");
        exit(EXIT_FAILURE);
    }
    
    /* Pass on Initial Position */
    temp -> row = maze -> starty;
    temp -> column = maze -> startx;
    temp -> dir = 0;
    
    return temp;
}

int move_walker(maze_t * maze, walker_t * walker, int dir)
{
    printf("Dir to walk: %d\n", dir);
    if(check_move(maze, walker, dir) == 1)
    {
        maze -> themaze[walker->row][walker->column] = 'X';
        if(dir == 0) /* Move North */
        {
            walker -> row = ((walker -> row) - 1);
            walker -> dir = 0;
            return 1;
        }
        else if(dir == 1) /* Move East */
        {
            walker -> column = ((walker -> column) + 1);
            walker -> dir = 1;
            return 1;
        }
        else if(dir == 2) /* Move South */
        {
            walker -> row = ((walker -> row) + 1);
            walker -> dir = 2;
            return 1;
        }
        else if(dir == 3) /* Move West */
        {
            walker -> column = ((walker -> column) - 1);
            walker -> dir = 3;
            return 1;
        }
    }
    else
    {
        printf("False Move! %d\n", dir);
    }
    return 1;
}

void cleanup_walker(maze_t * maze, walker_t * walker)
{

}
