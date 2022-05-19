#include "functions.h"

//reads lines from file
vector <string> read_from_file(string filename){
    ifstream file(filename);
    vector<string> lines;
    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

//function for text inputing
vector <string> text_input() {
    cout << "Press Enter for next line. If u wanna end input, go to next line, press Ctrl+B and then Enter." << endl;
    vector<string> lines;
    string line;
    cin.ignore();
    int end_of_text = 2;
    while (line[0] != end_of_text) {
        getline(cin, line);
        if (line == ""){
            line = " ";
        }
        lines.push_back(line);
    }
    lines.pop_back();
    return lines;

}

//creates input file
void create_input_file(string input_filename){
    string method;
    cout << "Do you want write in empty file or add text?\n Print w if you wanna write in empty file, print a if you wanna add text to existing file. \n";
    cin >> method;
    while (method != "w" and method != "a") {
        cout << " Enter 'w' or 'a'. \n";
        cin >> method;
    }
    vector <string> lines = text_input();
    write_to_file (lines, input_filename, method);
}

//creates output file
void create_output_file(string output_filename, string input_filename){
    char letter = input_letter();
    vector <string> result_text = result_text_from_text(letter, read_from_file(input_filename));
    write_to_file(result_text, output_filename, "w");

}

//inputs letter
char input_letter(){
    cout << "\nPlease input letter: "<<endl;
    char letter;
    cin >> letter;
    return letter;
}

//writes lines you have to your file
void write_to_file (vector <string> text, string filename, string method ){
    ofstream file;
    if (method == "w" ){
        file.open(filename);
    }
    else {
        file.open(filename, ios::app);
        file << '\n';
    }
    for (int i = 0; i < (text.size()); i++) {
        if (i == text.size() - 1) {
            file << text[i];
        }
        else {
            file << text[i] << "\n";
        }

    }
    file.close();
}

//makes result text for output file from input file
vector <string> result_text_from_text(char letter, vector <string> text){
    vector<string> result_text;
    string line;
    for (int i=0; i < text.size(); i++) {
        line = words_from_line(text[i], letter);
        result_text.push_back(line);
    }
    return result_text;
}


//deletes words from line which don`t start with given letter
string words_from_line (string line, char letter){
    string answer = "";
    int counter;
    int line_length = line.size();
    for (int i = 0; i < line_length; i++){
        if ((line[i] == letter) && (i==0 || (line[i-1] == ' ' ))){
            counter = i;
            while((counter != line_length) && (line[counter] != ' ') ){
                answer += line[counter];
                counter++;
            }
            answer += " ";
        }
    }
    return answer;
}

//prints file
void print_file(string filename){
    cout << filename << endl;
    vector <string> lines = read_from_file(filename);
    for (int i = 0; i<lines.size(); i++){
        cout << lines[i] << endl;
    }
}


