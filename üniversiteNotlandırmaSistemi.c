#include <stdio.h>

findWeight()
{
	int n,i=1,c,totalweight=0,sumc=0;
	int A,B,C,D,F;
	char g;
	printf("enter the number of courses taken:\n");
	scanf("%d",&n);
	while(i<n+1)
	{
		printf("enter the grade for course %d: ",i);
		scanf(" %c", &g);
		printf("enter the credit for course %d: ",i);
		scanf("%d",&c);
		if(g=='A')
		{
			totalweight=totalweight+(4*c);
		}
		else if(g=='B')
		{
			totalweight=totalweight+(3*c);
		}
		else if(g=='C')
		{
			totalweight=totalweight+(2*c);
		}
		else if(g=='D')
		{
			totalweight=totalweight+(1*c);
		}
		else if(g=='F')
		{
			totalweight=totalweight+(0*c);
		}
		else
		{
			printf("invalid grade value");
		}
		sumc=sumc+c;
		i++;
	}
	
	findGPA(totalweight,sumc);
}

findGPA(int totalweight,int sumc)
{
	double GPA;
	
	GPA=((double)totalweight/sumc);
	findCredit(GPA);
}

findCredit(double GPA)
{
	int maxcredit;
	if(GPA>=3.5)
	{
		maxcredit=24;
	}
	else if(GPA<3.5 && GPA>=3)
	{
		maxcredit=21;
	}
	else if(GPA<3 && GPA>=2.5)
	{
		maxcredit=18;
	}
	else if(GPA<2.5 && GPA>=2)
	{
		maxcredit=16;
	}
	else if(GPA<2 && GPA>=1.5)
	{
		maxcredit=12;
	}
	else if(GPA<1)
	{
		maxcredit=8;
	}
	printf("Your GPA is %f and you can take %d credits next semester",GPA,maxcredit);
}


int main()
{
	findWeight();
	
	
	return 0;
}
