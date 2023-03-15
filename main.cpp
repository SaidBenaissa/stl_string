#include <iostream>
#include <string>
#include <vector>

class Person {
private:
    std::string _name;
    int _age;
public:
    Person(const std::string& name, int age) : _name(name), _age(age) {
        std::cout << "Person constructor called" << std::endl;
    }
    void introduce() const {
        std::cout << "Hi, my name is " << _name << " and I am " << _age << " years old." << std::endl;
    }

    // Getters
    std::string getName() const { return _name; }
    int getAge() const { return _age; }

    // Setters
    void setName(const std::string& name) { _name = name; }
    void setAge(int age) { _age = age; }

    // Destructor
    virtual ~Person() {
        std::cout << "Person destructor called" << std::endl;
    };

    // print method
    virtual void print() const {
        std::cout << "Name: " << _name << ", Age: " << _age << std::endl;
    }
};

class Student : public Person {
private:
    std::string _major;
public:
    // Constructor
    Student(const std::string& name, int age, const std::string& major) : Person(name, age), _major(major) {
        std::cout << "Student constructor called" << std::endl;
    }

    // Getters
    std::string getMajor() const { return _major; }

    // Setters
    void setMajor(const std::string& major) { _major = major; }

    // Destructor
    virtual ~Student() {
        std::cout << "Student destructor called" << std::endl;
    };

    // print method override
    virtual void print() const override {
        std::cout << "Name: " << getName() << ", Age: " << getAge() << ", Major: " << _major << std::endl;
    }
};

int main() {
    std::vector<Person*> people = {
        new Person("Mike", 40),
        new Student("Sue", 20, "Math")
    };

    for (const auto& person : people) {
        person->print();
    }

    for (const auto& person : people) {
        delete person;
    }



    return 0;
}
