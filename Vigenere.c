//This is a program that encodes words using the Vigenere's cipher
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Prompts user for the key at command line
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //Checks if key is alphabetical
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (isalpha(argv[1][i]))
            {
                ;
            }
            else
            {
                printf("Please choose an alphabetical key\n");
                return 1;
            }
        }

    }
    else
    {
        printf("Please choose a valid key\n");
        return 1;
    }

    //Declares variable key
    string key = argv[1];

    //Prompts the user for the word to be encrypted
    string text = get_string("plaintext: ");

    //This encodes the text
    printf("ciphertext: ");
    int j = 0;

    for (int i = 0, n = strlen(text); i <= n; i++)
    {
        //Checks if it is alphabetical
        if (isalpha(text[i]))
        {
            //This is the variable for the key that loops, never exceeding the length of the key
            int l = j % strlen(key);

                //Checks if it is uppercase
                if ( isupper(text[i]) && isupper(key[l]))
                {
                    int upper = ((text[i] - 65) + (key[l] - 65)) % 26;
                    upper += 65;
                    printf("%c", upper);
                }

                else if ( isupper(text[i]) && islower(key[l]))
                {
                    int upper = ((text[i] - 65) + (key[l] - 97)) % 26;
                    upper += 65;
                    printf("%c", upper);
                }
                //Checks if it is lowercase
                else if ( islower(text[i]) && isupper(key[l]))
                {
                    int lower = ((text[i] - 97) + (key[l] - 65)) % 26;
                    lower += 97;
                    printf("%c", lower);
                }

                else if ( islower(text[i]) && islower(key[l]))
                {
                    int lower = ((text[i] - 97) + (key[l] - 97)) % 26;
                    lower += 97;
                    printf("%c", lower);
                }

            j++;
        }
        //Prints any non-letter character
        else
        {
            printf("%c", text[i]);
        }
    }
     printf("\n");
    return 0;
}

