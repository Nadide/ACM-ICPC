// Multiplication
#include <stdio.h>
#include <string.h>
int num1[1001], num2[1001];
int result[1005];

main ()
{
	char a[1001], b[1001];
	int len1=0, len2=0, len3;
	int i, j;

	scanf ("%s %s", a, b);	
	for (i=strlen(a)-1; i>=0; --i) 
		num1[ len1++ ] = (int)(a[i] - '0');
	for (i=strlen(b)-1; i>=0; --i)
		num2[ len2++ ] = (int)(b[i] - '0');

	
	for (i=0; i<len1; i++) {
		for (j=0; j<len2; j++) {
			result[i+j] = num1[i]*num2[j];
			if (result[i+j]>9) {
				result[i+j+1] += result[i+j]%10;
				result[i+j] %= 10;  
			}
		}
	}
	len3 = len1+len2-2;

	for (; len3>=0; len3--)
		printf ("%d", result[len3]);
	printf ("\n");
}
