#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Winston Venderbush
//10/2/16



int mystrlen(char *chr){
	int i = 0;
	while (*chr != 0){
		i++;
		chr++;
	}
	return i;
}

char* mystrcpy(char *dest, char *src){
	char *orig = dest;
	int i = 1;
	while (*src != 0){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return orig;
}

char* mystrncpy(char *dest, char *src, int n){
	char *orig = dest;
	int i = 1;
	while (n != 0){
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	return orig;
}

char* mystrcat(char *dest, char *src){
	char *orig = dest;
	while (*dest != 0){
		dest++;
	}
	while (*src != 0){
		*dest = *src;
		dest++;
		src++;
	}
	return orig;
}

char* mystrncat(char *dest, char *src, int n){
	char *orig = dest;
	while (*dest != 0){
		dest++;
	}
	while (n > 0){
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	return orig;
}

int mystrcmp(char *s1, char *s2){
	int minlen = mystrlen(s1);
	if (mystrlen(s2) < mystrlen(s1))
		minlen = mystrlen(s2);
	int sum1 = 0;
	int sum2 = 0;
	while (minlen + 1 > 0){
		sum1 += *s1;
		sum2 += *s2;
		minlen--;
	}
	return sum1 - sum2;
}

char* mystrchr(char *s, char c){
	while (*s != c){
		s++;
	}
	return s;
}

char* mystrstr(char *s, char *subs){
	while (*s) {
		char *startstr = s;
		char *teststr = subs;
		while (*s == *teststr && *s && *teststr){
			s++;
			teststr++;
		}
		if (*teststr == 0)
		    return startstr;	  
		    s = startstr + 1;
		}
	return NULL;
}


int main(){
	printf("Stringly System Diagnostic\n==========================");
	char s1[256] = "Big birds eating bird seed";
	char s2[256] = "Eat";
	char c = 'e';

	printf("\n");
	printf("string1: %s\n", s1);
	printf("string2: %s\n", s2);
	printf("testchar: %c\n", c);

	printf("\n");
	printf("mystrlen:\n");
	printf("mystrlen(string1) -- should be 26: %d\n", mystrlen(s1));

	printf("\n");
	printf("mystrcpy:\n");
	printf("mystrpy(string1, string2) -- should be 'Eat': %s\n", mystrcpy(s1, s2));

	printf("\n");
	char s3[128] = "Big birds eating bird seed";
	char s4[128] = "Eat";
	printf("mystrncpy:\n");
	printf("mystrnpy(string1, string2, 2) -- should be 'Eag birds eating bird seed': %s\n", mystrncpy(s3, s4, 2));

	printf("\n");
	char s5[128] = "Big birds eating bird seed";
	char s6[128] = "Eat";
	printf("mystrcat:\n");
	printf("mystrcat(string1, string2) -- should be 'Big birds eating bird seedEat': %s\n", mystrcat(s5, s6));

	printf("\n");
	char s7[128] = "Big birds eating bird seed";
	char s8[128] = "Eat";
	printf("mystrncat:\n");
	printf("mystrncat(string1, string2, 1) -- should be 'Big birds eating bird seedE': %s\n", mystrncat(s7, s8, 1));

	printf("\n");
	char s9[128] = "Big birds eating bird seed";
	char s10[128] = "Eat";
	printf("mystrcmp:\n");
	printf("mystrcmp(string1, string2) -- should be -12: %d\n", mystrcmp(s9, s10));

	printf("\n");
	char s11[128] = "Big birds eating bird seed";
	char s12[128] = "Eat";
	printf("mystrchr:\n");
	printf("mystrchr(string1, char) -- should be 'eating bird seed': %s\n", mystrchr(s11, c));

	printf("\n");
	char s13[128] = "Big birds eating bird seed";
	char s14[128] = "birds eating";
	printf("mystrstr:\n");
	printf("mystrstr(string1, 'birds eating') -- should be 'birds eating bird seed': %s\n", mystrstr(s13, s14));
	return 0;
}













