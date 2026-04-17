#  Student Grade Calculator in C

A clean, beginner-friendly **console application** built in C that calculates student grades, averages, highest and lowest marks, and assigns a letter grade — all with a polished report card output.

---

##  Sample Output

```
--------------------------------------------------
         STUDENT GRADE REPORT CARD
--------------------------------------------------
  Student Name : Ahmed Khan
  Subjects     : 5
--------------------------------------------------
  Subject  1   : 88.00
  Subject  2   : 76.50
  Subject  3   : 92.00
  Subject  4   : 65.00
  Subject  5   : 81.00
--------------------------------------------------
  Average      : 80.50
  Highest Mark : 92.00
  Lowest Mark  : 65.00
  Grade        : A   (Very Good)
--------------------------------------------------
```

---

##  Features

- Enter name and marks for any number of subjects (up to 10)
- Calculates **average**, **highest**, and **lowest** marks automatically
- Assigns a **letter grade** (A+, A, B, C, D, F) based on average
- **Input validation** — rejects invalid marks and non-numeric input
- Supports **multiple students** in one run
- Clean report card printed to the terminal

---

##  Project Structure

```
grade_calculator/
│
├── grade_calculator.c    # Main source file (all logic here)
└── README.md             # This file
```

---

##  How to Compile & Run

### On Linux / macOS

```bash
gcc grade_calculator.c -o grade_calculator
./grade_calculator
```

### On Windows (with MinGW or GCC)

```bash
gcc grade_calculator.c -o grade_calculator.exe
grade_calculator.exe
```

> **Requirements:** Any C compiler — GCC, Clang, or MSVC. No external libraries needed.

---

##  Grading Scale

| Average Score | Grade |
|--------------|-------|
| 90 – 100     | A+  (Excellent) |
| 80 – 89      | A   (Very Good) |
| 70 – 79      | B   (Good)      |
| 60 – 69      | C   (Average)   |
| 50 – 59      | D   (Pass)      |
| Below 50     | F   (Fail)      |

---

##  Concepts Practiced

- `struct` for grouping student data
- Functions with arrays and pointers
- `scanf` / `fgets` input handling
- Input validation loops
- String manipulation (`strcspn`)
- Loops, conditionals, and formatted output (`printf`)

---

##  Contributing

Pull requests are welcome! If you'd like to extend this project (e.g., save results to a file, add a menu system, or sort multiple students), feel free to fork and submit a PR.

---

##  License

MIT License — free to use, modify, and distribute.

---

##  Author

**Zoha Ashraf**  
https://github.com/ZohaAshraf
https://www.linkedin.com/in/zohashraf/

---

*Built as a learning project while studying C programming. Feedback and stars are appreciated! ⭐*
