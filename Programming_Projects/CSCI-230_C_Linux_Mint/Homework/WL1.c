// Mason Motschke CSCI 230 - 01
# include <stdio.h>
# include <stdlib.h>

int main(){
float r = 0.25, b = 2000.00, p, interest, total_int = 0.0;
int month = 1;

printf("Enter Payment Amount: ");
scanf("%f", &p);
printf("\n");
printf("Interest Rate: %0.2f\n", r);
printf("Ammount Borrowed: %0.2f\n", b);
printf("Payment Amount: %0.2f\n", p);
printf("\n");
printf("Month: %d, Interest Due: $%0.2f, Balance: $%0.2f\n", month, interest = (r/12)*b, b);
month += 1;

b = b + interest - p; total_int += interest;

    while(b > 0){
        interest = (r / 12) * (b - p + interest);
        printf("Month: %d, Interest: $%0.2f, Balance: $%0.2f\n", month, interest, b);
        b = b - p + interest; month += 1; total_int += interest;
    }

printf("Month: %d, Interest: $%0.2f, Balance: $%0.2f\n", month, interest, b);
printf("\n");
printf("Total Interest Paid: $%0.2f\n", total_int);
printf("\n");
return 0;
}
