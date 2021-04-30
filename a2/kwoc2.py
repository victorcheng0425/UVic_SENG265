#!/usr/bin/env python3

import sys
def readfile(*args): #first arguement: list, second arguement: file
	for line in args[1]:
		line = line.strip()
		words = line.split(",") #read all the line to word
		args[0].extend(words)

def extract_word(*args): #1st: exception, #2:input, #3:word  return max_length
	max_length = 0
	for (x, y) in enumerate(args[1]): # x=index, y=list
		temp = y.split(" ")
		if temp == ['']:
			continue
		for z in temp:
			if z.lower() not in args[0]:
				if(len(z) > max_length):
					max_length = len(z)
				temp1 = []
				temp1.append(z.upper())
				temp1.append(x+1)
				#temp1 = z.upper() + '#' + str(x+1)
				args[2].append(temp1)

	return max_length

def combine(*args): #1st word
	i = 0
	while(i < len(args[0])-1):
		j = i + 1
		while(j < len(args[0])):
			if(args[0][i][0] == args[0][j][0] and args[0][i][1] == args[0][j][1]):
				args[0].pop(j)
				#args[0][i] = args[0][i] + '*'
				if(len(args[0][i]) == 2):
					args[0][i].append('*')
				#break
			j = j + 1
		i = i + 1
	"""
	for (i, x) in enumerate(args[0][:-1]):
		print("x: %s index: %d" %(x, i))##############################################
		for (index, y) in enumerate(args[0][i+1:]):
			print("y: %s index: %d" %(y, i+index+1))##############################################
			if(x==y):
				print("depulicate: %s, index: %d" %(y, i+index+1))######################
				args[0].pop(i+index+1)
				args[0][i] = args[0][i] + '*'
				print(args[0])
				break
		print("\n")
	"""


def main():
	exception = []
	input = []
	word = []
	e_flag = 0
	max_length = 0
	if len(sys.argv) == 1:
		print("Not enough argument")
	elif(sys.argv[1] == "-e"):
		#print("Found -e")###########################################################
		f_exception = open(sys.argv[2], "r")
		f_input = open(sys.argv[3], "r")
		e_flag = 1    ###########################################################
	elif(len(sys.argv) > 3):
		if(sys.argv[2] == "-e"):
			#print("-e in argv[2]")###########################################################
			f_exception = open(sys.argv[3], "r")
			f_input = open(sys.argv[1], "r")
			e_flag = 1
	else:
		f_input = open(sys.argv[1], "r")
		readfile(input, f_input)
	if(e_flag is 1):
		readfile(exception, f_exception)
	readfile(input, f_input)

	#print(exception)###########################################################
	#print(input)###########################################################
	max_length = extract_word(exception, input, word)
	max_length += 2 #add two
	#print(word)################################
	combine(word)
	#print(word)  ################################
	word.sort(key=lambda x: (x[0], x[1]))
	#print(word)################################
	for x in word: #######################################
		#print(x[0])
		#print(x[1])
		"""
		if(x[len(x)-1] == '*'):
			#print("%s %s(%c%c)" % (x[:-2], input[int(x[len(x)-2])-1], x[len(x)-2], x[len(x)-1]))
			print("{}{}{} ({}{})".format(x[:-2], ' '*(max_length - len(x)+2), input[int(x[len(x)-2])-1], x[len(x)-2], x[len(x)-1]))
		else:
			#print("%s %s(%c)" % (x[:-1], input[int(x[len(x)-1])-1], x[len(x) - 1]))
			print("{}{}{} ({})".format(x[:-1], ' '*(max_length - len(x)+1), input[int(x[len(x)-1])-1], x[len(x) - 1]))
		"""
		if (len(x) == 3):
			print("{}{}{} ({}{})".format(x[0], ' '*(max_length - len(x[0])), input[x[1]-1], x[1], x[2]))
		else:
			print("{}{}{} ({})".format(x[0], ' '*(max_length - len(x[0])), input[x[1]-1], x[1]))
	if (e_flag is 1):
		f_exception.close()
	f_input.close()

if __name__ == "__main__":
	main()
