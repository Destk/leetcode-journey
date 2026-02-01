#include <iostream>

using namespace std;

bool checkNumbers(int matrix[][10], int N){
int count[101] = {0};
for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
        int num = matrix[i][j];
        if((num > 0) && (num <= N*N)){
            count[num]++;
        }else{
            return false;
        }
    }
}
for(int num = 1; num <= N*N; num++) {
    if(count[num] != 1) {  
        return false;  
    }
}
return true; 
}


int calculateMagicSum(int matrix[][10], int N){
    int magicsum{0};

    for(int j = 0; j < N; j++){
        magicsum += matrix[0][j];
    }
    

    for(int i = 1; i < N; i++){
        int sumstroka{0};
        for(int j = 0; j < N; j++){
            sumstroka += matrix[i][j];
        }
        if(sumstroka != magicsum){
            return -1;
        }
    }

    for(int i = 0; i < N; i++){
        int sumstolbik{0};
        for(int j = 0; j < N; j++){
            sumstolbik += matrix[j][i];
        }
        if(sumstolbik != magicsum){
            return -1;
        }
    }

    int sumdiagonal1{0};
    for(int i = 0; i < N; i++){
        sumdiagonal1 += matrix[i][i];
        }
        if(sumdiagonal1 != magicsum){
            return -1;
        }

    int sumdiagonal2{0};
    for(int i = 0; i < N; i++){
        sumdiagonal2 += matrix[i][N-1-i];
    }
    if(sumdiagonal2 != magicsum){
        return -1;
        }
    return magicsum;
}



bool isMagicSquare(int matrix[][10], int N){
    if (checkNumbers(matrix, N) && calculateMagicSum(matrix, N) != -1){
        return true;
    }else{
        return false;
    }
}


void printMatrix(int matrix[][10], int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matrix[i][j] << " "; 
        }
        cout << endl;
    }
}

int main(){
    char stop{};
    int N;
    int matrix[10][10];
    cout << " Введите размер матрицы N × N: " << endl;
    cin >> N;    
    cout << " Введите введите матрицу " << N << " × " << N << endl;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }
    cout << endl;
    printMatrix(matrix, N);
    cout << endl;
    cout << "Магическая сумма равна " << calculateMagicSum(matrix, N);
    cout << endl;
    if (isMagicSquare(matrix, N)){
        cout << "Это магический квадрат!\n";
    }else{
         cout << "Это не магический квадрат\n";
    }
    return 0;
 }