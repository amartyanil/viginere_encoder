#include <stdio.h>
#include <stdlib.h>

FILE* plain_text_input(char* filename, int no_of_characters);
char* encoder(FILE* fpIn, int no_of_characters);
//gcc -o main Main.c PlaintextInput.c Encoder.c
int main()
{
    int no_of_characters;
    printf("Enter number of characters in the plaintext: ");
    scanf("%d", &no_of_characters);
    FILE* plaintext = fopen("plaintext.txt", "w");
    plaintext = plain_text_input("plaintext.txt", no_of_characters);

    char* cipher_string = (char*) malloc((no_of_characters * 2 + 1) * sizeof(char));
    cipher_string = encoder(plaintext, no_of_characters);

    FILE* ciphertext = fopen("ciphertext.txt", "w");
    fprintf(ciphertext, "%s", cipher_string);

    free(cipher_string);
    fclose(plaintext);
    fclose(ciphertext);

}