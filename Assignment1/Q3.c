#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int GCD(int num1, int num2)
{
 int i,small,max=0;
 if(num1<num2)
  small=num1;
 else
  small=num2;
 for(i=1;i<small;i++)
  {
   if(num1%i==0 && num2%i==0)
    max=i;
  }
 return max; 
}

int main()
{
 int num1,num2;
 printf("Enter the two numbers : ");
 scanf("%d %d",&num1,&num2);
 printf("%d",GCD(num1,num2));
 return 0;
} 
