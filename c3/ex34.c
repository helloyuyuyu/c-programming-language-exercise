#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000
void itoa(int n, char s[]);
void reverse(char s[]);


int main()
{
	char s[MAXLINE];
	int n = 12345;

	itoa(n, s);
	printf("%s\n", s);
	
	return 0;
}



void itoa(int n, char s[])	// convert n to characters in s
{
	int sign, i;
	sign = n;
	i=0;
	do
	{
		s[i++] = abs(n % 10) +'0';
	}
	while((n /= 10) > 0);
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	char *pl, *pr; // the left pointer and right pointer
	int i;

	i = 0;
	pr = pl = s;

	while(s[i++] != '\0') 	// let pr points the last character
		pr++;
	pr--;
	
	char c;	
	while(pl < pr)		// reverse the line
	{
		c = *pl; *pl = *pr;	*pr = c;	
		++pl; --pr;
	}
}

