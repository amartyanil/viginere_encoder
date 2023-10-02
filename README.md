# Viginère Cipher Encoder
This is a command line application that [encodes a string using the Viginère cipher](https://www.coursera.org/learn/cryptography/supplement/7mgaE/programming-assignment-1). It creates two files: one for the plaintext and another for the ciphertext. Instead of adding the "value" of each letter in the key, it performs `XOR` operation.

### How to use
1. Navigate to the location where the repository is to be cloned using the terminal
2. Clone this repository by typing `git clone https://github.com/amartyanil/viginere_encoder`
3. Provided you have gcc installed in your system, create an executable file using the command `gcc -o <filename> Main.c PlaintextInput.c Encoder.c`   in the same location
4. Execute the file by using the command `./<filename>`
