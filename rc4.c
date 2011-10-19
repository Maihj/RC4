#include <string.h>
#include "rc4.h"

/*S is initialized to the identity permutation, mixes in bytes of the key.*/
void RC4_key(RC4_KEY* rc4_key, unsigned char* key, int keylength){
    int i, j, temp;
    unsigned char K[256];

    /*Initialize S*/
    for (i = 0; i < 256; i++)
	rc4_key -> S[i] = i;

    /*Initialize K*/
    j = 0;
    for (i = 0; i < 256; i++){
	K[i] = key[j % keylength];
	j++;
    }

    j = 0;
    for (i = 0; i < 256; i++){
	j = (j + rc4_key -> S[i] + K[i]) % 256;
	/*Swap rc4_key -> S[i] and S[j]*/
	temp = rc4_key -> S[i];
	rc4_key -> S[i] = rc4 -> S[j];
	rc4_key -> S[j] = temp;
    }
}

/*Encrypt the plaintext and output the ciphertext.*/
void RC4(RC4_KEY* rc4_key, unsigned char* plaintext, int plaintext_length, unsigned char* ciphertext){
    int i, j, n;
    
    i = 0;
    j = 0;
    for (i = 0; i < plaintext_length; i++){
	i = (i + 1) % 256;
	j = (j + rc4_key -> S[i]) % 256;
	/*Swap rc4_key -> S[i] and rc4_key -> S[j]*/
	temp = rc4_key -> S[i];
	rc4_key -> S[i] = rc4_key -> S[j];
	rc4_key -> S[j] = temp;

	n = rc4_key -> S[(rc4_key -> S[i] + rc4_key -> S[j]) % 256];
	
	/*Encryption*/
	ciphertext[i] = plaintext[i] ^ n;
    }
}
