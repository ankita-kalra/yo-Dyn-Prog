/* Minimum Cost Path Problem
*  Basically a double dimensional cost matrix of order mxn will be given to us...
*  now we have to find the min. cost path between (0,0) and (m,n)
*/

/*Optimal Substructure- In the submatrix the path from (0,0) to (i,j) should be minimum
* Overlapping Sum- C[i][j]=cost till (i-1,j-1) plus the cost from (i-1,j-1) to (i,j)
*/
#include <iostream>
#include <cmath>

using namespace std;

int minCost(int cost[][3],int m,int n)
{
    int C[m][n];
    cout << "inside minCost" << endl;

    //initialing first rows and columns
    for(int i=1;i<m;i++)
      C[0][i]=C[0][i-1]+cost[0][i];
    for(int j=1;j<n;j++)
      C[j][0]=C[j-1][0]+cost[j][0];

    cout  << "initialization done" << endl;
    for(int i=1;i<m;i++)
       for(int j=1;j<n;j++)
       {
        C[i][j]=min(min(C[i-1][j-1],C[i-1][j]),C[i][j-1])+cost[i][j];
       }
    cout << "cost found out" << endl;
    return C[m-1][n-1];
}

 int main()
 {
     int m=3,n=3;
     int d=m,e=n,i=0,j=0;
     int cost[3][3];
     for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
          cin >> cost[i][j];
     cout << minCost(cost,m,n) << endl;
 }
