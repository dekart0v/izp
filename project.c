/*
####################################
# Project 1. IZP
# ./project -d <delimeter> <command> <tab1.txt >tab2.txt
#
#
#
####################################
*/

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <string.h>

#define MAX_LINE_LENGTH 130

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        char line[MAX_LINE_LENGTH];
        char *delimeter;
        int delimeterCount = 0;
        char c;
        for (int i = 0; i < argc; i++) // main FOR-cycle for arguement-checking
        {
            if (strcmp(argv[i], "-d") == 0) // gets delimeter
            {
                delimeter = argv[i + 1];
            }

            if (strcmp(argv[i], "irow") == 0)
            {
                while ((c = getchar()) != '\n') // checking the very first line for delimeters
                {
                    printf("%c", c);
                    if (c == ':') // возможные виды разделителей
                    {
                        delimeterCount++; // get amount of delimeters
                    }
                }
                printf("\n");

                int lineNum = 0;
                while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
                {
                    if(++lineNum == (atoi(argv[i+1])-1))
                    {
                        for (int j = 0; j < delimeterCount; j++) // add delimeters to it
                        {
                            printf("%s", delimeter);
                        }
                        printf("\n%s", line);
                    }
                    else
                    {
                        printf("%s", line);
                    }
                }
            }

            if (strcmp(argv[i], "arow") == 0) // arow argument (не заменяет разделители на другие в файле)
            {
                while ((c = getchar()) != '\n') // checking the very first line for delimeters
                {
                    printf("%c", c);
                    if (c == ':') // возможные виды разделителей
                    {
                        delimeterCount++; // get amount of delimeters
                    }
                }
                printf("\n");

                while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) // copying the input file
                {
                    printf("%s", line);
                }

                for (int j = 0; j < delimeterCount; j++) // add delimeters to it
                {
                    printf("%s", delimeter);
                }
            }

            if (strcmp(argv[i], "drow") == 0)
            {
                int lineNum = 0;
                while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
                {   
                    if(++lineNum == atoi(argv[i+1]))
                    {
                        continue;
                    }
                    else
                    {
                        printf("%s", line);
                    }   
                }
            }

            if (strcmp(argv[i], "drows") == 0)
            {
                int lineNum = 0;
                while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
                {
                    int x = atoi(argv[i+1]); // beginning of wipe
                    int y = atoi(argv[i+2]); // end of wipe
                    if((++lineNum >= x) && (lineNum <= y))
                    {
                        continue;
                    }
                    else
                    {
                        printf("%s", line);
                    }
                }
            }

            if (strcmp(argv[i], "acol") == 0)
            {
                while((c = getchar()) != EOF)
                {
                   if(c == '\n')
                    {
                        printf("%s\n", delimeter);
                    }
                    else
                    {
                        printf("%c", c);
                    }
                }
               // printf("%s", delimeter);
            }

            /* if (strcmp(argv[i], "icol") == 0)
            {
                // TODO
            } */
        }
    }
    return 0;
}
