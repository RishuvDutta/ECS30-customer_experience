/*
 * customer_experience.c
 * Rishi Dutta 912790628
 * The program displays a menu of 4 options. The customer is able to make a decision and depending on the decision it will call a function to offer the customer a deal or allow the customer pay for their bill. If the customer is offered the deal it will increase, quit, or accept the deal depending on their decision.
 */
#include <stdio.h>
#include <stdlib.h>

char GetInput(void);
void SellUpgrade(int q_limit, int mbps, int mbps_increase, int price, int price_increase);
void PayBill(void);

int main(){
	char choice;
	printf("Welcome to CableCom! Please make a choice from the following options: \n1) Change your Password\n 2) Cancel your service\n 3) Schedule a service call\n 4) Pay your bill\n");
	scanf("%c", &choice);
	getchar();
	
	while (choice <= '0' || choice >= '5'){
	    printf("Please enter a number between 1 and 4.");
	    scanf("%c", &choice);
            getchar();
	}
	
	if (choice == '1'){
		SellUpgrade(2,10,1,50,1);
	}

	if  (choice == '2'){
		SellUpgrade(5,100,10,80,20);
	}
	
	if (choice == '3'){
                SellUpgrade(5,40,5,60,10);
	}
	
	if (choice == '4'){
		printf("We already have your credit card information and have charged you. Thanks for being a loyal customer!");
		return 0;
	}

}
/*
 * Output: The function returns the customer's response to the prompt 
 * Summary: The function asks the user to enter their choice, then it will record what decision the customer has made. If the customer does not pick "y", "n" or "q"the program asks the customer to re-enter a choice.
 */
char GetInput(void){
	char input;
	printf("Please enter your choice (y for yes, n for no, q for quit)");
	scanf("%lc", &input);
	while (input != 'y' || input != 'n' || input != 'q'){
	    printf("Please enter your choice (y for yes, n for no, q for quit)");
	    scanf("%c", &input);
	    getchar();
	}
	return input; 
}
/*
 * Input: if (input == 'q')
 * if (q>= q_limit)
 * if (input == 'y')
 * Summary: It gives the customer a prompt to see if they want to accept the offer that is offered to them. Depending on whether they accept the offer or not the amount of megabits per second and price increase, and if they press "q" enought times they quit the program 
 */
void SellUpgrade(int q_limit, int mbps, int mbps_increase, int price, int price_increase){
	int q = 0;
	char input;
	while (input != 'y'){
		printf("You are eligble for a limted time offer. You can get %d megabits per second for the low promotinal rate of $%d a month. Act now while supplies last.\n", mbps, price);
		char input = GetInput();
		if (input == 'q'){
			q = q + 1;
		}

		if (q >= q_limit) {
			return;
		}
		if (input == 'y'){
			printf("Great choice. Goodbye.\n");
			return;
		}
		
		mbps = mbps + mbps_increase;
		price = price + price_increase;
	}	
}

void PayBill(void){
	printf("We already have your credit card information and have charged you. Thanks for being a loyal customer!\n");
	return;
	}
