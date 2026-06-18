// Mo's Queries
struct Query{
    ll l,r,idx;
};
 
struct Mo{
    ll n,q,block;
    vector<ll>a,ans;
    vector<Query>queries;
    unordered_map<ll,ll>freq;
    ll cnt=0;
 
    Mo(ll n,ll q,const vector<ll>&a):n(n),q(q),a(a){
        block=sqrt(n)+1;
        ans.resize(q);
    }
 
    void add_query(ll l, ll r, ll idx){
        queries.push_back({l,r,idx});
    }
 
    void add(ll pos){
        if(freq[a[pos]]==0) cnt++; 
        freq[a[pos]]++;
    }
 
    void remove(ll pos){
        if(freq[a[pos]]==1) cnt--;
        freq[a[pos]]--;
    }
 
    void process(){
        sort(queries.begin(),queries.end(),[&](const Query&A,const Query&B){
            ll blockA=A.l/block;
            ll blockB=B.l/block;
            if(blockA!=blockB) return blockA<blockB;
            return (blockA&1)?(A.r>B.r):(A.r<B.r);
        });
        ll currL=0,currR=-1;
        for(auto& q:queries){
            while(currL > q.l) add(--currL);
            while(currR < q.r) add(++currR);
            while(currL < q.l) remove(currL++);
            while(currR > q.r) remove(currR--);
            ans[q.idx]=cnt;
        }
    }
    void print(){for(auto &x:ans) cout<<x<<endl;}
};

