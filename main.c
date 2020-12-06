#include <stdio.h>
#include "myBank.h"

int main(){
    char c=0;
    double amount;
    int accountnum;
    int check;

    while (c!='E'){
        printf("\nPlease choose a transaction type:\nO-Open Account\nB-Balance Inquiry\nD-Deposit\nW-Withdrawal\nC-Close Account\nI-Interest\nP-Print\nE-Exit\n");
        scanf(" %c",&c); 

        switch (c){
            case 'O':
            printf("Please enter amount for deposit: ");
            check = scanf(" %lf",&amount);
            if(check!=1){
                printf("Failed to read the amount\n");
            }
            else{
            Open(amount);}
            break;

            case 'B':
            printf("Please enter account number: ");
            check = scanf(" %d",&accountnum);
            if(check!=1){
                printf("Failed to read the account number\n");
            }
            else{Balance(accountnum);}
            break;

            case 'D':
            printf("Please enter account number: ");
            check = scanf(" %d",&accountnum);
            if(check!=0){
                printf("Enter amount to deposite: ");
                check = (scanf(" %lf",&amount));
                if(check!=0){
                     Deposite(accountnum, amount);
                }   
                else{
                printf("Failed to read the amount\n");
                }
            }
            else{
            printf("Failed to read the account number\n");
            }
            break;

            case 'W':
            printf("Please enter account number: ");
            check = scanf(" %d",&accountnum);
            if(check!=1){
                printf("Failed to read the account number\n");
                break;
            }
            else{
            printf("Please enter the amount to withdrawal: ");
            check = scanf(" %lf",&amount);
            if(check!=1){
                printf("Failed to read the amount\n");
            }else{
            Withdrawal(accountnum,amount);}
            }
            break;

            case 'C':
            printf("Please enter account number: ");
            check = scanf(" %d",&accountnum);
            if(check!=1){
                printf("Failed to read the account\n");
            }
            else{
            Close(accountnum);
            }
            break;

            case 'I':
            printf("Please enter interest rate: ");
            check = scanf(" %lf",&amount);
            if(check!=1){
                printf("Failed to read the interest rate\n");
            }
            else{
            Intereset(amount);}
            break;

            case 'P':
            Print();
            break;

            case 'E':
            Exit();
            break;

            default:
            printf("Invalid transaction type\n");  
            break;
        }     
    }
return 0;
}    
