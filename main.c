/* simulates a bank account, started 10/26/2021 */

#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>

typedef struct account {
    float balance;
    char name[20];
} account;

typedef struct bank {
    int numaccounts;
    account** accounts;
} bank;

bank* initbank() {
    bank* mybank = malloc(sizeof(bank));
    printf("Number of accounts: ");
    scanf("%d", &mybank->numaccounts);

    mybank->accounts = malloc(sizeof(account) * mybank->numaccounts);

    for(int i = 0; i < mybank->numaccounts; i++) {
        mybank->accounts[i] = malloc(sizeof(account));
        printf("\nName account %d: ", i + 1);
        scanf("%s", mybank->accounts[i]->name);
        printf("Current balance for %s: ", mybank->accounts[i]->name);
        scanf("%f", &mybank->accounts[i]->balance);
        printf("\n");
    }
    
    return mybank;
}

void displaybank(bank* mybank) {
    for(int i = 0; i < mybank->numaccounts; i++) {
        printf("| %d: %s | \ncurrent balance: $%.2f\n\n", i + 1, mybank->accounts[i]->name, mybank->accounts[i]->balance);
    }
}

int main() {
    bank* mybank = initbank();

    float paycheck;
    int day = 1, week = 1;
    int choice, from, to;
    float amount;

    system("cls");

    //day loop
    while (1) {
        //printf("week %d\n", week);
            
        system("cls");
        printf("---------------- day %d ----------------\n", day);
        displaybank(mybank);
        printf("-----------------------------------------\n\n");

        //menu loop
        while (1) {
            printf("1) transfer     2) end day\n\n");
            while (1) {
                printf("enter choice: ");
                scanf("%d", &choice);
                if (choice >= 1 && choice <= 2) break;
                else printf("invalid choice\n");
            }

            //make a transfer
            //move to one function pls you heathen
            if (choice == 1) {
                while(1) {
                    printf("from account: ");
                    scanf("%d", &from);
                    if (from <= mybank->numaccounts) break;
                    else printf("account does not exist\n");
                }

                while(1) {
                    printf("to account: ");
                    scanf("%d", &to);
                    if (to <= mybank->numaccounts) break;
                    else printf("account does not exist\n");
                }

                while(1) {
                    printf("amount: $");
                    scanf("%f", &amount);
                    if (amount <= mybank->accounts[from - 1]->balance) break;
                    else printf("amount too high\n");
                }

                mybank->accounts[from - 1]->balance -= amount;
                mybank->accounts[to - 1]->balance += amount;
            }

            if (choice == 2) break;

            system("cls");
            printf("---------------- day %d ----------------\n", day);
            displaybank(mybank);
            printf("-----------------------------------------\n\n");

        }

        if (day % 7 == 0) week++;
        day++;
    }
}