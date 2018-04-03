/*
建立在hdoj-2222题的基础上的，该题属于AC自动机的模板题
*/

#include<iostream>
#include<string>
#include<queue>
#define MAX_Tot 500005

using namespace std;

struct Aho {
    struct state {
        int next[26];
        int ff, cnt;
    }AC[MAX_Tot];

    int size;
    queue<int> que;

    void init() {
        for (int i = 0; i < MAX_Tot; i++) {
            memset(AC[i].next, 0, sizeof(AC[i].next));
            AC[i].ff = 0;
            AC[i].cnt = 0;
        }
        size = 1;
    }
    void insert(string s) {
        int n = s.size();
        int now = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (!AC[now].next[c - 'a']) {
                AC[now].next[c - 'a'] = size++;
            }
            now = AC[now].next[c - 'a'];
        }
        AC[now].cnt++;
    }
    void build() {
        AC[0].ff = -1;
        que.push(0);
        while (que.size()) {
            int u = que.front();
            que.pop();
            for (int i = 0; i < 26; i++) {
                if (AC[u].next[i]) {
                    if (!u) {
                        AC[AC[u].next[i]].ff = 0;
                    }else {
                        int v = AC[u].ff;
                        while (v != -1) {
                            if (AC[v].next[i]) {
                                AC[AC[u].next[i]].ff = AC[v].next[i];
                                break;
                            }
                            v = AC[v].ff;
                        }
                        if (v == -1) {
                            AC[AC[u].next[i]].ff = 0;
                        }
                    }
                    que.push(AC[u].next[i]);
                }
            }
        }
    }
    int Get(int u) {
        int res = 0;
        while (u) {
            res += AC[u].cnt;
            AC[u].cnt = 0;
            u = AC[u].ff;
        }
        return res;
    }
    int match(string s) {
        int n = s.size();
        int res = 0, now = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (AC[now].next[c - 'a']) {
                now = AC[now].next[c - 'a'];
            }else {
                int p = AC[now].ff;
                while (p != -1 && AC[p].next[c - 'a'] == 0) {
                    p = AC[p].ff;
                }
                if (p == -1) {
                    now = 0;
                }else {
                    now = AC[p].next[c - 'a'];
                }
            }
            if (AC[now].cnt) {
                res += Get(now);
            }
        }
        return res;
    }
}aho;


int main() {
    int N, T;
    cin >> T;
    while (T--) {
        aho.init();
        cin >> N;
        string s;
        for (int i = 0; i < N; i++) {
            cin >> s;
            aho.insert(s);
        }
        aho.build();
        cin >> s;
        cout << aho.match(s) << endl;
    }

    return 0;
}
