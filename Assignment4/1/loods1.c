/* File: loods1.c
 *
 * Assignment 4
 *
 * Author: Cas van der Weegen
 * UvANetID: 6055338
 *
 * Date:
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "loods1.h"

int isvol(loods1_t * loods1)
{
    if((loods1 -> size) == (loods1 -> front))
        return 1;
    return 0;
}

int isleeg(loods1_t * loods1)
{
    if((loods1 -> front) == 0)
        return 1;
    return 0;
}

loods1_t* maak_loods(void)
{
    loods1_t * loods1 = (loods1_t *)malloc(sizeof(loods1));
    
    if(!(loods1 = malloc(sizeof(loods1_t))))
    {
        printf("Cannot allocate memory for loods");
    }
    
    if(!(loods1 -> queue = (char *)malloc(sizeof(char) * COMPANYSIZE)))
    {
        printf("Cannot allocate memory for loods");
    }
    
    loods1 -> size = COMPANYSIZE;
    loods1 -> front = 0;
    return loods1;
}

void opslaan(loods1_t * loods1, char * name)
{
    if(isvol(loods1))
    {
        printf("The Queue is Full, aborting...\n");
    }
    else
    {
        strcpy(++(loods1 -> queue), name);
        ((loods1 -> front)++);
    }
}

char * leveren(loods1_t * loods1)
{
    if(isleeg(loods1))
    return NULL;

    ((loods1 -> front)--);
    return ((loods1->queue)--);
}

int sloop_loods(loods1_t * loods1)
{
    if((loods1 -> queue) != NULL)
    {
        free(loods1 -> queue);
        return 1;
    }
    printf("Couldn't destory loods");
    return 0;
}

