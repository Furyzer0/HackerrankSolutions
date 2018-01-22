#include <bits/stdc++.h>

using namespace std;  

vector<string> bombermanGame(vector<string>& minefield, long n, int r, int c){
    if(n == 1){
        return minefield;
    }
    n %= 4;
    if(n == 1){
        for(int t = 0; t < 2; t++){
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(minefield[i][j] == 'O'){
                        minefield[i][j] = 'X';
                        if(i != 0 && minefield[i - 1][j] != 'O'){
                            minefield[i - 1][j] = 'X';
                        }
                        if(i != r - 1 && minefield[i + 1][j] != 'O'){
                            minefield[i + 1][j] = 'X';
                        }
                        if(j != 0 && minefield[i][j - 1] != 'O'){
                            minefield[i][j - 1] = 'X';
                        }
                        if(j != c && minefield[i][j + 1] != 'O'){
                            minefield[i][j + 1] = 'X';
                        }
                    }
                }
            }
            for(int i = 0; i < r; i++){
                for(int j = 0; j < c; j++){
                    if(minefield[i][j] == '.')
                        minefield[i][j] = 'O';
                    else if(minefield[i][j] == 'X')
                        minefield[i][j] = '.';
                }
            }
        }
    }
    else if(n % 2 == 0){
        string fullMine = string(c, 'O');
        for(int i = 0; i < r; i++){
            minefield[i] = fullMine;
        }     
    }
    else if(n == 3){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(minefield[i][j] == 'O'){
                    minefield[i][j] = 'X';
                    if(i != 0 && minefield[i - 1][j] != 'O'){
                        minefield[i - 1][j] = 'X';
                    }
                    if(i != r - 1 && minefield[i + 1][j] != 'O'){
                        minefield[i + 1][j] = 'X';
                    }
                    if(j != 0 && minefield[i][j - 1] != 'O'){
                        minefield[i][j - 1] = 'X';
                    }
                    if(j != c && minefield[i][j + 1] != 'O'){
                        minefield[i][j + 1] = 'X';
                    }
                }
            }
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(minefield[i][j] == '.')
                    minefield[i][j] = 'O';
                else if(minefield[i][j] == 'X')
                    minefield[i][j] = '.';
            }
        }
    }
    return minefield;
}

int main() {
    int r, c;
    long n;
    cin >> r >> c >> n;
    vector<string> temp(r);
    for(int i = 0; i < r; i++){
        cin >> temp[i];
    }
    vector<string> result = bombermanGame(temp, n, r, c);
    for(vector<string>::iterator iter = result.begin(); iter != result.end(); iter++){
        cout << *iter << endl;
    }
}
