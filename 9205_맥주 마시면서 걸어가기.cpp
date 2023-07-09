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
vector<Locate> arr;    //��ǥ ���� ����
queue<Locate> route;   //BFS�� ���� ť
int visited[103] = { 0, };   //�湮 �������� 0, ������ 1

int dist(Locate a, Locate b) {   //����ư �Ÿ� ���ϴ� �Լ�
    return abs(a.x_loc - b.x_loc) + abs(a.y_loc - b.y_loc);
}

int bfs() {
    while (route.size() != 0) {
        Locate now = { route.front().x_loc, route.front().y_loc };

        route.pop();

        for (int i = 0; i < arr.size(); i++) {
            if (visited[i] == 1)    //�湮�ߴٸ� �ǳʶٱ�
                continue;
            else {
                if (dist(now, arr[i]) <= 1000) {    //�Ÿ��� 1000���� �۴ٸ� ť�� �ְ� �湮ó��
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
        //�湮ó�� �迭, ��ġ��ǥ ����, bfs�� ���� ť �ʱ�ȭ
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
            arr.push_back({ x, y });   //��ǥ �迭�� ��ġ �Է��ϱ�
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