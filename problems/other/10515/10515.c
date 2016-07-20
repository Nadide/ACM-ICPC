// September 9, 2015
#include <stdio.h>

int LastTwo (char string[])
{
	int len = strlen(string);
	printf ("last two= %d\n", (int)(string[len-1]-48));
	if (len == 1)
		return (int)( string[len-1]-48 );
	else
		return (int)( (string[len-2]-48)*10 + (string[len-1]-48) );
}

int main ()
{
	int lenM, lenN;
	int mLast, nLast;
	char m[101], n[101];

	scanf ("%s %s", m, n);
	lenM = strlen (m);
	lenN = strlen (n);

	// except 0 0
	while (lenM!=1 || lenN!=1 || m[lenM-1]!='0' || n[lenN-1]!='0') {
		mLast = m[ strlen(m)-1 ] -48;
		nLast = n[ strlen(n)-1 ] -48;
		
		printf ("mLast=%d nLast=%d\n", mLast, nLast);		

		switch (mLast) {
			case 4:
				printf ("%c\n", (nLast%2)?'4':'6');
				break;
			case 9:
				printf ("%c\n", (nLast%2)?'9':'1');
				break;
			case 0: case 1: case 5: case 6:
				printf ("%c\n", mLast+48);
				break;
			case 2:
				nLast = LastTwo(n); // find last two digit
				printf ("nLast = %d\n",nLast);
				switch (nLast % 4) {
					case 0:
						printf ("6\n");
						break;
					case 1:
						printf ("2\n");
						break;
					case 2:
						printf ("4\n");
						break;
					case 3:
						printf ("8\n");
				}
				break;
			case 3:
				nLast = LastTwo(n);
				switch (nLast % 4) {
                                        case 0:
                                                printf ("1\n");
                                                break;
                                        case 1:
                                                printf ("3\n");
                                                break;
                                        case 2:
                                                printf ("9\n");
                                                break;
                                        case 3:
                                                printf ("7\n");
				}
				break;
			case 7:
				nLast = LastTwo(n);
				switch (nLast % 4) {
                                        case 0:
                                                printf ("1\n");
                                                break;
                                        case 1:
                                                printf ("7\n");
                                                break;
                                        case 2:
                                                printf ("9\n");
                                                break;
                                        case 3:
                                                printf ("3\n");
				}
				break;
			case 8:
				nLast = LastTwo(n);
				switch (nLast % 4) {
                                        case 0:
                                                printf ("6\n");
                                                break;
                                        case 1:
                                                printf ("8\n");
                                                break;
                                        case 2:
                                                printf ("4\n");
                                                break;
                                        case 3:
                                                printf ("2\n");
				}
		}
		scanf ("%s %s", m, n);
	}

	return 0;
}
