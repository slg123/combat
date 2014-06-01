#!/usr/bin/env python

weblog = '/var/log/httpd/access_log'
file = open( weblog, 'r' )

ips = set()

#
# build a set of unique IP addresses
#
def get_unique_ips():
    for line in file:
        column = line.split(' ')
        ip = column[0]
        ips.add( ip )

get_unique_ips()

#
# get a count of how many times the IP shows up in the logfile
#
def get_ip_count( address ):
    count = 0
    f = open( weblog, 'r' )
    for line in f:
        if address in line:
            count += 1
    return count

ip_last_dates = set()

#
# get the last date string from the visiting IP address
#
def get_last_dates( date_count ):
    count = 0
    f = open( weblog, 'r' )
    for line in f:
        if address in line:
            count += 1
            if count == date_count:
                column = line.split(' ')
                date = column[2] + " " + column[3] + " " + column[4]
                return date

ip_counts = set()

for address in ips:
    ip_counts.add( get_ip_count( address ) )
    count = get_ip_count( address )
    ip_last_dates.add( get_last_dates( count ))

logs = set()

for date in ip_last_dates:
    f = open( weblog, 'r' )
    for line in f:
        column = line.split(' ')
        ip = column[0]
        ip_count = get_ip_count( ip )
        str_ip_count = str( ip_count )
        if date in line:
            log = ip + " --  " + str_ip_count + " --  " + column[2] + " " + column[3] + " " + column[4] 
            logs.add( log.rstrip() )

for entry in logs:
    print entry

