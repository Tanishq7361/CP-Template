//--------------------------------Segment Tree-------------------------------//

class segtree{
private:
    struct Node{
        ll sum;
        ll lazyAdd;
        ll lazySet;
        Node(): sum(0),
                lazyAdd(0),
                lazySet(LLONG_MIN){}
    };
    vector<Node>seg;
    ll n;
public:
    segtree(ll n, vll &arr){
        this->n=n;
        seg.resize(4*n +5);
        build(0,0,n-1,arr);
    }

    Node merge(const Node &L, const Node &R){
        Node P;
        P.sum = L.sum + R.sum;
        return P;
    }

    void push(ll inx, ll low, ll high){
        Node &node = seg[inx];
        if(node.lazySet!=LLONG_MIN){
            node.sum=(high - low + 1)*node.lazySet;
            if(low!=high){
                seg[2*inx +1].lazySet=node.lazySet;
                seg[2*inx +1].lazyAdd=0;
                seg[2*inx +2].lazySet=node.lazySet;
                seg[2*inx +2].lazyAdd=0;
            }
            node.lazySet=LLONG_MIN;
        }
        if(node.lazyAdd!=0){ 
            node.sum+=(high - low + 1)*node.lazyAdd;
            if(low!=high){
                if(seg[2*inx +1].lazySet!=LLONG_MIN){seg[2*inx +1].lazySet += node.lazyAdd;}
                else{seg[2*inx +1].lazyAdd += node.lazyAdd;}
                if(seg[2*inx +2].lazySet!=LLONG_MIN){seg[2*inx +2].lazySet += node.lazyAdd;}
                else{seg[2*inx +2].lazyAdd += node.lazyAdd;}
            }
            node.lazyAdd=0;
        }
    }

    void updateAdd(ll inx, ll low, ll high, ll ql, ll qr, long long val){
        push(inx,low,high);
        if(qr<low || high<ql){return;}
        if(ql<=low && high<=qr){
            seg[inx].lazyAdd+=val;
            push(inx,low,high);
            return;
        }
        ll mid=(low+high)/2;
        updateAdd(2*inx +1,low,mid,ql,qr,val);
        updateAdd(2*inx +2,mid+1,high,ql,qr,val);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
    }

    void updateSet(ll inx, ll low, ll high, ll ql, ll qr, long long val){
        push(inx,low,high);
        if(qr<low || high<ql){return;}
        if(ql<=low && high<=qr){
            seg[inx].lazySet= val;
            seg[inx].lazyAdd = 0;
            push(inx,low,high);
            return;
        }
        ll mid=(low+high) / 2;
        updateSet(2*inx +1, low, mid, ql, qr, val);
        updateSet(2*inx +2, mid+1, high, ql, qr, val);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
    }

    Node querySum(ll inx, ll low, ll high, ll ql, ll qr){
        Node P;
        push(inx, low, high);
        if(qr<low || high<ql){return P;}
        if(ql<=low && high<=qr){return seg[inx];}
        ll mid=(low+high)/2;
        P=merge(querySum(2*inx +1, low, mid, ql, qr),querySum(2*inx +2, mid+1, high, ql, qr));
        return P;
    }

    void build(ll inx, ll low, ll high, vll&arr){
        if(low==high){
            seg[inx].sum=arr[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*inx +1,low,mid,arr);
        build(2*inx +2,mid+1,high,arr);
        seg[inx]=merge(seg[2*inx +1],seg[2*inx +2]);
    }
    void updateSetPoint(ll inx, ll val){ updateSet(0,0,n-1,inx,inx,val);}
    void updateSetRange(ll ql, ll qr, ll val){ updateSet(0,0,n-1,ql,qr,val);}
    void updateAddPoint(ll inx, ll val){ updateAdd(0,0,n-1,inx,inx,val);}
    void updateAddRange(ll ql, ll qr, ll val){ updateAdd(0,0,n-1,ql,qr,val);}

};
//---------------------------------------------------------------------------------------//
