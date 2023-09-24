#include <stdio.h>
#include <stdlib.h>

//write to the contents of a file pointer "file"
void plain_text_input(FILE* file, int no_of_characters)
{
    char* file_content_string = (char*) malloc((no_of_characters+1) * sizeof(char));
    printf("Enter plaintext: ");
    fgets(file_content_string, no_of_characters+1, stdin);
    fprintf(file, "%s", file_content_string);
    free(file_content_string);
}
