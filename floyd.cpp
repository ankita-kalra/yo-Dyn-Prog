/* Floyd Warshall Algo- All Pairs Shortest Path Problem
*  Finding shortest distance between all vertices in an
*  edge weighted directed graph.
*/

#include <iostream>
#include <climits>

#define INF 9999999

using namespace std;

void floyd(int g[4][4],int d[4][4])
{
    for(int i=0;i<4;i++)
       for(int j=0;j<4;j++)
          d[i][j]=g[i][j];

    for(int k=0;k<4;k++)
      for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
         {
           if(d[i][k]+d[k][j]<d[i][j])
                d[i][j]=d[i][k]+d[k][j];
         }
}

int main()
{
  int a[4][4]={ {0,5,  INF, 10},{INF, 0,   3, INF},{INF, INF, 0,   1},{INF, INF, INF, 0}};
  int d[4][4];
  floyd(a,d);
  for(int i=0;i<4;i++)
 {
   for(int j=0;j<4;j++)
     {
      if(d[i][j]!=INF)
      cout << d[i][j] << " ";
      else
      cout << "INF" << " ";
      }
    cout << endl;
}
}
