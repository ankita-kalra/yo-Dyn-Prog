/* Longest Increasing Subsequence */
/* Say for Eg- {1,6,2,0,7,9,14,3} */
/* Longest Increasing Subsequence is 1,2,7,9,14 and function 'll return 5 */

#include <iostream>
#include <cstdlib>
#include <new>
using namespace std;

int longIncSeq(int arr[],int n)
{
    int *l,m=1;
    l=(int *)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
       {
        l[i]=1;
        cout << l[i] << " ";
       }
    cout << endl;
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
          if((arr[i]>arr[j]) && (l[i]<l[j]+1))
              l[i]+=1;

    for(int i=0;i<n;i++)
     {  cout << l[i] << " ";
        if(m<l[i])
         m=l[i];
     }
     cout << endl;

    free(l);

    return m;
}

int main()
{
    int n,d;
    cin >> n;
    d=n;
    int *test,i=0;
    test = new(nothrow)int[n];
    while(d--)
    {
    cin >> test[i];
    i++;
    }
    cout << longIncSeq(test,n) << endl;
    delete [] test;
    return 0;
}

