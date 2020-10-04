#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[]){

    // Input testing
    // 1. no input
    // 2. check for 26 characters
    // 3. check for letters only
    // 4. ensure no duplicates are in key

    // Ensure user entered only two arguements
    if(argc != 2){
        printf("ERROR: Please enter key as only argument.");
        return 1;
    }

    // Initialize cipher and calculate length
    string cipher = argv[1];
    int cipherLen = strlen(cipher);

    // Complete input testing for key and esnure cipher is 26 characters
    bool isValid = true;
    if( cipherLen != 26){
        printf("ERROR: Key did not contain 26 characters\n");
        return 1;
    }

    // Complete input testing for key and ensure cipher is alpha characters only and there aren't duplicates

    // Boolean array of each position of characters A - Z to indicate if value has been used.
    // Initialized to false.
    bool charUsed[26] = {0};

    // loop through ciper key
    for(int i=0; i < cipherLen; i++){
        if( !isalpha(cipher[i]) ){
            //not alpha value identified. End program.
            printf("ERROR: Key contains non alphabetic character\n");
            return 1;
        } else {
            // alpha character identified. Check to see if it's used.
            if( charUsed[toupper(cipher[i])-65] == 1){
                // char has been used. End program.
                printf("ERROR: Only use each alpha value once\n");
                return 1;
            } else{
                // not used. Mark as used in charUsed boolean array
                charUsed[toupper(cipher[i])-65] = 1;
            }

        }
    }




    // Ask user for plaintext
    string text = get_string("plaintext: ");


    // Execute substitution
    int stringLen = strlen(text);
    int ASCIIInt;
    char encryptedText[stringLen];


    // loop through string
    // identify character in plain text
    // search cipher for substitution
    // replace with proper case
    for(int i=0; i < stringLen ; i++){
        ASCIIInt = (int) text[i];
        if( text[i] >= 'a' && text[i] <= 'z' ){
            encryptedText[i] = tolower( (int) cipher[ASCIIInt-97]);
        } else if( text[i] >= 'A' && text[i] <= 'Z'){
            encryptedText[i] = toupper( (int) cipher[ASCIIInt-65]);
        } else {
            encryptedText[i] = text[i];
        }

    }


    // print ciphertext
    printf("ciphertext: %.*s\n",stringLen,encryptedText);

    /* Note: Printing Char Arrays
       When printing need to either make a char array with the null at the end
       or need to specify how long the array is by using printf formatting of %.*s
       where the number of characters is passed and then the variable of the array is passed as a pointer
     */

     return 0;

}