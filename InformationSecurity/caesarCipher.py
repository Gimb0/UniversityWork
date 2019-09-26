#!/usr/local/bin/python3

alphabet = "abcdefghijklmnopqrstuvwxyziABCDEFGHIJKLMNOPQRSTUVWXYZ"

def encrypt():
    print("Enter string to shift: ")
    plainText = input()
    print("Enter key to shift by: ")
    key = int(input())
    while key < 1 or key > 25:
        print("Enter a number between 0 and 25")
        key = int(input())
    cipherText = ""
    for i in plainText:
        charIndex = alphabet.find(i)
        cipherText += alphabet[charIndex+key]
    print(cipherText)

def decrypt():
    print("Enter string to unshift: ")
    cipherText = input()
    print("Enter key to shift by: ")
    key = int(input())
    while key < 1 or key > 25:
        print("Enter a number between 0 and 25")
        key = int(input())
    plainText = ""
    for i in cipherText:
        charIndex = alphabet.find(i)
        plainText += alphabet[charIndex-key]
    print(plainText)

def main():
    print("Encrypt or Decrypt?")
    task = input()
    if task[0] == "E" or task[0] == "e":
        encrypt()
    elif task[0] == "D" or task[0] == "d":
        decrypt()
    else:
        print("Bad option...\nQuiting!")

if __name__ == "__main__":
    main()

