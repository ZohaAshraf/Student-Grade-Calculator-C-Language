/*
 * ============================================================
 *  Student Grade Calculator
 *  A beginner-friendly C project
 *  Author: Your Name
 *  GitHub: github.com/yourusername
 * ============================================================
 */

#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define NAME_LEN     50

/* ---------- Data Structure ---------- */
typedef struct {
    char name[NAME_LEN];
    float marks[MAX_SUBJECTS];
    int   num_subjects;
} Student;

/* ---------- Helper Functions ---------- */

/* Calculate the average of all marks */
float calculate_average(float marks[], int n) {
    float sum = 0.0f;
    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }
    return (n > 0) ? sum / n : 0.0f;
}

/* Find the highest mark */
float find_highest(float marks[], int n) {
    float max = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] > max) max = marks[i];
    }
    return max;
}

/* Find the lowest mark */
float find_lowest(float marks[], int n) {
    float min = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] < min) min = marks[i];
    }
    return min;
}

/* Convert numeric average to letter grade */
const char* get_grade(float avg) {
    if (avg >= 90) return "A+  (Excellent)";
    if (avg >= 80) return "A   (Very Good)";
    if (avg >= 70) return "B   (Good)";
    if (avg >= 60) return "C   (Average)";
    if (avg >= 50) return "D   (Pass)";
    return               "F   (Fail)";
}

/* Print a decorative separator line */
void print_line(void) {
    printf("--------------------------------------------------\n");
}

/* Display the full result card for a student */
void display_report(Student *s) {
    float avg     = calculate_average(s->marks, s->num_subjects);
    float highest = find_highest(s->marks, s->num_subjects);
    float lowest  = find_lowest(s->marks, s->num_subjects);

    printf("\n");
    print_line();
    printf("         STUDENT GRADE REPORT CARD\n");
    print_line();
    printf("  Student Name : %s\n", s->name);
    printf("  Subjects     : %d\n", s->num_subjects);
    print_line();

    for (int i = 0; i < s->num_subjects; i++) {
        printf("  Subject %2d   : %.2f\n", i + 1, s->marks[i]);
    }

    print_line();
    printf("  Average      : %.2f\n", avg);
    printf("  Highest Mark : %.2f\n", highest);
    printf("  Lowest Mark  : %.2f\n", lowest);
    printf("  Grade        : %s\n",   get_grade(avg));
    print_line();
    printf("\n");
}

/* ---------- Input Helpers ---------- */

/* Read a valid mark in [0, 100] */
float read_mark(int subject_num) {
    float mark;
    while (1) {
        printf("  Enter mark for Subject %d (0-100): ", subject_num);
        if (scanf("%f", &mark) == 1 && mark >= 0 && mark <= 100) {
            return mark;
        }
        printf("  [!] Invalid input. Please enter a number between 0 and 100.\n");
        while (getchar() != '\n');   /* flush input buffer */
    }
}

/* Read a positive integer in [1, MAX_SUBJECTS] */
int read_num_subjects(void) {
    int n;
    while (1) {
        printf("  Number of subjects (1-%d): ", MAX_SUBJECTS);
        if (scanf("%d", &n) == 1 && n >= 1 && n <= MAX_SUBJECTS) {
            return n;
        }
        printf("  [!] Please enter a number between 1 and %d.\n", MAX_SUBJECTS);
        while (getchar() != '\n');
    }
}

/* ---------- Main ---------- */
int main(void) {
    Student s;
    char    again;

    printf("\n");
    print_line();
    printf("     WELCOME TO STUDENT GRADE CALCULATOR\n");
    print_line();

    do {
        /* Student name */
        printf("\n  Enter student name: ");
        while (getchar() != '\n');           /* flush before fgets */
        fgets(s.name, NAME_LEN, stdin);
        s.name[strcspn(s.name, "\n")] = '\0'; /* remove trailing newline */

        /* Number of subjects */
        s.num_subjects = read_num_subjects();

        /* Marks for each subject */
        printf("\n  Enter marks below:\n");
        for (int i = 0; i < s.num_subjects; i++) {
            s.marks[i] = read_mark(i + 1);
        }

        /* Show result */
        display_report(&s);

        /* Ask to continue */
        printf("  Calculate for another student? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    printf("\n  Thank you for using the Grade Calculator!\n\n");
    return 0;
}
