//-------------------------------sieve-------------------------//
vector<ll>prime;
vector<bool>nPrim;
vector<vector<ll>>divisor;
vector<ll>spf;
vector<ll>phi;
void opt_sieve(ll n){
    divisor.resize(n+1,{1});
    nPrim.resize(n+1);
    spf.resize(n+1);
    iota(all(spf),0);
    nPrim[1]=true;
    for(ll i=4;i<=n;i+=2) nPrim[i]=true,spf[i]=2;
    for(ll i=9;i<=n;i+=6) nPrim[i]=true,spf[i]=3;
    for(ll i=5;i*i<=n;i+=6){
        ll k=(i+2);
        if(nPrim[i]==0){
            for(ll j=i*i;j<=n;j+=i<<1){
                nPrim[j]=true;
                if(spf[j]==j) spf[j]=i;
            }
        }
        if(k<=n && nPrim[k]==0){
            for(ll j=k*k;j<=n;j+=k<<1){
                nPrim[j]=true;
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    // //-----------------divisors-------------------------//
    // for(ll i=2;i<=n;i++){
    // // if(nPrim[i]==0) prime.pb(i);
    //     for(ll j=i;j<=n;j+=i){
    //         divisor[j].pb(i);
    //     }
    // }
    // //-----------------phi with prime-------------------//
    // // phi[a*b]=phi[a]*phi[b]; IMP!!
    // // phi.resize(n+1,1);
    // // phi[1]=1;
    // for(ll i=2;i<=n;i++){
    //     if(nPrim[i]==0){
    //         prime.pb(i);
    //         // phi[i]=i-1;
    //     }
    //     // for(ll &p:prime){
    //     //     if(i*p >n) break;
    //     //     if(i%p==0){
    //     //         phi[i*p]=phi[i]*p;
    //     //         break;
    //     //     }
    //     //     else{
    //     //         phi[i*p]=phi[i]*(p - 1);
    //     //     }
    //     // }
    // }
}
//-----------------------------------------------------------------//