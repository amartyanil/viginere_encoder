#include <stdio.h>
#include <stdlib.h>

//make a string the version of the encoded version of the plaintext file
void encoder(FILE* plaintext, char* cipher_string)
{
    //read key length
    int key_length;
    printf("Enter key length: ");
    scanf("%d", &key_length);
    while (getchar() != '\n');

    //read key
    char ch;
    int i; 
    char* key = (char*) malloc((key_length) * sizeof(char));
    printf("Enter key: ");
    fgets(key, key_length + 1, stdin);
    while (getchar() != '\n');

    i = 0;

    while ((ch = fgetc(plaintext)) != EOF)
    {
        if (ch != '\n')
        {
            sprintf(cipher_string+i, "%02X", ch ^ key[i % key_length]);
            i=i+2;
        } 
    }    
    cipher_string[i] = '\0';
    
    free(key);
}
