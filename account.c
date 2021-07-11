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
#include "account.h"
#include "accountTicketingUI.h"
#include <string.h>
#include <stdlib.h>

void getAccount(struct Account* account, int highestNumber)
{
    // ---------------------------------------------------------
    // Account Data: get user input
    // ---------------------------------------------------------
    printf("New Account Data (Account#:%d)\n", highestNumber);
    printf("----------------------------------------\n");

    // Add the necessary code to get user input for each Account member:
    account->account_number = highestNumber;
    printf("Enter the account type (A=Agent | C=Customer): ");
    account->account_type = getCharOption("AC");
    putchar('\n');
}

void getUserLogin(struct UserLogin* login)
{
    // ---------------------------------------------------------
    // UserLogin Data: get user input
    // ---------------------------------------------------------
    printf("User Login Data Input\n");
    printf("----------------------------------------\n");

    // Add the necessary code to get user input for each UserLogin member:

    getCStringNoWhiteSpace(login->login_name, 1, 10);
    printf("Enter the display name (30 chars max): ");
    getCString(login->display_name, 1, 30);
    getCStringPassword(login->password, 8);
    putchar('\n');
}

void getDemographic(struct Demographic* demographic)
{
    // ---------------------------------------------------------
    // Demographic Data: get user input
    // ---------------------------------------------------------
    printf("Demographic Data Input\n");
    printf("----------------------------------------\n");

    // Add the necessary code to get user input for each Demographic member:
    // NOTE: You will need to get the CURRENT YEAR to devise the appropriate range
    //       when prompting for the birth year data.  There is a function in the 
    //       commonHelpers library that gives you this!
    printf("Enter birth year (current age must be between 18 and 110): ");
    demographic->birth_year = getIntFromRange(currentYear() - 110, currentYear() - 18);
    printf("Enter the household Income: $");
    demographic->income = getPositiveDouble();
    printf("Enter the country (30 chars max.): ");
    getCStringCountry(demographic->country, 1, 30);
    putchar('\n');
}

void updateAccount(struct Account* account)
{
    int selection;
    int flag = 1;
    do
    {
        printf("\nAccount: %d - Update Options\n", account->account_number);
        printf("----------------------------------------\n");
        printf("1) Update account type (current value: %c)\n", account->account_type);
        printf("2) Login\n");
        printf("3) Demographics\n");
        printf("0) Done\n");
        printf("Selection: ");
        selection = getIntFromRange(0, 3);
        switch (selection)
        {
        case 0:
            flag = 0;
            break;
        case 1:
            putchar('\n');
            printf("Enter the account type (A=Agent | C=Customer): ");
            account->account_type = getCharOption("AC");
            break;
        case 2:
            updateUserLogin(&account->user_login);
            break;
        case 3:
            updateDemographic(&account->demographic);
            break;
        default:
            break;
        }
    } while (flag);
}

void updateUserLogin(struct UserLogin* login)
{
    int selection;
    int flag = 1;
    do
    {
        printf("\nUser Login: %s - Update Options\n", login->login_name);
        printf("----------------------------------------\n");
        printf("1) Display name (current value: %s)\n", login->display_name);
        printf("2) Password\n");
        printf("0) Done\n");
        printf("Selection: ");
        selection = getIntFromRange(0, 2);
        switch (selection)
        {
        case 0:
            flag = 0;
            break;
        case 1:
            putchar('\n');
            printf("Enter the display name (30 chars max): ");
            getCString(login->display_name, 1, 30);
            break;
        case 2:
            putchar('\n');
            getCStringPassword(login->password, 8);
            break;
        default:
            break;
        }
    } while (flag);
}

void updateDemographic(struct Demographic* demographic)
{
    int selection;
    int flag = 1;
    do
    {
        printf("\nDemographic Update Options\n");
        printf("----------------------------------------\n");
        printf("1) Household Income (current value: $%.2lf)\n", demographic->income);
        printf("2) Country (current value: %s)\n", demographic->country);
        printf("0) Done\n");
        printf("Selection: ");
        selection = getIntFromRange(0, 2);
        switch (selection)
        {
        case 0:
            flag = 0;
            break;
        case 1:
            putchar('\n');
            printf("Enter the household Income: $");
            demographic->income = getPositiveDouble();
            break;
        case 2:
            putchar('\n');
            printf("Enter the country (30 chars max.): ");
            getCStringCountry(demographic->country, 1, 30);
            break;
        default:
            break;
        }
    } while (flag);
}