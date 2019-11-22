/*
 * Check if a given 9x9 matrix is a valid sudoku matrix
 * */

#include <iostream>
#include <vector>

using namespace std;

constexpr const auto sqrt_N = 3;
constexpr const auto N = sqrt_N * sqrt_N;


bool check_row_column(unsigned short grid[N][N]){
    for(int i = 0; i < N; ++i){
        bool r_check_list[N] = {false};
        bool c_check_list[N] = {false};
        for(int j = 0; j < N; ++j)
            if(not r_check_list[grid[i][j]] or not c_check_list[grid[j][i]])
                r_check_list[grid[i][j] - 1] = c_check_list[grid[j][i] - 1] = true;
            else return false;
    }
    return true;
}

bool check_sudoku(unsigned short grid[N][N]){

    if(not check_row_column(grid))
        return false;

    for(int i = 0; i < sqrt_N; ++i){
        for(int j = 0; j < sqrt_N; ++j){
            if(not check_row_column(grid, i * sqrt_N, j * sqrt_N, sqrt_N, sqrt_N))
                return false;
        }
    }

    return true;
}

int main() {

    int **m = new int*[N];
    for(int i = 0; i < N; ++i)
        m[i] = new int[N];


    return 0;
}