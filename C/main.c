#include <stdio.h>


int main(void) {


    FILE *fptr;

    // Open a file in writing mode
    fptr = fopen("patatas.txt", "w");

    // Write some text to the file
    fprintf(fptr, "Buenos dias");

    // Close the file
    fclose(fptr); 


    return 0;
}