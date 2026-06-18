//------------------------------Computing------------------------------//

ll modc;
vector<ll>pfact,invpfact,der;

void precompute(ll n, ll modc){
    pfact.resize(n+1,1),invpfact.resize(n+1,1),der.resize(n+1);
    for(int i=1;i<=n;i++){pfact[i]=(pfact[i-1]*i)%modc;}
    invpfact[n]=modinv(pfact[n],modc);
    for(int i=n-1;i>=1;i--){invpfact[i]=(invpfact[i+1]*(i+1))%modc;}
    if(n>=2) der[2]=1;
    for(int i=3;i<=n;i++){der[i]=((i-1)*(der[i-1]+der[i-2])%modc)%modc;}
}
ll ncr_mod(ll n, ll r){
    if(r>n || r<0) return 0;
    return (((pfact[n]*invpfact[r])%modc)*invpfact[n-r])%modc;
}
ll npr(ll n, ll r){
    if(r>n || r<0) return 0;
    return (pfact[n]*invpfact[n-r])%modc;
}
ll getpfact(ll n){return pfact[n];}
ll getinvpfact(ll n){return invpfact[n];}
ll getder(ll n){return der[n];}
ll rust(ll n, ll r){
    if(r<0 || r>n) return 0;
    if(n==0 || r==0) return 1;
    return ncr_mod(n%modc,r%modc)*rust(n/modc,r/modc)%modc;
}

//-------------------------------------------------------------------------//