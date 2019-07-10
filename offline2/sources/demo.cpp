//
// Created by afsara on 7/11/19.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

//globals

ifstream infile;
stack<float (*)[10]> s;
int sz = 4;

float (*makeIdentityMatrix(float identity[][10], int identity_sz))[10] {
    int row, col;

    cout << "here" << endl;
    for (row = 0; row < identity_sz; row++) {
        for (col = 0; col < identity_sz; col++) {

            // Checking if row is equal to column
            if (row == col) {
                identity[row][col] = 1;

            } else {
                identity[row][col] = 0;

            }

        }

    }
    return identity;

}


void showstack(stack<float (*)[10]> s) {

    cout << "printing topmost stack\n";

    float (*temp)[10];
    if (!s.empty()) {

        temp = s.top();

    }

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            cout << temp[i][j] << " ";
        }
        cout << endl;
    }

    cout << '\n';
}

stack<float (*)[10]> insertToStack(float arr[][10]) {

    cout << "in insert to stack\n";

    s.push(arr);

    cout << "\ns.size() : " << s.size();

    return s;


}

int main() {
    float identity[10][10];

    float (*identityMatrix)[10] = makeIdentityMatrix(identity, sz);

    insertToStack(identityMatrix);
    showstack(s);

    //readFromFile();
    return 1;
}
