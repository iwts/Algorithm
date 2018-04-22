struct Matrix{
    int m[MAX][MAX];
}ans,res; // res存初始矩阵，ans存结果矩阵

int n; // 指n阶方阵

// a、b矩阵相乘
Matrix matr_mul(Matrix a,Matrix b){
    Matrix temp;
    memset(temp.m,0,sizeof(temp.m));
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            for(int k = 1;k <= n;k++){
                temp.m[i][j] += a.m[i][k] * b.m[k][j];
                // temp.m[i][j] %= MOD; 如果需要求模就加上这一句
            }
        }
    }
    return temp;
}

// 求res矩阵的N次幂
void matr_pow(int N){
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(i == j){
                ans.m[i][j] = 1;
            }else{
                ans.m[i][j] = 0;
            }
        }
    }
    while(N){
        if(N & 1 == 1) ans = matr_mul(ans,res);
        res = matr_mul(res,res);
        N >>= 1;
    }
}
