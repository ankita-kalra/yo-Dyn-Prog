/* Longest Common Subsequence
*  Find longest common subsequence between two arrays
*  Say For Eg:- a1={2,4,8,6,1,3,6}  and a2={2,8,6,3,6}
*  Then longest common subsequence is {2,8,6,3,6} , so function will return it's length.
*/
#include <iostream>
#include <new>
#include <cmath>

using namespace std;

int longCommnSeq(int a[],int b[],int m,int n)
{
    int l[m+1][n+1];

    for(int i=0;i<=m;i++)
      for(int j=0;j<=n;j++)
      { //initialization
        if(i==0||j==0)
            l[i][j]=0;
        else if(a[i-1]==b[j-1])
            l[i][j]=max(max(l[i-1][j-1],l[i-1][j]),l[i][j-1])+1; //calculation
        else
            l[i][j]=max(max(l[i-1][j-1],l[i-1][j]),l[i][j-1]);  //calculation
      }
    return l[m][n];
}

int main()
{
   int m,n;
   cin >> m >> n;
   int *a=new(nothrow)int[m];
   int *b=new(nothrow)int[n];
   int d=m,e=n;
   int i=0,j=0;
   while(d--)
   {
       cin >> a[i];
       i++;
   }
   while(e--)
   {
       cin >> b[j];
       j++;
   }
   cout << longCommnSeq(a,b,m,n) << endl;
   delete []a;
   delete []b;
   return 0;
}

