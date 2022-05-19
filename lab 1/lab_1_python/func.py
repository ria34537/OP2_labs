def text_input():
    print(
        'Press Enter for going to next line. If u want to end input, go to next line? press CtrlB and then Enter.'
        '\nEnter your input here:')
    ending_combination = 2 #Ctrl+B code
    input_lines = []
    line = " "
    while ord(line[0]) != ending_combination:
        line = input()
        input_lines.append(line)
        if line == "":
            line = " "
    return input_lines[:-1]


def result_text(lines, letter): #function which creates lins for iutput file
    result_lines = []
    for line in lines:
        result_lines.append(result_line(line, letter))
    return result_lines


def result_line(line, letter): #function which takes line and returns only words that start from given letter
    words = line.split()
    result = ""
    for word in words:
        if word[0] == letter:
            result += word + " "
    result = result[:-1]
    return result


def write_in_file(lines, filename, method):  #function which writes given lines to file
    f = open(filename, method)
    for line in lines[:-1]:
        f.write(line + "\n")
    f.write(lines[-1])
    f.close()


def read_file(filename):  #function which read lines from given file
    f = open(filename, "r")
    lines = []
    for line in f:
        lines.append(line)
    return lines


def print_file(filename):  #prints file
    lines = read_file(filename)
    for line in lines[:-1]:
        print(line[:-2])
    print(lines[-1])


def print_result(input_filename, output_filename): #function that prints results of doing code
    print("Here is your input text:")
    print_file(input_filename)
    print("Here is your output text:")
    print_file(output_filename)


def input_file_creating():
    print("Hello\n")
    print("Do you want write in empty file or add text?\nPrint w if you wanna write in empty file, print a if you "
          "wanna add text")
    method = input()
    while not ((method == 'w') or (method == "a")):
        print("a or w please")
        method = input()
    lines = text_input()
    write_in_file(lines, "input.txt", method)
    
    
    
def result_file_creating(input_filename, output_filename):
	print("Now please input first letter")  #asking user for letter
	letter = input()
	write_in_file(result_text(read_file(input_filename), letter), output_filename, "w") #writing in output file result text

