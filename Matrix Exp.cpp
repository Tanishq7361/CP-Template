//-------------------------------------Matrix Exponentiation----------------------------//

struct Matrix{
    ll a[2][2]={{0,0},{0,0}};
    Matrix operator*(const Matrix& other) const {
        Matrix product;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    product.a[i][j]+=a[i][k]*other.a[k][j];
                    product.a[i][j]%=MOD;
                }
            }
        }
        return product;
    }
    Matrix operator%(ll mod) const {
        Matrix res;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                res.a[i][j]=a[i][j]%mod;
            }
        }
        return res;
    }
};

Matrix matpow(Matrix Final, ll k){
    Matrix product;
    for(int i=0;i<2;i++){
        product.a[i][i]=1.0;
    }
    while(k>0){
        if(k&1){
            product=product*Final;
        }
        Final=Final*Final;
        k/=2;
    }
    return product;
};

//---------------------------------------------------------------------------------------//
