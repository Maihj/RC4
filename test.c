#include <stdio.h>
#include <string.h>
#include "rc4.c"

int main(){
    int i;
    unsigned char plaintext[100];
    unsigned char key[6] = "cipher";
    unsigned char ciphertext[100];
    
    RC4_KEY rc4_key;
    
    printf("Please enter the plaintext: ");
    scanf("%s", plaintext);
    
    /*Encryption*/
    RC4_key(&rc4_key, key, strlen(key));
    RC4(&rc4_key, plaintext, strlen(plaintext), ciphertext);
    
    printf("The plaintext is: ");
    for (i = 0; i < strlen(plaintext); i++)
	printf("%x ", plaintext[i]);
    printf("\nThe key is: ");
    for (i = 0; i < strlen(key); i++)
	printf("%x ", key[i]);
    printf("\nThe ciphertext is: ");
    for (i = 0; i < strlen(ciphertext); i++)
	printf("%x ", ciphertext[i]);
    printf("\n");
    
    return 0;
}
