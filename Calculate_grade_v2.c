#include <stdio.h>
#include <string.h>

// Structure to define a subject
typedef struct {
    char name[50];
    float totalMarks;
} Subject;

// Function Prototypes
void clearInputBuffer();
int getValidChoice(int min, int max);
void printGradeEvaluation(float percentage);
float calculateSemester(Subject subjects[], int count);

int main() {
    int choice;
    
    printf("====================================================================\n");
    printf("========== WELCOME TO THE ENHANCED GRADE CALCULATOR ==============\n");
    printf("====================================================================\n");

    do {
        printf("\nMain Menu:\n");
        printf("1. Calculate grade for a single subject manually\n");
        printf("2. Calculate overall grade for a specific Semester\n");
        printf("3. Calculate overall grade for an entire Year\n");
        printf("0. Exit\n");
        printf("Please enter your choice: ");
        choice = getValidChoice(0, 3);

        if (choice == 1) {
            float totalMark, yourMark;
            printf("\nEnter Total mark of subject: ");
            scanf("%f", &totalMark);
            printf("Enter your mark: ");
            scanf("%f", &yourMark);
            
            if (totalMark > 0) {
                float percentage = (yourMark / totalMark) * 100;
                printf("\nYour percentage: %.2f%%\n", percentage);
                printf("Evaluation: ");
                printGradeEvaluation(percentage);
            } else {
                printf("Error: Total mark must be greater than zero.\n");
            }
        } 
        else if (choice == 2 || choice == 3) {
            int level;
            printf("\nSelect the Year Level (1-4): ");
            level = getValidChoice(1, 4);

            float yearEarned = 0;
            float yearTotal = 0;

            // Define subjects for Level 1 as an example (You can add other levels here)
            Subject l1_sem1[] = {
                {"Electronics_1", 150}, {"Operating systems", 100}, {"Electric Circuits_1", 150}, 
                {"Elective", 50}, {"Technical English", 50}, {"Mathematics_3", 100}, {"Modern Physics", 150}
            };
            Subject l1_sem2[] = {
                {"Electronics_2", 125}, {"Logic Circuits Design", 150}, {"Electric Circuits (2)", 125}, 
                {"Electromagnetic Field", 100}, {"Elective", 50}, {"Mathematics (4)", 100}, {"Numerical Analysis", 100}
            };

            // Calculate Semester 1
            if (choice == 2) {
                int sem;
                printf("Select the Semester (1-2): ");
                sem = getValidChoice(1, 2);
                
                printf("\n--- Entering grades for Level %d, Semester %d ---\n", level, sem);
                if (level == 1 && sem == 1) calculateSemester(l1_sem1, 7);
                else if (level == 1 && sem == 2) calculateSemester(l1_sem2, 7);
                else printf("Data for this semester is not implemented yet. Add it to the arrays!\n");
            } 
            // Calculate Entire Year
            else if (choice == 3) {
                printf("\n--- Entering grades for Level %d, ENTIRE YEAR ---\n", level);
                if (level == 1) {
                    printf("\n>>> SEMESTER 1 <<<\n");
                    float sem1Earned = 0, sem1Total = 0;
                    for(int i=0; i<7; i++) sem1Total += l1_sem1[i].totalMarks;
                    sem1Earned = (calculateSemester(l1_sem1, 7) / 100.0) * sem1Total; // Simplified reverse calc

                    printf("\n>>> SEMESTER 2 <<<\n");
                    float sem2Earned = 0, sem2Total = 0;
                    for(int i=0; i<7; i++) sem2Total += l1_sem2[i].totalMarks;
                    sem2Earned = (calculateSemester(l1_sem2, 7) / 100.0) * sem2Total;

                    float yearPercentage = ((sem1Earned + sem2Earned) / (sem1Total + sem2Total)) * 100;
                    printf("\n==================================\n");
                    printf("YEAR %d OVERALL RESULTS:\n", level);
                    printf("Total Marks: %.2f / %.2f\n", (sem1Earned + sem2Earned), (sem1Total + sem2Total));
                    printf("Overall Percentage: %.2f%%\n", yearPercentage);
                    printf("Final Year Evaluation: ");
                    printGradeEvaluation(yearPercentage);
                    printf("==================================\n");
                } else {
                    printf("Data for this year is not implemented yet.\n");
                }
            }
        }
    } while (choice != 0);

    printf("\nThank you for using the program!\n");
    return 0;
}

// Function to calculate grades for an array of subjects
float calculateSemester(Subject subjects[], int count) {
    float totalPossible = 0;
    float totalEarned = 0;

    for (int i = 0; i < count; i++) {
        float mark;
        printf("Enter your mark for %s (out of %.0f): ", subjects[i].name, subjects[i].totalMarks);
        scanf("%f", &mark);
        
        // Ensure mark doesn't exceed total or drop below 0
        if(mark > subjects[i].totalMarks) mark = subjects[i].totalMarks;
        if(mark < 0) mark = 0;

        totalEarned += mark;
        totalPossible += subjects[i].totalMarks;
    }

    float percentage = (totalEarned / totalPossible) * 100;
    printf("\n--- Semester Summary ---\n");
    printf("Semester Percentage: %.2f%%\n", percentage);
    printf("Semester Evaluation: ");
    printGradeEvaluation(percentage);
    printf("------------------------\n");
    
    return percentage;
}

// Reusable grade evaluation logic
void printGradeEvaluation(float percentage) {
    if (percentage < 50) printf("Failed\n");
    else if (percentage < 65) printf("Pass\n");
    else if (percentage < 75) printf("Good\n");
    else if (percentage < 85) printf("Very Good\n");
    else printf("Excellent\n");
}

// Helper to safely get user choices without infinite loops on bad input
int getValidChoice(int min, int max) {
    int choice;
    while (scanf("%d", &choice) != 1 || choice < min || choice > max) {
        clearInputBuffer();
        printf("Invalid input. Please enter a number between %d and %d: ", min, max);
    }
    return choice;
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
