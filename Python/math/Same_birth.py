from math import *

n = int(input("N = "))

Pn = 1 - factorial(365) / (365**n * factorial(365-n))
print("P = ", Pn)