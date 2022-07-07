import pickle

def do_all():
    create_input_file("input.bin")
    with open("input.bin", "rb") as f:
        tasks = pickle.load(f)
    print("here are your tasks")
    printy(tasks)
    special_tasks = select(tasks)
    with open("output.bin", "wb") as f:
        pickle.dump(special_tasks, f)
    print("here are your tasks from 12:45 to 17:30")
    printy(special_tasks)
    free = free_time(tasks)
    print_free(free)


def create_input_file(name):
    file = open(name, 'wb')
    num = input('Enter number of things to add: ')
    while not num.isdigit():
        num = input('This should be a number: ')
    stuff = []
    for i in range(int(num)):
        thing = input_it()
        task = {
            "name": thing[0],
            "start": thing[1],
            "duration": thing[2]
        }
        stuff.append(task)
        stuff = sorted(stuff, key=func)
    pickle.dump(stuff, file)
    file.close()


def select(struct):
    result = []
    for item in struct:
        if item["start"][0]*60 + item["start"][1] >= 765 and item["start"][0]*60 + item["start"][1] + item["duration"] <= 1050:
            result.append(item)
    return result


def input_it():
    name = input('Enter name of stuff you should do: ')
    start_hours = input('Input start hours: ')
    while not start_hours.isdigit() or int(start_hours) > 23:
        start_hours = input('This should be a number < 23: ')
    start_minutes = (input('Input start minutes: '))
    while not start_minutes.isdigit() or int(start_minutes) >60 :
        start_minutes = input('This should be a number an <60: ')
    duration = input("input duration: ")
    while not duration.isdigit():
        duration = input('This should be a number: ')
    return name, [int(start_hours), int(start_minutes)], int(duration)


def free_time(lst_of_tasks):
    free = []
    for i in range(len(lst_of_tasks)-1):
        if func(lst_of_tasks[i]) + lst_of_tasks[i]["duration"] < func(lst_of_tasks[i+1]):
            free.append([func(lst_of_tasks[i]) + lst_of_tasks[i]["duration"], func(lst_of_tasks[i+1]), func(lst_of_tasks[i+1]) - func(lst_of_tasks[i]) + lst_of_tasks[i]["duration"]])

    return free

def print_free(free):
    print("here`s free time")
    for item in free:
        print(f"start time: {item[0]//60}:{item[0]%60}  end time: {item[1]//60}:{item[1]%60} duration {item[2]}   ")

def printy(struct):
    for item in struct:
        print("name: " + item["name"] + " start: " + str(item["start"][0]) +":"+ str(item["start"][1]) + " duration: " + str(item["duration"]))


def func(struct):
    return struct["start"][0]*60 + struct["start"][1]

