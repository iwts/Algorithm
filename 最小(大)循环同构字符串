#include<string>

using namespace std;

int MinimumRepresentation(string s)  {  
    int i = 0;
    int j = 1;
    int k = 0;
    int len = s.size();
    int t;
    while(i < len && j < len && k < len){  
        t = s[(i+k) >= len ? i+k-len : i+k] - s[(j+k) >= len ? j+k-len : j+k];  
        if(!t){
            k++;
        }else{
            if(t > 0) { // 求最大修改此处为小于号即可
                i = i+k+1;  
            }else{
                j = j+k+1;  
            }
            if(i == j){
                ++j;
            }
            k = 0;  
        }
    }
    return (i < j ? i : j);
}
