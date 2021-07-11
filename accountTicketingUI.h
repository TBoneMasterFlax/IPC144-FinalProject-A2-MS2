/*
    ==================================================
    Assignment #2 Milestone #2:
    ==================================================
    Name   : Tuan Nguyen
    ID     : 109062166
    Email  : tnguyen140@myseneca.ca
    Section: NFF
*/

#ifndef ACCOUNTTICKETINGUI_H_
#define ACCOUNTTICKETINGUI_H_

#include "account.h"
#include "ticket.h"

struct AccountTicketingData
{
    struct Account* accounts;   // array of accounts
    const int ACCOUNT_MAX_SIZE; // maximum elements for account array

    struct Ticket* tickets;     // array of tickets
    const int TICKET_MAX_SIZE;  // maximum elements for ticket array
};

void displayAccountSummaryHeader(void);
void displayAccountDetailHeader(void);
void displayAccountSummaryRecord(const struct Account* account);
void displayAccountDetailRecord(const struct Account* account);
void applicationStartup(struct AccountTicketingData* accountsAndTickets);
int menuLogin(struct AccountTicketingData* accountsAndTickets);
void menuAgent(struct AccountTicketingData* accountsAndTickets, const struct Account* userAccount);
void menuCustomer(struct AccountTicketingData* accountsAndTickets, const struct Account* userAccount);
int findAccountIndexByAcctNum(int accountNumber, const struct Account accounts[], int size, int prompt);
void displayAllAccountSummaryRecords(const struct Account accounts[], int size);
void displayAllAccountDetailRecords(const struct Account accounts[], int size);
// Pause execution until user enters the enter key
void pauseExecution(void);
int loginValidation(struct AccountTicketingData* accountsAndTickets);
void displayAgentTicketHeader(void);
void displayAgentTicketRecord(const struct Ticket* tickets);
void displayAgentTicketEnder(void);
void displayCustomerTicketHeader(void);
void displayCustomerTicketRecord(const struct Ticket* tickets);
void displayCustomerTicketEnder(void);
void viewNewAgentTickets(struct AccountTicketingData* accountsAndTickets);
void viewActiveAgentTickets(struct AccountTicketingData* accountsAndTickets);
void viewCustomerTickets(struct AccountTicketingData* accountsAndTickets, const struct Account* account);

#endif