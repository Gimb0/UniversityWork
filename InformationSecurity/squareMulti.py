#!/usr/bin/env python3

in_str = input("Enter inputs as: a b mod n\n")
values = in_str.split(" ")
a = int(values[0], 2)
b = values[1]
b = list(str(b))
n = int(values[3], 2)
c = 0
d = 1
for i in b:
    c = c * 2
    d = (d*d) % n
    if int(i, 2) == 0b1:
        c = c + 1
        d = (d * a) % n

print("{0} = {1}".format(in_str, d))
