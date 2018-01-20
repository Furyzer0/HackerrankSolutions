#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string countLuck(vector <string> matrix, int length);
bool solveMaze(vector <string> matrix, int length, int k, int x, int y, int endx, int endy, int count);
bool using_wand(vector <string> matrix, int length, int x, int y);

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
        string result = countLuck(matrix, n);
        cout << result << endl;
    }
    return 0;
}

string countLuck(vector <string> matrix, int length) {
    int k;
    cin >> k;
    int startx = -1, starty = -1, endx = -1, endy = -1;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < matrix[0].length(); j++){
            char current = matrix[i][j];
            if(current == '*'){
                endx = j;
                endy = i;
                if(startx != -1)
                    break;
            }
            else if(current == 'M'){
                startx = j;
                starty = i;
                if(endx != -1)
                    break;
            }
        }
    }
    //cout << startx << ", " << starty << ", " << endx << ", " << endy << ", " << endl;
    solveMaze(matrix, length, k, startx, starty, endx, endy, 0);
    return "";
}

bool solveMaze(vector <string> matrix, int length, int k, int x, int y, int endx, int endy, int count){
    if(x == endx && y == endy){
        for(int i = 0; i < length; i++){
            cout << matrix[i] << endl;
        }      
        if(count == k)
            cout << "Impressed";
        else
            cout << "Oops!";
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
        if(solveMaze(matrix, length, k, x - 1, y, endx, endy, count))
            return true;
    }  
    if(x != matrix[0].length() - 1){
        if(solveMaze(matrix, length, k, x + 1, y, endx, endy, count))
            return true;
    }
    if(y != 0){
        if(solveMaze(matrix, length, k, x, y - 1, endx, endy, count))
            return true;
    }
    if(y != length - 1){
        if(solveMaze(matrix, length, k, x, y + 1, endx, endy, count))
            return true;
    } 
    return false;
}

bool using_wand(vector <string> matrix, int length, int x, int y){
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