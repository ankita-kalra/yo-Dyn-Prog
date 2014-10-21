/* Edit List Problem ... How many interchanges are required to make PARK to SPAKE...
* the type of interchanges which can be done are:- i)substitution ii)deletion and iii)addition...
like min. no of interchanges to change PARK to SPAKE or vice versa is 3...
*/

/*Subproblem is the min no. interchnanges required to change one substring to another...
*/
/*This program takes input list of integers...you can very well take ascii value of characters and
 *run this program...
*/

#include <iostream>
#include <cmath>

using namespace std;

int editList(int a[],int b[],int m,int n)
{
    int l[m+1][n+1];

    for(int i=0;i<=m;i++)
      {
       for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
             l[i][j]=i+j;
            else if(a[i-1]==b[j-1])
             l[i][j]=min(min(l[i][j-1],l[i-1][j]),l[i-1][j-1]);
            else
             l[i][j]=min(min(l[i][j-1],l[i-1][j]),l[i-1][j-1])+1;
        }

      }
      return l[m][n];
}

int main()
{
    int m,n;
    cin >> m >> n;
    int d=m,e=n;
    d=m,e=n;
    int i=0,j=0;
    int a[m],b[n];
    while(d--)
    {
        cin >> a[i] ;
        i++;
    }
    while(e--)
    {
        cin >> b[j];
        j++;
    }
    cout << editList(a,b,m,n) << endl;
}
