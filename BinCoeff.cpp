/* Binary Coefficient Problem-
*  C(n,k)=C(n-1,k-1)+C(n-1,k) */
#include <iostream>
#include <climits>

using namespace std;

int binCoeff(int n,int k)
{
    int coeff[k+1][n+1];

    for(int i=0;i<=k;i++)
    {
     for(int j=0;j<=n;j++)
     {
         if(i==0)
          coeff[i][j]=1;
         else if(j==0)
          coeff[i][j]=0;
         else if(i==j)
          coeff[i][j]=1;
         else if(i<j)
          coeff[i][j]=coeff[i-1][j-1]+coeff[i][j-1];
         else if(i>j)
          coeff[i][j]=0;
         else
           coeff[i][j]=-1;
         cout << coeff[i][j] << " " ;
     }
         cout << endl;
    }
    return coeff[k][n];
}

int main()
{
    int n,k;
    cin >> n >> k;
    cout << binCoeff(n,k) << endl;
}
