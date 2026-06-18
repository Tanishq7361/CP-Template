//------------------------------DSU------------------------------//

vector<ll>par,sze,edge,val;
ll component;
void dsuready(ll n){
    par.resize(n+1); sze.resize(n+1,1);
    edge.resize(n+1); val.resize(n+1);
    iota(par.begin(),par.end(),0ll);
    component=n;
}

ll find(ll x){
    if(x!=par[x]){
        ll p=par[x];
        par[x]=find(par[x]);
        val[x]^=val[p];
    }
    return par[x];
}

bool unite(ll x, ll y){
    ll prevx=x,prevy=y;
    x=par[x]; y=par[y];
    if(x==y) {edge[x]++; return false;}
    if(sze[x]<sze[y]) {swap(x,y); swap(prevx,prevy);}
    par[y]=x; sze[x]+=sze[y];
    val[y]=val[prevx]^val[prevy];//^edge-weight
    edge[x]+=edge[y]+1;
    component--;
    return true;
}

ll getsz(ll x) { return sze[find(x)];}
ll edgecnt(ll x) { return edge[find(x)];}

//-------------------------------------------------------------------------//