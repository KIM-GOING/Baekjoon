#include <iostream>
#include <vector>
#include <queue>

#define INF 999999999

using namespace std;

int n, m;
int start, arrival;
vector<pair<int, int>> v[1001];
int dist[1001];
bool check[1001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void di() {

    while (!pq.empty()) {
        int cost = pq.top().second;
        pq.pop();

        if (!check[cost]) {
            check[cost] = true;

            for (int k = 0; k < v[cost].size(); k++) {
                int next = v[cost][k].first;

                if (dist[next] > dist[cost] + v[cost][k].second) {
                    dist[next] = dist[cost] + v[cost][k].second;
                    pq.push(make_pair(dist[next], next));
                }

            }
        }
    }

}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, a, f;
        cin >> s >> a >> f;
        v[s].push_back(make_pair(a, f));
    }

    
    cin >> start >> arrival;
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;
    
    pq.push(make_pair(0, start));

    di();

    cout << dist[arrival];

    return 0;
}
