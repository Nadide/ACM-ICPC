// Stacks
#include <stdio.h>
#include "cs50.h"

int main(void)
{
    char s[101],r[101],rEnd=-1;
    while (scanf("%s",s)==1) {
        for (int i=0; i<strlen(s); i++)
            if (('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z') || ('0'<=s[i] && s[i]<='9'))
                r[++rEnd] = s[i];
            else {
                while (rEnd >=0)
                    printf ("%c", r[rEnd--]);
                printf ("%c", s[i]);
            }
        while (rEnd >=0)
            printf ("%c", r[rEnd--]);
        printf (" ");
    }
}

