
#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes
    void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
    void updateGPA(double* gpaPtr, double newGpa);
    void printStudent(const char* name, const double& gpa);
    double averageGPA(const double gpas[], int size);

// TODO: implement addStudent
    void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
        if(size == capacity){
            throw("List full");
        }
        names[size] = name;
        gpas[size] = gpa;
        size++;
    }

// TODO: implement updateGPA
    void updateGPA(double* gpaPtr, double newGpa){
        if(gpaPtr != nullptr) *gpaPtr = newGpa;
    }

// TODO: implement printStudent
    void printStudent(const char* name, const double& gpa){
        std::cout << name << ", " << gpa;
    }

// TODO: implement averageGPA
    double averageGPA(const double gpas[], int size){
        if(size == 0) throw ("No students");
        double avg = 0.0;
        for(int i = 0; i < size; i++){
            avg += gpas[i];
        }
        return avg/size;
    }

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                try{
                    char* name = new char[100];
                    double gpa;
                    std::cout << "Enter name: ";
                    std::cin >> name;
                    std::cout << "Enter GPA: ";
                    std::cin >> gpa;
                    addStudent(name, gpa, names, gpas, size, capacity);
                    break;
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 2: {
                // TODO: implement menu logic
                int idx;
                double newGPA;
                std::cout << "Enter index to update: ";
                std::cin >> idx;
                std::cout << "Enter new GPA: ";
                std::cin >> newGPA;
                updateGPA(&gpas[idx], newGPA);
                break;
            }
            case 3: {
                // TODO: implement menu logic
                if(size == 0) std::cout << "No students\n";
                for(int i = 0; i < size; i++){
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try{
                    std::cout << "Average GPA: " << averageGPA(gpas, size);
                } catch (const char* msg) {
                    std::cout << msg << std::endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for(int i = 0; i < size; i++){
        delete[] names[i];
    }
    return 0;
}
