#include<stdio.h>
#include<math.h>

#define SIZE 50

int strlen(char *string)
{
 int count=0;
 while(string[count]!='\0')
  count++;
 return count;
}  

int strcmp(char *string1, char *string2)
{
 int i = 0, j = 0, flag = 0;
 if(strlen(string1)!=strlen(string2) )
 {
  return 1;
 }
 while(string1[i]!='\0' )
 {
  if(string1[i] == string2[j] )
	{
	 flag=1;
	}
  else
    {
     flag=0;
	}
  i++;
  j++;
 }
 if(flag == 1)
 {
  return 0;
 }
 else
 {
  return 1;
 }
}

int main()
{
 char *string1[SIZE],*string2[SIZE];
 int i=0;
 printf("Enter the 1st string : ");
 gets(string1);
 printf("\nEnter the 2nd string : ");
 gets(string2);
 printf("\n%d",strcmp(&string1,&string2));
 return 0;
}
 
