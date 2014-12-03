/* File: maze.c
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
#include <ctype.h>
#include <string.h>

#include "maze.h"

/* Incomplete definitions of the maze support function . */
maze_t* init_maze(int rows, int columns)
{
    maze_t * temp;
    char ** themaze;
    int r;
    
    if(!(themaze = malloc(rows * sizeof *themaze)))
    {
        printf("Couldn't allocate memory for maze\n");
        exit(EXIT_FAILURE);
    }
    for(r = 0; r < rows; r++)
    {
        if(!(themaze[r] = malloc(((columns) + 1) * sizeof(*themaze))))
        {
            printf("Couldn't allocate memory for maze\n");
            exit(EXIT_FAILURE);
        }
    }
    
    if(!(temp = (maze_t*)malloc((columns + 1) * sizeof(struct maze_t))))
    {
        printf("Couldn't allocate memory for maze\n");
        cleanup_maze(temp);
        exit(EXIT_FAILURE);
    }
    
    temp -> rows = rows;
    temp -> columns = columns;
    temp -> themaze = themaze;
    
    return temp;
}

maze_t* read_maze(char * filename)
{
    maze_t * maze;
    char buffer[BUFFERSIZE];
    FILE * fp;
    int rows, columns;
    int r = 0,
        c = 0,
        l = 0,
        i = 0,
        foundstart = 0,
        foundexit = 0;
    
    /* Open File */
    if(!(fp = fopen(filename, "r")))
    {
        sprintf(buffer, "Could not open file %s", filename);
        perror(buffer);
        exit(EXIT_FAILURE);
    }
    
    /* Extract Rows & Cols from file */
    if(!(fscanf(fp,"%d, %d", &rows, &columns)))
    {
        printf("File isn't of the correct format\n");
        exit(EXIT_FAILURE);
    }
        
    /* Init the Maze */
    maze = init_maze(rows, columns);
    
    /* Extract rest of the file */
    while(fgets(buffer, BUFFERSIZE, fp))
    {   
        if(l > 0)
        {
            if(r < rows)
            {
                for(c = 0; c < columns; c++)
                {
                    /* Fill the maze */
                    strcpy(maze -> themaze[r], buffer);
                    
                    /* Check if an entrance is present */
                    if(!foundstart)
                    {
                        i = 0;
                        while(maze -> themaze[r][i] != 'S' && maze -> themaze[r][i++]);
                        
                        if(maze -> themaze[r][i] == START)
                        {
                            maze -> startx = i;
                            maze -> starty = r;
                            foundstart = 1;
                        }
                    }
                    
                    /* Check if an exit is present */
                    if(!foundexit)
                    {
                        i = 0;
                        while(maze -> themaze[r][i] != 'E' && maze -> themaze[r][i++]);
                        
                        if(maze -> themaze[r][i] == EXIT)
                        {
                            foundexit = 1;
                        }
                    }
                }
            }
            r++;
        }
        l++;

    }    
    /* Terminate if no entrance was found */
    if(!foundstart)
    {
        printf("Maze has no entrance!\n");
        cleanup_maze(maze);
        exit(EXIT_FAILURE);
    }
    
    /* Terminate if no exit was found */
    if(!foundexit)
    {
        printf("Maze has no exit!\n");
        cleanup_maze(maze);
        exit(EXIT_FAILURE);
    }
    
    return maze;
}

void print_maze(maze_t * maze)
{
    /* Clear the console for a 'cleaner' display */
    system("clear");
    
    /* Print the maze */
    int r = 0, c = 0;
    for(r = 0; r < maze -> rows; r++)
    {
        for(c = 0; c < maze -> columns; c++)
        {
            printf("%c", maze -> themaze[r][c]);
        }
        printf("\n");
    }
}

void cleanup_maze (maze_t * maze)
{
    /* Cleanup the maze struct */
    int r;
    for(r = 0; r < maze->rows; r++)
    {
        free(maze->themaze[r]);
    }
    free(maze->themaze);
}
