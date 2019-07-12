/*
//
// Created by afsara on 7/11/19.
//

#include <bits/stdc++.h>
#include <fcntl.h>

using namespace std;
const double PI = acos(-1.0);
const double EPS = 1e-4;

ifstream infile, infile2, infile3;
ofstream outfile, outfile2, outfile3;
int sz = 4;

stack<float (*)[10]> s;
stack<int> Size;


struct Point {
    float x, y, z, w = 1;

    Point() {
    }

    Point(float px, float py, float pz) {

        x = px;
        y = py;
        z = pz;
        w = 1;
    }

};

struct Vector {
    float x, y, z, w = 0;

    Vector() {
        x = x;
        y = y;
        z = z;
    };

    Vector(float vx, float vy, float vz) {

        x = vx;
        y = vy;
        z = vz;
        w = 0;
    }

};

Vector eye(0, 0, 0), look(0, 0, 0), up(0, 0, 0);
float fovY, aspectRatio, near, far;

//functions


float (*matrixMultiplication(float firstMatrix[][10], float secondMatrix[][10],
                             int rowFirst,
                             int columnFirst, int rowSecond, int columnSecond))[10];


float (*makeIdentityMatrix(float identity[][10], int identity_sz))[10];

void showstack(stack<float (*)[10]> s);

void insertToStack(float arr[][10]);

float (*getTopOfStack())[10];

float (*makeTranslationMatrix(float transX, float transY, float transZ))[10];

float (*makeScalingMatrix(float scaleX, float scaleY, float scaleZ))[10];

inline double degToRad(double ang) {
    return ang * PI / 180.0;
}

static inline bool isNearlyEqual(const double &a, const double &b) {
    return std::abs(a - b) < EPS;
}

float Cos(float angle) {
    float var = cos(degToRad(angle));
    if (isNearlyEqual(var, 0)) var = 0;
    return var;
}

float Sin(float angle) {
    float var = sin(degToRad(angle));
    if (isNearlyEqual(var, 0)) var = 0;
    return var;
}

float Tan(float angle) {
    float var = tan(degToRad(angle));
    if (isNearlyEqual(var, 0)) var = 0;
    return var;
}


Vector crossProduct(const Vector &vec1, const Vector &vec2) {

    Vector res;
    res.x = vec1.y * vec2.z - vec2.y * vec1.z;
    res.y = vec1.z * vec2.x - vec2.z * vec1.x;
    res.z = vec1.x * vec2.y - vec2.x * vec1.y;

    return res;
}


float dotProduct(const Vector &vec1, const Vector &vec2) {

    float res;
    //cout << "\n vec1 : " << vec1.x << " " << vec1.y << " " << vec1.z << endl;
    //cout << "\n vec2 : " << vec2.x << " " << vec2.y << " " << vec2.z << endl;
    res += vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;

    if (isNearlyEqual(res, 0)) res = 0;

    //cout << "\n res : " << res << endl;
    return res;
}

Vector normalize(Vector a) {
    int val = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);

    Vector p;
    p.x = a.x / val;
    p.y = a.y / val;
    p.z = a.z / val;

    cout << "\nnormalizing\n[ " << p.x << " " << p.y << " " << p.z << " " << p.w << " ] \n";
    return p;
}

Vector multiply(Vector v, float scalar) {
    // cout << "scalar is " << scalar << endl;
    v.x = v.x * scalar;
    v.y = v.y * scalar;
    v.z = v.z * scalar;
    return v;
}

Vector add(Vector v1, Vector v2) {
    Vector ret;
    ret.x = v1.x + v2.x;
    ret.y = v1.y + v2.y;
    ret.z = v1.z + v2.z;
    return ret;

}


Vector subtract(Vector v1, Vector v2) {
    Vector ret;
    ret.x = v1.x - v2.x;
    ret.y = v1.y - v2.y;
    ret.z = v1.z - v2.z;
    return ret;

}

Vector rotateRod(Vector x, Vector rotateAxis, float rotateAngle) {


    Vector temp1 = multiply(x, Cos(rotateAngle)); //cos(theta)*x ; x is a vector
    //cout << "\ntemp1 " << temp1.x << " " << temp1.y << " " << temp1.z << endl;

    Vector temp2 = crossProduct(rotateAxis, x); // a cross x
    //cout << "\ntemp2 " << temp2.x << " " << temp2.y << " " << temp2.z << endl;

    Vector temp3 = multiply(temp2, Sin(rotateAngle)); //sin(theta) * (a cross x)
    //cout << "\ntemp3 " << temp3.x << " " << temp3.y << " " << temp3.z << endl;

    Vector temp4 = add(temp1, temp3); // cos(theta)*x + sin(theta) * (a cross x)
    //cout << "\ntemp4 " << temp4.x << " " << temp4.y << " " << temp4.z << endl;


    float temp5 = dotProduct(rotateAxis, x); // a dot x
    //cout << "\ntemp5 " << temp5 << endl;

    Vector temp6 = multiply(rotateAxis, temp5); // (a dot x)*a
    //cout << "\ntemp6 " << temp6.x << " " << temp6.y << " " << temp6.z << endl;

    Vector temp7 = multiply(temp6, (1 - Cos(rotateAngle))); // (1-cos(theta)) * (a dot x)*a
    //cout << "\ntemp7 " << temp7.x << " " << temp7.y << " " << temp7.z << endl;

    Vector finalR = add(temp4,
                        temp7); // cos(theta)*x + sin(theta) * (a cross x) + (1-cos(theta)) * (a dot x)*a
    //cout << "\nfinal  " << finalR.x << " " << finalR.y << " " << finalR.z << endl;

    return finalR;
}


void printMatrix(float (*matrix)[10]) {
    cout << "\n in print matrix \n";

    for (int i = 0; i < sz - 1; ++i) {
        for (int j = 0; j < sz - 1; ++j) {
            cout << matrix[i][j] << " ";
            outfile << matrix[j][i] << " ";
        }
        cout << endl;
        outfile << endl;
    }
    outfile << "-" << endl;
}

void printMatrix2(float (*matrix)[10]) {
    cout << "\n in print matrix \n";

    for (int i = 0; i < sz - 1; ++i) {
        for (int j = 0; j < sz - 1; ++j) {
            cout << matrix[i][j] << " ";
            outfile2 << matrix[j][i] << " ";
        }
        cout << endl;
        outfile2 << endl;
    }
    outfile2 << "-" << endl;
    cout << " out of printmatrix2" << endl;
}

void printMatrix3(float (*matrix)[10]) {

    for (int i = 0; i < sz - 1; ++i) {
        for (int j = 0; j < sz - 1; ++j) {
            cout << matrix[i][j] << " ";
            outfile3 << matrix[j][i] << " ";
        }
        cout << endl;
        outfile3 << endl;
    }
    outfile3 << "-" << endl;
    cout << " out of printmatrix3" << endl;
}

void print(float (*matrix)[10]) {

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


float (*makeIdentityMatrix2(int identity_sz))[10] {

    int row, col;

    float(*identity)[10] = new float[10][10];
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

void readFromFile() {
// open a file in read mode.
    cout << "Reading from the file" << endl;

    string line;

    infile.open("scene.txt");

    if (!infile.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }

    int line_num = 0;
    vector<string> tokens[100]; // Create vector to hold the words
    while (getline(infile, line)) {


        string buf;                 // Have a buffer string
        stringstream ss(line);       // Insert the string into a stream



        while (ss >> buf)
            tokens[line_num].push_back(buf);

        line_num++;
    }


    //printing the file content as a 2d array
    for (int j = 0; j < line_num; ++j) {

        for (int i = 0; i < tokens[j].size(); ++i) {

            //cout << j << " : " << i << " " << tokens[j][i] << " \n";

        }
        //cout << endl;
    }

    string command;
    for (int i = 0; i < line_num; ++i) {

        if (i == 0) {
            eye.x = stof(tokens[i][0].c_str());
            eye.y = stof(tokens[i][1].c_str());
            eye.z = stof(tokens[i][2].c_str());
        } else if (i == 1) {
            look.x = stof(tokens[i][0].c_str());
            look.y = stof(tokens[i][1].c_str());
            look.z = stof(tokens[i][2].c_str());
        } else if (i == 2) {
            up.x = stof(tokens[i][0].c_str());
            up.y = stof(tokens[i][1].c_str());
            up.z = stof(tokens[i][2].c_str());
        } else if (i == 3) {
            fovY = stof(tokens[i][0].c_str());
            aspectRatio = stof(tokens[i][1].c_str());
            near = stof(tokens[i][2].c_str());
            far = stof(tokens[i][3].c_str());
        } else {

            for (int itr = 0; itr < tokens[i].size(); ++itr) {

                command = tokens[i][itr];


                //start parsing commandscrossProduct(rotateAxis, iHat)
                if (command == "triangle") {


                    //go to next line
                    i++;


                    cout << "found a triangle " << endl;
                    //input three points
                    struct Point firstPoint, secondPoint, thirdPoint;


                    firstPoint.x = stof(tokens[i][itr].c_str());
                    firstPoint.y = stof(tokens[i][itr + 1].c_str());
                    firstPoint.z = stof(tokens[i][itr + 2].c_str());


                    i++;
                    secondPoint.x = stof(tokens[i][itr].c_str());
                    secondPoint.y = stof(tokens[i][itr + 1].c_str());
                    secondPoint.z = stof(tokens[i][itr + 2].c_str());

                    i++;
                    thirdPoint.x = stof(tokens[i][itr].c_str());
                    thirdPoint.y = stof(tokens[i][itr + 1].c_str());
                    thirdPoint.z = stof(tokens[i][itr + 2].c_str());

                    float myMatrix[10][10];

                    vector<float> temp;
                    temp.push_back(firstPoint.x);
                    temp.push_back(secondPoint.x);
                    temp.push_back(thirdPoint.x);
                    temp.push_back(1);

                    temp.push_back(firstPoint.y);
                    temp.push_back(secondPoint.y);
                    temp.push_back(thirdPoint.y);
                    temp.push_back(1);

                    temp.push_back(firstPoint.z);
                    temp.push_back(secondPoint.z);
                    temp.push_back(thirdPoint.z);
                    temp.push_back(1);

                    temp.push_back(1);
                    temp.push_back(1);
                    temp.push_back(1);
                    temp.push_back(1);


                    for (int j = 0; j < sz; ++j) {

                        for (int k = 0; k < sz; ++k) {
                            myMatrix[j][k] = temp.at(j * 4 + k);
                        }
                    }

                    //printMatrix(myMatrix);

                    float (*resultant)[10];

                    resultant = matrixMultiplication(s.top(), myMatrix, sz, sz, sz, sz);

                    printMatrix(resultant); //T*I



                    //showstack(s);

                } else if (command == "scale") {
                    //                input scaling factors
                    //                generate the corresponding scaling matrix T
                    //                S.push(product(S.top,T))

                    //go to next line
                    i++;


                    cout << "do scaling " << endl;
                    struct Point scaleFactor;


                    //parsing values
                    scaleFactor.x = stof(tokens[i][itr].c_str());
                    scaleFactor.y = stof(tokens[i][itr + 1].c_str());
                    scaleFactor.z = stof(tokens[i][itr + 2].c_str());


                    float (*scaleMatrix)[10] = new float[10][10];
                    scaleMatrix = makeScalingMatrix(scaleFactor.x, scaleFactor.y, scaleFactor.z);
                    //printMatrix(scaleMatrix);


                    float (*prev)[10];
                    float (*New)[10];
                    prev = s.top();
                    New = matrixMultiplication(prev, scaleMatrix, sz, sz, sz, sz);
                    s.push(New);


                    float (*resultant)[10];

                    //resultant = matrixMultiplication(s.top(), scaleMatrix, sz, sz, sz, sz);

                    //printMatrix(resultant); //T*I

                    //insertToStack(resultant);
                    //showstack(s);

                } else if (command == "translate") {

                    //                input translation amounts
                    //                generate the corresponding translation matrix T
                    //                S.push(product(S.top,T))



                    //go to next line
                    i++;


                    cout << "do translate " << endl;
                    struct Point t;


                    //parsing values
                    t.x = stof(tokens[i][itr].c_str());
                    t.y = stof(tokens[i][itr + 1].c_str());
                    t.z = stof(tokens[i][itr + 2].c_str());


                    float (*T)[10] = new float[10][10];
                    T = makeTranslationMatrix(t.x, t.y, t.z);
                    //printMatrix(T);

                    float (*prev)[10];
                    float (*New)[10];
                    prev = s.top();
                    New = matrixMultiplication(prev, T, sz, sz, sz, sz);
                    s.push(New);

                    //float (*resultant)[10];

                    //resultant = matrixMultiplication(s.top(), T, sz, sz, sz, sz);

                    //printMatrix(resultant); //T*I

                    //insertToStack(resultant);
                    //showstack(s);


                } else if (command == "rotate") {
                    //            input rotation angle and axis
                    //            generate the corresponding rotation matrix T
                    //            S.push(product(S.top,T))
                    //
                    //go to next line
                    i++;


                    cout << "do rotate " << endl;
                    struct Vector rotateAxis;
                    float rotateAngle;


                    //parsing values
                    rotateAngle = stof(tokens[i][itr].c_str());
                    //rotateAngle = degToRad(rotateAngle);

                    rotateAxis.x = stof(tokens[i][itr + 1].c_str());
                    rotateAxis.y = stof(tokens[i][itr + 2].c_str());
                    rotateAxis.z = stof(tokens[i][itr + 3].c_str());

                    rotateAxis = normalize(rotateAxis);

                    Vector c1, c2, c3;


                    Vector iHat(1, 0, 0), jHat(0, 1, 0), kHat(0, 0, 1);


                    c1 = rotateRod(iHat, rotateAxis, rotateAngle);
                    c2 = rotateRod(jHat, rotateAxis, rotateAngle);
                    c3 = rotateRod(kHat, rotateAxis, rotateAngle);


                    float R[10][10];

                    vector<float> temp;
                    temp.push_back(c1.x);
                    temp.push_back(c2.x);
                    temp.push_back(c3.x);
                    temp.push_back(0);

                    temp.push_back(c1.y);
                    temp.push_back(c2.y);
                    temp.push_back(c3.y);
                    temp.push_back(0);

                    temp.push_back(c1.z);
                    temp.push_back(c2.z);
                    temp.push_back(c3.z);
                    temp.push_back(0);

                    temp.push_back(0);
                    temp.push_back(0);
                    temp.push_back(0);
                    temp.push_back(1);


                    for (int j = 0; j < sz; ++j) {

                        for (int k = 0; k < sz; ++k) {
                            R[j][k] = temp.at(j * 4 + k);
                        }
                    }

                    //printMatrix(R);

                    float (*prev)[10];
                    float (*New)[10];
                    prev = s.top();
                    New = matrixMultiplication(prev, R, sz, sz, sz, sz);
                    s.push(New);

                } else if (command == "push") {

                    cout << "PUSH" << endl;
                    Size.push(s.size());

                } else if (command == "pop") {


                    cout << "POP" << endl;
                    int l = Size.top();
                    while (s.size() != l) {
                        s.pop();
                    }
                }
            }
        }
    }
    infile.close();
}


void readFromStage1File() {
    // open a file in read mode.
    cout << "Reading from the stage1.txt file" << endl;

    string line;

    infile2.open("stage1.txt");
    cout << "here";
    if (!infile2.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }

    int line_num = 0;
    vector<string> tokens[200]; // Create vector to hold the words

    while (getline(infile2, line)) {


        string buf;                 // Have a buffer string
        stringstream ss(line);       // Insert the string into a stream

        while (ss >> buf)
            tokens[line_num].push_back(buf);

        line_num++;

    }



    //printing the file content as a 2d array
    for (int j = 0; j < line_num; ++j) {

        for (int i = 0; i < tokens[j].size(); ++i) {

            //cout << j << " : " << i << " " << tokens[j][i] << " \n";

        }
        // cout << endl;
    }

    Vector l(0, 0, 0), r(0, 0, 0), u(0, 0, 0);
    l = subtract(look, eye); //l = look - eye
    l = normalize(l); //l.normalize()
    r = crossProduct(l, up); //r = l X up
    r = normalize(r); // r.normalize()
    u = crossProduct(r, l); // u = r X l


    //Apply the following translation T to move the eye/camera to origin.
    float (*T)[10] = new float[10][10];

    T = makeIdentityMatrix2(sz);
    T[0][sz - 1] = -eye.x;
    T[1][sz - 1] = -eye.y;
    T[2][sz - 1] = -eye.z;
    T[3][sz - 1] = 1;



    //Apply the following rotation R such that the l aligns with the -Z axis, r with X axis, and u with Y axis.
    float (*R)[10] = new float[10][10];
    vector<float> temp = {r.x, r.y, r.z, 0, u.x, u.y, u.z, 0, -l.x, -l.y, -l.z, 0, 0, 0, 0, 1};

    for (int j = 0; j < sz; ++j) {

        for (int k = 0; k < sz; ++k) {
            R[j][k] = temp.at(j * 4 + k);
        }
    }


    float (*V)[10] = new float[10][10];
    V = matrixMultiplication(R, T, sz, sz, sz, sz);
    //printMatrix2(V);

    //V*matrix
    int itr = 0;
    for (int i = 0; i < line_num; i++) {

        if (tokens[i][itr] == "-") { i++; }
        if (tokens[i][itr] == "end") break;
        //input three points
        struct Point firstPoint, secondPoint, thirdPoint;


        firstPoint.x = stof(tokens[i][itr].c_str());
        firstPoint.y = stof(tokens[i][itr + 1].c_str());
        firstPoint.z = stof(tokens[i][itr + 2].c_str());


        i++;
        secondPoint.x = stof(tokens[i][itr].c_str());
        secondPoint.y = stof(tokens[i][itr + 1].c_str());
        secondPoint.z = stof(tokens[i][itr + 2].c_str());

        i++;
        thirdPoint.x = stof(tokens[i][itr].c_str());
        thirdPoint.y = stof(tokens[i][itr + 1].c_str());
        thirdPoint.z = stof(tokens[i][itr + 2].c_str());

        float myMatrix[10][10];

        vector<float> temp;
        temp.push_back(firstPoint.x);
        temp.push_back(secondPoint.x);
        temp.push_back(thirdPoint.x);
        temp.push_back(1);

        temp.push_back(firstPoint.y);
        temp.push_back(secondPoint.y);
        temp.push_back(thirdPoint.y);
        temp.push_back(1);

        temp.push_back(firstPoint.z);
        temp.push_back(secondPoint.z);
        temp.push_back(thirdPoint.z);
        temp.push_back(1);

        temp.push_back(1);
        temp.push_back(1);
        temp.push_back(1);
        temp.push_back(1);


        for (int j = 0; j < sz; ++j) {

            for (int k = 0; k < sz; ++k) {
                myMatrix[j][k] = temp.at(j * 4 + k);
            }
        }

        cout << "\t\tABOUT TO MULTIPLY THE FOLLOWING\n\n";
        print(V);
        cout << endl;
        print(myMatrix);
        cout << "\n\n";

        float (*resultant)[10];

        resultant = matrixMultiplication(V, myMatrix, sz, sz, sz, sz);

        printMatrix2(resultant); //T*I


    }
}

void readFromStage2File() {
    // open a file in read mode.
    cout << "Reading from the stage2.txt file" << endl;

    string line;

    infile3.open("stage2.txt");
    cout << "here2\n";
    if (!infile3.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }

    int line_num = 0;
    vector<string> tokens[200]; // Create vector to hold the words

    while (getline(infile3, line)) {


        string buf;                 // Have a buffer string
        stringstream ss(line);       // Insert the string into a stream

        while (ss >> buf)
            tokens[line_num].push_back(buf);

        line_num++;

    }



    //printing the file content as a 2d array
    for (int j = 0; j < line_num; ++j) {

        for (int i = 0; i < tokens[j].size(); ++i) {

            //cout << j << " : " << i << " " << tokens[j][i] << " \n";

        }
        // cout << endl;
    }

    float fovX = fovY * aspectRatio; //fovX = fovY * aspectRatio
    float t = near * Tan(fovY / 2); //t = near * tan(fovY/2)
    float div_r = near * Tan(fovX / 2); //r = near * tan(fovX/2)




    float (*P)[10] = new float[10][10];
    vector<float> temp = {near / div_r, 0, 0, 0, 0, near / t, 0, 0, 0, 0, (-(far + near) / (far - near)),
                          (-(2 * far * near) / (far - near)), 0, 0, -1, 0};

    for (int j = 0; j < sz; ++j) {

        for (int k = 0; k < sz; ++k) {
            P[j][k] = temp.at(j * 4 + k);
        }
    }

    print(P);

    //P*matrix
    int itr = 0;
    for (int i = 0; i < line_num; i++) {

        if (tokens[i][itr] == "-") { i++; }
        if (tokens[i][itr] == "end") break;
        //input three points
        struct Point firstPoint, secondPoint, thirdPoint;


        firstPoint.x = stof(tokens[i][itr].c_str());
        firstPoint.y = stof(tokens[i][itr + 1].c_str());
        firstPoint.z = stof(tokens[i][itr + 2].c_str());


        i++;
        secondPoint.x = stof(tokens[i][itr].c_str());
        secondPoint.y = stof(tokens[i][itr + 1].c_str());
        secondPoint.z = stof(tokens[i][itr + 2].c_str());

        i++;
        thirdPoint.x = stof(tokens[i][itr].c_str());
        thirdPoint.y = stof(tokens[i][itr + 1].c_str());
        thirdPoint.z = stof(tokens[i][itr + 2].c_str());

        float myMatrix[10][10];

        vector<float> temp;
        temp.push_back(firstPoint.x);
        temp.push_back(secondPoint.x);
        temp.push_back(thirdPoint.x);
        temp.push_back(1);

        temp.push_back(firstPoint.y);
        temp.push_back(secondPoint.y);
        temp.push_back(thirdPoint.y);
        temp.push_back(1);

        temp.push_back(firstPoint.z);
        temp.push_back(secondPoint.z);
        temp.push_back(thirdPoint.z);
        temp.push_back(1);

        temp.push_back(1);
        temp.push_back(1);
        temp.push_back(1);
        temp.push_back(1);


        for (int j = 0; j < sz; ++j) {

            for (int k = 0; k < sz; ++k) {
                myMatrix[j][k] = temp.at(j * 4 + k);
            }
        }

        cout << "\t\tABOUT TO MULTIPLY THE FOLLOWING\n\n";
        print(P);
        cout << endl;
        print(myMatrix);
        cout << "\n\n";

        float (*resultant)[10];

        resultant = matrixMultiplication(P, myMatrix, sz, sz, sz, sz);

        printMatrix3(resultant); //T*I


    }
}

int main() {

    float identity[10][10];
    float (*identityMatrix)[10] = makeIdentityMatrix(identity, sz);
    insertToStack(identityMatrix);

    outfile.open("stage1.txt");
    readFromFile();
    outfile << "end" << endl;
    outfile.close();

    outfile2.open("stage2.txt");
    readFromStage1File();
    outfile2 << "end" << endl;
    outfile2.close();

    outfile2.open("stage2.txt");
    readFromStage1File();
    outfile2 << "end" << endl;
    outfile2.close();

  */
