#include <stdio.h>

int main(){
    int i, j, temp, keylength = 3;
    unsigned char S[256], K[3] = "abc";
    
    /*S is initialized to the identity permutation, mixes in bytes of the key.*/
    for (i = 0; i < 256; i++)
	S[i] = i;

    j = 0;
    for (i = 0; i < 256; i++){
	j = (j + S[i] + K[i % keylength]) % 256;
	/*Swap S[i] and S[j]*/
	temp = S[i];
	S[i] = S[j];
	S[j] = temp;
    }
    
    /*Output the keystream by pseudo-random number generator.*/
    i = 0;
    j = 0;
    while(1){
	i = (i + 1) % 256;
	j = (j + S[i]) % 256;
	/*Swap S[i] and S[j]*/
	temp = S[i];
	S[i] = S[j];
	S[j] = temp;
	/*generate K*/
	K[0] = S[(S[i] + S[j]) % 256];
	printf("%s\n", K[0]);
    }
    return 0;
}
