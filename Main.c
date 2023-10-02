#include <stdio.h>
#include <stdlib.h>

void plain_text_input(FILE* filename, int no_of_characters);
void encoder(FILE* plaintext, char* cipher_string);

int main()
{
    int no_of_characters;   
    printf("Enter number of characters in the plaintext: ");
    scanf("%d", &no_of_characters);
    
    FILE* plaintext_w = fopen("plaintext.txt", "w");
    while (getchar() != '\n');
    plain_text_input(plaintext_w, no_of_characters);
    fclose(plaintext_w);

    FILE* plaintext_r = fopen("plaintext.txt","r");
    char* cipher_str = (char*) malloc((no_of_characters+1) * sizeof(char));
    encoder(plaintext_r, cipher_str);
    FILE* ciphertext = fopen("ciphertext.txt", "w");
    fprintf(ciphertext, "%s", cipher_str);
    free(cipher_str);
    fclose(plaintext_r);
    fclose(ciphertext);
}
