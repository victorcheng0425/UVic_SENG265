#!/usr/bin/env python3
from math import *
import sys

def mah(*args):
	print(args[1])
	print(args[0])
	a = int(args[0])
	print(type(a))
	b = int(args[1])
	c = sqrt(a**2 + b**2)
	return c
		
def main():
	if len(sys.argv) == 3:
		a = sys.argv[1]
		b = sys.argv[2]
		print(mah(a,b))


if __name__ == "__main__":
	main()
