/****************************************************************
 * AUTHOR        : Zachary Norman & Shilong Zhang
 * ASSIGNMENT    : Lab 11
 * CLASS         : CS02
 * SECTION       : MTWH: 7:30-12:30
 * DUE DATE      : 1/29/19
 ****************************************************************/
#include <iostream>

using namespace std;
/****************************************************************
 * Lab 11
 * ______________________________________________________________
 * This program contains two exercises. Exercise one adds two
 * user-inputted matrices. Exercise two multiplies two user-
 * inputted matrices.
 * ______________________________________________________________
 * INPUT:
 *      m1          : Matrix A
 *      m2          : Matrix B
 * OUTPUT:
 *      ex1         : The sum of matrix A and matrix B
 *      ex2         : The product of matrix A and matrix B
 *
 ****************************************************************/


// GLOBAL VARIABLES
// These are the constants for the matrix sizes
const int N = 3, M = 2, Q = 2, R = 3, S = 3;

// PROTOTYPES
/****************************************************************
 * matrixAdd
 *  This function adds matrix a and matrix b and returns it to
 *  the sum matrix
 ****************************************************************/
void matrixAdd(const int a[][N],    // Matrix A
               const int b[][N],    // Matrix B
               int sum[][N]);       // The sum matrix to return

/****************************************************************
 * matrixMult
 *  This function multiplies matrix a by matrix b nd returns it
 *  to the product matrix
 ****************************************************************/
void matrixMult(const int a[][R],   // Matrix A
                const int b[][S],   // Matrix B
                int product[][S]);  // The product matrix to return


int main()
{
    {
        // VARIABLES
        int m1[M][N];   // Matrix A
        int m2[M][N];   // Matrix B
        int sum[M][N];  // The sum matrix

        // INPUT - receive matrix A from user
        cout << "Enter Matrix A(size 2x3): ";
        for(int i = 0; i < M; i++){
            for(int k = 0; k < N; k++){
                cin >> m1[i][k];
            }
        }
        cout << endl;

        // INPUT - receive matrix B from user
        cout << "Enter Matrix B(size 2x3): ";
        for(int i = 0; i < M; i++){
            for(int k = 0; k < N; k++){
                cin >> m2[i][k];
            }
        }
        cout << endl;

        // PROCESSING
        // Use matrixAdd to add matrix A and B and return to sum
        matrixAdd(m1, m2, sum);

        // OUTPUT - output the sum
        cout << "Res:" << endl;
        for(int i = 0; i < M; i++){
            for(int k = 0; k < N; k++){
                cout << sum[i][k] << " ";
            }
            cout << endl;
        }
    }
    {
        // EXERCISE 2
        // VARIABLES
        int m1[Q][R];      // Matrix A
        int m2[R][S];      // Matrix B
        int product[Q][S]; // The product matrix

        // INPUT - receive matrix A from user
        cout << "Enter Matrix A(size 2x3): ";
        for(int i = 0; i < Q; i++){
            for(int k = 0; k < R; k++){
                cin >> m1[i][k];
            }
        }
        cout << endl;

        // INPUT - receive matrix B from user
        cout << "Enter Matrix B(size 3x3): ";
        for(int i = 0; i < R; i++){
            for(int k = 0; k < S; k++){
                cin >> m2[i][k];
            }
        }
        cout << endl;

        // PROCESSING
        // INITIALIZE product matrix
        for(int i = 0; i < Q; i++){
            for(int k = 0; k < S; k++){
                product[i][k] = 0;
            }
        }
        // Use matrixMult to and return to product
        matrixMult(m1, m2, product);

        // OUTPUT - output the product
        cout << "Res:" << endl;
        for(int i = 0; i < Q; i++){
            for(int k = 0; k < S; k++){
                cout << product[i][k] << " ";
            }
            cout << endl;
        }

    }

    return 0;
}

void matrixMult(const int a[][R], const int b[][S], int product[][S]){
    // Use the given formula to find product (I switched k and j)
    for(int i = 0; i < Q; i++){
        for(int k = 0; k < S; k++){
            for(int j = 0; j < R; j++){ // Sigma part
                product[i][k] += a[i][j]*b[j][k];
            }
        }
    }
}

void matrixAdd(const int a[][N], const int b[][N], int sum[][N]){
    // Use the given formula to find the sum
    for(int i = 0; i < M; i++){
        for(int k = 0; k < N; k++){
            sum[i][k] = a[i][k] + b[i][k];
        }
    }
}
