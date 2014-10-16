#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
// gcc -fopenmp -o par par.c

int generate_triangle_number( int i ) {
    int j;
    int n = 0;
    #pragma omp parallel for
    for ( j = i; j > 0; j-- ) {
        n += j;
    }
    return n;
}

int get_factor_count( int n ) {
    int i;
    int count = 0;
    #pragma omp parallel for
    for ( i = 1; i <= n; i++ ) {
        if ( n % i == 0 ) {
            count++;
        }
    }
    return count;
}

int main() {
    int i, j, k, min;

    #pragma omp parallel for private(j)
    for ( i = 0; i < 15000; ++i ) {
    //for ( i = 12000; i < 13000; ++i ) {
        if ( i % 1000 == 0 ) {
            printf( "n -> %d\n", i ); 
        }
        j = generate_triangle_number( i );
        k = get_factor_count( j ); 
        if ( k > 500 ) {
            min = j; 
            if ( j < min ) {
                j = min; 
            }
        }
    }
    printf( "%d\n", min ); 
    return 0;
}
