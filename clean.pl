#!/usr/bin/perl

use strict;
use warnings;
use autodie;
use Socket;

my %seen_ips;
my $file = "/var/www/html/visitors.out";

open my $fh, "<", $file;
while ( <$fh> ) {
    next if /IP Addr/; 
    my ( $ip, $dash1, $count, $dash2, $dash3, $date ) = split " "; 
    my $host = gethostbyaddr( inet_aton( $ip ), AF_INET ); 
    if ( $count && $date && $host ) {    
        $seen_ips{ $ip }++ || printf( "%-17s -- %-8d -- %s] -- %s\n", $ip, $count, $date, $host ); 
    }
}

