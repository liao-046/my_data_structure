#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int32_t row;
    int32_t col;
    int32_t value;
}term;

void fast_transpose(term a[], term b[]);
void mmult(term a[], term b[], term d[]);
void storesum(term d[], int *totald, int row, int column, int *sum);
int compare(int a, int b);
void madd(term a[], term b[], term s[], int *count_z);
void relu(term a[]);
void sigmoid(term a[]);
void clear_buffer();
int see_matrix_value(term a[], int row, int col);