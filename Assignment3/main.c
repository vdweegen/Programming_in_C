/* File: main.c
 *
 * Assignment 3
 *
 * Author: Cas van der Weegen
 * UvANetID: 6055338
 *
 * Date: Sat Feb 25 (25/02/2012)
 */

/* Standard Libraries */
#include <stdlib.h>
#include <stdio.h>

/* Need for sleep() */
#include <unistd.h>

/* Include header files */
#include "maze.h"
#include "walker.h"
#include "solvers.h"

#define MAX_STEPS 1000

int main (int argc, char **argv)
{
    maze_t* maze;
    walker_t* walker;
    int count, dir;
    
    if(argc < 2)
    {
        printf("You must specify the maze to solve\n");
        return EXIT_FAILURE;
    }
    else if(argc > 2)
    {
        printf("Too many arguments\n");
        return EXIT_FAILURE;
    }
    
    /* Prepare Maze */
    maze = read_maze(argv[1]);
    walker = init_walker(maze);
    
    /* Start Looping */
    count = 0;
    while (count < MAX_STEPS)
    {
        count++;
        //dir = randomwalker(maze, walker);
        dir = righthandwalker(maze, walker);
        move_walker(maze, walker, dir);
        print_maze(maze);
        printf("%d\n", count);
        
        /*
         * I added a sleep(1) for a cleaner display  of the program
         * together with a system("clear") definition in maze.c,
         * both can be commented for a quicker run of the program
         */
        sleep(1);
        if (at_exit(maze, walker))
            break;
    }

    if (count < MAX_STEPS)
        printf("Found exit after %d steps\n", count);
    return 0;
}
