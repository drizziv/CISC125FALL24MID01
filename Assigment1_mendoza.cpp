#include <iostream>
#include <string>

class Person{// this is the base class
  public:
    
    int age = 19; // declaring variables
    std::string name = "Ivan";
    
    void PrintInfo() const// creating a method that prints out a persons name and age
     {
       std::cout<< "name :" << name << ", Age:" << age << '\n';
     }
     };
class Student : public Person{// child class inherits from the parent class "person"
  
      public: double StudentId = 1133;// assigning variables
      std::string major = "compsci";
      

      void PrintStudentInfo() const{// the const ensures that this method should not change the student object
        PrintInfo();// call in the method from the person class
        std::cout<<"Student ID: " << StudentId << '\n';// outputing the students info
        std::cout<<"Student major: "<< major <<'\n';
        }
    };
    class Course{ // the course class is going to have some agregation
         
         public: Course(const Student& student) : student(student) {} // This constructor helps with agregation by assigning student as a refference of student.
         
          void CourseDetails() const { // Added 'const' to ensure this function does not modify the object.
          std::cout<<"Instructors name: " << instructorName << '\n';
          std::cout<<"Course name: "<< courseName << '\n';
          student.PrintStudentInfo();// this line calls the method from the student class to show students details in course context
          }
          private:    std::string courseName = "CISC";  
           const Student& student;
           std::string instructorName = "Sumanth";

    };



         int main(){ 
          Student student;// createda student object
          Course course(student); // Create course with a reference to a student
          course.CourseDetails();//  Called 'CourseDetails' to print course and student information.

      return 0;// terminates code

    }
    
         
