ll dp[20][2][2];
vll digits;
// think of prev,prev2,sum mod,non-zero count,position parity,direction
ll cnt(ll pos, ll tight, ll lead){
    ll len=digits.size();
    if(pos==len) return 1;
    if(dp[pos][tight][lead]!=-1) return dp[pos][tight][lead];
    ll ans=0;
    ll mx=tight?digits[pos]:9;
    for(int i=0;i<=mx;i++){
        ll ntight=(tight && i==mx);
        ll nlead=(lead && i==0);
        ans+=cnt(pos+1,ntight,nlead);
    }
    return dp[pos][tight][lead]=ans;
}
ll small(ll n){
    if(n<0) return 0;
    if(n==0) return 1;
    digits.clear();
    while(n>0){
        ll rem=n%10;
        digits.pb(rem);
        n/=10;
    }
    rev(digits);
    memset(dp,-1,sizeof(dp));
    return cnt(0,1,1);
}