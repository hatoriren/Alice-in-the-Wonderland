#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int minMushroomPieces(int startHeight, int endHeight) {
    if (startHeight == endHeight) return 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> visited(2 * max(startHeight, endHeight), 0); 

    pq.push({ 0, startHeight });

    while (!pq.empty()) {
        int pieces = pq.top().first;
        int height = pq.top().second;
        pq.pop();

        if (height == endHeight) return pieces;
        if (visited[height]) continue;
        visited[height] = 1;

        if (height < endHeight)
            pq.push({ pieces + 1, height * 2 });
        if (height - 100 > 0)
            pq.push({ pieces + 1, height - 100 });
    }

    return -1;
}

int main() {
    int tests, x, y;
    cin >> tests;
    tests = min(tests, 100);
    while (tests--) {
        cin >> x >> y;
       x = max(1, x);
       y = min(y, 100000);
        int result = minMushroomPieces(x, y);
        if (result == -1) cout << "NIE" << endl;
        else cout << result << endl;
    }
    system("pause");
}
