# Grade Calculator for Thebes Academy

This repository contains a C program designed to help students calculate their grades, semester percentages, and overall year percentages. The project has been developed in stages, which are organized into different Git branches.

## Branches and Features

### 1. `master` Branch (Original Version)
**File:** `Calclate the gread.c`
- This branch contains the initial version of the program.
- It calculates the grade for a single subject and provides a basic evaluation (Pass, Good, Very Good, Excellent).
- Uses `goto` statements for navigation.
- Contains hardcoded logic for checking subjects one by one.

### 2. `v2-enhancements` Branch (Version 2)
**File:** `Calculate_grade_v2.c`
- **Main Menu Navigation**: Replaced `goto` statements with `do-while` loops and switch-cases for a much more robust user experience that prevents crashes on bad input.
- **Data Structures**: Introduced C `struct` to handle subjects, making the code much shorter, cleaner, and easier to scale.
- **Semester & Year Calculation**: Added the ability to calculate the overall percentage for an entire semester or a full academic year by aggregating the maximum and earned marks of all subjects.
- **Input Validation**: Added functions to validate user input and clear the input buffer.

### 3. `v3-file-handling` Branch (Version 3 - Current)
**File:** `Calculate_grade_v3.c`
- **Complete Subjects Database**: Includes all accurate subjects and maximum marks for all 4 levels (Years 1 to 4), including First and Second semesters, based on the academy's official syllabus.
- **Formatted Transcript**: Prints a beautifully formatted table at the end of the calculation showing Subject Name, Max Marks, Earned Marks, and Individual Subject Grade, alongside the overall total.
- **File Handling (Data Saving)**: Automatically saves a copy of the printed transcript into a text file named `Student_Transcript.txt` in the same directory. This creates a permanent record of the student's grades without needing to re-enter them.

## How to Compile and Run
You can compile any of the C files using GCC:
```bash
gcc Calculate_grade_v3.c -o GradeCalculator
./GradeCalculator
```
