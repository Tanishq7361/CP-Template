//-------------------------------String Hashing---------------------------------//

struct Hashing{
    string s; int n;
    ll p1=331,m1=999999937;
    ll p2=379,m2=1e9 + 87;
    vll p_pow1,p_pow2,h1,h2,inv_pow1,inv_pow2;
    Hashing(const string& str) : s(str){
        n=s.length(); p_pow1.resize(n); p_pow2.resize(n);
        h1.resize(n+1);
        h2.resize(n+1);
        inv_pow1.resize(n);
        inv_pow2.resize(n);
        p_pow1[0]=1; p_pow2[0]=1; inv_pow1[0]=1; inv_pow2[0]=1;
        ll inv_p1=modinv(p1,m1); ll inv_p2=modinv(p2,m2);
        for(int i=1;i<n;i++){
            p_pow1[i]=(p_pow1[i-1]*p1) % m1; p_pow2[i]=(p_pow2[i-1]*p2)%m2;
            inv_pow1[i]=(inv_pow1[i-1]*inv_p1) % m1; inv_pow2[i]=(inv_pow2[i-1]*inv_p2)%m2;
        }
        for(int i=0;i<n;i++){
            h1[i+1]=(h1[i]+(s[i] - 'a' +1)*p_pow1[i])%m1;
            h2[i+1]=(h2[i]+(s[i] - 'a' +1)*p_pow2[i])%m2;
        }
    }
    pll get_hash(int l,int r){
        ll res1=(h1[r+1]-h1[l]+m1)%m1; ll res2=(h2[r+1]-h2[l]+m2)%m2;
        res1=(res1*inv_pow1[l])%m1; res2=(res2*inv_pow2[l])%m2;
        return make_pair(res1,res2);
    }
};
    // set hash ((a+k)^h +(b+k)^h + (c+k)^h )%m 
    // k is large upto 10^9 and  60<h<small

//----------------------------------------------------------------------------------//