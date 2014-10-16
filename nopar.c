#include <stdio.h>
#include <stdlib.h>

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
    int i, j, k, min;
    min = 99999999; 

    for ( i = 0; i < 15000; ++i ) {
        if ( i % 1000 == 0 ) {
            printf( "n -> %d\n", i ); 
        }
        j = generate_triangle_number( i );
        k = get_factor_count( j ); 
        if ( k > 500 ) {
            printf( "%d has more than 500 divisors.\n", j ); 
            if ( j < min ) {
                min = j; 
            }
        }
    }
    printf( "%d\n", min ); 
    return 0;
}
