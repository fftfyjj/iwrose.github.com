#include <stdio.h>

void main()
{
  int A[]={292,12, 3, 31,92,29,192,93,84,983,88};
  int p= 0;
  int q= 10;
  mergeSort(A, p, q);
 
}
void mergeSort(int *A[], int p, int r)
{
  int q = (p+r)/2;
  mergeSort(A[], p, q);
  mergeSort(A[], q+1, r]);
  merge(A[], p, q, r);
}

void merge(int *A[], int p, int q,int r)
{
  int n1= q-p+1;
  int n2= r-q;
  //divide A into 2 arrays
  int L[100];
  int R[100];
  for(int i=0; i<n1; i++)
    {
      L[i]=A[p+i];
    }
  for(int i=0; i<n2; i++)
    {
      R[i]=A[q+i];
    }
  L(n1)=9999;
  R(n2)=9999;
  //merge the 2 array
  int m=0;
  int n=0;
  for(j=0; j< (r-p+1); j++)
    {
      if(L[m]<R[n])
	{
	  A[p+j]=L[m];
	  m++;
	}else
	{
	  A[p+j]=L[n];
	  n++;
	}
    }
}
