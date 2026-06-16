#include <stdio.h>
#include <string.h>

// Structure to define a subject
typedef struct {
    char name[60];
    float totalMarks;
    float earnedMarks; // Added to store the user's mark for transcript
} Subject;

// Function Prototypes
void clearInputBuffer();
int getValidChoice(int min, int max);
void printGradeEvaluation(float percentage);
const char* getGradeString(float percentage);
float calculateSemester(Subject subjects[], int count);
void printTranscript(Subject subjects[], int count, const char* title);
void saveTranscriptToFile(Subject subjects[], int count, const char* title, float percentage);

int main() {
    int choice;
    
    printf("====================================================================\n");
    printf("========== WELCOME TO THE ENHANCED GRADE CALCULATOR V3 ===========\n");
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

            // Define subjects for Level 1
            Subject l1_sem1[] = {
                {"Electronics_1", 150, 0}, {"Operating systems", 100, 0}, {"Electric Circuits_1", 150, 0}, 
                {"Elective", 50, 0}, {"Technical English", 50, 0}, {"Mathematics_3", 100, 0}, {"Modern Physics", 150, 0}
            };
            Subject l1_sem2[] = {
                {"Electronics_2", 125, 0}, {"Logic Circuits Design", 150, 0}, {"Electric Circuits (2)", 125, 0}, 
                {"Electromagnetic Field", 100, 0}, {"Elective", 50, 0}, {"Mathematics (4)", 100, 0}, {"Numerical Analysis", 100, 0}
            };

            // Define subjects for Level 2
            Subject l2_sem1[] = {
                {"Electronic Measurements (1)", 150, 0}, {"Electronic Circuits (1)", 150, 0}, {"Communication Systems (1)", 125, 0}, 
                {"ElectricalMachine & transformers", 100, 0}, {"Computer Architectures", 100, 0}, {"Feasibility studies & OR", 50, 0}, {"Civil Engineering", 75, 0}
            };
            Subject l2_sem2[] = {
                {"Electronics (3)", 150, 0}, {"Electronic Measurements (2)", 150, 0}, {"Communication Systems (2)", 125, 0}, 
                {"Electronic Circuits (2)", 150, 0}, {"Field Training (1)", 50, 0}, {"Eng Economics & Projects Mgmt", 50, 0}, {"Mechanical Engineering", 75, 0}
            };

            // Define subjects for Level 3
            Subject l3_sem1[] = {
                {"Electronic Circuits (3)", 150, 0}, {"Electromagnetic Waves", 125, 0}, {"Digital Signal Processing", 125, 0}, 
                {"Automatic Control", 100, 0}, {"Digital Communication Sys (1)", 150, 0}, {"Technical Report Writing", 50, 0}, {"Eelective", 50, 0}
            };
            Subject l3_sem2[] = {
                {"Antennas", 150, 0}, {"Electronic Circuits (4)", 150, 0}, {"Microprocessor & Interfacing", 150, 0}, 
                {"Field Training (2)", 50, 0}, {"Human Rights", 50, 0}, {"Elective (1)", 100, 0}, {"Elective (1)", 100, 0}
            };

            // Define subjects for Level 4
            Subject l4_sem1[] = {
                {"Programmable logic controllers", 100, 0}, {"Microwave Engineering", 150, 0}, {"Satellite Communications", 125, 0}, 
                {"Neural Networks", 125, 0}, {"Engineering Legislations", 50, 0}, {"Elective (2)", 100, 0}, {"Elective (2)", 100, 0}
            };
            Subject l4_sem2[] = {
                {"Optical Communication Systems", 150, 0}, {"Project", 200, 0}, {"Embedded Systems", 100, 0}, 
                {"Environmental Impact of Projects", 50, 0}, {"Pop., Repro. Health & Fam Plan.", 50, 0}, {"Elective (2)", 100, 0}, {"Elective (2)", 100, 0}
            };

            Subject* currentSem1;
            Subject* currentSem2;

            if (level == 1) { currentSem1 = l1_sem1; currentSem2 = l1_sem2; }
            else if (level == 2) { currentSem1 = l2_sem1; currentSem2 = l2_sem2; }
            else if (level == 3) { currentSem1 = l3_sem1; currentSem2 = l3_sem2; }
            else { currentSem1 = l4_sem1; currentSem2 = l4_sem2; }

            // Calculate specific semester
            if (choice == 2) {
                int sem;
                printf("Select the Semester (1-2): ");
                sem = getValidChoice(1, 2);
                
                printf("\n--- Entering grades for Level %d, Semester %d ---\n", level, sem);
                Subject* targetSem = (sem == 1) ? currentSem1 : currentSem2;
                
                float pct = calculateSemester(targetSem, 7);
                char title[100];
                sprintf(title, "Level %d - Semester %d Transcript", level, sem);
                printTranscript(targetSem, 7, title);
                saveTranscriptToFile(targetSem, 7, title, pct);
            } 
            // Calculate Entire Year
            else if (choice == 3) {
                printf("\n--- Entering grades for Level %d, ENTIRE YEAR ---\n", level);
                
                printf("\n>>> SEMESTER 1 <<<\n");
                float sem1Earned = 0, sem1Total = 0;
                for(int i=0; i<7; i++) sem1Total += currentSem1[i].totalMarks;
                float pct1 = calculateSemester(currentSem1, 7);
                sem1Earned = (pct1 / 100.0) * sem1Total;

                printf("\n>>> SEMESTER 2 <<<\n");
                float sem2Earned = 0, sem2Total = 0;
                for(int i=0; i<7; i++) sem2Total += currentSem2[i].totalMarks;
                float pct2 = calculateSemester(currentSem2, 7);
                sem2Earned = (pct2 / 100.0) * sem2Total;

                float yearPercentage = ((sem1Earned + sem2Earned) / (sem1Total + sem2Total)) * 100;
                
                // Combine into one array for the year transcript
                Subject yearSubjects[14];
                for(int i=0; i<7; i++) yearSubjects[i] = currentSem1[i];
                for(int i=0; i<7; i++) yearSubjects[i+7] = currentSem2[i];
                
                char title[100];
                sprintf(title, "Level %d - Full Year Transcript", level);
                printTranscript(yearSubjects, 14, title);
                saveTranscriptToFile(yearSubjects, 14, title, yearPercentage);

                printf("\n==================================\n");
                printf("YEAR %d OVERALL RESULTS:\n", level);
                printf("Total Marks: %.2f / %.2f\n", (sem1Earned + sem2Earned), (sem1Total + sem2Total));
                printf("Overall Percentage: %.2f%%\n", yearPercentage);
                printf("Final Year Evaluation: ");
                printGradeEvaluation(yearPercentage);
                printf("==================================\n");
            }
        }
    } while (choice != 0);

    printf("\nThank you for using the program!\n");
    return 0;
}

