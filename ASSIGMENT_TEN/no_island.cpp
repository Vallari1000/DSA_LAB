#include<iostream>
using namespace std;
static int mat[10][10] = {
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 1, 0, 0, 0, 1},
    {1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 0, 0, 1, 0, 0, 1}
    };
static int count = 0;
void find_whole_island(int i, int j, int &count){
        mat[i][j] = 0;
        if(mat[i][j+1] == 0 && mat[i+1][j+1] == 0 && mat[i+1][j] == 0){
            count++;
            return;
        }else if (mat[i][j+1] == 1){
            find_whole_island(i, j+1, count);
        }else if ( mat[i+1][j+1] == 1){
            find_whole_island(i+1, j+1, count);
        }else{
            find_whole_island(i+1, j, count);
        }
        
}
int no_island(int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m){
            return count;
        }
        if(mat[i][j] == 1){
            find_whole_island(i, j, count);
        }else{
                        
        }
        if(mat[i][j+1] == 1){
            find_whole_island(i, j, count);
        }else{
            no_island(i, j+1, n, m);
        }
        if(mat[i+1][j+1] == 1){
            find_whole_island(i, j, count);
        }else{
            no_island(i+1, j+1, n, m);
        }
        if(mat[i+1][j] == 1){
            find_whole_island(i, j, count);
        }else{
            no_island(i+1, j, n, m);
        }
        return count;
        
}
int main(){
    int n = no_island(0, 0, 10, 10);
    cout << n << endl;
    for(int i = 0; i<10; i++){
        for(int j = 0; j<10; j++){
            cout << mat[i][j]; cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}