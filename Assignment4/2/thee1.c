/* File: thee1.c
 *
 * Assignment 4
 *
 * Author: Cas van der Weegen
 * UvANetID: 6055338
 *
 * Date:
 */

/* Standard Libraries */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Include header files */
#include "loods1.h"

#define BUFFERSIZE (50)

int main(void)
{
    system("clear");
    printf("Welcome to C-Industries Tea Company\n\nShell: (type 'help' for help)\n");
    
    int exit = 0,
        i,j;
    loods1_t * loods1;
    loods1_t * loods2;
    
    loods1 = maak_loods();
    loods2 = maak_loods();
    
    do{
        char buffer[BUFFERSIZE];
        char input[BUFFERSIZE];
        printf("> ");
        if(fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            if (strncmp (buffer,"exit",3) == 0)
            {
                printf("Now exiting\n");
                sloop_loods(loods1, loods2);
                exit = 1;
            }
            else if (strncmp (buffer,"leveren",6) == 0)
            {
                char * data = leveren(loods1);
                if(data == NULL)
                {
                    printf("The Queue is empty\n");
                }
                else
                {
                    printf("%s", data);
                }
            }
            else if (strncmp (buffer,"verplaatsen21",13) == 0)
            {
                printf("verplaats %s van Loods2 naar Loods1\n", verplaatsen21(loods2, loods1));
            }
            else if (strncmp (buffer,"verplaatsen12",13) == 0)
            {
                printf("verplaats %s van Loods1 naar Loods2\n", verplaatsen12(loods1, loods2));
            }
            else if (strncmp (buffer,"opslaan",7) == 0)
            {
                /* Clear char input */
                for(i = 0; i < BUFFERSIZE; i++)
                {
                    input[i] = ' ';
                }
                /* Copy buffer to input */
                for(j = 0; buffer[j] != '\0'; j++)
                {
                    input[j] = buffer[j+8];
                }
                /* Save to Loods */
                opslaan(loods1, input);
            }
            else if (strncmp (buffer,"help",3) == 0)
            {
                printf("Commandos:\n\tlist\t\t\tgeeft de status van de stack weer\n\topslaan <string>\tSaves the entered string\n\tleveren\t\t\tPrint the top item of the Stack\n\tverplaatsen12\t\tMove the top item of Loods1 to Loods2\n\tverplaatsen21\t\tMove the top item of Loods2 to Loods1\n\texit\t\t\tExit the Program\n");
            }
            else if (strncmp (buffer,"list",3) == 0)
            {
                printf("> Listing the Queue: (loods1)\n");
                printf("\tloods1 -> size: %d\n\tloods1 -> front: %d\n", loods1 -> size, loods1 -> front);
                printf("> Listing the Queue: (loods2)\n");
                printf("\tloods2 -> size: %d\n\tloods2 -> front: %d\n", loods2 -> size, loods2 -> front);
            }
            else
            {
                printf("Command not recognized\n");
            }
        }
    } while(exit != 1);
    return 0;
}
