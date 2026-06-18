//---------------------------------------Fenwick Tree------------------------------------//
struct FT{
private:
    vector<ll>fen;
    ll n;
public:
    FT(ll n){
        fen.resize(n);
        this->n=n;
    };
    void update(ll pos, ll dif){ // a[pos] += dif
        for(;pos<n;pos|=pos+1) fen[pos]+=dif;
    }
    ll query(ll pos){ // sum of values in [0, pos)
        ll res = 0;
        for(;pos>0;pos&=pos-1) res+=fen[pos-1];
        return res;
    }
    ll lower_bound(ll sum){// min pos st sum of [0, pos] >= sum
        if(sum<=0) return -1;
        ll pos=0;
        for(ll pw=1<<25;pw;pw>>=1){
            if(pos+pw<=n && fen[pos+pw-1]<sum) pos+=pw,sum-=fen[pos-1];
        }
        return pos;
    }
};
//---------------------------------------------------------------------------------------//
