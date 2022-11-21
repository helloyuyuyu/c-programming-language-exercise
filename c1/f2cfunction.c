#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define  STEP 20


float f2c(float f);

int main()
{
	for(float f=LOWER;f <= UPPER; f += STEP) 
		printf("%3.0f %3.1f\n", f, f2c(f));
}

float f2c(float f)
{
	return (f-32) * (5.0/9.0);
}
