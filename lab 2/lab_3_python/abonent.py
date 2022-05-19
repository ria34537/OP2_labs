class Abonent:
    #class constructor
    def __init__(self, name, surname, patronymic, address, phone):
        self.__name = name
        self.__surname = surname
        self.__patronymic = patronymic
        self.__address = address
        self.__phone = phone

    #getters
    @property
    def name(self):
        return self.__name

    @property
    def surname(self):
        return self.__surname

    @property
    def patronymic(self):
        return self.__patronymic

    @property
    def address(self):
        return self.__address

    @property
    def phone(self):
        return self.__phone

    #setters
    @name.setter
    def name(self, value):
        self.__name = value

    @surname.setter
    def surname(self, value):
        self.__surname = value

    @patronymic.setter
    def patronymic(self, value):
        self.__patronymic = value

    @address.setter
    def address(self, value):
        self.__address = value

    @phone.setter
    def phone(self, value):
        self.__phone = value

    #function that counts sum ogf phone number digits
    def numbers_count(self):
        summ = 0
        for item in self.__phone:
            if item != "-":
                summ += int(item)
        return summ
