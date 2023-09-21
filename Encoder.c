#include <stdio.h>
#include <stdlib.h>

//read the file from fpIn and return the encoded string
char* encoder(FILE* fpIn, int no_of_characters)
{
    char* ciphertext = (char*) malloc((no_of_characters * 2 + 1) * sizeof(char));

    //read key length
    int key_length;
    printf("Enter key length: ");
    scanf("%d", &key_length);

    //read key
    unsigned char ch;
    int i; 
    unsigned char* key = (unsigned char*) malloc(key_length * sizeof(unsigned char));
    printf("Enter key: ");
    fgets((char*)key, key_length + 1, stdin);

    //store the encrypted key in ciphertext in hex-encoded format
    i = 0;
    while (fscanf(fpIn, "%c", &ch) == 1)
    {
        if (ch != '\n')
        {
            sprintf(ciphertext + 2 * i, "%02X", ch ^ key[i % key_length]);
            i++;
        }
    }

    //end the string
    ciphertext[i] = '\0';

    fclose(fpIn);

    return ciphertext;
}