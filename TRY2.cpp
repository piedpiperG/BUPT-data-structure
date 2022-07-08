#include<bits/stdc++.h>
using namespace std;

int *SortArry(int *StrA,int lenA, int *StrB, int lenB)
{
 if (StrA == NULL || StrB == NULL)
  return NULL;

 int *StrC = new int[lenA + lenB+1];
 int i, j, k; i = j = k = 0;
 while (i < lenA && j < lenB)
 {
  if (StrA[i] < StrB[j])
   StrC[k++] = StrA[i++];
  else
  {
   StrC[k++] = StrB[j++];
  }
 }

 while (i<lenA)
 {
  StrC[k++] = StrA[i++];
 }

 while (j<lenB)
 {
  StrC[k++] = StrB[j++];
 }

 return StrC;
}
int main()
{
 int array1[] = { 1, 4, 6, 7, 9, 12 };
 int array2[] = { 2, 3, 4, 5, 6, 7, 8, 10 };
 int lenA = sizeof(array1) / sizeof(int);
 int lenB = sizeof(array2) / sizeof(int);
 int *ret = SortArry(array1, lenA, array2, lenB);
 for (int i = 0; i < (lenA + lenB); i++)
  cout << ret[i] <<endl;
 delete[] ret; //Çå¿Õ¶ÑÄÚ´æ
 return 0;
}
