    #include <bits/stdc++.h>

    using namespace std;

    void printMatrix(const vector< vector<int> >& matrix)
    {
        for(auto v : matrix) {
            for(int i : v) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    int areaDfs(vector< vector<int> >& matrix, int i, int j)
    {
        if(matrix[i][j] != 1)
            return 0;
            
        int area = 1;
        matrix[i][j] = 2;
        bool up, down, right, left;
        
        down = i > 0; 
        up = i < matrix.size() - 1;
        left = j > 0;
        right = j < matrix[0].size() - 1;

        if(down) {
            area += areaDfs(matrix, i - 1, j);
        }
        if(up) {
            area += areaDfs(matrix, i + 1, j);
        }
        if(left) {
            area += areaDfs(matrix, i, j - 1);
        }
        if(right) {
            area += areaDfs(matrix, i, j + 1);
        }
        if(up && right) {
            area += areaDfs(matrix, i + 1, j + 1);
        }
        if(up && left) {
            area += areaDfs(matrix, i + 1, j - 1);
        }
        if(down && right) {
            area += areaDfs(matrix, i - 1, j + 1);
        }
        if(down && left) {
            area += areaDfs(matrix, i - 1, j - 1);
        }

        return area;
    }

    int connectedCell(vector < vector<int> >& matrix)
    {
        int result = 0;

        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                if(matrix[i][j] == 1) {
                    result = max(result, areaDfs(matrix, i, j));
                    //cout << result << endl;
                }
            }
        }

        return result;
    }

    int main() 
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector< vector<int> > matrix(n,vector<int>(m));
        for(int matrix_i = 0;matrix_i < n;matrix_i++){
        for(int matrix_j = 0;matrix_j < m;matrix_j++){
            cin >> matrix[matrix_i][matrix_j];
        }
        }
        int result = connectedCell(matrix);
        cout << result << endl;

        //printMatrix(matrix);
        return 0;
    }