// Function to calculate grades and store them in the structs
float calculateSemester(Subject subjects[], int count) {
    float totalPossible = 0;
    float totalEarned = 0;

    for (int i = 0; i < count; i++) {
        float mark;
        printf("Enter your mark for %-35s (out of %.0f): ", subjects[i].name, subjects[i].totalMarks);
        scanf("%f", &mark);
        
        // Ensure mark doesn't exceed total or drop below 0
        if(mark > subjects[i].totalMarks) mark = subjects[i].totalMarks;
        if(mark < 0) mark = 0;

        subjects[i].earnedMarks = mark; // Store it for the transcript
        totalEarned += mark;
        totalPossible += subjects[i].totalMarks;
    }

    float percentage = (totalEarned / totalPossible) * 100;
    return percentage;
}

// Function to print a beautifully formatted transcript table
void printTranscript(Subject subjects[], int count, const char* title) {
    printf("\n\n");
    printf("=================================================================================\n");
    printf("                            %s\n", title);
    printf("=================================================================================\n");
    printf("%-35s | %-10s | %-10s | %-15s\n", "Subject Name", "Max Marks", "Your Mark", "Grade");
    printf("---------------------------------------------------------------------------------\n");
    
    float totalMax = 0, totalEarned = 0;
    
    for(int i = 0; i < count; i++) {
        float pct = (subjects[i].earnedMarks / subjects[i].totalMarks) * 100;
        printf("%-35s | %-10.1f | %-10.1f | %-15s\n", 
               subjects[i].name, 
               subjects[i].totalMarks, 
               subjects[i].earnedMarks, 
               getGradeString(pct));
               
        totalMax += subjects[i].totalMarks;
        totalEarned += subjects[i].earnedMarks;
    }
    printf("---------------------------------------------------------------------------------\n");
    float finalPct = (totalEarned / totalMax) * 100;
    printf("%-35s | %-10.1f | %-10.1f | %-15s\n", "OVERALL TOTAL", totalMax, totalEarned, getGradeString(finalPct));
    printf("=================================================================================\n");
}

// Function to save the transcript to a text file
void saveTranscriptToFile(Subject subjects[], int count, const char* title, float percentage) {
    FILE *file = fopen("Student_Transcript.txt", "a");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    fprintf(file, "=================================================================================\n");
    fprintf(file, "                            %s\n", title);
    fprintf(file, "=================================================================================\n");
    fprintf(file, "%-35s | %-10s | %-10s | %-15s\n", "Subject Name", "Max Marks", "Your Mark", "Grade");
    fprintf(file, "---------------------------------------------------------------------------------\n");
    
    float totalMax = 0, totalEarned = 0;
    for(int i = 0; i < count; i++) {
        float pct = (subjects[i].earnedMarks / subjects[i].totalMarks) * 100;
        fprintf(file, "%-35s | %-10.1f | %-10.1f | %-15s\n", 
               subjects[i].name, 
               subjects[i].totalMarks, 
               subjects[i].earnedMarks, 
               getGradeString(pct));
               
        totalMax += subjects[i].totalMarks;
        totalEarned += subjects[i].earnedMarks;
    }
    fprintf(file, "---------------------------------------------------------------------------------\n");
    fprintf(file, "Overall Percentage: %.2f%%\n", percentage);
    fprintf(file, "Final Grade: %s\n", getGradeString(percentage));
    fprintf(file, "=================================================================================\n\n\n");
    
    fclose(file);
    printf(">>> Transcript successfully saved to 'Student_Transcript.txt' <<<\n");
}

// Reusable grade evaluation logic (returns string for table)
const char* getGradeString(float percentage) {
    if (percentage < 50) return "Failed";
    else if (percentage < 65) return "Pass";
    else if (percentage < 75) return "Good";
    else if (percentage < 85) return "Very Good";
    else return "Excellent";
}

void printGradeEvaluation(float percentage) {
    printf("%s\n", getGradeString(percentage));
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
