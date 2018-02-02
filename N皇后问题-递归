/*
N皇后问题，就是在N*N棋盘中能以如何的顺序摆放N个皇后能让所有的皇后不互相吃。
输出部分是这样：每一行代表一种摆放可能，一行N个数字，表示1-N行皇后摆放的列
的号码。
主要利用的就是递归，从第1行开始枚举第一行摆放位置，然后递归到下一行，每次枚
举列的位置的时候就是跟上N-i行比较，看是否跟之前的皇后重叠。
*/


#include<iostream>
#define N 8

using namespace std;

int queen[N];

void Queen(int k){
	if(k == N){
		for(int i = 0;i < N;i++){
			cout << queen[i] + 1 << " ";
		}
		cout << endl;
		return ;
	}
	for(int i = 0;i < N;i++){
		int j = 0;
		for(;j < k;j++){
			if(queen[j] == i || abs(queen[j] - i) == abs(k - j)){
				break;
			}
		}
		if(j == k){
			queen[k] = i;
			Queen(k+1);
		}
	}
}

int main() {
	Queen(0);

	system("pause");
	return 0;
}
