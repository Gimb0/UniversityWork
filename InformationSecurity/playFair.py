#!/usr/bin/env python3

from sys import argv
from string import ascii_lowercase
from math import modf

def main():
    print("Playfair cipher program...")
    if(len(argv) > 1):
        if argv[1] == 'd':
            for arg in argv[2:]:
                playfairDecrypt(arg)
        elif argv[1] == 'e':
            for arg in argv[2:]:
                playfairEncrypt(arg)
    else:
        playfairEncrypt("playfaircipher")

def playfairEncrypt(plaintext):
    ciphertext = ""
    table = ['r', 'i', 's', 'k']
    for i in ascii_lowercase:
        if i == 'j':
            continue
        elif table.count(i) == 0:
            table.append(i)
    if (len(plaintext) % 2) == 1:
        plaintext += "x"
    for (a, b) in zip(plaintext[0::2], plaintext[1::2]):
        indexA = table.index(a)/5
        indexB = table.index(b)/5
        colA, rowA = modf(indexA)
        colB, rowB = modf(indexB)

        colA = int(round(colA * 5))
        colB = int(round(colB * 5))

        cipherColA = ''
        cipherRowA = ''
        cipherColB = ''
        cipherRowB = ''

        if rowA == rowB:
            cipherRowA = rowA
            cipherRowB = rowB
            if colA == 4:
                cipherColA = 0
            else:
                cipherColA = colA + 1
            if colB == 4:
                cipherColB = 0
            else:
                cipherColB = colB + 1
        elif colA == colB:
            cipherColA = colA
            cipherColB = colB
            if rowA == 4:
                cipherRowA = 0
            else:
                cipherRowA = rowA + 1
            if rowB == 4:
                cipherRowB = 0
            else:
                cipherRowB = rowB + 1
        else:
            cipherRowA = rowA
            cipherRowB = rowB
            cipherColA = colB
            cipherColB = colA

        cipherIndexA = (cipherRowA * 5) + cipherColA
        cipherIndexA = int(round(cipherIndexA))
        ciphertext += table[cipherIndexA]
        cipherIndexB = (cipherRowB * 5) + cipherColB
        cipherIndexB = int(round(cipherIndexB))
        ciphertext += table[cipherIndexB]

    print("Ciphertext is: {}".format(ciphertext))

def playfairDecrypt(ciphertext):
    plaintext = ""
    table = ['r', 'i', 's', 'k']
    for i in ascii_lowercase:
        if i == 'j':
            continue
        elif table.count(i) == 0:
            table.append(i)
    if (len(ciphertext) % 2) == 1:
        ciphertext += "x"
    for (a, b) in zip(ciphertext[0::2], ciphertext[1::2]):
        indexA = table.index(a)/5
        indexB = table.index(b)/5
        colA, rowA = modf(indexA)
        colB, rowB = modf(indexB)

        colA = int(round(colA * 5))
        colB = int(round(colB * 5))

        cipherColA = ''
        cipherRowA = ''
        cipherColB = ''
        cipherRowB = ''

        if rowA == rowB:
            cipherRowA = rowA
            cipherRowB = rowB
            if colA == 0:
                cipherColA = 4
            else:
                cipherColA = colA -1
            if colB == 0:
                cipherColB = 4
            else:
                cipherColB = colB - 1
        elif colA == colB:
            cipherColA = colA
            cipherColB = colB
            if rowA == 0:
                cipherRowA = 4
            else:
                cipherRowA = rowA - 1
            if rowB == 0:
                cipherRowB = 4
            else:
                cipherRowB = rowB - 1
        else:
            cipherRowA = rowA
            cipherRowB = rowB
            cipherColA = colB
            cipherColB = colA

        cipherIndexA = (cipherRowA * 5) + cipherColA
        cipherIndexA = int(round(cipherIndexA))
        plaintext += table[cipherIndexA]
        cipherIndexB = (cipherRowB * 5) + cipherColB
        cipherIndexB = int(round(cipherIndexB))
        plaintext += table[cipherIndexB]

    print("Plaintext is: {}".format(plaintext))

if __name__ == "__main__":
    main()