/*  outfile3.open("stage2.txt");
    readFromStage2File();
    outfile3 << "end" << endl;
    outfile3.close();*//*


    return 0;
}

float
(*matrixMultiplication(float firstMatrix[][10], float secondMatrix[][10], int rowFirst,
                       int columnFirst,
                       int rowSecond, int columnSecond))[10] {

    float (*resultantMatrix)[10] = new float[10][10];
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
    return resultantMatrix;
}


float (*makeIdentityMatrix(float identity[][10], int identity_sz))[10] {

    int row, col;

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

    cout << "\nprinting the full stack\n\n";

    float (*temp)[10];
    stack<float (*)[10]> tempStack;

    tempStack = s;
    while (!tempStack.empty()) {

        temp = tempStack.top();
        printMatrix(temp);
        tempStack.pop();
    }

}

void insertToStack(float (*arr)[10]) {

    cout << "\n\ninserting to stack\n";

    s.push(arr);

    cout << "s.size() : " << s.size() << "\n\n";


}

float (*makeScalingMatrix(float scaleX, float scaleY, float scaleZ))[10] {

    float (*myMatrix)[10] = new float[10][10];

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {

            if (i == j && i == 0) myMatrix[i][j] = scaleX;
            else if (i == j && i == 1) myMatrix[i][j] = scaleY;
            else if (i == j && i == 2) myMatrix[i][j] = scaleZ;
            else if (i == j && i == 3) myMatrix[i][j] = 1;
            else
                myMatrix[i][j] = 0;

        }
    }
    return myMatrix;
}


float (*makeTranslationMatrix(float transX, float transY, float transZ))[10] {

    float (*myMatrix)[10] = new float[10][10];

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {

            if (i == j) {
                myMatrix[i][j] = 1;

            } else {
                if (i == 0 && j == 3) myMatrix[i][j] = transX;
                else if (i == 1 && j == 3) myMatrix[i][j] = transY;
                else if (i == 2 && j == 3) myMatrix[i][j] = transZ;
                else myMatrix[i][j] = 0;
            }

        }
    }
    return myMatrix;
}
*/
