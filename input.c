#include <stdio.h>
#include <stdlib.h>

//Function for getting int input. Simple, but not very configurable
//End of function can be optimized a bit, but stays for readability
int getInt() {
    char *inp;
    int retInt, len, i;

    if (fgets(inp, 130, stdin) == NULL) {
        return 1;
    }

    len = strlen(inp); 
    
    for(i=0;i<len;i++) {
        int isNum = 0;
        if (!( (inp[i] < 58) && (inp[i] > 47) )){
            isNum = 1; 
        }
    }

    if ((isNum == 0) && (inp != NULL)) {
        return (atoi(inp)); 
    }
    else {
        return 1;
    }

}

int getLine(char *inp, int size) {
    char c;
    int of;

    //If the user doesn't specify a size, the program will free the input string and allocate a char array size 50
    //This is done to prevent the getLine function from creating an overflow bug
    if (size == NULL) {
        size = 48;
        free(inp);
        inp = malloc(sizeof(char)*50);
    }

   if (fgets(inp, size, stdin) == NULL) {
        return 1;
    }
    //Flushes the input if the last character is not line break
    if (inp[strlen(inp)-1] != "\n"){
        while ( ((c = getchar()) != "\n") && (c != EOF) );
    }
    //Repleace linebrake with \0 so it is formatted as a proper string
    inp[strlen(inp)-1] = "\0";
    return 0;
}


//Used to clear the std buffer 
void clearBuffer() {
    char c;
    while ( (c = (getchar()) != '\n') && (c != '\0') (c != EOF) );
}
