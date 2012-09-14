#ifndef RC4_H
#define RC4_H

#define KEY_LENGTH 6
#define TEXT_LENGTH 10

typedef struct RC4_KEY_S{
    unsigned char S[256];
}RC4_KEY;

/*S is initialized to the identity permutation, mixes in bytes of the key.*/
void RC4_key(RC4_KEY *rc4_key, unsigned char *key, int *keylength);

/*Encrypt the plaintext and output the ciphertext.*/
void RC4(RC4_KEY *rc4_key, unsigned char *plaintext, int *plaintext_length, unsigned char *ciphertext);

#endif
