#include <stdio.h>

#define MAXLINE 1000	// maxmium input line length
#define TABWIDTH 4		// a tab = 4 spaces

int getLine(char line[], int maxline);

int main()
{
	

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
