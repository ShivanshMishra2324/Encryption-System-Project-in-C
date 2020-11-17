/*
    File: ciphers.h
    This header file contains all the functions and declarations,
    for the Caesar and Vigenere Encryption Project.
*/

// Standard Header Files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
    Declaration of Global String Variables.
    These Global variables will be given dynamically allocated memory after calling allocateGlobal().
    These Global variables will be freed after calling freeGlobal().
*/
char *encrypted, *vigenereKey, *decrypted;

/*
    Function to dynamically allocate the memory of global variables.
*/
void allocateGlobal()
{
    encrypted = (char *)malloc(256 * sizeof(char));
    vigenereKey = (char *)malloc(256 * sizeof(char));
    decrypted = (char *)malloc(256 * sizeof(char));
}

/*
    Function to free the dynamically allocated memory of global variables.
*/
void freeGlobal()
{
    free(encrypted);
    free(vigenereKey);
    free(decrypted);
}

/*
    Function to Caesar Encrypt a String.
    Important: The Same function can be used to,
    Decrypt a Caesar Cipher using key = 26 - key.
*/
char* caesarEncrypt(char *text, int key)
{
    char currChar;
    int i;

    // Traversing the Text
    for(i = 0; text[i] != '\0'; i++)
    {
        currChar = text[i];

        // Encrypting Uppercase Characters
        if(isupper(currChar))
            encrypted[i] = (currChar + key - 65) % 26 + 65;

        // Encrypting Lowercase Characters
        else if(islower(currChar))
            encrypted[i] = (currChar + key - 97) % 26 + 97;

        // Other characters are not encrypted
        else
            encrypted[i] = currChar;
    }
    encrypted[i] = '\0';

    return encrypted;
}

/*
    Functions to Vigenere Encrypt a String.
    Generating the Vigenere Key to fit the length of text.
    This function will be called inside vigenereEncrypt() and vigenereDecrypt()
*/
char* generateVigenereKey(char *text, char *key)
{
    int textLength = strlen(text);
    int keyLength = strlen(key);

    int i = 0, j = 0;

    /*  Adding the required characters,
        to make the length of key equal to that of text */
    while(i < textLength)
    {
        if(j == keyLength)
            j = 0;

        // The characters in key are all uppercase
        vigenereKey[i] = toupper(key[j]);
        i++;
        j++;
    }
    vigenereKey[i] = '\0';

    return vigenereKey;

}

/*
    Function to Vigenere Encrypt a String.
*/
char* vigenereEncrypt(char *text, char *key)
{
    char currChar, currKeyChar, upperChar;

    int i;

    // Copying generated vigenere key via calling the function
    strcpy(vigenereKey, generateVigenereKey(text, key));

    //Traversing the text
    for(i = 0; text[i] != '\0'; i++)
    {
        currChar = text[i];
        currKeyChar = vigenereKey[i];
    
        // Encrypting Uppercase Characters
        if(isupper(currChar))
            encrypted[i] = (currChar + currKeyChar) % 26 + 65;

        // Encrypting Lowercase Characters
        else if(islower(currChar))
        {
            currChar = toupper(currChar);
            upperChar = (currChar + currKeyChar) % 26 + 65;
            encrypted[i] = tolower(upperChar);
        }

        // Other Characters are not encrypted
        else
            encrypted[i] = currChar;
    }
    encrypted[i] = '\0';

    return encrypted;
}

/*
    Function to Vigenere Decrypt a String.
*/
char* vigenereDecrypt(char *encrypted, char *key)
{
    char currChar, currKeyChar, upperChar;

    int i;

    // Copying generated vigenere key via calling the function
    strcpy(vigenereKey, generateVigenereKey(encrypted, key));

    //Traversing the encrypted text
    for(i = 0; encrypted[i] != '\0'; i++)
    {
        currChar = encrypted[i];
        currKeyChar = vigenereKey[i];

        // Decrypting Uppercase Characters
        if(isupper(currChar))
            decrypted[i] = (currChar - currKeyChar + 26) % 26 + 65;

        // Decrypting Lowercase Characters
        else if(islower(currChar))
        {
            currChar = toupper(currChar);
            upperChar = (currChar - currKeyChar + 26) % 26 + 65;
            decrypted[i] = tolower(upperChar);
        }

        // Other Characters are not decrypted
        else
            decrypted[i] = currChar;
    }
    decrypted[i] = '\0';

    return decrypted;
}
