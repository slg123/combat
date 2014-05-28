#!/usr/bin/env python

file = open( 'web.log', 'r' )

ips = set()

def get_uniques():
    for line in file:
        column = line.split(' ')
        ip = column[0]
        ips.add( ip )

get_uniques()

def get_ip_count( address ):
    count = 0
    f = open( 'web.log', 'r' )
    for line in f:
        if address in line:
            count += 1
    return count

ip_last_dates = set()

def get_last_dates( date_count ):
    count = 0
    f = open( 'web.log', 'r' )
    for line in f:
        if address in line:
            count += 1
            if count == date_count:
                column = line.split(' ')
                date = column[2] + " " + column[3]
                return date

ip_counts = set()

for address in ips:
    ip_counts.add( get_ip_count( address ) )
    count = get_ip_count( address )
    print count
    ip_last_dates.add( get_last_dates( count ))

print ips
print ip_counts
print ip_last_dates

