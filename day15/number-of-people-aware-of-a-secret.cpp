class Solution {
public:
    long dp[1001];
    long m=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp,-1,sizeof(dp));
        return helper(1,n,delay,forget);
    }
    long helper(int day,int &n,int &delay,int &forget){
        // some people know the secret on this day
        if(dp[day]!=-1)
            return dp[day];
        long ans=0;
        // he is the one who knows the secret so do ans++
        ans++;
        // but if till the end of nth day he forgets the secret then do we have to add this to answer?  No
        if(day+forget<=n)
            ans--;
        // now on what days he can tell the secret?   that is from day+delay to min(day+forget,n+1)-1
        for(int start=day+delay;start<(min(day+forget,n+1));start++){
            ans+=helper(start,n,delay,forget);
            ans%=m;
        }
        // store it in dp
        dp[day]=ans;
        return ans;
        
    }
};
