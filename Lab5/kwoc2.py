#!/usr/bin/env python3
import sys

















def main():
    print("TEST")
    if len(argv)<2:
        print("Not evought argument")
        sys.exit()
    if(argv[1] is "-e"):
        print("Found -e")
    else if(argv[2] is "-e"):
        print("-e in argv[2]")
        
        
        
if __name__ == "__main__":
	main()