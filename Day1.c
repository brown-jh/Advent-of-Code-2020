// Advent of Code
// Day 1
// Read a bunch of strings from a text file
// and look for duos that add to give "2020"
#include <stdio.h>
#include <stdlib.h>


int numOfLines(FILE *file)
{
    int number = 0;
    char buffer[30];
    

    while (fscanf(file, "%c", buffer) != EOF)
    {
        if (buffer[0] == '\n')
            number++;
    }

    

    return number;
}

void populateArray(FILE *file, int lineCount, int *values)
{
    int i = 0;
    char buffer[50];

    for (i = 0; i < lineCount; i++)
    {   
        // put our value in the buffer
        fscanf(file, "%s", buffer);

        // read the buffer into our array
        values[i] = atoi(buffer);

        printf("%d\n", values[i]);


    }

}

int getTwentyTwenty(int *values, int lineCount)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int curNum = 0;
    int toAdd = 0;
    int secondToAdd = 0;
    int numToCheck = 0;
    
    // for each number in our list
    for (i = 0; i < lineCount; i++)
    {

        curNum = values[i];

        // add it by all other numbers in the list AFTER it
        for (j = (i+1); j < lineCount; j++)
        {
            toAdd = values[j];
            for (k = (j+1); k < lineCount; k++)
            {
                secondToAdd = values[k];
                numToCheck = toAdd + curNum + secondToAdd;
                if (numToCheck == 2020)
                {
                    printf("FOUND 2020. From %d at %d and %d at %d and %d at %d\n", curNum, i, toAdd, j, secondToAdd, k);
                    return (curNum * toAdd * secondToAdd);
                }
            }

        }
    }
    printf("FOUND NOTHING!\n");
    return 0;

}

int main(void)
{
    FILE *file;
    int lineCount;
    int *values = NULL;
    int i = 0;
    int answer = 0;

    file = fopen("input.txt", "r");
    lineCount = numOfLines(file);

    printf("line count: %d\n", lineCount);

    values = malloc(sizeof(int) * lineCount);
    // go through and populate our new array with values!!

    fseek(file, 0, SEEK_SET);
    populateArray(file, lineCount, values);

    for (i = 0; i < lineCount; i++)
    {
        printf("%d\n", values[i]);
    }

    // everything is in our array!
    // now just find the two numbers that add up to 2020!
    // oh and multiply them by each other!

    answer = getTwentyTwenty(values, lineCount);


    printf("The answer is: %d!\n", answer);

}