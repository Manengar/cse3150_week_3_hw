# cse3150_week_3_hw

*How I used...:*
**Pointers**: every student's name is stored using new char[] on the heap and freed from memory at the end with delete[]  
**Const**: used const double& for gpa to prevent modification and const char in printstudent function for the name  
**References**: size of student list is updated by the reference in addStudent  
**Casting**: average GPA displayed as both a double and rounded integer using static_cast<int>  
**Exceptions**: "list full" is thrown when you add to a full list, and when computing an avg with no student throws 'no student'. These are printed as error messages and caught in 'main'.  
**Control flow**: used 'if/else', 'switch', and do/while loop for the interactive menu implementation.  
