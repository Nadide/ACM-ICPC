// Addition
#include <stdio.h>
#include <string.h>
#define MAX(len1,len2) (len1>len2)?(len1):(len2)
int number1[1001], number2[1001];
int result[1005]; 

int main ()
{
	char a[1001], b[1001];
	int len1=0, len2=0, maxsize;
	int i, j;
	
	scanf ("%s %s", a, b);	
	for (i=strlen(a)-1; i>=0; --i) 
		number1[len1++] = (int)(a[i] - '0');
	for (i=strlen(b)-1; i>=0; --i)
		number2[len2++] = (int)(b[i] - '0');

	maxsize = MAX(len1,len2);
	for (i=0; i<maxsize; i++) {
		result[i]+= number1[i]+number2[i];
		if (result[i]>9) {
			result[i+1]+= 1;
			result[i]%= 10;
		}
	}
	if (result[maxsize] != 0)
		maxsize++;

	for (--maxsize; maxsize>=0; --maxsize)
		printf ("%d", result[maxsize]);
	printf ("\n");
}
