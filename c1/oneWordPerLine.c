#include <stdio.h>
#define FALSE 0
#define TRUE 1

int main()
{
	int c;
	int preblank;
	preblank = FALSE;
	while((c = getchar()) != EOF)
	{
		if(c=='\t' || c==' ' || c=='\n')
		{
			if(preblank == FALSE)
			{
				printf("\n");
				preblank = TRUE;
			}
		}
		else
		{
			preblank = FALSE;
			putchar(c);
		}
	}
}
