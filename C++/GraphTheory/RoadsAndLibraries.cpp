#include <iostream>
#include <vector>

using namespace std;

inline void DFS(vector< vector<int> >& adj_list, vector<bool>& visited, int i)
{
    visited[i] = true;

    for(int j : adj_list[i]) {
        if(!visited[j]) {
            DFS(adj_list, visited, j);
        }
    }
}

unsigned long long RandL(vector< vector<int> >& adj_list, vector<bool>& visited, long cLib, long cRoad, int n) 
{  
    if(cLib <= cRoad)
        return cLib * n;
    
    unsigned long long connected = 0;

    for(int i = 0; i < n; ++i) {
        if(!visited[i]){
            DFS(adj_list, visited, i);
            ++connected;
        }
    }

    return (connected * cLib) + ((n - connected) * cRoad);
}

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        long n;
        long m;
        long cLib;
        long cRoad;

        cin >> n >> m >> cLib >> cRoad;

        vector< vector<int> > adj_list(n, vector<int>(0));

        for(int j = 0; j < m; ++j) {
            int city1;
            int city2;

            cin >> city1 >> city2;
            --city1;
            --city2;

            adj_list[city1].push_back(city2);
            adj_list[city2].push_back(city1);
        }

        vector<bool> visited(n, false);
        cout << RandL(adj_list, visited, cLib, cRoad, n) << endl;
    }

    return 0;
}