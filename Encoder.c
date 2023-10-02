#include <stdio.h>
#include <stdlib.h>

void encoder(FILE* plaintext, char* cipher_string)
{
    //read key length
    int key_length;
    printf("Enter key length: ");
    scanf("%d", &key_length);
    while (getchar() != '\n');

    //read key
    char* key = (char*) malloc((key_length) * sizeof(char));
    printf("Enter key: ");
    fgets(key, key_length + 1, stdin);
    while (getchar() != '\n');

    //do the encoding operation by changing the string
    char ch;
    int i;
    i = 0;
    while ((ch = fgetc(plaintext)) != EOF)
    {
        if (ch != '\n')
        {
            cipher_string[i] = (char) (ch ^ key[i % key_length]);
            i++;
        } 
    }    
    cipher_string[i] = '\0';
    free(key);
}
