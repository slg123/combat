#!/usr/bin/perl

use strict;
use warnings;
use autodie;

my %seen_ips;

my $file = "/var/www/html/visitors.out";

print "<html>\n";
print "<pre>\n";

open my $fh, "<", $file;
while ( <$fh> ) {
    next if /IP Addr/; 
    my ( $ip, $dash1, $count, $dash2, $dash3, $date ) = split " "; 
    my $nslookup = "nslookup $ip | grep name | awk '{ print \$4 }'";
    my $host = `$nslookup`; 
    chomp $host;
    $host =~ s/(=||\R)//g;               
    $host = substr $host, 0, -1;

    if ( $count && $date && $host ) {
        $seen_ips{ $ip }++ || printf( "%-17s -- %-8d -- %s] hostname: %s\n", $ip, $count, $date, $host ); 
    }
}

print "</pre>\n";
print "</html>\n"; 
