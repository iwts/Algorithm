#include<iostream>

using namespace std;

int Max(int a,int b){
	return a > b ? a : b;
}

void st(int n) {
    for(int i = 1;i <= n;i++){
        cin >> dp[i][0];
        // 节省时间，实际上初始化dp应该为：dp[i][0] = A[i];
    }
    for(int j = 1;(1 << j) <= n;j++){
        for(int i = 1;i + (1 << j) - 1 <= n; i++){
            dp[i][j] = Max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int rmq(int l,int r) {
    int k = 0;
    while((1 << (k + 1)) <= r - l + 1) k++;
    return Max(dp[l][k], dp[r - (1 << k) + 1][k]);
    // 具体找最大值还是最小值，只用更改Max还Min就可以了，注意 st 函数里也要修改
}

int main(){
	
	system("pause");
	return 0;
}
