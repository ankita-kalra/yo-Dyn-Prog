/*Matrix Multiplication Problem-
* We are doing matrix multiplication now suppose we have to multiply 4 matrices
* such as A.B.C.D=A.(B.C).D Now we have to parenthesize such as the cost of multiplication is min.
* Multiplying Amxn X Bnxo we have Cmxo . For this we need m.n.o multiplications...
* So we make a table such that multiplication is min.
* Let's see how?
*/


#include <iostream>
#include <climits>

using namespace std;

int matMul(int p[],int n)
{
 int cost[n][n];

 int j,c;

 /* one matrices...that is ixk and kXj...so if i == j then multiplying matrix by itself is not needed.
 *  if two other arrays match then no need to multiply them with cost[i][j] to save space complexity.
 */
for (int i=0;i<n;i++)
    cost[i][i]=0;
/* 1.considering optimal substructures of different lengths /
*  which 'll ultimately result in the product of two bigger matrices.
   2.now this product to be nin we consider different values of k.
*/
for(int l=2;l<n;l++)
{
  for(int i=1;i<=n-l+1;i++)
   {
     j=i+l-1;
     cost[i][j]=INT_MAX;
     for(int k=i;k<=j-1;k++)
     {
         c=cost[i][k]+cost[k+1][j]+p[i-1]*p[k]*p[j];
         if(c<cost[i][j])
            cost[i][j]=c;
     }
   }
}
       return cost[1][n-1];
}
int main()
{
    int n;
    cin >> n;
    int d=n;
    int arr[n];
    int i=0;
    while(d--)
    {   cin >> arr[i];
        i++;
    }
    cout << matMul(arr,n) << endl;
}


