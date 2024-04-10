/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  :Aung Moe Thwe
Student ID#:148396237
Email      :amthwe@myseneca.ca
Section    :ZBB

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
            "==============================\n"
            "1) VIEW   ALL Appointments\n"
            "2) VIEW   Appointments by DATE\n"
            "3) ADD    Appointment\n"
            "4) REMOVE Appointment\n"
            "------------------------------\n"
            "0) Previous menu\n"
            "------------------------------\n"
            "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt) {
    int i, valid = 0;
    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }
    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            valid = 1;
        }
    }
    if (!valid)
    {
        printf("*** No records found ***");
    }
    printf("\n");

}


// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max) {
    int choice;
    do
    {
        printf("Search Options\n==========================\n");
        printf("1) By patient number\n2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");

        printf("Selection: ");
        choice = inputIntRange(0, 2);
        printf("\n");

        switch (choice)
        {
        case 1:
            searchPatientByPatientNumber(patient, max);

            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);

            suspend();
            break;
        default:
            break;
        }

    } while (choice);
}


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max) {
    int i, indicator = 0, index;

    for (i = 0; i < max; i++) //checks through each patient num
    {
        if (patient[i].patientNumber == 0)
        {
            indicator = 1;
            index = i;
        }
    }
    if (indicator != 0)
    {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
        printf("*** New patient record added ***\n\n");
    }
    else
    {
        printf("ERROR: Patient listing is FULL!");
        printf("\n\n");
    }
}



// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max) {
    int num;
    printf("Enter the patient number: ");
    num = inputIntPositive();
    printf("\n");

    if (findPatientIndexByPatientNum(num, patient, max) != -1) //this function returns -1 if it cant be located
    {
        num = findPatientIndexByPatientNum(num, patient, max);
        menuPatientEdit(patient + num);
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }
}


// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int num, index;
    char choice;
    printf("Enter the patient number: ");
    num = inputIntPositive();
    printf("\n");

    index = findPatientIndexByPatientNum(num, patient, max);
    if (index == -1)
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    else
    {
        displayPatientData(&patient[index], FMT_FORM);

        printf("\n");

        printf("Are you sure you want to remove this patient record? (y/n): ");
        choice = inputCharOption("yn");
        

        if (choice == 'n')
        {
            printf("Operation aborted.\n");
            clearInputBuffer();
        }
        else
        {
            patient[index].patientNumber = 0; //safe state
            printf("Patient record has been removed!\n\n");
            
        }

    }

}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data)
{
    int i, j;
    sortAppointments(data->appointments, data->maxAppointments);

    // Displaying the patients
    displayScheduleTableHeader(NULL, 1);
    for (i = 0; i < data->maxAppointments; i++) 
    {
        for (j = 0; j < data->maxPatient; j++) 
        {
            if (data->appointments[i].patientNumber && data->patients[j].patientNumber) 
            {
                if (data->appointments[i].patientNumber == data->patients[j].patientNumber) 
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 1);
                }
            }
        }
    }

    printf("\n");

}


// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data)
{
    int i,j, maxD;
    struct Date date;

    printf("Year        : ");
    date.year = inputIntPositive();
    printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTH);
    date.month = inputIntRange(1, 12);
    maxD = daysOfMonth(date.year, date.month);
    printf("Day (%d-%d)  : ", MIN_DAY, maxD);
    date.day = inputIntRange(MIN_DAY, maxD);

    sortAppointments(data->appointments, data->maxAppointments);
    printf("\n");

    //display data
    displayScheduleTableHeader(&date, 0);
    for ( i = 0; i < data->maxAppointments; i++)
    {
        for (j = 0; j < data->maxPatient; j++)
        {
            if ((data->appointments[i].patientNumber && data->patients[j].patientNumber)  && (data->appointments[i].patientNumber == data->patients[j].patientNumber))
            {
                if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                }
            }
        }
    }
    printf("\n");
}



// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment appointment[], int maxAppointments, struct Patient* patient, int maxPatients)
{
    int patientNum, maxDay, patientSearch= 0, newSlot, valid = 0;
    struct Time tempTime;
    struct Date tempDate;

    newSlot = newAppointment(appointment, maxAppointments);


    printf("Patient Number: ");
    patientNum = inputIntPositive();

    patientSearch = findPatientIndexByPatientNum(patientNum, patient, maxPatients);

    if (patientSearch != -1)
    {
        do
        {
            printf("Year        : ");
            tempDate.year = inputIntPositive();
            printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTH);
            tempDate.month = inputIntRange(MIN_MONTH, MAX_MONTH);
            maxDay = daysOfMonth(tempDate.year, tempDate.month);
            printf("Day (%d-%d)  : ", MIN_DAY, maxDay);
            tempDate.day = inputIntRange(MIN_DAY, maxDay);

            printf("Hour (%d-%d)  : ", MIN_HOUR_ADD, MAX_HOUR_ADD);
            tempTime.hour = inputIntRange(MIN_HOUR_ADD, MAX_HOUR_ADD);
            printf("Minute (%d-%d): ", MIN_MIN, MAX_MIN);
            tempTime.min = inputIntRange(MIN_MIN, MAX_MIN);

            while (tempTime.hour < MIN_HOUR || tempTime.hour > MAX_HOUR || tempTime.min % MIN_INTERVAL != 0 || (tempTime.hour == MAX_HOUR && tempTime.min > 0))
            {
                printf("ERROR: Time must be between 10:00 and 14:00 in 30 minute intervals.\n\n");

                printf("Hour (%d-%d)  : ", MIN_HOUR_ADD, MAX_HOUR_ADD);
                tempTime.hour = inputIntRange(MIN_HOUR_ADD, MAX_HOUR_ADD);
                printf("Minute (%d-%d): ", MIN_MIN, MAX_MIN);
                tempTime.min = inputIntRange(MIN_MIN, MAX_MIN);
            }

            if (timeSlot(tempDate, tempTime, appointment, maxAppointments))
            {
                appointment[newSlot].patientNumber = patientNum;
                appointment[newSlot].time = tempTime;
                appointment[newSlot].date = tempDate;
                printf("\n*** Appointment scheduled! ***\n\n");
                valid = 1;
            }
            else
            {
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
        } while (!valid);
        
    }
    else
    {
        printf("\n*** No records found ***\n\n");
    }

}


// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment appointment[], int maxAppointments, struct Patient* patient, int maxPatients)
{
    int patientNum, patientInd, maxDay, appointmentInd;
    struct Date temp;

    printf("Patient Number: ");
    patientNum = inputIntPositive();

    patientInd = findPatientIndexByPatientNum(patientNum, patient, maxPatients);

    if (patientInd > 0)
    {
        printf("Year        : ");
        temp.year = inputIntPositive();
        printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTH);
        temp.month = inputIntRange(MIN_MONTH, MAX_MONTH);
        maxDay = daysOfMonth(temp.year, temp.month);
        printf("Day (%d-%d)  : ", MIN_DAY, maxDay);
        temp.day = inputIntRange(MIN_DAY, maxDay);

        appointmentInd = findRecordIndex(patientNum, temp, appointment, maxAppointments);
        printf("\n");
        if (appointmentInd != -1)
        {
            displayPatientData(&patient[patientInd], FMT_FORM);
            printf("Are you sure you want to remove this appointment (y,n): ");

            if (inputCharOption("yn") == 'y')
            {
                appointment[appointmentInd].patientNumber = 0;
                printf("\nAppointment record has been removed!\n\n");
                
            }
            else
            {
                printf("\nAppointemnt record was not removed!\n\n");
            }
        }
        else
        {
            printf("\nAppointment record not found!\n\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }

}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
    void searchPatientByPatientNumber(const struct Patient patient[], int max) {
        int num;

        printf("Search by patient number: ");
        num = inputIntPositive();

        printf("\n");

        if (findPatientIndexByPatientNum(num, patient, max) != -1)
        {
            num = findPatientIndexByPatientNum(num, patient, max);
            displayPatientData(&patient[num], FMT_FORM);
            printf("\n");
        }
        else
        {
            printf("*** No records found ***\n\n");
        }
    }


// Search and display patient records by phone number (tabular)
    void searchPatientByPhoneNumber(const struct Patient patient[], int max) {
        int i, found = 0;
        char searchNum[PHONE_LEN + 1];
        printf("Search by phone number: ");
        inputCString(searchNum, 1, PHONE_LEN + 1);


        printf("\n");
        displayPatientTableHeader();


        for (i = 0; i < max; i++)
        {
            if (strcmp(patient[i].phone.number, searchNum) == 0)
            {
                if (!found)
                {
                    found = 1;
                }
                displayPatientData(&patient[i], FMT_TABLE);

            }
        }
        printf("\n");

        if (!found)
        {
            printf("*** No records found ***\n\n");
        }
    }



// Get the next highest patient number
    int nextPatientNumber(const struct Patient patient[], int max) {
        int i, highest = 0;
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber > highest)
            {
                highest = patient[i].patientNumber;
            }
        }
        return highest + 1;
    }


// Find the patient array index by patient number (returns -1 if not found)
    int findPatientIndexByPatientNum(int patientNumber,
        const struct Patient patient[], int max) 
    {
        int i;
        for (i = 0; i < max; i++)
        {
            if (patient[i].patientNumber == patientNumber)
            {
                return i; // return index if found
            }
        }
        return -1; // if not found
    }


