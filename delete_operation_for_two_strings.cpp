class Solution {
public:
    int minDistance(string word1, string word2) {
    if(word1.length()==0 or word2.length()==0)
        return word1.length()+word2.length();
    
    string s1,s2;
    s1=word1;s2=word2;
    int n=s1.length(),m=s2.length();
    vector<vector<int>> dp(n,vector<int>(m,0)); // dp[i][j] denotes LCS of s1[0..i] and  s2[0...j]
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int t1=(i==0 or j==0)?0:dp[i-1][j-1];
            int t2=(i==0)?0:dp[i-1][j];
            int t3=(j==0)?0:dp[i][j-1];
            if(s1[i]==s2[j])
                dp[i][j]=1+t1; // in case of match of last characters in the sequences find lcs in s1[0....i-1] and s2[0....j-1] and add 1 to it;
                    
            else
                dp[i][j]=max(t2,t3); // else reject either of the last letters and find lcs
        }

    return n+m-2*dp[n-1][m-1]; // deleted elements will be total minus the ones to be kept
    }   
};
