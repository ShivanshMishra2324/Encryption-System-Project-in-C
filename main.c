/*
    File: main.c
    This C file is the basis of this project.
    This file calls the required functions to Encrypt and Decrypt text strings.
*/

/*
    Preprocessing Header File "ciphers.h"
    This contains the preprocessed standard header files,
    and the definitions of Encrypting and Decrypting Functions.
*/
#include "ciphers.h"

int main()
{
    // Function call to allocate the Global String Variables
    allocateGlobal();

    char text[256], keyStr[256], ans='y';
    int keyNum;
    int op = 1;

    // Main program loop
    do
    {
        // Menu (Print statements)
        printf("   **Encryption System**\n");
        printf("1. Caesar Encrypt Message\n");
        printf("2. Caesar Decrypt Message\n");
        printf("3. Vigenere Encrypt Message\n");
        printf("4. Vigenere Decrypt Message\n");
        printf("5. Exit.\n");
        printf("Enter your option: ");
        scanf("%d", &op);

        // Switching Option
        switch(op)
        {

        	// Caesar Encrypting
            case 1:
                    printf("Enter text to be Caesar encrypted (Max 255 characters): ");
                    scanf(" %[^\n]s", text);
                    printf("Enter key (must be an integer value): ");
                    scanf("%d", &keyNum);
                    printf("\nThe Caesar encrypted message is: ");
                    printf("\n%s\n\n", caesarEncrypt(text, keyNum));
                    break;

       		// Caesar Decrypting
            case 2:
                    printf("Enter text to be Caesar decrypted (Max 255 characters): ");
                    scanf(" %[^\n]s", text);
                    printf("Enter key (must be an integer value): ");
                    scanf("%d", &keyNum);
                    printf("\nThe Caesar decrypted message is: ");
                    printf("\n%s\n\n", caesarEncrypt(text, 26 - keyNum));
                    break;

          	// Vigenere Encrypting
            case 3:
                    printf("Enter text to be Vigenere decrypted(Max 255 characters): ");
                    scanf(" %[^\n]s", text);
                    printf("Enter key (must be a string value) (Max 255 characters): ");
                    scanf(" %[^\n]s", keyStr);
                    printf("\nThe Vigenere encrypted message is: ");
                    printf("\n%s\n\n", vigenereEncrypt(text, keyStr));
                    break;

           	// Vigenere Decrypting
            case 4:
                    printf("Enter text to be Vigenere decrypted (Max 255 characters): ");
                    scanf(" %[^\n]s", text);
                    printf("Enter key (must be a string value) (Max 255 characters): ");
                    scanf(" %[^\n]s", keyStr);
                    printf("\nThe Vigenere encrypted message is: ");
                    printf("\n%s\n\n", vigenereDecrypt(text, keyStr));
                    break;

            // Exit Option
            case 5:
                    ans = 'n';
                    // CMD clear screen command executed using system()
                    system("cls");
                    // Bash clear screen command executed using system()
                    // system("clear");
                    goto exitLabel;
                    break;

          	// Default option
            default:
                    printf("Wrong Option, Please try again! \n");
                    break;
        }

        // Continue
        printf("Do you want to continue (y/n) ? ");
        scanf(" %c", &ans);

    // To clear screen after each menu iteration
    // CMD clear screen command executed using system()
    system("cls");
    // Bash clear screen command executed using system()
    // system("clear");

    }while(ans == 'y' || ans == 'Y');

    // Label for Exiting case (case 5)
    exitLabel:

    // freeing up the Global String Variables
    freeGlobal();

    printf("Made by: Swaraj Pande and Shivansh Mishra \n");

    return 0;
}