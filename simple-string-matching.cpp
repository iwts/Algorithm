/*
    我们可以看出来，在function函数中，我们利用i枚举了子串的开始位置，开始位置一确定，那么终止位置也确定了，因
为子串的长度一定是n。所以第一层for循环逐一判断条件，i到m-n的时候就可以停止了，因为后面根本无法满足储存一个子串。
而第二个for循环就没有什么好说的了，逐一匹配。逐一为什么是i+j，因为第一层循环表示开始位置，第二层循环表示字符的
具体第几个字符，那么实际上在匹配字符串中必须要加上前面的i，才能到达具体的位置。此处自己理解。由此，可以算出算法
复杂度是O(n*m)。
*/

#include<iostream>
#include<string>
#define MAX 110

using namespace std;

void function(string s,string t){
	int n = s.size();
	int m = t.size();
	for(int i = 0;i <= m-n;i++){
		bool judge = true;
		for(int j = 0;j < n;j++){
			if(s[j] != t[i+j]){
				judge = false;
				break;
			}
		}
		if(judge){
			cout << i << endl;
		}
	}
}

int main() {
	// s表示模板字符串，t表示匹配字符串
	string s,t;
	cin >> s >> t;
	function(s,t);
	
	system("pause");
	return 0;
}
