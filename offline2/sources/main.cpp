/*
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <stack>

using namespace std;


//globals
ofstream outfile;
ifstream infile;


//functions


void enterData(float firstMatrix[][10], float secondMatrix[][10], int rowFirst, int columnFirst, int rowSecond,
               int columnSecond);

void
matrixMultiplication(float firstMatrix[][10], float secondMatrix[][10], float resultantMatrixResult[][10], int rowFirst,
                     int columnFirst, int rowSecond, int columnSecond);

void display(float resultantMatrix[][10], int rowFirst, int columnSecond);


void showstack(stack<float (*)[10]> s) {
   */
/* while (!s.empty()) {
        cout << '\t' << s.top();
        s.pop();
    }*//*

   cout<<"in show stack\n";
    cout << '\n';
}


stack<float (*)[10]> insertToStack(float arr[][10]) {

    cout << "in insert to stack\n";
    stack<float (*)[10]> s;
    s.push(arr);

    cout << "The stack is : ";
    showstack(s);

    cout << "\ns.size() : " << s.size();
    cout << "\ns.top() : " << s.top();


    cout << "\ns.pop() : ";
    s.pop();
    s.pop();
    return s;


}

void readFromFile() {
    // open a file in read mode.
    cout << "Reading from the file" << endl;

    string line;

    infile.open("scene.txt");

    if (!infile.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }
    while (getline(infile, line)) {
        cout << line << endl;
    }

}

void writeTofile() {
    char data[100];

    // open a file in write mode.

    outfile.open("stage1.txt");

    cout << "Writing to the file" << endl;

    cin.getline(data, 100);
    // write inputted data into the file.
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // again write inputted data into the file.
    outfile << data << endl;

    // close the opened file.
    outfile.close();
}

*/
/*float(*)[10] identityMatrix(float identity[][10], int identity_sz) {
    int row, col;

    for (row = 0; row < identity_sz; row++) {
        for (col = 0; col < identity_sz; col++) {

            // Checking if row is equal to column
            if (row == col) {
                identity[row][col] = 1;
               // printf("%d ", 1);
            }
            else {
                identity[row][col] = 0;
                //printf("%d ", 0);
            }

        }
        printf("\n");
    }
    return identity;
}*//*



int main() {


    //writeTofile();
    //readFromFile();
 */
/*   float firstMatrix[10][10], secondMatrix[10][10], resultantMatrix[10][10], identity[10][10];
    int rowFirst, columnFirst, rowSecond, columnSecond, i, j, k;

    cout << "Enter rows and column for first matrix: ";
    cin >> rowFirst >> columnFirst;
    cout << "Enter rows and column for second matrix: ";
    cin >> rowSecond >> columnSecond;

    // If column of first matrix in not equal to row of second matrix, asking user to enter the size of matrix again.
    while (columnFirst != rowSecond) {

        cout << "Error! column of first matrix not equal to row of second." << endl;
        cout << "Enter rows and column for first matrix: ";
        cin >> rowFirst >> columnFirst;
        cout << "Enter rows and column for second matrix: ";
        cin >> rowSecond >> columnSecond;

    }


    enterData(firstMatrix, secondMatrix, rowFirst, columnFirst, rowSecond, columnSecond);

    matrixMultiplication(firstMatrix, secondMatrix, resultantMatrix, rowFirst, columnFirst, rowSecond, columnSecond);

    display(resultantMatrix, rowFirst, columnSecond);*//*


    float identity[10][10];
    //stack<int> s = insertToStack(identity);
    //showstack(s);


    //identityMatrix(identity,4);

    return 0;
}


void enterData(float firstMatrix[][10], float secondMatrix[][10], int rowFirst, int columnFirst, int rowSecond,
               int columnSecond) {

    int i, j;

    cout << endl << "Enter elements of matrix 1:" << endl;

    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < columnFirst; ++j) {
            cout << "Enter elements a" << i + 1 << j + 1 << ": ";
            cin >> firstMatrix[i][j];
        }
    }

    cout << endl << "Enter elements of matrix 2:" << endl;

    for (i = 0; i < rowSecond; ++i) {
        for (j = 0; j < columnSecond; ++j) {
            cout << "Enter elements b" << i + 1 << j + 1 << ": ";
            cin >> secondMatrix[i][j];
        }
    }
}

void
matrixMultiplication(float firstMatrix[][10], float secondMatrix[][10], float resultantMatrix[][10], int rowFirst,
                     int columnFirst,
                     int rowSecond, int columnSecond) {

    int i, j, k;

    // Initializing elements of matrix resultantMatrix to 0.
    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < columnSecond; ++j) {
            resultantMatrix[i][j] = 0;
        }
    }
    // multiplying firstMatrix and secondMatrix and storing in array resultantMatrix.
    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < columnSecond; ++j) {
            for (k = 0; k < columnFirst; ++k) {
                resultantMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

void display(float resultantMatrix[][10], int rowFirst, int columnSecond) {

    int i, j;

    cout << "Output Matrix:" << endl;

    for (i = 0; i < rowFirst; ++i) {
        for (j = 0; j < columnSecond; ++j) {
            cout << resultantMatrix[i][j] << " ";
            if (j == columnSecond - 1)
                cout << endl << endl;
        }
    }

}*/
