#include<stdio.h>
#include<string.h>

int main()
{
	char amessage[] = "now is the time";
	char *pmessage = "now is the time";

	int l = strlen(amessage);
	printf("%d\n", l);
	l = strlen(pmessage);
	printf("%d\n", l);
	
	
	printf("%s\n", amessage);
	printf("%s\n", pmessage);

	for(int i = 0; i < l; i++)
		putchar(amessage[i]); 
	printf("\n");

	for(int i = 0; i < l; i++)
		putchar(pmessage[i]); 
	printf("\n");

	return 0;
}
