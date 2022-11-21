#include <stdio.h>

#define MAXLINE 1000 // maxmium input line length

int getLine(char line[], int maxline);
void escape(char to[], char from[]);	// convert characters into visible escape sequence

int main()
{
	char line[MAXLINE];
	char visibleLine[MAXLINE];
	while(getLine(line, MAXLINE))
	{
		escape(visibleLine, line);
		printf("%s", visibleLine);
	}
	
	return 0;
}

void escape(char to[], char from[])	// convert characters into visible escape sequence
{
	int c;
	int i = 0;
	int j = 0;
	while(c = from[i++]) 
	{
		switch(c)
		{
		case '\n':
			to[j++] = '\\';
			to[j++] = 'n';
			break;
		case '\t':
			to[j++] = '\\';
			to[j++] = 't';
			break;
		default:
			to[j++] = c;
			break;
		}
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
