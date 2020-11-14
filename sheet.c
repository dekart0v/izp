/*
####################################################
#          Made by Ilia Iudenkov (xiuden00)        #
#        VUT FIT 2020 (zima) - IZP (Project #1)    #
#              15.11.2020. 23:59:59                #
#     https://github.com/dekart0v/izp-pr1.git      #
#     Works: -d, arow, irow, drow, drows, acol     #
####################################################
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 130 // max line length for fgets(line, MAX_LINE_LENGTH, stdin)

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        char line[MAX_LINE_LENGTH]; // variable for line returning from fgets(line, MAX_LINE_LENGTH, stdin)
        char *delimeter;            // symbol for delimeters
        int delimeterCount = 0;     // amount of delimeters in every single line in input file
        char c;                     // var for chars returning from (c = getchar()

        for (int i = 0; i < argc; i++) // main FOR-cycle for arguement-checking
        {
            if (strcmp(argv[i], "-d") == 0) // gets delimeter
            {
                delimeter = argv[i + 1]; // stores delimeter in variable "delimeter"
            }

            /*
            ##############################################################################
            #                                   LINES                                    #
            ##############################################################################
            */

            else if (strcmp(argv[i], "irow") == 0) // operation irow
            {
                while ((c = getchar()) != '\n') // checking the very first line for delimeters
                {
                    printf("%c", c);
                    if (c == ':') // possible delimeters in a file
                    {
                        delimeterCount++; // gets amount of delimeters
                    }
                }
                printf("\n");

                int lineNum = 0;
                while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
                {
                    if (++lineNum == (atoi(argv[i + 1]) - 1))
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

            else if (strcmp(argv[i], "arow") == 0) // operation arow
            {
                while ((c = getchar()) != '\n') // checking the very first line for delimeters
                {
                    printf("%c", c);
                    if (c == ':') // possible delimeters in a file
                    {
                        delimeterCount++; // gets amount of delimeters
                    }
                }
                printf("\n");

                while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL) // copying the input file
                {
                    printf("%s", line);
                }

                for (int j = 0; j < delimeterCount; j++) // add delimeters to input file
                {
                    printf("%s", delimeter);
                }
            }

            else if (strcmp(argv[i], "drow") == 0) // operation drow
            {
                int lineNum = 0; // counts lines in input file
                while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
                {
                    if (++lineNum == atoi(argv[i + 1])) // line count + 1; if line == arguement after 'drow'
                    {
                        continue; // do not print this line
                    }
                    else // if not equal -> print current line
                    {
                        printf("%s", line);
                    }
                }
            }

            else if (strcmp(argv[i], "drows") == 0) // operation drows
            {
                int lineNum = 0; // counts lines in input file
                while (fgets(line, MAX_LINE_LENGTH, stdin) != NULL)
                {
                    int x = atoi(argv[i + 1]);              // beginning of wipe
                    int y = atoi(argv[i + 2]);              // end of wipe
                    if ((++lineNum >= x) && (lineNum <= y)) // if number is in range(x, y) -> skip printing
                    {
                        continue;
                    }
                    else // if not -> print
                    {
                        printf("%s", line);
                    }
                }
            }

            /*
            ##############################################################################
            #                                   COLUMNS                                  #
            ##############################################################################
            */

            else if (strcmp(argv[i], "acol") == 0) // operation acol
            {
                while ((c = getchar()) != EOF) // getting single characters till the EOF
                {
                    if (c == '\n') // if finds \n print delimeter before it, so another column appends
                    {
                        printf("%s\n", delimeter);
                    }
                    else // if not, just print this char
                    {
                        printf("%c", c);
                    }
                }
            }

            /*
            else if (strcmp(argv[i], "dcol") == 0) // operation dcol
            {
                int colNum = 0;
                while (fgets(col, MAX_LINE_LENGTH, stdin) != NULL)
                {
                    if (++colNum == atoi(argv[i + 1])) 
                    {
                        continue;
                    }
                    else
                    {
                        printf("%s", col);
                    }
                }
            }

            else if (strcmp(argv[i], "dcols") == 0) // operation dcols
            {
                int colNum = 0;
                while (fgets(col, MAX_LINE_LENGTH, stdin) != NULL)
                {
                    int x = atoi(argv[i + 1]);
                    int y = atoi(argv[i + 2]);
                    if ((++colNum >= x) && (colNum <= y))
                    {
                        continue;
                    }
                    else
                    {
                        printf("%s", col);
                    }
                }
            }

            else if (strcmp(argv[i], "icol") == 0)
            {
                while ((c = getchar()) != '\n')
                {
                    printf("%c", c);
                    if (c == ':')
                    {
                        delimeterCount++;
                    }
                }
                printf("\n");

                int colNum = 0;
                while (fgets(col, MAX_LINE_LENGTH, stdin) != NULL)
                {
                    if (++colNum == (atoi(argv[i + 1]) - 1))
                    {
                        for (int j = 0; j < delimeterCount; j++) // add delimeters to it
                        {
                            printf("%s", delimeter);
                        }
                        printf("\n%s", col);
                    }
                    else
                    {
                        printf("%s", col);
                    }
                }
            }

            else if (strcmp(argv[i], "cset") == 0) // operation cset
            {
                for (int j = 0; j < strlen(cell); j++)
                {
                    cell = argv[i + 1];
                    printf("%s", cell);
                }
            }

            else if (strcmp(argv[i], "tolower") == 0) // operation tolower
            {
                for (int j = 0; j < strlen(cell); j++)
                {
                    tolower(cell[j]);
                    printf("%s", cell);
                }
            }

            else if (strcmp(argv[i], "toupper") == 0) // operation toupper
            {
                for (int j = 0; j < strlen(cell); j++)
                {
                    toupper(cell[j]);
                    printf("%s", cell);
                }
            }

            else if (strcmp(argv[i], "round") == 0) // operation round
            {
                for (int j = 0; j < strlen(cell); j++)
                {
                    printf("%.0s", (int)cell[j]);
                }
            }

            else if (strcmp(argv[i], "int") == 0) // operation int
            {
                for(int j = 0; j < strlen(cell); j++)
                {
                    printf("%.0s", (int)cell[j]);
                }
            }

            else if (strcmp(argv[i], "move") == 0) // operation move
            {
                for (int j = 0; j < strlen(cell); j++)
                {
                    for (int x = 0; x < strlen(cell); x++)
                    {
                        char temp[] = cell;
                        cell = cell+1
                        cell+1 = x;
                    }
                    printf("%s ", cell);
                }
            }

            else if (strcmp(argv[i], "swap") == 0) // operation swap
            {
                for (int j = 0; j < strlen(cell); j++)
                {
                    for (int x = 0; x < strlen(cell); x++)
                    {
                        char temp[] = cell;
                        cell = cell+1
                        cell+1 = x;
                    }
                    printf("%s ", cell);
                }
            }

            else if (strcmp(argv[i], "copy") == 0) // operation copy
            {
                for (int j = 0; j < strlen(cell); j++)
                {
                    for (int x = 0; x < strlen(cell); x++)
                    {
                        char temp[] = cell;
                        cell = cell+1
                        cell+1 = x;
                    }
                    printf("%s ", cell);
                }
            }

            else if (strcmp(argv[i], "beginswith") == 0) // operation beginswith
            {
                for (int j = 0; j < strlen(cell); j++)
                {
                    if (line != argv[i + 1])
                    {
                        break;
                    }
                    else
                    {
                        printf("%s", line);
                    }
                }
            }

            else if (strcmp(argv[i], "contains") == 0) // operation contains
            {
                for (int j = 0; j < strlen(cell); j++)
                {
                    if (line != argv[i + 1])
                    {
                        printf("SUCCESS");
                    }
                    else
                    {
                        printf("FAULT"); // smth to do w/ container
                    }
                }
            }

            else if (strcmp(argv[i], "rows") == 0) // operation rows
            {
                while ((c = getchar()) != EOF) 
                {
                    if (c == '\n') // if finds \n print delimeter before it, so another column appends
                    {
                        printf("%s\n", delimeter);
                    }
                    else // if not, just print this char
                    {
                        printf("%c", c);
                    }
                }

                for (int j = 0; j < strlen(cell); j++)
                {
                    if (line != argv[i + 1])
                    {
                        printf("SUCCESS");
                    }
                    else
                    {
                        printf("FAULT"); // smth to do w/ container
                    }
                }
            } 
            */
        }
    }
    return 0;
}
