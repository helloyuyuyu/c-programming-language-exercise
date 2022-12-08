#include <stdio.h>
#define MAXLINE 1000


void reverse(char s[]);
int getLine(char line[], int maxline);

int main()
{
	char line[MAXLINE];

	while(getLine(line, MAXLINE) > 0) 
	{
		reverse(line);
		printf("%s\n", line);
	}

	return 0;
}

void reverse(char s[])
{
	char *pl, *pr; // the left pointer and right pointer
	int i;

	i = 0;
	pr = pl = s;

	while(s[i++] != '\0') 	// let pr point the last character
		pr++;
	pr--;
	
	char c;	
	while(pl < pr)		// reverse the line
	{
		c = *pl; *pl = *pr;	*pr = c;	
		++pl; --pr;
	}
}



int getLine(char s[], int lim)
{
	int c, i;

	for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;

	if(c == '\n')
	{
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';
	return i;
}
