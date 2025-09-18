#include <iostream>
#include <cstring>   // for strlen, strcpy

// TODO: function prototypes

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa);

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa);

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size);

void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
	if (size >= capacity) {
		throw "List full";
	}
	int len = std::strlen(name);
	names[size] = new char[len + 1];
	std::strcpy(names[size], name);
	gpas[size] = gpa;
	size++;
}

void updateGPA(double* gpaPtr, double newGpa) {
	if (gpaPtr != nullptr) {
		*gpaPtr = newGpa;
	}
}

void printStudent(const char* name, const double& gpa) {
	std::cout << name << " : " << gpa << std::endl;
}

double averageGPA(const double gpas[], int size) {
	if (size == 0) {
		throw "No students";
	}
	double sum = 0.0;
	for (int i = 0; i< size; i++) {
		sum += gpas[i];
	}
	return sum / size;
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
		std::cout << "Enter name: ";
		char buffer[100];
		std::cin >> buffer;
		std::cout << "Enter GPA: ";
		double gpa;
		std::cin >> gpa;
		try {
		    addStudent(buffer, gpa, names, gpas, size, capacity);
		} catch (const char* msg) {
	    	    std::cout << msg << std::endl;
		}
                break;
            }
            case 2: {
                // TODO: implement menu logic
	        std::cout << "Enter index: ";
		int idx;
		std::cin >> idx;
		if (idx >= 0 && idx < size) {
		    std::cout << "Enter new GPA: ";
		    double newGpa;
		    std::cin >> newGpa;
		    updateGPA(&gpas[idx], newGpa);
		} else {
		    std::cout << "Invalid index" << std::endl;
		}
                break;
            }
            case 3: {
                // TODO: implement menu logic
		for (int i = 0; i < size; i++) {
		    printStudent(names[i], gpas[i]);
		}
                break;
            }
            case 4: {
                // TODO: implement menu logic
		try {
		    double avg = averageGPA(gpas, size);
	            std::cout << "Average GPA = " << avg
		              << " (rounded = " << static_cast<int>(avg) << ")" << std::endl;
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
    for (int i = 0; i < size; i++) {
	    delete[] names[i];
    }

    return 0;
}

