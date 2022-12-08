#include <stdio.h>

void reverse(char *s, int left, int right);

int main()
{
	char s[] = "helloworld\n";
	printf("%s", s);
	reverse(s, 0, 10);
	printf("%s", s);
	

	return 0;
}
void reverse(char *s, int left, int right)
{
	int temp;
	temp = s[left];
	s[left] = s[right];
	s[right] = temp;
	if(left < right )
		reverse(s, ++left, --right);
}
