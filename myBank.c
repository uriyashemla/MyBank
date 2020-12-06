#include <stdio.h>
#include "myBank.h"

double bank [50][2]  = {0};
int check;

void Open(double amount){
    if (amount>0){
        for (int i = 0; i < 50; i++){
            if(i==49&&bank[i][1]!=0){
                printf("sorry there is no available account\n");
                break;
            }
            if(bank[i][1]==0){
                printf("New account number is: %d\n",i+901);
                bank[i][0] = amount;
                bank[i][1] = 1;
                break;
            }
        }
    }
    else{
        printf("Failed to read the amount\n");
    }
}

void Balance(int accountnum){
    if(accountnum>=901&&accountnum<=950){
        if (bank[accountnum-901][1]!=0){
            printf("The balance of account number %d is: %0.2f\n",accountnum,bank[accountnum-901][0]);
        }
        else{
            printf("This account is closed\n");
        }
    }    
    else{
        printf("the account number doesn't exist\n");
    }    
} 

void Deposite(int accountnum, double amount){
    if (accountnum>=901&&accountnum<=950){
        if (amount>=0){     
            if (bank[accountnum-901][1]!=0){
                bank[accountnum-901][0]+=amount;
                printf("your balance is:%0.2f\n",bank[accountnum-901][0]);
            }
            else{
                printf("the bank account is close\n");
            }
        }
        else{
            printf("you can't deposite negative amount\n");
        }    
    }
    else{
        printf("Failed to read the account number\n");
    }    
}

void Withdrawal(int accountnum, double withdraw){
    if (withdraw>0){
        if (bank[accountnum-901][1]!=0&&accountnum>=901&&accountnum<=950){
            if(bank[accountnum-901][0]>withdraw){
            bank[accountnum-901][0]-=withdraw;
            printf("The new balance is: %0.2f\n",bank[accountnum-901][0]);
            }
            else{
            printf("Cannot withdraw more than the balance\n");   
            }
        }    
        else{
         printf("the account number doesn't exist\n");
        }
    }    
    else{
        printf("you cant withdrawal negative amount\n");
    }
}

void Close(int accountnum){
    if (accountnum>=901&&accountnum<=950){
        if(bank[accountnum-901][1]!=0){
            bank[accountnum-901][1]=0;
            bank[accountnum-901][0]=0;
            printf("Closed account number %d\n", accountnum);
        }
        else{
        printf("the account is already closed\n");
        }
    }    
    else{
        printf("the account number doesn't exist\n");
    }
}

void Intereset(double precent){
    if (precent>0){
        for (int i = 0; i < 50; i++){
            if(bank[i][1]!=0){
                bank[i][0]*=(1+(precent/100));
            }
        }
        
    } 
    else{
        printf("Failed to read the interest rate\n");
    }   
}

void Print(){
    for (int i = 0; i < 50; i++){
        if(bank[i][1]!=0){
            printf("the balance of account number %d is: %0.2f\n",i+901,bank[i][0]);
        }
    }
}

void Exit(){
    for (int i = 0; i < 50; i++){
    bank[i][1]=0;
    bank[i][0]=0;
    }
}