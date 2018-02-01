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

bool ransom_note(map<string, int> magazine, map<string, int> ransom) {
    for(pair<string, int> word : ransom){
        map<string, int>::iterator it = magazine.find(word.first);
        if(it != magazine.end()){
            if(word.second > it -> second) return false;
            else magazine.erase(it);
        }
        else return false;
    }
    return true;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    map<string, int> magazine;
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       string temp; cin >> temp;
       map <string, int>::iterator it = magazine.find(temp);
       if(it != magazine.end()) it -> second += 1;
       else magazine.insert(pair<string ,int>(temp, 1));
    }

    map <string, int> ransom;
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       string temp; cin >> temp;
       map <string, int>::iterator it = ransom.find(temp);
       if(it != ransom.end()) it -> second += 1;
       else ransom.insert(pair<string, int>(temp, 1));
    }

    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
