# 🎓 Thebes Academy Grade Calculator

![C](https://img.shields.io/badge/Language-C-blue.svg)
![Version](https://img.shields.io/badge/Version-3.0-brightgreen.svg)

A comprehensive, terminal-based C program built specifically for students of **Thebes Academy** to calculate their grades, semester percentages, and overall academic year evaluations.

---

## ✨ Features

- **📊 Comprehensive Database**: Pre-configured with the exact syllabus, subjects, and maximum marks for all 4 Years (Levels 1 to 4) of Thebes Academy.
- **🧮 Smart Calculation**: Calculates your percentage for a single subject, a full semester, or aggregates both semesters to give you your final year grade!
- **🖨️ Beautiful Transcripts**: Generates a clean, formatted ASCII table displaying your subjects, marks, and evaluations instantly.
- **💾 Auto-Save (File Handling)**: Automatically saves your generated transcript into a `Student_Transcript.txt` file so you never lose your results.
- **🛡️ Robust Input Handling**: Prevents the program from crashing if you accidentally type letters instead of numbers, and ensures marks cannot exceed the maximum allowed limits.

---

## 🚀 How to Run

1. **Clone the repository:**
   ```bash
   git clone https://github.com/YOUR_USERNAME/thebes-grade-calculator.git
   cd thebes-grade-calculator
   ```

2. **Compile the program using GCC:**
   ```bash
   gcc Calculate_grade_v3.c -o GradeCalculator
   ```

3. **Run the executable:**
   - On Windows:
     ```bash
     .\GradeCalculator.exe
     ```
   - On Linux / macOS:
     ```bash
     ./GradeCalculator
     ```

---

## 🌿 Git Branches & Version History

This project was developed incrementally to demonstrate best software engineering practices. You can explore the evolution of the code across different branches:

### `master` (Original)
The initial, primitive version of the application (`Calclate the gread.c`). Relied on hardcoded logic and `goto` statements to calculate grades one by one.

### `v2-enhancements` (Version 2)
Major refactor (`Calculate_grade_v2.c`). 
- Replaced `goto` with `do-while` loops.
- Introduced C `struct`s to organize subject data.
- Added the ability to calculate a full semester and year.

### `v3-file-handling` (Version 3)
The ultimate version (`Calculate_grade_v3.c`).
- Integrated the complete syllabus for all 4 years.
- Added ASCII table Transcript printing.
- Implemented file handling to save transcripts to `.txt` files.

---

## 🤝 Contributing
Feel free to fork this project, submit pull requests, or open issues to suggest new features (like GPA calculation using credit hours).

## 📄 License
This project is open-source and available for all students to use and modify!
