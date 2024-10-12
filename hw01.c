#include "myfunc.h"

int main(){

    int32_t i = 0, row = 0, col = 0, w_v = 0, x_v = 0, b_v = 0;
    
    printf("================================ Matrix W ================================\n");
    printf("Entering as the following rules: \n(1. The values must larger than 0. )\n");
    printf("(2. The format of input must be 'row' 'column' 'value', example: 5, 6, 8 )\n");
    printf("\nPlease enter 'total' rows, 'total' columns and 'total' values of matrix W: \n");
    printf("================================ Matrix W ================================\n");
    while(1){
        scanf("%d %d %d", &row, &col, &w_v);
        if(row < 0 || col < 0 || w_v < 0 || w_v>row*col || (w_v==0 && (row!=0 || col!=0))){
            printf("Wrong input, please enter again.\n");
            clear_buffer();
        }
        else{
            break;
        }
    }
    term W[w_v+2];
    W[i].row = row;
    W[i].col = col;
    W[i].value = w_v;

    printf("================================ Matrix W ================================\n");
    printf("Entering as the following rules: \n(1. The values must larger than 0. )\n");
    printf("(2. The format of input must be 'row' 'column' 'value', example: 5, 6, 8 )\n");
    printf("(3. The input order needs to follow the row major rule. )\n");
    printf("\nPlease enter row, column and value of matrix W: \n");
    printf("================================ Matrix W ================================\n");
    for(int i = 1 ; i<w_v+1 ; i++){
        scanf("%d %d %d", &W[i].row, &W[i].col, &W[i].value);
        // 除錯：row, col非負
        if (W[i].row < 0 || W[i].col < 0 || W[i].col > W[0].col-1 || W[i].row > W[0].row-1 || (W[i].row < W[i-1].row && i!=1) || W[i].value == 0 || (W[i].row == W[i-1].row && W[i].col < W[i-1].col)){
            printf("Wrong input, please enter reasonable inputs.\n");
            clear_buffer();
            if(i>0)    i--;
        }
    }
    
    printf("================================ Matrix X ================================\n");
    printf("Entering as the following rules: \n(1. The values must larger than 0. )\n");
    printf("(2. The format of input must be 'row' 'column' 'value', example: 5, 6, 8 )\n");
    printf("\nPlease enter 'total' rows, 'total' columns and 'total' values of matrix X: \n");
    printf("================================ Matrix X ================================\n");
    while(1){
        scanf("%d %d %d", &row, &col, &x_v);
        if( row != W[0].col || x_v>row*col || row<0 || col<0 || x_v<0 || (x_v==0 && (row!=0 || col!=0))){
            printf("Wrong input, please enter again.\n");
            clear_buffer();
        }
        else{
            break;
        }
    }
    term X[x_v+2];
    X[i].row = row;
    X[i].col = col;
    X[i].value = x_v;
    printf("================================ Matrix X ================================\n");
    printf("Entering as the following rules: \n(1. The values must larger than 0. )\n");
    printf("(2. The format of input must be 'row' 'column' 'value', example: 5, 6, 8 )\n");
    printf("(3. The input order needs to follow the row major rule. )\n");
    printf("\nPlease enter row, column and value of matrix X: \n");
    printf("================================ Matrix X ================================\n");
    for(int i = 1 ; i<x_v+1 ; i++){
        scanf("%d %d %d", &X[i].row, &X[i].col, &X[i].value);
        // 除錯：row非負
        if (X[i].row < 0 || X[i].col<0 || X[i].row > X[0].row-1 || (X[i].row < X[i-1].row && i!=1) || X[i].col > X[0].col-1 || X[i].value == 0 || (X[i].row == X[i-1].row && X[i].col < X[i-1].col)) {
            printf("Wrong input, please enter again.\n");
            clear_buffer();
            if(i>0)    i--;
        }   
    }
    
    printf("================================ Matrix B ================================\n");
    printf("Entering as the following rules: \n(1. The values must larger than 0. )\n");
    printf("(2. The format of input must be 'row' 'column' 'value', example: 5, 6, 8 )\n");
    printf("\nPlease enter 'total' rows, 'total' columns and 'total' values of matrix B: \n");
    printf("================================ Matrix B ================================\n");
    while(1){
        scanf("%d %d %d", &row, &col, &b_v);
        if( row != W[0].row || col != X[0].col || b_v>row*col || row<0 || col<0 || b_v<0 || (b_v==0 && (row!=0 || col!=0))){
            printf("Wrong input, please enter again.\n");
            clear_buffer();
        }
        else{
            break;
        }
    }
    term B[b_v+2];
    B[i].row = row;
    B[i].col = col;
    B[i].value = b_v;

    printf("================================ Matrix B ================================\n");
    printf("Entering as the following rules: \n(1. The values must larger than 0. )\n");
    printf("(2. The format of input must be 'row' 'column' 'value', example: 5, 6, 8 )\n");
    printf("(3. The input order needs to follow the row major rule. )\n");
    printf("\nPlease enter row, column and value of matrix B: \n");
    printf("================================ Matrix B ================================\n");
    for(int i = 1 ; i<b_v+1 ; i++){
        scanf("%d %d %d", &B[i].row, &B[i].col, &B[i].value);
        // 除錯：row非負
        if (B[i].row < 0 || B[i].row > B[0].row-1 || B[i].col < 0 || (B[i].row < B[i-1].row && i!=1) || B[i].col > B[0].col-1 || B[i].value == 0 || (B[i].row == B[i-1].row && B[i].col < B[i-1].col)) {
            printf("Wrong input, please enter again.\n");
            clear_buffer();
            if(i>0)    i--;
        }
    }
    
    term WX[W[0].row*X[0].col+1];
    term Z[W[0].row*X[0].col+1];
    int count_z = 0;

    for(int i = 0 ; i<W[0].row*X[0].col+1 ; i++){
        WX[i].row = 0;
        WX[i].col = 0;
        WX[i].value = 0;
        Z[i].row = 0;
        Z[i].col = 0;
        Z[i].value = 0;
    }

   
    mmult(W, X, WX);
    madd(WX, B, Z, &count_z);
    
    printf("================================= Result =================================\n");
    printf("The result W * X + B = \nrow  col  value\n");
    for(int i = 0 ; i<count_z+2 ; i++){
        if(Z[i].value != 0){//矩陣相加為0的值不存入
            printf("%-4d %-4d %-5d\n", Z[i].row, Z[i].col, Z[i].value);
        }
    }
    printf("================================= Result =================================\n");
    
    printf("============================== check values ==============================\n");
    int see = 0;
    while(1){
        printf("1. See specific row and column of the result matrix: (Press 1)\n2. Skip to the next step: (Press 2)\nPress: ");
        scanf("%d", &see);
        if(see != 1){
            break;
        }
        else{
            int s_row = 0, s_col = 0;
            printf("Entering as the following rules: \n(1. The format of input must be 'row' 'column', example: 5, 6 )\n");
            while(1){
                printf("\nSee values from specific row and column of the result matrix: ");
                scanf("%d %d", &s_row, &s_col);
                //除錯
                if(s_row>Z[0].row-1 || s_col>Z[0].col-1 || s_row<0 || s_col<0){
                    printf("Wrong input, please enter again.\n");
                    clear_buffer();
                }
                else{
                    break;
                }
            }
            printf("The value in row %d and column %d is: %d.\n", s_row, s_col, see_matrix_value(Z, s_row, s_col));
            printf("============================== check values ==============================\n");
        }
    }
    printf("=============================== other need ===============================\n");
    int num = 0;
    while(1){
        printf("1. Activation function for Z: ReLU(Press 1)\n2. Activation function for Z: Sigmoid (Press 2)\n3. No other needs (Press 3)\n");
        printf("Press: ");
        scanf("%d", &num);
        if(num == 1){
            relu(Z);
            printf("row col value\n");
            for(int i = 0 ; i<count_z+1 ; i++){
                printf("%2d %3d %4d\n", Z[i].row, Z[i].col, Z[i].value);
            }
        }
        else if(num == 2){
            sigmoid(Z);
            printf("row col value\n");
            for(int i = 0 ; i<count_z+1 ; i++){
                printf("%2d %3d %4d\n", Z[i].row, Z[i].col, Z[i].value);
            }
        }
        else if(num == 3){
            break;
        }
        else{
            printf("Wrong input, please enter again.\nPress: ");
            clear_buffer();
        }
    }
    printf("=============================== other need ===============================\n");


    return 0;
}