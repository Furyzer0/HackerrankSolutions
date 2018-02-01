#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector < vector <int> > memVector;

vector<int> array_left_rotationR(vector<int> a, int n, int k);

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
        cin >> a[a_i];
    }
    vector<int> output = array_left_rotationR(a, n, k);
    for(int i = 0; i < n;i++)
        cout << output[i] << " ";
    cout << endl;
    return 0;
}

vector<int> array_left_rotationR(vector<int> a, int n, int k) {
    vector <int> temp(a.begin(), a.begin() + k);
    for(int i = k; i < n; i++) {
        a[i - k] = a[i];
    }
    a.insert(a.begin() + n - k, temp.begin(), temp.end());
    return a;
}