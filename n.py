#!/usr/bin/python

import math

def is_prime( n ):
    d = 2
    while 1:
        if n % d == 0:
            return 0
        if d < math.sqrt( n ):
            d = d+1
        else:
            return 1

count = 0
i = 0
while count != 10001:
    i = i+1
    if is_prime( i ):
        count = count+1

print i
