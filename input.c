#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function for getting int input. Simple, but not very configurable
//
//Returns:  positive int - int entered by user
//          -1 - Incorrect input
int getInt() {
    char inp[140];
    int len, i;

    if (fgets(inp, 128, stdin) == NULL) {
        return -1;
    }

    len = strlen(inp); 
    int isNum = 0;
    //(len-2) as that is the last character before the '\n' in the input string
    for(i=0;i<len-1;i++) {
        if (!( (inp[i] < 58) && (inp[i] > 47) )){
            isNum = 1; 
        }
    }

    if (!isNum) {
        return (atoi(inp)); 
    }
    else {
        return -1;
    }

}
    //Function: getLine
    //          Gets string input from user. Assumes valid ascii input
    //Parameters: *inp - char array to be filled; size - size of the char array
    //
    //Returns:  0 - sucsess
    //          1 - no input
    //          2 - input too long (still puts the input read into the char array)
int getLine(char *inp, int size) {
    char c;
    int returnVal = 0;

    //If the user doesn't specify a size, the program will free the input string and allocate a char array size 50
    //This is done to prevent the getLine function from creating an overflow bug

    if (size == 0) {
        size = 48;
        inp = (char*)realloc(inp, sizeof(char)*50);
    }

   if (fgets(inp, size, stdin) == NULL) {
        return 1;
    }
    printf("%c\n", *(inp + (strlen(inp) - 1)) );
    //Flushes the input if the last character is not line break
    if (*(inp + (strlen(inp) - 1)) != '\n'){
        while ( ((c = getchar()) != '\n') && (c != EOF) );
        returnVal = 2;
    }
    //Repleace linebrake with \0 so it is formatted as a proper string
    inp[strlen(inp)-1] = '\0';
    return returnVal;
}


//Used to clear the stdin buffer 
//Want to set a limit for the while loop, but don't know how large to set the max runs
void clearBuffer() {
    char c;
    int maxIterations = 10;
    while ( (c = (getchar()) != '\n') && (c != '\0') && (c != EOF) );
}
