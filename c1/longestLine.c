#include <stdio.h>

#define MAXLINE 1000 // maxmium input line length

int getLine(char line[], int maxline);
void copy(char to[], char from[]);


// print the longest input line
int main()
{
	int len;		// current line length
	int max;		// maxmium length seen so far
	char line[MAXLINE];		// current input line
	char longest[MAXLINE];	// longest line saved here 
	int preLineLen;
	int firstPart;
	preLineLen = 0;
	firstPart = 1;

	
	max = 0;
	while((len = getLine(line,MAXLINE)) > 0)
	{
		if(len == (MAXLINE-1) && line[MAXLINE-2] != '\n')	// if the line longer than MAXLINE
		{													// we only get the accurate length
			preLineLen += len;
			if(firstPart)
			{
				copy(longest,line);		
				firstPart = 0;
			}
			continue;
		}
		
		if(preLineLen)
		{
			len += preLineLen;
			preLineLen = 0;
			firstPart = 1;
		}

		if(len > max && len > MAXLINE - 1)
		{
			max = len;
		}
		else if(len > max)
		{
			max = len;
			copy(longest,line);		
		}
	}

	if(max > 0)		// there was a line
		printf("%s", longest);
	
	return 0;

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

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i]=from[i]) != '\0')
		++i;	
}









