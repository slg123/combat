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

// find a triangle number with more than 500 divisors...
int main( int argc, char *argv[] ) {

    int i, j, k, thread_id, nloops;
#pragma omp parallel private( thread_id, nloops )
    {    
        nloops = 0;
#pragma omp for
        for ( i = 1; i < 15000; i++ ) {
            if ( i % 1000 == 0 ) {
                printf( "current n -> %d\n", i ); 
            }
            //++nloops;
            j = generate_triangle_number( i );
            k = get_factor_count( j ); 
            if ( k > 500 ) {
                printf( "FOUND!! %d is divisible by more than 500 numbers.\n", j ); 
                exit(1); 
            }
            thread_id = omp_get_thread_num(); 
            //printf( "Thread %d performed %d iterations of the loop.\n", thread_id, nloops ); 
        }
    }
    return 0;
}
