// todo：看起来好像有问题

// #include<iostream>
// #include<string>
// #define MAX 110

// using namespace std;

// int Next[MAX];
// int extend[MAX];

// void get_next(string s) {
// 	memset(Next,0,sizeof(Next));
// 	int len = s.size();
// 	Next[0] = len;
// 	for(int i = 0;i < len-1 && s[i] == s[i+1];i++);
// 	Next[1] = i;
// 	int a = 1;
// 	for(int k = 2;k < len;k++){
// 		int p = a + Next[a] - 1;
// 		int l = Next[k-a];
// 		if((k-1) + l >= p){
// 			int j = (p-k+1) > 0 ? (p-k+1) : 0;
// 			while(k+j < len && s[k+j] == s[j]){
// 				j++;
// 			}
// 			Next[k] = j;
// 			a = k;
// 		}else{
// 			Next[k] = l;
// 		}
// 	}
// }

// void get_extend(string s, string t) {
// 	memset(Next,0,sizeof(Next)); 
// 	getnext(t); 
// 	int sl = s.size();
// 	int tl = t.size();
// 	int a = 0;
// 	int minl = sl > tl ? tl : sl;
// 	while(a < minl && s[a] == t[a]){
// 		a++;
// 	}
// 	extand[0] = a;
// 	a = 0;
// 	for(int k = 1;k < sl;k++){
// 		int p = a+extand[a]-1;
// 		int l = Next[k-a];
// 		if((k-1)+l >= p){
// 			int j = (p-k+1) > 0 ? (p-k+1) : 0; 
// 			while(k+j < sl && j < tl && s[k+j] == t[j] ){
// 				j++;
// 			} 
// 			extand[k] = j;
// 			a = k;
// 		}else{
// 			extand[k] = l;
// 		}
// 	}
// }
