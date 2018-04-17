// 只给出2个函数，形参列表有注释


// 快速幂
int Pow(int a,int b){ // 即a的b次幂
	int ans = 1;
	int base = a;
	while(b){
		if(b & 1) ans *= base;
		base *= base;
		b >>= 1;
	}
	return ans;
}

// 快速幂取模
int pow_mod(int a,int b,int c){  // 即a的b次幂模c
	int ans = 1;
	int base = a%c;
	while(b){
		if(b & 1) ans = (ans*base)%c;
		base = (base*base)%c;
		b >>= 1;
	}
	return ans;
}

int main(){
    // empty
    
    system("pause");
    return 0;
}
