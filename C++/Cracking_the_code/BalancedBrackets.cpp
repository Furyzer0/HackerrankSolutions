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

map <char, int> brackets = {
    {'(', 1},
    {'[', 2},
    {'{', 3},
    {')', 4},
    {']', 5},
    {'}', 6}
};

bool is_symetric(char c1, char c2) {
    return brackets.at(c1) <= 3 && brackets.at(c2) > 3;
}

bool is_match(char c1, char c2) {
    return brackets.at(c2) - brackets.at(c1) == 3;
}

bool is_balanced(string expression) {
    if(expression.length() == 0)    return true;

    int l, r;

    //find where the pairs start
    for(int i = 0; i < expression.length() - 1; i++){
        char c1 = expression[i], c2 = expression[i + 1];
        if(is_match(c1, c2)){
            l = i, r = i + 1;
            break;
        }
        if(i == expression.length() - 2)    return false;            
    }

    //extend the interval until unmatched pairs found
    while(l >= 0 && r < expression.length()){
        char c1 = expression[l], c2 = expression[r];
        if(is_match(c1, c2)){
            l--, r++;
            continue;
        }
        if(is_symetric(c1, c2)){
            return false;
        }
        break;
    }
    //remove the matched pairs and check the next step
    return is_balanced(expression.erase(l + 1, r - (l + 1)));
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
