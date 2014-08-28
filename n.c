#include <stdio.h>
#include <math.h>

int main() {
    int i;
    int count = 0;
    while ( count != 10001 ) {
        i++;
        if ( is_prime( i )) {
            count++;
        }
    }
    printf( "%d\n", i ); 
    return 0;
}

int is_prime( int n ) {
    int d = 2;
    while (1) {
        if ( n % d == 0 ) {
            return 0;
        }
        if ( d < sqrt(n) ) {
            d++; 
        } else {
            return 1;
        }
    }
}


