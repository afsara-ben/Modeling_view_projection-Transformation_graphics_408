/*
//
// Created by afsara on 7/11/19.
//

#include <iostream>

float (*identityMatrix(float identity[][2], int identity_sz))[2]{

    std::cout << "Here\n";

    for(int i = 0 ; i < identity_sz ; i++){
        for(int j = 0 ; j < identity_sz ; j++){
            std::cout << identity[i][j] << " ";
        }
        std::cout << "\n";
    }

    return identity;
}

int main(int argc, char const *argv[])
{
    */
/*float f[][2] = {
            {1,2},
            {3,4}
    };*//*


    float f[2][2];
    float (*ff)[2] = identityMatrix(f,2);

   */
/* for(int i = 0 ; i < sizeof(ff)/sizeof(ff[0][0]) ; i++){
        for(int j = 0 ; j < 2 ; j++){
            std::cout << ff[i][j] << " ";
        }
        std::cout << "\n";
    }
*//*

    return 0;
}
*/
