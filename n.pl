#!/usr/bin/perl

sub is_prime {
    my $n = shift;
    my $sqrt = sqrt( $n ); 
    my $d = 2;

    while (1) {
        return 0 if ( $n % $d == 0 );
        return 1 if ( $d > $sqrt );
        $d++;
    }
}

my ( $count, $i ) = 0;
while ( $count != 10001 ) {
    $i++;
    if ( is_prime( $i ) ) {
        $count++;
    }
}
print $i, "\n"; 
