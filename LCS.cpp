
#include<iostream>
#include<string>
#define MAX 233

using namespace std;

char s1[MAX];
char s2[MAX];
int max_len[MAX][MAX];

int Max(int a,int b){
	return a > b ? a : b;
}

int main(){
	while(cin >> s1 >> s2){
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		for(int i = 0;i <= len1;i++){
			max_len[i][0] = 0;
		}
		for(int i = 0;i <= len2;i++){
			max_len[0][i] = 0;
		}
		for(int i = 1;i <= len1;i++){
			for(int j = 1;j <= len2;j++){
				if(s1[i-1] == s2[j-1]){
					max_len[i][j] = max_len[i-1][j-1] + 1;
				}else{
					max_len[i][j] = Max(max_len[i-1][j],max_len[i][j-1]);
				}
			}
		}
		cout << max_len[len1][len2] << endl;
	}

	system("pause");
	return 0;
}
