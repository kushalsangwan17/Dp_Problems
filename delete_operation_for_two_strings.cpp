#include<bits/stdc++.h>
using namespace std;
const int MOD=1000000007;
const int NUM=100000;
#define ll long long

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length(),m=s2.length();
    vector<vector<int>> dp(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int t1=(i==0 or j==0)?0:dp[i-1][j-1];
            int t2=(i==0)?0:dp[i-1][j];
            int t3=(j==0)?0:dp[i][j-1];
            if(s1[i]==s2[j])
                dp[i][j]=1+t1;

            else
                dp[i][j]=max(t2,t3);
        }

    cout<<(n+m)-2*(dp[n-1][m-1]);
}