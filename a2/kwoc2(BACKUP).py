#!/usr/bin/env python3

import sys

def main():
    print("TEST")
    if len(sys.argv) == 1:
        print("Not enought argument")
        #sys.exit()
    elif(sys.argv[1] == "-e"):
        print("Found -e")
    elif(sys.argv[2] == "-e"):
        print("-e in argv[2]")
        
        
        
if __name__ == "__main__":
    main()
    
