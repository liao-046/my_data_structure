#include "myfunc.h"

void fast_transpose(term a[], term b[]){
    /*the tanspose of a is placed in b*/
    int row_term[a[0].col], start_pos[a[0].col+10], j = 0;
    int num_col = a[0].col, num_row = a[0].row, num_term = a[0].value;
    b[0].row = num_col;
    b[0].col = num_row;
    b[0].value = num_term;

    if(num_term > 0){
        for(int i = 0 ; i<num_col ; i++){
            row_term[i] = 0;
        }
        for(int i = 1 ; i<=num_term ; i++){
            row_term[a[i].col]++;
        }
        start_pos[0] = 1;
        for(int i = 1 ; i<num_col ; i++){
            start_pos[i] = start_pos[i-1] + row_term[i-1];
        }
        for(int i = 1; i<=num_term ; i++){
            j = start_pos[a[i].col];
            b[j].row = a[i].col;
            b[j].col = a[i].row;
            b[j].value = a[i].value;
            start_pos[a[i].col]++;
        }
    }
}

void mmult(term a[], term b[], term d[]){
    /*multiply two sparse matrices. */
    int i = 0, j = 0, column =0, totalb = b[0].value, totald = 0;
    int row_a = a[0].row, col_a = a[0].col, totala = a[0].value, col_b = b[0].col, row_b = b[0].row; 
    int row_begin = 1, row = a[1].row, sum = 0;
    term new_b[b[0].value+1];
    if(col_a != b[0].row){
        printf("Incompatible matrices.\n");
        exit(1);
    }

    fast_transpose(b, new_b);
    for(int i = 0 ; i<b[0].value+1 ; i++){
    }

    /*set boundary condition*/
    a[totala+1].row = row_a;
    new_b[totalb+1].row = col_b;
    new_b[totalb+1].col = row_b;

    for(int i = 1 ; i<=totala; ){
        column = new_b[1].row;// 當前的column b
        for(int j = 1 ; j<=totalb+1 ; ){
            if(a[i].row != row){
                storesum(d, &totald, row, column, &sum);
                i = row_begin;
                for( ; new_b[j].row == column ; j++);
                column = new_b[j].row;
            }
            else if(new_b[j].row != column){
                storesum(d, &totald, row, column, &sum);
                i = row_begin;
                column = new_b[j].row;
            }
            else switch(compare(a[i].col, new_b[j].col)){//a matrix和b matrix都未結束
                case -1: // a<b, a已做完，跳下一項 
                    i++;
                    break;
                case 0:
                    sum +=(a[i++].value * new_b[j++].value);
                    break;
                case 1: // a>b, b已做完，跳下一項 
                    j++;
            }
        }
        for( ; a[i].row==row ; i++);
        row_begin = i;
        row = a[i].row;
    }
    d[0].row = row_a;
    d[0].col = col_b;
    d[0].value = totald;

}

void storesum(term d[], int *totald, int row, int column, int *sum){
    if(*sum != 0){
        (*totald)++;
        d[*totald].row = row;
        d[*totald].col = column;
        d[*totald].value = *sum;
        *sum = 0;
    }
}

int compare(int a, int b){
    if(a < b){
        return -1;
    }
    else if(a == b){
        return 0;
    }
    else{
        return 1;
    }
}

void madd(term a[], term b[], term s[], int *count_z){
    int count_b = 1, count_s = 0, temp_r = 0, temp_c = 0, temp_v = 0;

    if(a[0].row != b[0].row || a[0].col != b[0].col){
        printf("Incompatible matrices.\n");
        exit(1);
    }

    for(int i = 0 ; i<a[0].value+1 ; i++){
        s[count_s].row = a[i].row;
        s[count_s].col = a[i].col;
        s[count_s].value = a[i].value;
        count_s++;        
    }
    for(int i = 1 ; i<b[0].value+1 ; i++){
        int found = 0;
        for(int j = 1 ; j<a[0].value+1 ; j++){
            if(b[i].row == a[j].row && b[i].col == a[j].col){
                s[j].value += b[i].value;
                b[i].value = 0;
                found = 1;
                break;
            }
        }
        if(!found){//都沒有一樣的
            s[count_s].row = b[i].row;
            s[count_s].col = b[i].col;
            s[count_s].value = b[i].value;
            count_s++;
        }
    }

    for(int i = 1 ; i<count_s+1 ; i++){//改為row major
        for(int j = i ; j<count_s+1 ; j++){
            if(s[i].row > s[j].row || (s[i].row == s[j].row && s[i].col > s[j].col)){
                //swap row
                temp_r = s[i].row;
                s[i].row = s[j].row;
                s[j].row = temp_r;
                //swap column
                temp_c = s[i].col;
                s[i].col = s[j].col;
                s[j].col = temp_c;
                //swap value
                temp_v = s[i].value;
                s[i].value = s[j].value;
                s[j].value = temp_v;
            }
        }
    }
    for(int i = 1 ; i<count_s+1 ; i++){
        if(s[i].value != 0){
            (*count_z)++;
        }
    }
    s[0].value = *count_z;
    printf("%d\n", *count_z);
}

void relu(term a[]){
    for (int i = 1 ; i < a[0].value+1 ; i++) {
        a[i].value = fmax(0, a[i].value);
    }
}

void sigmoid(term a[]){
    for (int i = 1; i < a[0].value+1 ; i++) {
        a[i].value = 1.0 / (1.0 + exp((-1.0)*(double)a[i].value));
    }
}

void clear_buffer(){
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF);
}

int see_matrix_value(term a[], int row, int col){
    for(int i = 1 ; i<a[0].value+1 ; i++){
        if(row == a[i].row && col == a[i].col){
            return a[i].value;
        }
    }
    return 0;
}