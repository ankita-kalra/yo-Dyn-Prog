/* Longest Palindromic Subsequence-  It is nothing but the longest common subsequence between the string and it's reverse
*  isn't it??? Just think once ! :)
*/

#include <iostream>
#include <climits>
#include <cmath>
#include <string>

using namespace std;

string rev(string s)
{
    string revr=s;
    for(int i=s.length()-1;i>=0;i--)
        revr[i]=s[s.length()-1-i];
    return revr;
}
int lps(string s)
{
   string r=rev(s);
   int n=s.length();
   int t[n+1][n+1];
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<n;j++)
       {
           if(i==0 ||j==0)
             t[i][j]=0;
           else if(s[i]==r[j])
             t[i][j]=max(max(t[i-1][j-1],t[i-1][j]),t[i][j-1])+1;
           else
             t[i][j]=max(max(t[i-1][j-1],t[i-1][j]),t[i][j-1]);
             cout << t[i][j] << " " ;
       }
       cout << endl;
   }

    return t[n-1][n-1];
}
int main()
{
    string s;
    cin >> s;
    cout << lps(s) << endl;
}
