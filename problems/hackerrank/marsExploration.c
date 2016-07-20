#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* S = (char *)malloc(10240 * sizeof(char));
    scanf("%s",S);
    int len = strlen(S), c=0;
    for (int i=0; i<len; i+=3) {
        if (S[i] != 'S')   c++;
        if (S[i+1] != 'O') c++;
        if (S[i+2] != 'S') c++;
    }
    printf ("%d\n", c);
    
    return 0;
}

