#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>>& universe, int x, int y, int& area, int m, int n) {
    static const vector<int> dx = {-1, 1, 0, 0};
    static const vector<int> dy = {0, 0, -1, 1};
    universe[x][y] = 0;
    area++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n && universe[nx][ny] == 1) {
            dfs(universe, nx, ny, area, m, n);
        }
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> universe(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> universe[i][j];
        }
    }

    vector<int> collectingArea;
    int res = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (universe[i][j] == 1) {
                int area = 0;
                dfs(universe, i, j, area, m, n);
                collectingArea.push_back(area);
                res++;
            }
        }
    }

    quickSort(collectingArea, 0, collectingArea.size()-1);

    cout << "The total number of planets is : " << res << endl;
    cout << "The areas of the planets in non-decreasing order are : ";
    for (int area : collectingArea) {
        cout << area << " ";
    }
    cout << endl;

    return 0;
}
