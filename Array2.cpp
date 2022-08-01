#include <iostream>
using namespace std;

int arrA[3][3] = {
    {1, 5, 0},
    {0, 4, 1},
    {3, 6, 5}
};

int arrB[3][3] = {
    {6, 4, 1},
    {-1, 5, 1},
    {-2, -4, 0}
};

int arrC[3][3];
int main(void){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                arrC[i][j] = arrA[i][j] * arrB[j][i];
            }
        }
    }

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", arrC[i][j]);
        }
        cout << endl;
    }
}