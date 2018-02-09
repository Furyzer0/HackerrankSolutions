#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int count_region(vector< vector<int> >& grid, int y, int x, int n, int m) {
	if (y < 0 || x < 0 || y >= n || x >= m)   return 0;
	if (grid[y][x] == 0)     return 0;
	int count = 1;
	grid[y][x]--;

	count += count_region(grid, y + 1,   x , n, m);
	count += count_region(grid, y - 1,   x , n, m);
	count += count_region(grid,   y  , x + 1, n, m);
	count += count_region(grid,   y  , x - 1, n, m);
	count += count_region(grid, y + 1, x + 1, n, m);
	count += count_region(grid, y - 1, x - 1, n, m);
	count += count_region(grid, y - 1, x + 1, n, m);
	count += count_region(grid, y + 1, x - 1, n, m);

	return count;
}

int get_biggest_region(vector< vector<int> > grid, int n, int m) {
	int max_length = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			max_length = max(max_length, count_region(grid, i, j, n, m));
		}
	}

	return max_length;
}

int main() {
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector< vector<int> > grid(n, vector<int>(m));
	for (int grid_i = 0; grid_i < n; grid_i++) {
		for (int grid_j = 0; grid_j < m; grid_j++) {
			cin >> grid[grid_i][grid_j];
		}
	}
	cout << get_biggest_region(grid, n, m) << endl;
	cin.ignore();
	cin.get();
	return 0;
}
