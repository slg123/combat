#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
// gcc -fopenmp -o par par.c

int generate_triangle_number( int i ) {
    int j;
    int n = 0;
    for ( j = i; j > 0; j-- ) {
        n += j;
    }
    return n;
}

int get_factor_count( int n ) {
    int i;
    int count = 0;
    for ( i = 1; i <= n; i++ ) {
        if ( n % i == 0 ) {
            count++;
        }
    }
    return count;
}

int main() {
    int i, j, k, lowest, curr_low;
    #pragma omp parallel for private(j)

    for ( i = 0; i < 15000; i++ ) {
        if ( i % 1000 == 0 ) {
            printf( "n -> %d\n", i ); 
        }
        j = generate_triangle_number( i );
        k = get_factor_count( j ); 
        if ( k > 500 ) {
            curr_low = j;
            lowest = curr_low; 
            if ( curr_low < lowest ) {
                lowest = curr_low;
            }
        }
    }
    printf( "%d\n", lowest ); 
    return 0;
}
