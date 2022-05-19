#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector <string> read_from_file(string filename);
string words_from_line (string line, char letter);
vector <string> result_text_from_text(char letter, vector <string> text);
void write_to_file (vector <string> text, string filename, string method );
vector <string> text_input();
void create_input_file(string input_filename);
void create_output_file(string output_filename, string input_filename);
void print_file(string filename);
char input_letter();

