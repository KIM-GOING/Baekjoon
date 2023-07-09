#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct Locate {
    int x_loc = 0;
    int y_loc = 0;
};

int t, n;
int r = 0;
vector<Locate> arr;    //좌표 적은 벡터
queue<Locate> route;   //BFS를 위한 큐
int visited[103] = { 0, };   //방문 안했으면 0, 했으면 1

int dist(Locate a, Locate b) {   //맨해튼 거리 구하는 함수
    return abs(a.x_loc - b.x_loc) + abs(a.y_loc - b.y_loc);
}

int bfs() {
    while (route.size() != 0) {
        Locate now = { route.front().x_loc, route.front().y_loc };

        route.pop();

        for (int i = 0; i < arr.size(); i++) {
            if (visited[i] == 1)    //방문했다면 건너뛰기
                continue;
            else {
                if (dist(now, arr[i]) <= 1000) {    //거리가 1000보다 작다면 큐에 넣고 방문처리
                    route.push(arr[i]);
                    visited[i] = 1;
                }
            }
        }

        if (visited[arr.size() - 1]) {
            r = 1;
            break;
        }
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int u = 0; u < t; u++) {
        //방문처리 배열, 위치좌표 벡터, bfs를 위한 큐 초기화
        for (int i = 0; i < n + 2; i++)
            visited[i] = 0;
        arr.clear();
        while (!route.empty())
            route.pop();
        r = 0;
        cin >> n;
        for (int i = 0; i < n + 2; i++) {
            int x, y;
            cin >> x >> y;
            arr.push_back({ x, y });   //좌표 배열에 위치 입력하기
        }

        route.push(arr[0]);
        visited[0] = 1;

        if (bfs() == 1)
            cout << "happy" << "\n";
        else
            cout << "sad" << "\n";

    }

    return 0;
}