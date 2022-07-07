
#include "functions.h"
int main()
{
    string inputname = "input.bin";
    string outname = "result.bin";
    createFile(inputname);
    cout << "here`s input file" << endl;
    outFile(inputname);
    vector <task> stuff = get_vector(inputname);
    sort(stuff.begin(), stuff.end(), comp);
    vector <task> selected = select_from(stuff);
    write_to_file(outname, selected);
    cout << "here`s result file" << endl;
    outFile(outname);
    vector <freet> free = free_time(stuff);
    print_vector(free);



    return 0;
}
