#include <stdio.h>

void qsort(int v[], int left, int right);

int main()
{
	int a[10] = {19, 18, 20, 22, 4, 6, 3, 10, 19, 12};	
	qsort(a, 0, 9);
	for(int i = 0; i < 10; i++)
		printf("%d  ",a[i]);
	printf("\n");


	return 0;
}



void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);
	if(left >= right)
		return;;
	swap(v, left, (left + right)/2);
	last = left;
	for(i = left + 1; i <= right; i++)
		if(v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

void swap(int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
