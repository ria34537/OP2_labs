#include "functions.h"

using namespace std;


void createFile(string &name) {
    ofstream outFile(name, ios::binary | ios::out);
    cout << "input num of tasks ";
    int k;
    cin >> k;
    task stuff;
    cin.ignore();
    for (int i = 0; i < k; ++i) {
        cout << "input name of task ";
        cin >> stuff.name;
        cout << "input start hour of task ";
        cin >> stuff.start_hour;
        while (stuff.start_hour > 23){
            cout << "should be < 24" << endl;
            cin >> stuff.start_hour;
        }
        cout << "input start minutes of task ";
        cin >> stuff.start_minutes;
        while (stuff.start_minutes > 59){
            cout << "should be < 60" << endl;
            cin >> stuff.start_minutes;
        }
        cout << "input start duration of task ";
        cin >> stuff.duration;
        outFile.write((char *) &stuff, sizeof(task));
    }
    outFile.close();
}


bool comp(task a, task b) {
    return (a.start_hour * 60 + a.start_minutes < b.start_hour * 60 + b.start_minutes);
}

void outFile(string &name) {
    task tasks;
    ifstream inFile(name, ios::binary | ios::in);
    while (inFile.read((char *) &tasks, sizeof(task))) {
        cout << tasks.name << " " << tasks.start_hour << ":" << tasks.start_minutes << " duration: " << tasks.duration
             << endl;
    }
    inFile.close();
}

vector<task> get_vector(string &name) {
    vector<task> stuff;
    task tasks;
    ifstream inFile(name, ios::binary | ios::in);
    while (inFile.read((char *) &tasks, sizeof(task))) {
        stuff.push_back(tasks);
    }
    inFile.close();
    return stuff;
}

vector<task> select_from(vector<task> stuff) {
    vector<task> chosen;
    for (int i = 0; i < stuff.size(); ++i) {
        if ((stuff[i].start_hour * 60 + stuff[i].start_minutes > 765) &&
            (stuff[i].start_hour * 60 + stuff[i].start_minutes + stuff[i].duration < 1050)) {
            chosen.push_back(stuff[i]);
        }
    }
    return chosen;
}

void write_to_file(string &name, vector<task> stuff) {
    ofstream outFile(name, ios::binary | ios::out);
    for (int i = 0; i < stuff.size(); ++i) {
        outFile.write((char *) &stuff[i], sizeof(task));
    }
    outFile.close();
}

vector<freet> free_time(vector<task> stuff) {
    vector<freet> freetime;
    freet time;
    for (int i = 0; i < stuff.size() - 1; ++i) {
        time.start_hour = (stuff[i].start_hour * 60 + stuff[i].start_minutes + stuff[i].duration) / 60;
        time.start_minutes = (stuff[i].start_hour * 60 + stuff[i].start_minutes + stuff[i].duration) % 60;
        time.end_hour = stuff[i + 1].start_hour;
        time.end_minutes = stuff[i + 1].start_minutes;
        freetime.push_back(time);
    }

    return freetime;
}

void print_vector(vector<task> tasks) {
    for (int i = 0; i < tasks.size(); ++i) {
        cout << tasks[i].name << " " << tasks[i].start_hour << ":" << tasks[i].start_minutes << " duratiion: "
             << tasks[i].duration << endl;

    }
}

void print_vector(vector<freet> tasks) {
    int duration;
    cout << "free time:" << endl;
    for (int i = 0; i < tasks.size(); ++i) {
        duration =  tasks[i].end_hour*60 + tasks[i].end_minutes - tasks[i].start_hour*60 - tasks[i].start_minutes;
        cout << tasks[i].start_hour << ":" << tasks[i].start_minutes << "-" << tasks[i].end_hour << ":"
             << tasks[i].end_minutes << " duratiion: " << duration << endl;

    }
}