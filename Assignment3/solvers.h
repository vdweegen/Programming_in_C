/* File: solvers.h
 *
 * Assignment 3
 *
 * Author: Cas van der Weegen
 * UvANetID: 6055338
 *
 * Date: Sat Feb 25 (25/02/2012)
 */

#ifndef SOLVERS_H
#define SOLVERS_H

/* solver function that will return a direction for the next step. */
int randomwalker(maze_t * maze, walker_t * walker);
int righthandwalker(maze_t * maze, walker_t * walker);
#endif
