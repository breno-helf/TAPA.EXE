#include<bits/stdc++.h>
using namespace std;

const int MAX = 512;

typedef pair<int, int> pii;
typedef long long ll;

struct pos {
    int x, y, cap;
    pos(int X = 0, int Y = 0, int C = 0):
	x(X), y(Y), cap(C) {}
    bool operator < (const pos ot) const {
	return cap < ot.cap;
    }
};

int h, w;
ll grid[MAX][MAX];
int mrk[MAX][MAX];
ll water = 0;
int X, Y;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int valid(int x, int y) {
    return (x >= 1 && x <= h && y >= 1 && y <= w);
}

void simulate() {
    priority_queue<pos> Q;
    Q.push(pos(X, Y, -grid[X][Y]));
    water -= grid[X][Y];
    mrk[X][Y] = 1;
    
    while (!Q.empty()) {
	pos cur = Q.top();
	int x = cur.x, y = cur.y, cap = cur.cap;
	Q.pop();
	for (int i = 0; i < 8; i++) {
	    int Nx = x + dx[i];
	    int Ny = y + dy[i];

	    if (valid(Nx, Ny)) {
		if (grid[Nx][Ny] < 0 && !mrk[Nx][Ny])  {
		    ll add = min((ll)cap, -grid[Nx][Ny]);
		    //printf("--> (%d, %d) suguei %lld de (%d, %d)\n", x, y, add, Nx, Ny);
		    water += add;
		    mrk[Nx][Ny] = 1;
		    Q.push(pos(Nx, Ny, add));
		}
	    }
	}
    }
}

int main() {
    scanf("%d%d", &h, &w);
    for (int i = 1; i <= h; i++) {
	for (int j = 1; j <= w; j++) {
	    scanf("%lld", &grid[i][j]);
	    //grid[i][j] *= -1;
	}
    }
    scanf("%d%d", &X, &Y);
    
    simulate();

    printf("%lld\n", water);
}
