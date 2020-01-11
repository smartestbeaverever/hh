/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    vector <string> original;
    vector <string> desired;

    vector<vector<int> > matrix;
    vector<int> zerorow;
    for (auto i = 0; i <= desired.size(); i++) {
        zerorow.push_back(i);
    }
    matrix.push_back(zerorow);
    for (auto i = 1; i <= original.size(); i++) {
        vector<int> row;
        row.push_back(i);
        for (auto j = 0; j <= desired.size(); j++) {
            int cost = (original[i] == desired[j]) ? 0 : 1;
            int src1 = matrix[i-1][j] + 1;
            int src2 = matrix[i][j-1] + 1;
            int src3 = matrix[i-1][j-1] + cost;
            row.push_back(min(min(src1, src2), src3));
        }
        matrix.push_back(row);
    }
    return 0;
}
