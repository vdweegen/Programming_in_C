/*
 * File: opgave1.c
 *
 * This files calculates PI by choosing an x
 * amount of random numbers within a square
 * and checks how many of those points are
 * within the circle that lays within the square.
 *
 * Author: Cas van der Weegen
 * UvANetID: 6055338
 *
 * Date: Fri Feb 10 (10/02/2012)
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: %s <amount>\n", argv[0]);
    }
    else 
    {
        if(isalpha(*argv[1]))
        {
            printf("Error!\n\tArgument MUST be a number!\n\nusage: %s <amount>\n", argv[0]);
        }
        else if (isdigit(*argv[1]))
        {
            int Amount,i,counter=0,atoi(const char *str);
            double x,y,z,pi;

            srand(time(NULL));
            counter=0;
            Amount = atoi(argv[1]);
            for ( i=0; i<Amount; i++)
            {
                x = (double)rand()/RAND_MAX;
                y = (double)rand()/RAND_MAX;
                z = x*x+y*y;
               
                if (z<=1)
                {
                    counter++;
                }
            }
            
            pi = (double)counter / Amount * 4;
            printf("Aantal willekeurige punten: %d\n\tBenadering van PI: %g \n",Amount,pi);
        }
    }
}