/* Longest Bitonic Subsequence- Subsequence which is first increasing and then decreasing
*  How to find?
* Optimal Substructure- Increasing till a[i] and Decreasing after a[i]
* Example- Input a[] = {1, 11, 2, 10, 4, 5, 2, 1};
* Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)
*/


#include <iostream>

using namespace std;

int lbs(int a[],int n)
{
    int lis[n];
    //initialization of lis
    for(int i=0;i<n;i++)
        lis[i]=1;
    //filling lis lengths
    for(int i=1;i<n;i++)
     for(int j=0;j<i;j++)
       if(a[i]>a[j] && lis[i]<lis[j]+1)
         lis[i]=lis[j]+1;
    //initialization of lds
    int lds[n];
    for(int i=0;i<n;i++)
        lds[i]=1;
   //filling lds lengths
    for(int i=n-2;i>=0;i--)
        for(int j=n-1;j>i;j--)
         if(a[i]>a[j] && lds[i] < lds[j]+1)
           lds[i]=lds[j]+1;
   //finding max bitonic sequence
    int m=lis[0]+lds[0]-1;
    for(int i=1;i<n;i++)
      if(lis[i]+lds[i]-1>m)
        m=lis[i] + lds[i] -1;

      return m;
}
int main()
{
    int n;
    cin >> n;
    int d=n;
    int a[n],i=0;
    while(d--)
    {
     cin >> a[i];
     i++;
    }
    cout << lbs(a,n) << endl;
}
