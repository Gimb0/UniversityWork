#!/usr/bin/env python3

from sys import argv

# a = n(q) + r
def euclidianAlg(a1, n1):
    n = int(n1)
    a = int(a1)
    r = n%a
    r2 = r
    q = int(n/a)
    while(r > 1):
        print("{0} = {1} x {2} + {3}".format(n, a, q, r))
        n = a
        a = r
        r2 = r
        r = n%a
    print("{0} = {1} x {2} + {3}".format(n, a, q, r))
    if r == 0:
        if int(n1)%int(a1) == 0:
            print("{0} is the gcd of {0} and {1}".format(a1, n1))
        else:
            print("Greatest common divisor if {0}".format(r2))
    elif r == 1:
        print("GCD = 1\n{0} and {1} are co-prime.".format(n1, a1))


# Get input from user in form a mod x
def main():
    print("Euclidian algorithm")
    if len(argv) == 3:
        euclidianAlg(argv[1], argv[2])
    else:
        usrInput = input("Enter equation in format a and n:")
        eq = usrInput.split(" ")
        euclidianAlg(eq[0], eq[1])
    
if __name__ == "__main__":
    main()
