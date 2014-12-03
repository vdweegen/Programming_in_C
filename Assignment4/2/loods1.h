/* File: loods1.h
 *
 * Assignment 4
 *
 * Author: Cas van der Weegen
 * UvANetID: 6055338
 *
 * Date:
 */
#ifndef LOODS1_H
#define LOODS1_H

#define BUFFERSIZE (50)
#define COMPANYSIZE (15)

/* Incomplete type declaration. */
typedef struct loods1_t
{
    char * queue;
    int size,
        front;

} loods1_t;

loods1_t * maak_loods(void);
int leeg(loods1_t * loods1);
int isvol(loods1_t * loods1);
int isleeg(loods1_t * loods1);
int sloop_loods(loods1_t * loods1, loods1_t * loods2);
void opslaan(loods1_t * loods1, char * name);
char * leveren(loods1_t * loods1);
char * verplaatsen12(loods1_t * loods1, loods1_t * loods2);
char * verplaatsen21(loods1_t * loods2, loods1_t * loods1);

#endif