#include<stdio.h>
#include<stdlib.h>

int Isprime(int num)
{
 int flag=0,i;
 for(i=1;i<=num;i++)
 {
  if(num%i==0)
  {
   flag++;
  }
 }
  if(flag==2)
  {
   return 1;
  }
  else
  {
   return 0;
  }
}

void primefactors(int num)
{
 int i;
 if(num == '0' || num =='1')
  printf("\nThe number doesn't have prime factors");
 for(i=1;i<num;i++)
 {
  if(num%i==0 && Isprime(i))
   {
    printf(" %d, ",i);
    num=num/i;
   }
 }
}

int main()
{
 int a;
 printf("Enter the number : ");
 scanf("%d",&a);
 primefactors(a);
 return 0;
} 
