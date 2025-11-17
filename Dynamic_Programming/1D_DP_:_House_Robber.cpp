class Solution {
  public:
    int solve(int N,vector<int>& dp,int K) {
        if(N==0) return 0;
        if(N==1) return K;
        if(dp[N] != -1) return dp[N];
        int steal = K + solve(N-2,dp,K);
        int skip = solve(N-1,dp,K);
        return dp[N] = max(steal,skip);
    }
    
    int maximizeMoney(int N, int K) {
        // code here
        vector<int>dp(N+1,-1);
        return solve(N,dp,K);
    }
};
