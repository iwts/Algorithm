/*
5*5的地图来测试，但是代码有一个问题，如果在point中重载符号<的判定
条件是a.value > b.value，即权值越大优先级越高，那么在例子中返回的
值是20，而最长的路径是21。原因就是有9的那个转折点，因为9比1大，左
移往9转了，但是实际上，往1方向转，总数能达到21。个人认为是图例不好，
如果从点(0,2)开始向下走，这样不重复绕一圈能达到32。
优先队列使用了STL。
*/

#include<iostream>
#include<string>
#include<queue>
#define MAX 5

using namespace std;

/*
点数据的结构体，xy表示位置，value表示目前的权值，
flag表示已经被走过。
*/
struct point {
	int x, y;
	int value;
	bool flag = false;
	friend bool operator<(point a, point b) {
		return a.value < b.value;
	}
};

priority_queue<point> que;
point nowState; // 当前点
point endState; // 终止点
point nextState; // 下一步要走的点
int way[MAX][MAX]; // 地图，值表示权值，0表示不通

// 初始化
void init() {
	nowState.x = 0;
	nowState.y = 0;
	nowState.value = 1;
	endState.x = 4;
	endState.y = 4;
	endState.value = 1;

	memset(way, 1, sizeof(way));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> way[i][j];
		}
	}
}
/*
初始化测试数据：
1 1 9 2 3
0 1 1 0 1
0 1 3 0 1
0 1 2 0 1
0 1 2 1 1
*/

// 选择下一个点的函数
void nextend(point nowState) {
	point next;
	int move[4][2] = { { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } }; // 4种行动模式
	for (int i = 0; i < 4; i++) {
		int fx = nowState.x + move[i][0];
		int fy = nowState.y + move[i][1];
		if (fx >= 0 && fx < MAX && fy >= 0 && fy < MAX) {
			if (way[fx][fy]) {
				next.x = fx;
				next.y = fy;
				next.flag = true;
				next.value = nowState.value + way[fx][fy];
				way[fx][fy] = 0;
				que.push(next);
			}
		}
	}
}

// 跟BFS类似，判断出结果的条件不同
int priority_bfs() {
	while (!que.empty()) {
		nowState = que.top();
		que.pop();
		while (nowState.flag && !que.empty()) {
			nowState = que.top();
			que.pop();
		}
		if (nowState.x == endState.x && nowState.y == endState.y) {
			return nowState.value;
		}
		nowState.flag = true;
		nextend(nowState);
	}
	return -1;
}

int main() {
	init();
	que.push(nowState);
	int ans = priority_bfs();
	if (ans == -1) {
		cout << "no ans" << endl;
	}else {
		cout << "ans is " << ans << endl;
	}

	system("pause");
	return 0;
}
