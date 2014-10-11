#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[] ) {

    int i;
    int j;
    int k;
    int triangle_num;

    if ( argc != 3 ) {
        fprintf( stderr, "usage: %s <start> <end>\n", argv[0] ); 
        fprintf( stderr, "   ex: %s 12373 12376\n",   argv[0] ); 
        exit( EXIT_FAILURE ); 
    }

    int start = atoi( argv[1] ); 
    int end   = atoi( argv[2] ); 

    for ( i = start; i < end; i++ ) {
        k = generate_triangle_number( i ); 
        j = get_factor_count( k ); 

        printf( "%d : %d : %d\n", i, k, j ); 
        if ( j > 500 ) {
            printf( "FOUND!! -> %d is divisible by more than 500 numbers.\n", k ); 
            break;
        }
    }
    return 0;
}

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
