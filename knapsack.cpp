/* Knap Snack Problem- There is a knapsack of capacity W and the items which can be kept in it
*  are of weights 3 ton, 4 ton and 5 tons with values $5 , $7 and $8 respectively. Find out the
*  combination of weights to be kept in knapsack so that their their overall value is the largest.
*/

#include <iostream>
#include <climits>

using namespace std;

int knapsack(int W,int wt[],int val[],int n)
  {
      int i,w;
      int K[n+1][W+1];

      for(int i=0;i<=n;i++)
      {
       for(int j=0;j<=W;j++)
        { //initialization to build up other columns
         if(i==0 || j==0)
          K[i][j]=0;
         else if(wt[i-1]<=(j))
          K[i][j]=max(val[i-1]+K[i][j-wt[i-1]],K[i-1][j]);
         else
          K[i][j]=K[i-1][j];
          cout << K[i][j] << " ";
        }
        cout << endl;
      }
      return K[n][W];

  }

  int main()
  {
      int n,W;
      cin >> n >> W ;
      int d=n;
      int i=0;
      int wt[n],val[n];
      while(d--)
      {
          cin >> wt[i] >> val[i] ;
          i++;
      }
      cout << knapsack(W,wt,val,n) << endl;
  }
