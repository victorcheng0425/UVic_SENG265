#!/usr/bin/env python3
from math import *
import sys


		
def main():
	if len(sys.argv) > 1:
		for str in sys.argv:
			temp = str.split(",")
			for x in temp:
			 print (x)


if __name__ == "__main__":
	main()

