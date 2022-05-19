from abonent import Abonent

#creating an object
def object_create():
    print("Please, input name:")
    name = input()
    print("Please, input surname:")
    surname = input()
    print("Please, input patronymic:")
    patronymic = input()
    print("Pleas, input address:")
    address = input()
    print("Pleas, input phone in format XXX-XXX-XX-XX:")
    phone = input()
    while not phone_correctness(phone):
        print("please input normal phone:")
        phone = input()
    object = Abonent(name, surname, patronymic, address, phone)
    return object


#checking if input of phone number is valid
def phone_correctness(phone):
    length = len(phone)
    if length != 13:
        return 0
    counter = 0
    for i in range(length):
        if ((i == 3) or (i == 7) or (i == 10)) and (phone[i] != "-"):
            counter += 1
        if ((i != 3) and (i != 7) and (i != 10)) and (not phone[i].isdigit()):
            counter += 1
    if counter != 0:
        return 0
    else:
        return 1


#creating a list of persons
def list_of_abonents():
    print("Hello, how many abonents do you wanna create?")
    num = int(input())
    abonent_lst = []
    for i in range (num):
        abonent_lst.append(object_create())
    return abonent_lst


#finding a person with max sum of phone digits (or persons if their sums is equal)
def max_phone(lst):
    index = 0
    max_lst = []
    for i in range(len(lst)):
        if lst[i].numbers_count() > lst[index].numbers_count():
            index = i
    for item in lst:
        if item.numbers_count() == lst[index].numbers_count():
            max_lst.append(item)
    return max_lst


#printing abonents and persons with maximum sum of phone digits
def print_result(list_of_persons, list_of_max_phone):
    print("\nHere is all abonents you had inputed:")
    for person in list_of_persons:
        print(f"\n{person.name} {person.surname} {person.patronymic} \n{person.address}\n{person.phone}\n")
    print("\nPerson(s) with the biggest sum of phone numbers:")
    for person in list_of_max_phone:
        print(f"\n{person.name} {person.surname} {person.patronymic} \n{person.address}\n{person.phone}\nsum of phone "
              f"digits: {person.numbers_count()}")

