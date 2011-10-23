#include "rc4.h"

/*S is initialized to the identity permutation, mixes in bytes of the key.*/
void RC4_key(RC4_KEY* rc4_key, unsigned char* key, int keylength){
    int i, j, temp;

    /*Initialize S*/
    for (i = 0; i < 256; i++)
	rc4_key -> S[i] = i;

    j = 0;
    for (i = 0; i < 256; i++){
	j = (j + rc4_key -> S[i] + key[i % keylength]) % 256;
	/*Swap rc4_key -> S[i] and rc4_key -> S[j]*/
	temp = rc4_key -> S[i];
	rc4_key -> S[i] = rc4_key -> S[j];
	rc4_key -> S[j] = temp;
    }
}

/*Generate the key stream which length is the same as plaintext's and encrypt the plaintext and output the ciphertext.*/
void RC4(RC4_KEY* rc4_key, unsigned char* plaintext, int plaintext_length, unsigned char* ciphertext){
    int i = 0, j = 0, n, temp;

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
