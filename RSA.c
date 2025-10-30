#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>


int main(){

    int prime[] = {2, 3, 5, 7};
    srand(time(NULL));

    int randomIndex = rand() % 4;

    int p = prime[randomIndex];
    int q = prime[(randomIndex + (rand() % 3) + 1) % 4];
    int n = p*q;
    int r = (p-1)*(q-1);
    int e = 7;
    int d = 0;

    int i = 0;
    while (i < 1000) {
        if (((e*i)%r) == 1){
            d = i;
            break;
        }
        i++;
    }
    printf("P: %d\n", p);
    printf("Q: %d\n", q);
    printf("E: %d\n", e);
    printf("N: %d\n", n);
    printf("R: %d\n", r);
    printf("D: %d\n", d);
    
    int message[10] = {1,2,3,4,5,6,7,8,9,0};
    /*
    printf("Enter a message of 10 numbers: ");
    for (i = 0; i < 10; i++) {
        scanf("\n%d", &message[i]);
    }
    printf("You entered: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", message[i]);
    }
    */

    printf("Your message is: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", message[i]);
    }
    printf("\n");


    int crypt[10];

    for (i = 0; i < 10; i++) {
        crypt[i] = (int)fmod(pow(message[i], e), n);
    }

    printf("Your public key is (%d,%d)\n",e,n);
    printf("Your encrypted message is: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", crypt[i]);
    }
    printf("\n");

    int decrypt[10];

    for (i = 0; i < 10; i++) {
        decrypt[i] = (int)fmod(pow(crypt[i],d), n);
    }

    printf("Your private key is (%d,%d)\n",d,n);
    printf("Your decrypted message is: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", decrypt[i]);
    }
    printf("\n");

    return 0;
}