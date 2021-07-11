/*
    ==================================================
    Assignment #2 Milestone #2:
    ==================================================
    Name   : Tuan Nguyen
    ID     : 109062166
    Email  : tnguyen140@myseneca.ca
    Section: NFF
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "commonHelpers.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// -----------------------------------------
// Function Definitions

// Uses the time.h library to obtain current year information
// Get the current 4-digit year from the system
int currentYear(void)
{
    time_t currentTime = time(NULL);
    return localtime(&currentTime)->tm_year + 1900;
}

// As demonstrated in the course notes: https://ict.senecacollege.ca//~ipc144/pages/content/formi.html#buf
// Empty the standard input buffer
void clearStandardInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; // On purpose: do nothing 
    }
}

int getInteger(void)
{
    int intValue = 0;
    char newLine = 'n';
    do
    {
        scanf("%d%c", &intValue, &newLine);
        if (newLine != '\n')
        {
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
        }
    } while (newLine != '\n');
    return intValue;
}

int getPositiveInteger(void)
{
    int intValue = 0;
    char newLine = 'n';
    do
    {
        scanf("%d%c", &intValue, &newLine);
        if (newLine != '\n')
        {
            clearStandardInputBuffer();
            printf("ERROR: Value must be a positive integer greater than zero: ");
        }
        else if (intValue <= 0)
        {
            printf("ERROR: Value must be a positive integer greater than zero: ");
        }
    } while (newLine != '\n' || intValue <= 0);
    return intValue;
}

int getPositiveIntegerOrZero(void)
{
    int intValue = 0;
    do
    {
        scanf("%d", &intValue);
        if (intValue < 0)
        {
            printf("ERROR: Value must be positive or zero: ");
        }
        clearStandardInputBuffer();
    } while (intValue < 0);
    return intValue;
}

double getDouble(void)
{
    double doubleValue = 0.0;
    char newLine = 'n';
    do
    {
        scanf("%lf%c", &doubleValue, &newLine);
        if (newLine != '\n')
        {
            clearStandardInputBuffer();
            printf("ERROR: Value must be a double floating-point number: ");
        }
    } while (newLine != '\n');
    return doubleValue;
}

double getPositiveDouble(void)
{
    double doubleValue = 0.0;
    char newLine = 'n';
    do
    {
        scanf("%lf%c", &doubleValue, &newLine);
        if (newLine != '\n')
        {
            clearStandardInputBuffer();
            printf("ERROR: Value must be a double floating-point number: ");
        }
        else if (doubleValue <= 0)
        {
            printf("ERROR: Value must be a positive double floating-point number: ");
        }
    } while (newLine != '\n' || doubleValue <= 0);
    return doubleValue;
}

int getIntFromRange(int lowerBound, int upperBound)
{
    int intValue = 0;
    char newLine;
    do
    {
        newLine = 'n';
        scanf("%d%c", &intValue, &newLine);
        if (newLine != '\n')
        {
            clearStandardInputBuffer();
            printf("ERROR: Value must be an integer: ");
        }
        else if (intValue < lowerBound || intValue > upperBound)
        {
            printf("ERROR: Value must be between %d and %d inclusive: ", lowerBound, upperBound);
        }
    } while (newLine != '\n' || intValue < lowerBound || intValue > upperBound);
    return intValue;
}

char getCharOption(char string[])
{
    char ch = 'c';
    char newLine = 'n';
    int i = 0;
    int flag = 1;
    int length = strlen(string);
    do
    {
        scanf("%c%c", &ch, &newLine);
        if (newLine != '\n')
        {
            clearStandardInputBuffer();
        }
        else
        {
            for (i = 0; i < length; i++)
            {
                if (string[i] == ch)
                    flag = 0;
            }
        }
        if (flag == 1)
        {
            printf("ERROR: Character must be one of [%s]: ", string);
        }
    } while (flag);
    return ch;
}

void getCString(char* string, int lowerBound, int upperBound)
{
    char userString[151] = "\0";
    int flag = 1;
    int userLength;
    do
    {
        scanf("%[^\n]s", userString);
        clearStandardInputBuffer();
        userLength = strlen(userString);
        if (lowerBound == upperBound && userLength != lowerBound)
        {
            printf("ERROR: String length must be exactly %d chars: ", lowerBound);
        }
        else if (lowerBound != upperBound && userLength > upperBound)
        {
            printf("ERROR: String length must be no more than %d chars: ", upperBound);
        }
        else if (lowerBound != upperBound && userLength < lowerBound)
        {
            printf("ERROR: String length must be between %d and %d chars: ", lowerBound, upperBound);
        }
        else
        {
            strcpy(string, userString);
            flag = 0;
        }
    } while (flag);
}

void getCStringNoWhiteSpace(char* string, int lowerBound, int upperBound)
{
    char userString[30] = "\0";
    int flag = 1;
    int i;
    int userLength;
    int spaceConfirm;
    do
    {
        spaceConfirm = 0;
        printf("Enter user login (%d chars max): ", upperBound);
        scanf("%30[^\n]", userString);
        clearStandardInputBuffer();
        userLength = strlen(userString);
        for (i = 0; i < userLength; i++)
        {
            if (isspace(userString[i]) != 0)
            {
                spaceConfirm = isspace(userString[i]);
            }
        }
        if (spaceConfirm != 0)
        {
            printf("ERROR:  The user login must NOT contain whitespace characters.\n");
        }
        else if (lowerBound == upperBound && userLength != lowerBound)
        {
            printf("ERROR: String length must be exactly %d chars: ", lowerBound);
        }
        else if (userLength > upperBound)
        {
            printf("ERROR: String length must be no more than %d chars: ", upperBound);
        }
        else if (userLength < lowerBound)
        {
            printf("ERROR: String length must be between %d and %d chars: ", lowerBound, upperBound);
        }
        else
        {
            for (i = 0; i < userLength; i++)
            {
                string[i] = userString[i];
            }
            flag = 0;
        }
    } while (flag);
}

void getCStringPassword(char* string, int bound)
{
    char userString[30] = "\0";
    int flag = 1;
    int i;
    int userLength;
    int spaceConfirm;
    int digitNum, upperCaseNum, lowerCaseNum, symbolNum;
    printf("Enter the password (must be %d chars in length): ", bound);
    do
    {
        spaceConfirm = 0, digitNum = 0, upperCaseNum = 0, lowerCaseNum = 0, symbolNum = 0;
        scanf("%30[^\n]", userString);
        clearStandardInputBuffer();
        userLength = strlen(userString);
        for (i = 0; i < userLength; i++)
        {
            if (isspace(userString[i]) != 0)
            {
                spaceConfirm = isspace(userString[i]);
            }
            switch (userString[i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                digitNum++;
                break;
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                upperCaseNum++;
                break;
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
                lowerCaseNum++;
                break;
            case '!':
            case '@':
            case '#':
            case '$':
            case '%':
            case '^':
            case '&':
            case '*':
                symbolNum++;
                break;
            }
        }
        if (spaceConfirm != 0)
        {
            printf("ERROR:  The password must NOT contain whitespace characters.\n");
        }
        else if (userLength != bound)
        {
            printf("ERROR: String length must be exactly %d chars: ", bound);
        }
        else if (digitNum < 2 || upperCaseNum < 2 || lowerCaseNum < 2 || symbolNum < 2)
        {
            printf("SECURITY: Password must contain 2 of each:\n");
            printf("          Digit: 0-9\n");
            printf("          UPPERCASE character\n");
            printf("          lowercase character\n");
            printf("          symbol character: !@#$%%^&*\n");
            printf("Enter the password (must be 8 chars in length): ");
        }
        else
        {
            for (i = 0; i < userLength; i++)
            {
                string[i] = userString[i];
            }
            flag = 0;
        }
    } while (flag);
}

void getCStringCountry(char* string, int lowerBound, int upperBound)
{
    char userString[30] = "\0";
    int flag = 1;
    int i;
    int userLength;
    do
    {
        scanf("%30[^\n]", userString);
        clearStandardInputBuffer();
        userLength = strlen(userString);
        if (lowerBound == upperBound && userLength != lowerBound)
        {
            printf("ERROR: String length must be exactly %d chars: ", lowerBound);
        }
        else if (userLength > upperBound)
        {
            printf("ERROR: String length must be no more than %d chars: ", upperBound);
        }
        else if (userLength < lowerBound)
        {
            printf("ERROR: String length must be between %d and %d chars: ", lowerBound, upperBound);
        }
        else
        {
            for (i = 0; i < userLength; i++)
            {
                switch (userString[i])
                {
                case 'a':
                    userString[i] = 'A';
                    break;
                case 'b':
                    userString[i] = 'B';
                    break;
                case 'c':
                    userString[i] = 'C';
                    break;
                case 'd':
                    userString[i] = 'D';
                    break;
                case 'e':
                    userString[i] = 'E';
                    break;
                case 'f':
                    userString[i] = 'F';
                    break;
                case 'g':
                    userString[i] = 'G';
                    break;
                case 'h':
                    userString[i] = 'H';
                    break;
                case 'i':
                    userString[i] = 'I';
                    break;
                case 'j':
                    userString[i] = 'J';
                    break;
                case 'k':
                    userString[i] = 'K';
                    break;
                case 'l':
                    userString[i] = 'L';
                    break;
                case 'm':
                    userString[i] = 'M';
                    break;
                case 'n':
                    userString[i] = 'N';
                    break;
                case 'o':
                    userString[i] = 'O';
                    break;
                case 'p':
                    userString[i] = 'P';
                    break;
                case 'q':
                    userString[i] = 'Q';
                    break;
                case 'r':
                    userString[i] = 'R';
                    break;
                case 's':
                    userString[i] = 'S';
                    break;
                case 't':
                    userString[i] = 'T';
                    break;
                case 'u':
                    userString[i] = 'U';
                    break;
                case 'v':
                    userString[i] = 'V';
                    break;
                case 'w':
                    userString[i] = 'W';
                    break;
                case 'x':
                    userString[i] = 'X';
                    break;
                case 'y':
                    userString[i] = 'Y';
                    break;
                case 'z':
                    userString[i] = 'Z';
                    break;
                }
                string[i] = userString[i];
            }
            flag = 0;
        }
    } while (flag);
}