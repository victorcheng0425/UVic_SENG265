#!/usr/bin/env python3

import sys

#read the file, put it in the list
def readfile(*args): #first arguement: list, second arguement: file
	for line in args[1]:
		line = line.strip()
		words = line.split(",") #read all the line to word
		args[0].extend(words) #add to the list

#THIS FUNCTION RETURN MAX_LENGTH
#extract word from input (compare with the exception file)
def extract_word(*args): #arguement #1st: exception, #2:input, #3:word  return max_length
	max_length = 0
	for (x, y) in enumerate(args[1]): # x=index, y=list
		temp = y.split(" ")
		if temp == ['']:
			continue
		for z in temp:
			if z.lower() not in args[0]: #turn word to lower case
				if(len(z) > max_length):
					max_length = len(z)
				temp1 = []
				temp1.append(z.upper()) #turn upper and put it in temp list
				temp1.append(x+1) #add the line number to temp list
				args[2].append(temp1) #add temp list to word(list)

	return max_length

#combine two word together if their line number is the same, add * afterward
def combine(*args): #arguement #1st word
	i = 0
	while(i < len(args[0])-1):
		j = i + 1
		while(j < len(args[0])):
			#if two word and line number are the same, combine it together and add "*" to list
			if(args[0][i][0] == args[0][j][0] and args[0][i][1] == args[0][j][1]):
				args[0].pop(j)
				if(len(args[0][i]) == 2):
					args[0][i].append('*')
			j = j + 1
		i = i + 1

def main():
	#create multiple list
	exception = []
	input = []
	word = []
	e_flag = 0
	max_length = 0
	if len(sys.argv) == 1:
		print("Not enough argument")
	#open file
	elif(sys.argv[1] == "-e"):
		f_exception = open(sys.argv[2], "r")
		f_input = open(sys.argv[3], "r")
		e_flag = 1    #set e_flag to one if -e was found
	elif(len(sys.argv) > 3):
		if(sys.argv[2] == "-e"):
			f_exception = open(sys.argv[3], "r")
			f_input = open(sys.argv[1], "r")
			e_flag = 1 #set e_flag to one if -e was found
	else: #if no -e was found, goes here
		f_input = open(sys.argv[1], "r")
		#readfile(input, f_input)
	if(e_flag is 1 and f_exception != None): #if -e found, check f_exception and read the file
		readfile(exception, f_exception)
	if(f_input != None):#check input file
		readfile(input, f_input)
	#get max_length from the function(extract_word)
	max_length = extract_word(exception, input, word)
	max_length += 2 #add two as required
	combine(word)
	word.sort(key=lambda x: (x[0], x[1])) #sort the word using lambda
	for x in word: 
		if (len(x) == 3):#print * if exist
			print("{}{}{} ({}{})".format(x[0], ' '*(max_length - len(x[0])), input[x[1]-1], x[1], x[2]))
		else:#dont print * if not exist
			print("{}{}{} ({})".format(x[0], ' '*(max_length - len(x[0])), input[x[1]-1], x[1]))
	if (e_flag is 1): #close the file
		f_exception.close()
	f_input.close()

if __name__ == "__main__":
	main()
