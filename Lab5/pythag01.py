#!/usr/bin/env python3
from math import *

def mah(*args):
	print(args[1])
	print(args[0])
	a = args[0]
	print(type(a))
	b = args[1]
	c = sqrt(a**2 + b**2)
	return c
	
	
def main():
	print("Lab5")
	print(mah(6,5))


if __name__ == "__main__":
	main()