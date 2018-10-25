#include<iostream>
#define MAX 2333

using namespace std;

int n[MAX];
int dp[MAX];

int Max(int a,int b){
    return a > b ? b : a;
}

int kadane(){
    int ans = n[0];
    dp[0] = n[0];
    for(int i = 1;i < strlen(n);i++){
        dp[i] = Max(n[i],dp[i-1]+n[i]);
        ans = Max(dp[i],ans);
    }
}

int main(){
	// 自设例子

	system("pause");
	return 0;
}
