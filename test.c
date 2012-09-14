#include <stdio.h>
#include "rc4.h"

int main(){
    int i, x;
    int *p;
    unsigned char plaintext[TEXT_LENGTH];
    unsigned char key[KEY_LENGTH] = "cipher";
    unsigned char ciphertext[TEXT_LENGTH];
    
    RC4_KEY rc4_key;
    
    printf("------------------------------\n----------RC4 CIPHER----------\n------------------------------\n");
    printf("Please enter the plaintext(%d characters): ", TEXT_LENGTH);
    for (i = 0; i < TEXT_LENGTH; i++)
	scanf("%c", &plaintext[i]);
   
    /*Encryption*/
    x = KEY_LENGTH;
    p = &x;
    RC4_key(&rc4_key, &key[0], p);
    x = TEXT_LENGTH;
    RC4(&rc4_key, &plaintext[0], p, &ciphertext[0]);
    
    printf("The plaintext is: ");
    for (i = 0; i < TEXT_LENGTH; i++)
	printf("%x ", plaintext[i]);
    printf("\nThe key is: ");
    for (i = 0; i < KEY_LENGTH; i++)
	printf("%x ", key[i]);
    printf("\nThe ciphertext is: ");
    for (i = 0; i <TEXT_LENGTH; i++)
	printf("%x ", ciphertext[i]);
    printf("\n\n");
    
    return 0;
}
