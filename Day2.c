#include <stdlib.h>
#include <stdio.h>




int checkLine(FILE *file)
{
    
    char buffer[10];
    int min = 0, max = 0, charCount = 0;
    char checkChar = 0;

    // line organization:
    // number-number2: string


    // read until the dash
    fscanf(file, "%[^-]", buffer);

    // store our minimum value
    min = atoi(buffer);
    
    // read past that dash (-)
    fscanf(file, "%c", buffer);

    // read until the space
    fscanf(file, "%[^ ]", buffer);

    // store that maximum value
    max = atoi(buffer);

    // skip that space
    fscanf(file, "%c", buffer);

    // read the character we're checking
    fscanf(file, "%c", buffer);
    checkChar = buffer[0];
    buffer[0] = 0;




    while (buffer[0] != '\n')
    {
        if (buffer[0] == checkChar)
        {
            charCount++;
        }

        if (fscanf(file, "%c", buffer) == EOF)
        {
            return -1;
        }
    }

    if ((charCount > max) || (charCount < min))
    {
        return 0;
    }

    printf("min: %d\nmax: %d\nchar: %c\ngot: %d\n\n\n", min, max, checkChar, charCount);
    return 1;

}



int main(void)
{
    FILE *file;
    int line = 0;
    int count = 0;
    int run = 1;


    file = fopen("day2input.txt", "r");

    while (run == 1)
    {
        if ((line = checkLine(file)) == 1)
        {
            count++;

        }
        else if (line == -1)
        {
            run = 0;
        }

        
    }

    printf("NUMBER OF PASSES: %d\n", count);
    
}