// Sorting Appointments 
    void sortAppointments(struct Appointment appointments[], int max)
    {
        int i, j;
        struct Appointment temporary;

        // Storing all the date and time values in minutes for comparison
        for (i = 0; i < max; i++)
        {
            appointments[i].time.min = (appointments[i].date.year * 12 * 30 * 24 * 60) + (appointments[i].date.month * 30 * 24 * 60) + (appointments[i].date.day * 24 * 60) + (appointments[i].time.hour * 60) + appointments[i].time.min;
        }

        // Using bubble sort to compare minutes and then swap the structs
        for (i = max - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (appointments[j].time.min > appointments[j + 1].time.min)
                {
                    temporary = appointments[j];
                    appointments[j] = appointments[j + 1];
                    appointments[j + 1] = temporary;
                }

            }
        }
        // Converting total minutes back to minutes
        for (i = 0; i < max; i++) {
            appointments[i].time.min = appointments[i].time.min - (appointments[i].date.year * 12 * 30 * 24 * 60) - (appointments[i].date.month * 30 * 24 * 60) - (appointments[i].date.day * 24 * 60) - (appointments[i].time.hour * 60);
        }
    }


// To check for any available time slot
int timeSlot(struct Date date, struct Time time, struct Appointment* appointment, int max)
{
    int i;
    for ( i = 0; i < max; i++)
    {
        if (appointment[i].time.min == time.min && appointment[i].time.hour == time.hour && appointment[i].date.day == date.day && appointment[i].date.month == date.month && appointment[i].date.year == date.year)
        {
            return 0;
        }
    }
    return 1;
}

// Leap years and return days of month
int daysOfMonth(int year, int month)
{
    // Check if the month is February
    if (month == 2) {
        // Check for leap year
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29; // Leap year
        }
        else {
            return 28; // Not a leap year
        }
    }
    // For April, June, September, and November
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    // For January, March, May, July, August, October, and December
    else {
        return 31;
    }
}

// appointment index search using date and number. returns index
int findRecordIndex(int patientNumber, struct Date date, struct Appointment* app, int maxAppointments)
{
    int i = 0, valid = 0;

    while (valid == 0 && i < maxAppointments)
    {
        if ((app[i].patientNumber == patientNumber) && (app[i].date.day == date.day) && (app[i].date.month == date.month) && (app[i].date.year == date.year)) {
            valid = 1;
        }

        i++;
    }
    return i - 1;
}

// new empty index to save appointments
int newAppointment(struct Appointment* appointment, int max)
{
    int i = 0, valid = 0;
    while (valid == 0 && i < max)
    {
        if (appointment[i].patientNumber < 1)
        {
            valid = 1;
        }
        i++;
    }
    return i;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
    void inputPatient(struct Patient* patient) {

        printf("Patient Data Input\n------------------\n");

        printf("Number: %05d\n", patient->patientNumber);
        printf("Name  : ");
        inputCString(patient->name, 1, NAME_LEN);
        printf("\n");
        inputPhoneData(&patient->phone);



    }



// Get user input for phone contact information
    void inputPhoneData(struct Phone* phone) 
    {
        int choice;


        printf("Phone Information\n");
        printf("-----------------\n");
        printf("How will the patient like to be contacted?\n");
        printf("1. Cell\n");
        printf("2. Home\n");
        printf("3. Work\n");
        printf("4. TBD\n");
        printf("Selection: ");
        choice = inputIntRange(1, 4);
        printf("\n");

        switch (choice)
        {
        case 1:
            strncpy(phone->description, "CELL", PHONE_DESC_LEN);
            break;
        case 2:
            strncpy(phone->description, "HOME", PHONE_DESC_LEN);
            break;
        case 3:
            strncpy(phone->description, "WORK", PHONE_DESC_LEN);
            break;
        case 4:
            strncpy(phone->description, "TBD", PHONE_DESC_LEN);
            phone->number[0] = '\0';
            return;
        default:
            printf("ERROR:\n");
            break;
        }

        printf("Contact: %s", phone->description);
        printf("\nNumber : ");
        inputCString(phone->number, 10, 10);
        printf("\n");
    }




//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    int counter = 0;
    FILE* fp = NULL;
    fp = fopen(datafile, "r");

    if (fp!=NULL)
    {
        while ((fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[counter].patientNumber,patients[counter].name, patients[counter].phone.description, patients[counter].phone.number) != EOF && counter < max))
        {
            counter++;
        }
        fclose(fp);
    }
    else
    {
        printf("Failed to open file\n");
    }

    return counter;
}


// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
    int importAppointments(const char* datafile, struct Appointment appointment[], int max)
    {
        int counter = 0;
        FILE* fp = NULL;
        fp = fopen(datafile, "r");

        if (fp != NULL)
        {
            while ((fscanf(fp, "%d,%d,%d,%d,%d,%d", &appointment[counter].patientNumber,&appointment[counter].date.year,&appointment[counter].date.month,&appointment[counter].date.day, &appointment[counter].time.hour,&appointment[counter].time.min) != EOF && counter < max))
            {
                counter++;
            }
            fclose(fp);
        }
        else
        {
            printf("Failed to open file\n");
        }
        
        return counter;
    }
