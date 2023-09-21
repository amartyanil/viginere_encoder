#include <stdio.h>
#include <stdlib.h>

//generate a file "ptext.txt" for the plaintext
FILE* plain_text_input(char* filename, int no_of_characters)
{
    FILE* ptext = fopen(filename,"w");

    //take the string as input
    char* file_content_string = (char*) malloc((no_of_characters) * sizeof(char));
    printf("Enter plaintext: ");
    fgets(file_content_string, no_of_characters+1, stdin);
    
    fprintf(ptext, "%s", file_content_string);

    free(file_content_string);
    fclose(ptext);
    
    return fopen(filename, "r"); 
}