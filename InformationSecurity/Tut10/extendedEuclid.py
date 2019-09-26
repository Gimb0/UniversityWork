#!/usr/bin/env python3

# Greatest Common Divisor function
def gcd(n, a):
    q = int(n / a)
    r = n % a 
    while r > 1:
        n = q
        a = r
        q = int(n / a)
        r = n % a
    return r

# Get correct input
a = int(input("Enter a: "))
n = int(input("Enter n: "))
while a > n:
    print("a should be less than n")
    a = int(input("Enter a: "))
    n = int(input("Enter n: "))

# Test if there is a multiplicative inverse
if gcd(n, a) == 0:
    print("No multiplicative inverse")
    # exit()

# Extended GCD algorithm
A1 = 1
A2 = 0
A3 = n
B1 = 0
B2 = 1
B3 = a

while B3 > 1:
    Q = int(A3 / B3)
    T1 = A1 - (Q * B1)
    T2 = A2 - (Q * B2)
    T3 = A3 - (Q * B3)
    A1 = B1
    A2 = B2
    A3 = B3
    B1 = T1
    B2 = T2
    B3 = T3

if B3 == 1:
    if B2 < 0:
        B2 = n + B2
    print("Inverse of {0} mod {1} is {2}".format(a, n, B2))
if B3 == 0:
    print("No inverse. A3 = {}".format(A3))
