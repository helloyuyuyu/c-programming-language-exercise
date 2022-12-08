#include <stdio.h>
#include <string.h>
#define MAXLINE 1000
int getLine(char line[], int maxline);

// print lines that match pattern from 1st arg
int main(int argc, char *argv[])
{
	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;
	while(--argc > 0 && (*++argv)[0] == '-')
		while(c = *++argv[0])
			switch(c)


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
