#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{      
	
	int i = 1,j=1;
	for (i=1; i <= 9; i ++ )
	
		for (i=1; j <= 9; i++)
		{
			printf(" % d * % d = % 2d",i,j,i*j);
			printf("\n");
		}


	
	system("pause");
	return 0;
	
}
