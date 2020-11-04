#!/usr/bin/python3

import sys
import getopt


def gcd(p, q):
    "This func returns the value of p & q's greates common divisor"
    if q == 0:
        return p
    r = p % q
    return gcd(q, r)


def main(argv):
    if len(sys.argv) != 3:
        print("Usage: python gcd.py p q")
        return
    p = int(sys.argv[1])
    q = int(sys.argv[2])
    print(argv, gcd(p, q), sep=' ', end='\n')


if __name__ == "__main__":
    main(sys.argv)
