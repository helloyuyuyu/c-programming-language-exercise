#include <stdio.h>
#include <string.h>

#define MAXLINES 5000	// max lines to be sorted

char *lineptr[MAXLINES];	// pointers to text lines
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main()
{
	int nlines;
	if((nlines = readlines(lineptr, MAXLINES)) >= 0)	
	{
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}
	else
	{
		printf("error:input too big to sort\n ");
		return 1;
	}
}

#define MAXLEN 1000	// max length of the input line
int  getLine(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while((len = getLine(line, MAXLEN)) > 0)
		if(nlines >= maxlines || (p = alloc(len)) == NULL) 
			return -1;
		else
		{
			line[len-1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	return nlines;
}

void writelines(char *lineptr[], int nlines)
{
	int i;
	for(i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
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

#define ALLOCSIZE 10000	// size of available space
static char allocbuf[ALLOCSIZE];	// storage for alloc
static char *allocp = allocbuf;		// next free position

char *alloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp >= n)
	{
		allocp += n;
		return allocp - n;
	}
	else
		return 0;

}

void afree(char *p)
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}



void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	if(left >= right)
		return;;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left + 1; i <= right; i++)
		if(strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}


void swap(char *v[], int i, int j)
{
	char *tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}






























