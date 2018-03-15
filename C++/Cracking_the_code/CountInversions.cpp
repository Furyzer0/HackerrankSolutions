#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
typedef vector<int>::iterator Iterator;

long merge_parts(Iterator begin, Iterator end, vector<int>& left, vector<int>& right)
{
    long swapCount = 0;

    Iterator l = left.begin();
    Iterator r = right.begin();

    while(l != left.end() && r != right.end()) {
        if(*l <= *r) {
            *begin++ = *l++;
        }
        else {
            *begin++ = *r++;
            // https://www.geeksforgeeks.org/counting-inversions/
            swapCount += distance(l, left.end());
        }
    }

    while(l != left.end())  
        *begin++ = *l++;
    while(r != right.end())
        *begin++ = *r++;

    return swapCount;
}

long merge_sort(Iterator begin, Iterator end)
{
    long swapCount = 0;

    int n = distance(begin, end);
    if(n <= 1)
        return 0;  

    Iterator middle = next(begin, n / 2);

    vector<int> left(begin, middle);
    vector<int> right(middle, end);

    swapCount += merge_sort(left.begin(), left.end());
    swapCount += merge_sort(right.begin(), right.end());
    swapCount += merge_parts(begin, end, left, right);

    return swapCount;
}

int main() 
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        long result = merge_sort(arr.begin(), arr.end());
        cout << result << endl;
        //merge_sort(arr.begin(), arr.end());
        //for(int i = 0; i < n; ++i)
        //    cout << arr[i] << " ";
    }
    return 0;
}
