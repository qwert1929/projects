#include <stdio.h>

int fact(int);
 
int combination()
{
 int x,y,xcy;
 
  	printf("Enter a number x and y\n");
  	scanf("%d %d",&x,&y);
  	xcy=fact(x)/(fact(y)*fact(x-y));
    printf("Value of %dC%d = %d\n",x,y,xcy);
}
 
int fact(int n)
{
    int i,f=1;
    for(i=1;i<=n;i++)
    {
        f=f*i;
    }
    return f;
}

int power()
{
int base, exponent;
int result = 1;
printf("Enter x and y: ");
scanf("%d %d", &base,&exponent);

	for (exponent;exponent>0;exponent--)
	
	result = (result * base);
	
	printf("Answer = %d\n", result);
return result;
}    

int factorial()
{
int i,f,x;
 
printf("Enter x: ");
scanf("%d",&x);
 
for(i=1;i<=x;i++)
	f=f*i;
 
 printf("Factorial of %d is: %d\n",x,f);
 
  return f;
}


int main()
{
	
	int x,y;
	

	factorial(x);
	power(x,y);
	combination(x,y);

	
	return 0;
}
