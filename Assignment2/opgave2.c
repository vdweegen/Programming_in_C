/*
 * File: opgave2.c
 *
 * Author: Cas van der Weegen
 * UvANetID: 6055338
 *
 * Date: Fri Feb 17 (17/02/2012)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("usage: %s <encoded txt> <frequences txt>\n", argv[0]);
    }
    else 
    {
        FILE *freq = fopen(argv[2], "r");

        float f,
            checkfreq = 0.0,
            checkfreqorg = 0.0,
            freqs[26],
            freqsorg[26];
        char characters[26],
            charactersorg[26],
            character[2],
            checkchar,
            checkcharorg,
            buffer[1024];
        int count[26] = {0},
            c = 0,
            i = 0,
            j = 0,
            x = 0,
            shift = 0,
            len = 0;
        
        /* Prepare the array that holds all original frequencies */
        while(fscanf(freq, "%s %f", character, &f) != EOF)
        {
            characters[x] = character[0];   
            freqs[x] = f;
            x++;
        }
        fclose(freq);
        
        /* Calculate how large the array should be */
        FILE *buff = fopen(argv[1], "r");
        if(fgets(buffer, 1024, buff) != NULL)
        {
            len += strlen(buffer);
        }
        char string[len];        
        fclose(buff);
        
        FILE *file = fopen(argv[1], "r");
        
        /* read ONLY the first line of the file */
        fgets(string,sizeof string,file);
        
        /* Print the Encrypted String */
        printf("\n\nEncrypted:\n");
        for(i = 0; i <= (int)strlen(string); i++)
        {
            printf("%c", string[i]);
        }
        
        /* Print the Encrypted String after filtered */
        printf("\n\nFiltered:\n");
        for(i = 0; i <= (int)strlen(string); i++)
        {
            if(((int)string[i] >= 65) && ((int)string[i] <= 90))
            {
                string[i] = (char)((int)string[i] + 32);
            }
            printf("%c", string[i]);
        }
        
        /* Create an array that will hold the letters and count */
        while(string[c] != '\0')
        {
            if(string[c] >= 'a' && string[c] <= 'z')
            {
                count[string[c]-'a']++;
            }
            c++;
        }
        
        /* Count the amount of chars in the string */
        for(i = 0; i <= (int)strlen(string); i++)
        {
            if(string[i] != ' ')
            {
                j++;
            }
            i++;
        }
        j = j - 1; /* Account for '\0' */
        printf("\nTotal Length: %d\n", j);
        
        /* Prepare the array that holds the calculated frequencies */
        for(c = 0; c < 26; c++)
        {
            if(count[c] != 0)
            {
                charactersorg[c] = c+'a';
                freqsorg[c] = (float)(((float)count[c] / (float)j) * (float)100);
            }
            
        }
        
        /* Start "sorting" the array that holds the calculated frequencies (HIGH) */
        for(c = 0; c < 26; c++)
        {
            if(freqsorg[c] > checkfreqorg)
            {
                checkfreqorg = freqsorg[c];
                checkcharorg = charactersorg[c];
            }
        }
        
        /* Start "sorting" the array that holds all original frequencies (HIGH) */
        for(c = 0; c < 26; c++)
        {
            if(freqs[c] > checkfreq)
            {
                checkfreq = freqs[c];
                checkchar = characters[c];
            }
        }      
        
        /* Calculate most likely shift */
        shift = ((int)checkchar - (int)checkcharorg);
        if(shift < 0)
        {
            shift = shift + 26;
        }
        printf("\nMost likely shift: %d\nShifting: %c -> %c (takes %d shifts)", shift, checkcharorg, checkchar, shift);
        
        /* Start shifting */
        for(c = 0; c < (int)strlen(string); c++)
        {
            if(((int)string[c]) >= 97 && ((int)string[c]) <= 122)
            {
                if(((int)string[c] + shift) > 122)
                {
                    string[c] = (char)(97 + ((int)string[c] + shift)-123);
                }
                else
                {
                    string[c] = (char)((int)string[c] + shift);
                }
            }
        }
        
        /* Print the Decrypted String */
        printf("\n\nDecrypted:\n");
        for(i = 0; i <= (int)strlen(string); i++)
        {
            printf("%c", string[i]);
        }        
        fclose(file);
        printf("\n\nFrequency Outputs:\nCalculated\tOriginal\n");
        for(c = 0; c < 26; c++)
        {
            if(count[c] != 0)
            {
                printf("%c %4.3f\t\t%c %4.3f\n", characters[c], freqs[c], charactersorg[c], freqsorg[c]/2.0);
            }
            
        }
        printf("\n");
    }
    return 0;
}