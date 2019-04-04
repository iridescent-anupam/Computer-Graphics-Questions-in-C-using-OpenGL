#include<stdio.h>
#include<stdlib.h>

int main()
{
 int *void_ptr;
 int *int_ptr;
 int *char_ptr;
 int *float_ptr;
 printf("Size of Void Pointer : %ld\n",sizeof(void_ptr));
 printf("Size of Integer Pointer : %ld\n",sizeof(int_ptr));
 printf("Size of Character Pointer : %ld\n",sizeof(char_ptr));
 printf("Size of Flaot Pointer : %ld\n",sizeof(float_ptr));
 return 0;
} 
