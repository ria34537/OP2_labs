#include <iostream>
#include "functions.h"

int main(){
    string input_filename = "input.txt";
    string output_filename = "output.txt";
    create_input_file(input_filename);
    create_output_file(output_filename, input_filename);
    print_file(input_filename);
    print_file(output_filename);
}

