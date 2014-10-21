/* I have coins of Rs. 1,2 and 3 , now in how many possible ways can I give change??
* This is Coin Change Problem . Input Will be an array of coins,the sum required and
* output 'll be the no. of ways...*/

#include <iostream>

using namespace std;

int change(int coins[],int m,int sum)
   {
       int ways[sum+1][m];
       int x=0,y=0;
       //initializing row 0 and col 0
       for(int i=0;i<m;i++)
         { ways[0][i]=1;
           ways[1][i]=1;
           cout << ways[0][i] << " " << ways[1][i] << endl;
         }
       for(int i=1;i<=sum;i++)
         ways[i][0]=1;
       for(int i=1;i<=sum;i++)
        {
         for(int j=0;j<m;j++)
         {
           //No. of ways with j-1 coins
           x=((j>=1)?ways[i][j-1]:0);

           //Extra No. of ways possible including the coin it is basically the no. of ways of getting sum-denomination of this coin
           y=(i-coins[j]>=0)?ways[i-coins[j]][j]:0;
            cout << x << ":" << y << endl;
           //there sum
           ways[i][j]=x+y;
           cout << x+y << endl;
         }
        }
         return ways[sum][m-1];

   }
int main()
{
    int num,sum;
    cin >> num >> sum;
    int a[num];
    int d=num;
    int i=0;
    while(d--)
    {
        cin >> a[i];
        i++;
    }
    cout << change(a,num,sum) << endl;
}
