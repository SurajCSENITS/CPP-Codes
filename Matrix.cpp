#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <tuple>
#include <bits/stdc++.h>

void transpose(vector<vector<int>>& matrix){
    int n= matrix.size();
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++) 
            swap(matrix[i][j], matrix[j][i]);
}

void rotate(vector<vector<int>>& matrix){
    // first do tranpose of the matrix
    // then reverse each row/reverse the matrix by 180 deg
    int n= matrix.size();
    transpose(matrix);
    for(int i=0;i<n;i++) reverse(matrix[i].begin(), matrix[i].end());
}

vector<int> spiralMatrix(vector<vector<int>>& matrix){
    int m= matrix.size(), n= matrix[0].size();
    int top= 0, bottom= m-1, left= 0, right= n-1;
    int direction= 0;
    vector<int> spiral_traversal;
    
    while(left<=right and top<=bottom){
        if(direction==0){ // left to right
            for(int j=left;j<=right;j++) spiral_traversal.push_back(matrix[top][j]);
            top+= 1;
        } else if(direction==1){ // top to bottom
            for(int i=top;i<=bottom;i++) spiral_traversal.push_back(matrix[i][right]);
            right-= 1;
        } else if(direction==2){ // right to left
            for(int j=right;j>=left;j--) spiral_traversal.push_back(matrix[bottom][j]);
            bottom-= 1;
        } else{ // bottom to top
            for(int i=bottom;i>=top;i--) spiral_traversal.push_back(matrix[i][left]);
            left+= 1;
        }
        direction= (direction+1)%4;
    }
    return spiral_traversal;
}

vector<vector<int>> generateMatrix(int n){
    int curr= 1;
    int top= 0, bottom= n-1, left= 0, right= n-1;
    int direction= 0;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    while(left<=right and top<=bottom){
        if(direction==0){ // left to right
            for(int j=left;j<=right;j++) matrix[top][j]= curr++;
            top+= 1;
        } else if(direction==1){ // top to bottom
            for(int i=top;i<=bottom;i++) matrix[i][right]= curr++;
            right-= 1;
        } else if(direction==2){ // right to left
            for(int j=right;j>=left;j--) matrix[bottom][j]= curr++;
            bottom-= 1;
        } else{ // bottom to top
            for(int i=bottom;i>=top;i--) matrix[i][left]= curr++;
            left+= 1;
        }
        direction= (direction+1)%4;
    }
    return matrix;
}

int rectangleSum(vector<vector<int>>&& matrix, int l1, int r1, int l2, int r2){
    // first calcluate row wise prefix sum
    // then calculate column wise prefix sum from the row-wise prefix-sum matrix
    int m= matrix.size();
    int n= matrix[0].size();
    for(int i=0;i<m;i++){
        int row_sum= 0;
        for(int j=0;j<n;j++){
            row_sum+= matrix[i][j];
            matrix[i][j]= row_sum;
        }
    }

    for(int j=0;j<n;j++){
        int col_sum= 0;
        for(int i=0;i<m;i++){
            col_sum+= matrix[i][j];
            matrix[i][j]= col_sum;
        }
    }

    return matrix[l2][r2]-matrix[l2][r1-1]-matrix[l1-1][r2];
}

bool isValidCoordinates(int rows, int cols, int i, int j){
    return i<rows and j<cols and i>=0 and j>=0;
}

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart){
    vector<vector<int>> coordinates;
    int k= 1;

    coordinates.push_back({rStart, cStart});
    while(coordinates.size()<rows*cols){
        if(k%2==1){
            // move right by `k` steps
            for(int j=1;j<=k;j++)
                if(isValidCoordinates(rows, cols, rStart, cStart+j)) 
                    coordinates.push_back({rStart, cStart+j});
            cStart+= k;
            // move down by `k` steps
            for(int i=1;i<=k;i++)
                if(isValidCoordinates(rows, cols, rStart+i, cStart))
                    coordinates.push_back({rStart+i, cStart});
            rStart+= k;
        } else{
            // move left by `k` steps
            for(int j=1;j<=k;j++)
                if(isValidCoordinates(rows, cols, rStart, cStart-j)) // rstart cstrat-j
                    coordinates.push_back({rStart, cStart-j});
            cStart-= k;
            // move up by `k` steps
            for(int i=1;i<=k;i++)
                if(isValidCoordinates(rows, cols, rStart-i, cStart)) // rstart-i cstart
                    coordinates.push_back({rStart-i, cStart});
            rStart-= k;
        }
        k+= 1;
    }
    return coordinates;
}


// Definition for singly-linked list.
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head){
    vector<vector<int>> spiralMat(m, vector<int>(n, -1));
    int top= 0, bottom= m-1, left= 0, right= n-1;
    int direction= 0;
    while(head!=nullptr){
        if(direction==0){
            for(int j=left;j<=right;j++){
                spiralMat[top][j]= head->val, head= head->next;
                if(head==nullptr) break;
            }
            top+= 1;
        } else if(direction==1){
            for(int i=top;i<=bottom;i++){
                spiralMat[i][right]= head->val, head= head->next;
                if(head==nullptr) break;
            }
            right-= 1;
        } else if(direction==2){
            for(int j=right;j>=left;j--){
                spiralMat[bottom][j]= head->val, head= head->next;
                if(head==nullptr) break;
            }
            bottom-= 1;
        } else{
            for(int i=bottom;i>=top;i--){
                spiralMat[i][left]= head->val, head= head->next;
                if(head==nullptr) break;
            }
            left+= 1;
        }
        direction= (direction+1)%4;
    }
    return spiralMat;
}

int main(){

    vector<vector<int>> matrix= {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<int> spiralTraversal= spiralMatrix(matrix);
    for(int ele: spiralTraversal) cout<< ele<<" "; 

return 0;
}