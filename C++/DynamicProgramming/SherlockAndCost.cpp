#include <bits/stdc++.h>

using namespace std;

int cost(vector <int>& B, int low, int high, int i);

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        int result = cost(arr, 0, 0, 1);
        cout << result << endl;
    }
    return 0;
}

int cost(vector <int>& B, int low, int high, int i){
    int length = B.size();
    if(i == length)
        return max(low, high);
    int hh = abs(B[i - 1] - B[i]);
    int hl = B[i - 1] - 1;
    int lh = B[i] - 1;
    //int ll = 1 - 1; = 0

    int next_low = max(low, high + hl);
    int next_high = max(high + hh, low + lh);

    return cost(B, next_low, next_high, i + 1);
}