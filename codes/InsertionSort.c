#include <stdio.h>

void main()
{
  int A[10]={4,3,2,1,5,1320,213,93,12393,1020};
  int j;
  int key;
  int i;
  for(j=1; j<10; j++)
   {
     key=A[j];
    //Insert key to sorted sequence
     i=j-1;
     while((i>-1)&&(key<A[i]))
     {
       A[i+1]=A[i];
       i--;
     }
     A[i+1]=key;
   }
  for(j=0;j<10;j++)
  {
    printf("%d,",A[j]);
  }
}
