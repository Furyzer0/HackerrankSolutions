#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void countLuck(vector <string> matrix, int length);
bool solveMaze(vector <string>& matrix, int length, int k, int x, int y, int count);
bool using_wand(vector <string>& matrix, int length, int x, int y);

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int m;
        cin >> n >> m;
        vector<string> matrix(n);
        for(int matrix_i = 0; matrix_i < n; matrix_i++){
           cin >> matrix[matrix_i];
        }
        countLuck(matrix, n);
    }
    return 0;
}

/*Find starting point and pass it to solveMaze method       
*/
void countLuck(vector <string> matrix, int length) {
    int k;
    cin >> k;
    int startx = -1, starty = -1;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < matrix[0].length(); j++){
            char current = matrix[i][j];
            if(current == 'M'){
                startx = j;
                starty = i;
                break;
            }
        }
    }
    solveMaze(matrix, length, k, startx, starty, 0);
    return;
}
/* Find the solution using DFS and check every point has more than two path to count how many times want is used
*/
bool solveMaze(vector <string>& matrix, int length, int k, int x, int y, int count){          
    if(matrix[y][x] == '*'){
        if(count == k)
            cout << "Impressed";
        else
            cout << "Oops!";
        cout << endl;
        return true;
    }
    if(matrix[y][x] == 'X' || matrix[y][x] == '+'){
        return false;
    }
    matrix[y][x] = '+'; 
    if(using_wand(matrix, length, x, y)){
        count++;
    }
    if(x != 0){
        if(solveMaze(matrix, length, k, x - 1, y, count))
            return true;
    }  
    if(x != matrix[0].length() - 1){
        if(solveMaze(matrix, length, k, x + 1, y, count))
            return true;
    }
    if(y != 0){
        if(solveMaze(matrix, length, k, x, y - 1, count))
            return true;
    }
    if(y != length - 1){
        if(solveMaze(matrix, length, k, x, y + 1, count))
            return true;
    } 
    return false;
}

/* Look for paths are open, if there are more and equal than two paths return true
*/
bool using_wand(vector <string>& matrix, int length, int x, int y){
    int open_count = 0;

    if(x != 0){
        if(matrix[y][x - 1] != '+' && matrix[y][x - 1] != 'X')
            open_count++;
    }

    if(x != matrix[0].length() - 1){
        if(matrix[y][x + 1] != '+' && matrix[y][x + 1] != 'X')
            open_count++;
    }

    if(y != 0){
        if(matrix[y - 1][x] != '+' && matrix[y - 1][x] != 'X')
            open_count++;
    }

    if(y != length - 1){
        if(matrix[y + 1][x] != '+' && matrix[y + 1][x] != 'X')
            open_count++;
    }

    if(open_count >= 2)
        return true;
    return false;
}