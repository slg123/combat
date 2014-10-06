#!/usr/bin/perl -w
use strict;

sub check_for_system_mem_below_512M {
    my $meminfo = '/proc/meminfo';
    my $memtotal;

    if ( open my $meminfo_fh, '<', $meminfo ) {
        while ( <$meminfo_fh> ) {
            if ( m/ \A MemTotal: \s+ (\d+) \s+ kB \s+ \z /xms ) {
                $memtotal = $1 / 1024;
                print $memtotal, "\n"; 
                last;
            }
        }
        close $meminfo_fh;
    }

    if ( $memtotal =~ /^(\d)\./ ) {
        $memtotal = $1;
        print $memtotal, "\n"; 
    }

    if ( $memtotal < 4096 ) {
        printf "This insane VMware server has less than 4GB physical memory! Better buy more and make the VMware fat cats even richer![ %.2f GB ]\n", $memtotal / 1024;
    }
}


check_for_system_mem_below_512M(); 
