#include <stdio.h>

int main() {

    int i;
    int j;
    int k;
    int triangle_num;

    for ( i = 0; i < 20000; i++ ) {
    //for ( i = 4471; i < 20000; i++ ) {
        k = generate_triangle_number( i ); 
        j = get_factor_count( k ); 

        printf( "%d : %d : %d\n", i, k, j ); 
        if ( j > 500 ) {
            printf( "FOUND!! "); 
            printf( "%d is divisible by > 500 numbers.\n", k ); 
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
