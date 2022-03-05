#include<stdio.h>
#define SIZE 5

int main(){
      int A[ SIZE ] = { 1, 2, 3, 4, 5 }, B[ SIZE ], C[ SIZE ];
      copy_array( B, A, SIZE );
      copy_array_reverse( C, A, SIZE );
      print_array( A, SIZE );
      print_array( B, SIZE );
      print_array( C, SIZE );
}
void copy_array( int dest[], int source[], int size ){
    int i;
    for( i = 0; i < size; i++ ) dest[ i ] = source[ i ];
}
void copy_array_reverse( int dest[], int source[], int size ){
    int i, j = size - 1;
    for( i = 0; i < size; i++, j-- ) dest[ j ] = source[ i ];
}
void print_array( int A[], int size ){
    int i;
    for( i = 0; i < size; i++ ){
        printf( "%d ", A[ i ] );
    }
    printf( "\n\n\n" );
}
