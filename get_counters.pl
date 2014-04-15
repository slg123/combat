#!/usr/bin/perl

use strict;
use warnings;
use autodie;

my $os = `uname`;
chomp( our $date = `date '+%Y-%m-%d %H:%M:%S'` );  

sub get_linux_vmm_counters {
    my $file = "/proc/meminfo";
    my %counter_values = ();

    open my $fh, "<", $file;
    while ( <$fh> ) {
        chomp;
        my ( $name, $value, $junk ) = split ' ';
        $counter_values{ $name } = $value; 
    }
    close $fh;

    my $out = "/root/perl/linux_counters.csv";
    open my $ofh, ">>", $out;
    my @wanted_values = qw( MemTotal: MemFree: Buffers: SwapFree: Shmem: Slab: ); 
    while ( my ( $name, $value ) = each %counter_values ) {
        for ( @wanted_values ) {
            if ( $name =~ $_ ) {
                print $ofh "$date,$name,$value\n";
                printf "%s,%s,%s\n", $date, $name, $value;
            }
        }
    }
    close $ofh;
}

sub get_linux_cpu_counters {
    my $file = "/proc/stat";
    my $out  = "/root/perl/linux_counters.csv";
    open my $fh, "<", $file;
    open my $ofh, ">>", $out;
    while ( <$fh> ) {
        if ( /cpu/ ) {
            my ( $cpu, $f1, $f2, $f3, $f4, $f5, $f6, $f7, $f8, $f9 ) = split ' ', $_;
            print "$date,$cpu,$f1,$f2,$f3\n";   # example for now
            print $ofh "$date,$cpu,$f1,$f2,$f3\n";
        }
    }
    close $fh;
    close $ofh;
}

sub get_aix_vmm_counters {
}

sub get_aix_cpu_counters {
}

sub get_solaris_cpu_counters {
}

sub get_solaris_vmm_counters {
}

for ( my $i = 0; $i < 100; $i++ ) {
    if ( $os =~ "Linux" ) {
        get_linux_vmm_counters();
        get_linux_cpu_counters();
    }
    sleep( 10 );
}
