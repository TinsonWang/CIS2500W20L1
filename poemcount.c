#include <stdio.h>
#include <ctype.h>

#define MAXIMUM 50 /* Maximum number of lines in a poem allowed */

/* Program that counts the number of words on a line and the number of lines.
    Prints out the total number of words and the total number of lines.
    Then prints out the number of words on each line. */

int main (int argc, char *argv[])
{
    int lineCounter, wordCounter, wordCounterTotal, charCounter;
    int counterArray[MAXIMUM];
    int wordState = 0;
    int c, i;

    int periodUsed;
    periodUsed = 0;

    wordCounter = 0;
    lineCounter = 0;
    wordCounterTotal = 0;
    charCounter = 0;

    printf("Enter a poem:\n");

    /*Continues as long as either one of these conditions remains true*/
    while ( ( (c = getc(stdin)) != '.') || (periodUsed == 0) )
    {
        charCounter++;

        if (wordState == 0)
        {
            if (isalpha(c))
            {
                wordState = 1;
                wordCounter++;
            }
        }
        else if (wordState == 1)
        {
            if (isspace(c))
            {
                wordState = 0;
            }
        }

        if (c == '\n')
        {
            counterArray[lineCounter] = wordCounter;
            wordCounterTotal += wordCounter;
            lineCounter++;
            wordState = 0;
            wordCounter = 0;
            charCounter = 0;
        }
        else if ((c == '.') && (charCounter == 1))
        {
            printf("There are %d words on %d lines.\n", wordCounterTotal, lineCounter);
            /*printf("charCounter: %d\n",charCounter);*/
            for (i = 0; i < lineCounter; i++)
            {
                printf("%d ", counterArray[i]);
            }
            printf("\n");
            return 0;
        }

        if (lineCounter > 50)
        {
            printf("ERROR: Maximum number of lines allowed in a poem is %d", MAXIMUM);
        }
    }

    /*printf("periodUsed: %d\n", periodUsed);*/
    /*printf("wordState: %d\n", wordState);*/
    printf("There are %d words on %d lines.\n", wordCounterTotal, lineCounter);
    for (i = 0; i < lineCounter; i++)
    {
        printf("%d ", counterArray[i]);
    }
    printf("\n");
    return 0;
}