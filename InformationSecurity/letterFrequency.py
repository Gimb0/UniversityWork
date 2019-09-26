#!/usr/bin/env python3

from sys import argv
from string import ascii_lowercase

def main():
    filename = "test.txt"
    if(len(argv) > 2):
        for i in argv[1:]:
            letterFrequency(i)
    else:
        letterFrequency(filename)

def letterFrequency(filename):
    print("File {}".format(filename))
    with open(filename) as f:
        text = f.read().strip()
        dic = {}
        for c in ascii_lowercase:
            dic[c] = text.count(c)
        for i in dic:
            print("\t{0}: {1}".format(i, dic[i]))

if __name__ == "__main__":
    main()
