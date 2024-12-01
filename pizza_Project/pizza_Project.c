#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
//Sharon Olshanetsky
//ID: 318845740
//program description: the program will recieve a pizza order, will calculate the price and print the pizza picture
const double basic_Pizza_Price = 70.00;
const int olive_Price = 10;
const int mush_Price = 12;
const int tomato_Price = 9;
const int pineapple_Price = 14;
const int reg_Dough_Price = 0;
const int vegan_Price = 5;
const int whole_Wheat_Price = 3;
const int gluten_Free_Price = 4;
const int basic_Size = 2000;
const char reg_Dough_Char = 'r';
const char vegan_Char = 'v';
const char whole_Wheat_Char = 'w';
const char gluten_Free_Char = 'f';
const int basic_Length = 40;
const int basic_Width = 50;
const double all = 1;
const double half = 0.5;
const double quarter = 0.25;
const int delivery_Price = 15;
const double tax = 1.17;
const int one_Shekel = 1;
const int two_Shekel = 2;
const int five_Shekel = 5;
const int ten_Shekel = 10;
const int id_Max_Length = 9;
const int min_pizza_length = 10;
const int min_pizza_width = 10;
const int max_pizza_length = 40;
const int max_pizza_width = 80;

struct pizza {
	int length;
	int width;
	char dough_Type;
	double price;
	double part_Of_Pizza;
	double part_Of_Olives;
	double part_Of_Mush;
	double part_Of_Tomato;
	double part_Of_Pineapple;
	char char_Of_Topping;
};


void printLogo();
int checkIdLength();
int checkDigitId();
void printMenu(double basic_Pizza_Price, int basic_Length, int basic_Width, int olive_Price, int mush_Price, int tomato_Price, int pineapple_Price, int reg_Dough_Price, int vegan_Price, int whole_Wheat, int gluten_Free);
int validPizzaAmount();
int checkPizzaLength(int min_pizza_length, int max_pizza_length);
int checkPizzaWidth(int min_pizza_width, int max_pizza_width);
char scanDoughType();
double addDoughToPrice(char dough_Type, int pizza_Price, int part_Of_Pizza, int reg_Dough_Price, int vegan_Price, int whole_Wheat_Price, int gluten_Free_Price);
double checkToppingPart(double all, double half, double quarter);
double addToppingToSum(double sum_Of_Toppings, double part_Of_Topping);
double addToppingToPrice(double pizza_Price, double part_Of_Pizza, int topping_Price, double part_Of_Topping);
double checkExceededTopping(double sum_Of_Toppings, double part_Of_Topping);
void printPizzaDetails(int pizzaNum, int pizza_Length, int pizza_width, double pizza_price);
struct pizza reduceFromTopping(struct pizza, double quarter);
void printPizzaDrawing(int pizza_Length, int pizza_Width, struct pizza pizza1, double quarter, char top1, char top2, char top3, char top4);
double addDeliveryToPrice(double total_Price, int delivery_Price);
double printOrderDetails(int id, int pizza_Amount, double total_Price, double tax);
void calculatePayment(double price_With_Tax);

void main()
{
	struct pizza pizza1,updated_Pizza;
	int pizza_amount, i, id;
	char top1, top2, top3, top4;
	double sum_Of_Toppings = 0.0, total_Price = 0.0, total_Price_With_Tax;

	printLogo();
	id = checkDigitId();
	printMenu(basic_Pizza_Price, basic_Length, basic_Width, olive_Price, mush_Price, tomato_Price, pineapple_Price, reg_Dough_Price, vegan_Price, whole_Wheat_Price, gluten_Free_Price);
	pizza_amount = validPizzaAmount();
	for (i = 1; i <= pizza_amount; i++)
	{
		pizza1.part_Of_Olives = 0.0;
		pizza1.part_Of_Mush = 0.0;
		pizza1.part_Of_Tomato = 0.0;
		pizza1.part_Of_Pineapple = 0.0;
		pizza1.price = 0.0;
		printf("\n*************************************************\n");
		printf("Pizza #%d:\n\n", i);
		pizza1.length = checkPizzaLength(min_pizza_length, max_pizza_length);
		pizza1.width = checkPizzaWidth(min_pizza_width, max_pizza_width);
		pizza1.part_Of_Pizza = ((pizza1.length * pizza1.width) / (double)basic_Size);
		pizza1.price += pizza1.part_Of_Pizza * basic_Pizza_Price;
		pizza1.dough_Type = scanDoughType();
		pizza1.price = addDoughToPrice(pizza1.dough_Type, pizza1.price, pizza1.part_Of_Pizza, reg_Dough_Price, vegan_Price, whole_Wheat_Price, gluten_Free_Price);
		// this part scans the toppings choices
		printf("\nPlease choose the toppings:\n\n");

		printf("Olives (choose 0-3): \n");
		pizza1.part_Of_Olives = checkToppingPart(all, half, quarter);
		pizza1.price = addToppingToPrice(pizza1.price, pizza1.part_Of_Pizza, olive_Price, pizza1.part_Of_Olives);
		sum_Of_Toppings += pizza1.part_Of_Olives;

		if (sum_Of_Toppings < 1)
		{
			printf("\nMushrooms (choose 0-3): \n");
			pizza1.part_Of_Mush = checkToppingPart(all, half, quarter);
			pizza1.part_Of_Mush = checkExceededTopping(sum_Of_Toppings, pizza1.part_Of_Mush);
			sum_Of_Toppings = addToppingToSum(sum_Of_Toppings, pizza1.part_Of_Mush);

			if (sum_Of_Toppings < 1)
			{
				pizza1.price = addToppingToPrice(pizza1.price, pizza1.part_Of_Pizza, mush_Price, pizza1.part_Of_Mush);

				printf("\nTomatos (choose 0-3): \n");
				pizza1.part_Of_Tomato = checkToppingPart(all, half, quarter);
				pizza1.part_Of_Tomato = checkExceededTopping(sum_Of_Toppings, pizza1.part_Of_Tomato);
				sum_Of_Toppings = addToppingToSum(sum_Of_Toppings, pizza1.part_Of_Tomato);

				if (sum_Of_Toppings < 1)
				{
					pizza1.price = addToppingToPrice(pizza1.price, pizza1.part_Of_Pizza, tomato_Price, pizza1.part_Of_Tomato);

					printf("\nPineapple (choose 0-3): \n");
					pizza1.part_Of_Pineapple = checkToppingPart(all, half, quarter);
					pizza1.part_Of_Pineapple = checkExceededTopping(sum_Of_Toppings, pizza1.part_Of_Pineapple);
					sum_Of_Toppings = addToppingToSum(sum_Of_Toppings, pizza1.part_Of_Pineapple);
					if (sum_Of_Toppings <= 1)
					{
						pizza1.price = addToppingToPrice(pizza1.price, pizza1.part_Of_Pizza, pineapple_Price, pizza1.part_Of_Pineapple);
					}
				}
			}
		}
		printPizzaDetails(i, pizza1.length, pizza1.width, pizza1.price);
		total_Price += pizza1.price;
		//this part updates the topping part in order to print the pizza drawing
		updated_Pizza = reduceFromTopping(pizza1, quarter);
		top1 = updated_Pizza.char_Of_Topping;
		updated_Pizza = reduceFromTopping(updated_Pizza, quarter);
		top2 = updated_Pizza.char_Of_Topping;
		updated_Pizza = reduceFromTopping(updated_Pizza, quarter);
		top3 = updated_Pizza.char_Of_Topping;
		updated_Pizza = reduceFromTopping(updated_Pizza, quarter);
		top4 = updated_Pizza.char_Of_Topping;
		printPizzaDrawing(pizza1.length, pizza1.width, updated_Pizza, quarter, top1, top2, top3, top4);
		sum_Of_Toppings = 0;



	}
	total_Price = addDeliveryToPrice(total_Price, delivery_Price);
	total_Price_With_Tax = printOrderDetails(id, pizza_amount, total_Price, tax);
	calculatePayment(total_Price_With_Tax);


}

//the function will print the opening message and pizza logo
void printLogo()
{
	printf("Welcome to MTA-Pizza!\n\n");
	printf("*****\n");
	printf(" *** \n");
	printf("  *\n\n");
}

//the function will check the id length
int checkIdLength()
{
	int id;
	int tempId;
	int count = 0;
	bool isCorrect = false;
	while (isCorrect == false)
	{
		printf("Please enter your ID number:\n");
		scanf("%d", &id);
		tempId = id;
		while (tempId / 10 != 0)
		{
			count++;
			tempId = tempId / 10;
		}
		if (count > 9 || id <= 0)
		{
			printf("Invalid ID number! Try again.\n");
			count = 0;
		}
		else
		{
			isCorrect = true;
		}
	}
	return id;
}

//the function will check the check digit in the id
int checkDigitId()
{
	//first step
	int id = checkIdLength();
	int check_Digit_Entered = id % 10;
	int tempID;
	tempID = id / 10;
	int count = 0, sum = 0, num, real_Check_Digit;
	while (tempID != 0)
	{
		if (count == 0 || count % 2 == 0)
		{
			num = (tempID % 10) * 2;
			sum += (num % 10) + (num / 10);
			count++;
		}
		else
		{
			num = (tempID % 10) * 1;
			sum += (num % 10) + (num / 10);
			count++;
		}
		tempID = tempID / 10;
	}
	if (sum % 10 != 0)
	{
		real_Check_Digit = 10 - (sum % 10);
	}
	else
		real_Check_Digit = 0;
	if (real_Check_Digit != check_Digit_Entered)
	{
		printf("Invalid check digit! Try again.\n");
		id = checkDigitId();
	}
	return id;

}

//The function will print the pizza menu
void printMenu(double basic_Pizza_Price, int basic_Length, int basic_Width, int olive_Price, int mush_Price, int tomato_Price, int pineapple_Price, int reg_Dough_Price, int vegan_Price, int whole_Wheat_Price, int gluten_Free_Price)
{
	printf("\nOur menu:\n");
	printf("*********\n");
	printf("Basic pizza: %.2lf NIS for %dX%d size pizza\n\n", basic_Pizza_Price, basic_Length, basic_Width);
	printf("Toppings for basic size pizza:\n");
	printf("Olives: %d NIS\n", olive_Price);
	printf("Mushrooms: %d NIS\n", mush_Price);
	printf("Tomatoes: %d NIS\n", tomato_Price);
	printf("Pineapple: %d NIS\n\n", pineapple_Price);
	printf("Dough type for basic size pizza:\n");
	printf("Regular: %d NIS\n", reg_Dough_Price);
	printf("Vegan: %d NIS\n", vegan_Price);
	printf("Whole wheat: %d NIS\n", whole_Wheat_Price);
	printf("Gluten free: %d NIS\n\n", gluten_Free_Price);
}

//the function will check the amount of pizzas entered
int validPizzaAmount()
{
	int pizzaAmount;
	printf("How many pizzas would you like to order? ");
	scanf("%d", &pizzaAmount);
	while (pizzaAmount < 1)
	{
		printf("Invalid choice! Try again.\n");
		printf("How many pizzas would you like to order? ");
		scanf("%d", &pizzaAmount);
	}
	return pizzaAmount;
}

//the function will check the length of the current pizza
int checkPizzaLength(int min_pizza_length, int max_pizza_length)
{
	int length;
	printf("Please enter your pizza's length (cm): ");
	scanf("%d", &length);
	while (length % 2 != 0 || length < min_pizza_length || length > max_pizza_length)
	{
		printf("Invalid length! Try again.\n");
		printf("Please enter your pizza's length (cm): ");
		scanf("%d", &length);
	}
	return length;
}

//the function will check the width of the current pizza
int checkPizzaWidth(int min_pizza_width, int max_pizza_width)
{
	int pizzaWidth;
	printf("Please enter your pizza's width (cm): ");
	scanf("%d", &pizzaWidth);
	while (pizzaWidth % 2 != 0 || pizzaWidth < min_pizza_width || pizzaWidth > max_pizza_width)
	{
		printf("Invalid width! Try again.\n");
		printf("Please enter your pizza's width (cm): ");
		scanf("%d", &pizzaWidth);
	}
	return pizzaWidth;
}

//the function will print the dough menu, scan the dough type entered and check if it is valid
char scanDoughType()
{
	bool isRight = false;
	char pizza_Dough;
	while (isRight == false)
	{
		printf("\n");
		printf("Please enter the pizza's dough type:\n");
		printf("r - for regular\n");
		printf("v - for vegan\n");
		printf("w - for whole wheat\n");
		printf("f - for gluten-free\n");
		scanf(" %c", &pizza_Dough);
		switch (pizza_Dough)
		{
		case 'r':
			isRight = true;
			break;
		case 'v':
			isRight = true;
			break;
		case 'w':
			isRight = true;
			break;
		case 'f':
			isRight = true;
			break;
		default:
			printf("Invalid choice! Try again.\n");
			break;
		}
	}
	return pizza_Dough;
}

//the function will add the dough type price to the pizza price
double addDoughToPrice(char dough_Type, int pizza_Price, int part_Of_Pizza, int reg_Dough_Price, int vegan_Price, int whole_Wheat_Price, int gluten_Free_Price)
{
	switch (dough_Type)
	{
	case 'r':
		break;
	case 'v':
		pizza_Price += part_Of_Pizza * vegan_Price;
		break;
	case 'w':
		pizza_Price += part_Of_Pizza * whole_Wheat_Price;
		break;
	case 'f':
		pizza_Price += part_Of_Pizza * gluten_Free_Price;
		break;
	}
	return pizza_Price;

}

//the function will scan the topping choise and will check if it is valid
double checkToppingPart(double all, double half, double quarter)
{
	int topping_Choise;
	double topping_Part;
	bool isValid = false;
	while (isValid == false)
	{
		printf("0. None \n");
		printf("1. Whole pizza \n");
		printf("2. Half pizza \n");
		printf("3. Quarter pizza \n");
		scanf("%d", &topping_Choise);
		switch (topping_Choise)
		{
		case 0:
			topping_Part = 0;
			isValid = true;
			break;
		case 1:
			topping_Part = all;
			isValid = true;
			break;
		case 2:
			topping_Part = half;
			isValid = true;
			break;
		case 3:
			topping_Part = quarter;
			isValid = true;
			break;
		default:
			printf("Invalid choice! Try again.\n");
			break;
		}
	}
	return topping_Part;
}

//the function will get the topping part and will add the topping value to the pizza price
double addToppingToPrice(double pizza_Price, double part_Of_Pizza, int topping_Price, double part_Of_Topping)
{
	pizza_Price += part_Of_Pizza * part_Of_Topping * topping_Price;
	return pizza_Price;
}

double checkExceededTopping(double sum_Of_Toppings, double part_Of_Topping)
{
	while ((sum_Of_Toppings + part_Of_Topping) > 1)
	{
		printf("You have exceeded the maximum amount of toppings allowed on one pizza! Try again.\n");
		part_Of_Topping = checkToppingPart(all, half, quarter);
	}
	return part_Of_Topping;
}

//the function will get the part of topping and the sum of topping and will check if it exceeded the max amount
double addToppingToSum(double sum_Of_Toppings, double part_Of_Topping)
{
	sum_Of_Toppings += part_Of_Topping;
	return sum_Of_Toppings;
}

//the function will print the current pizza details
void printPizzaDetails(int pizzaNum, int pizza_Length, int pizza_width, double pizza_price)
{
	printf("\nPizza #%d details:\n", pizzaNum);
	printf("*******************\n");
	printf("Pizza size: %dx%d\n", pizza_Length, pizza_width);
	printf("Pizza price (without tax): %.2lf\n", pizza_price);
}

//the function will reduce a quarter from a given topping part
struct pizza reduceFromTopping(struct pizza pizza1, double quarter)
{
	if (pizza1.part_Of_Olives != 0)
	{
		pizza1.char_Of_Topping = 'O';
		pizza1.part_Of_Olives -= quarter;
	}
	else if (pizza1.part_Of_Mush != 0)
	{
		pizza1.char_Of_Topping = 'M';
		pizza1.part_Of_Mush -= quarter;
	}
	else if (pizza1.part_Of_Tomato != 0)
	{
		pizza1.char_Of_Topping = 'T';
		pizza1.part_Of_Tomato -= quarter;
	}
	else if (pizza1.part_Of_Pineapple != 0)
	{
		pizza1.char_Of_Topping = 'P';
		pizza1.part_Of_Pineapple -= quarter;
	}
	else
		pizza1.char_Of_Topping = ' ';
	return pizza1;
}
//the function will get the pizza details and print the pizza drawing 
void printPizzaDrawing(int pizza_Length, int pizza_Width, struct pizza pizza1, double quarter, char top1, char top2, char top3, char top4)
{
	int i,m, n;
	for (i = 0; i < pizza_Width; i++) // top half
	{
		printf("%c", pizza1.dough_Type);
	}
	printf("\n");
	for (i = 1; i < pizza_Length / 2; i++) // top half
	{
		for (m = 0; m < pizza_Width / 2; m++) // top left
		{
			if (m == 0)
				printf("%c", pizza1.dough_Type);
			else
			{
				printf("%c", top4);
			}

		}
		for (n = pizza_Width / 2; n < pizza_Width; n++) //top right
		{
			if (n == pizza_Width - 1)
				printf("%c", pizza1.dough_Type);
			else
			{
				printf("%c", top1);
			}
				
		}
		printf("\n");

	}
	for (i = pizza_Length / 2; i < pizza_Length-1; i++) // bottom half
	{
		for (m = 0; m < pizza_Width / 2; m++) // botoom left
		{
			if (m == 0)
				printf("%c", pizza1.dough_Type);
			else
			{
				printf("%c", top3);
			}
		}
		for (n = pizza_Width / 2; n < pizza_Width; n++) // bottom right
		{
			if (n == pizza_Width - 1)
				printf("%c", pizza1.dough_Type);
			else
			{
				printf("%c", top2);
			}
		}
		printf("\n");

	}
	for (i = 0; i < pizza_Width; i++) // top half
	{
		printf("%c", pizza1.dough_Type);
	}
	printf("\n");

}

//the function will ask if delivery is needed and will add delivery price to total price
double addDeliveryToPrice(double total_Price, int delivery_Price)
{
	bool isCorrect = false;
	int delivery;
	printf("\n*************************************************\n");
	while (isCorrect == false)
	{ 
	   printf("Do you want delivery for the price of 15 NIS? Enter 1 for delivery or 0 for pick - up: ");
	   scanf("%d", &delivery);
	   switch (delivery)
	   {
	      case 0:
			  isCorrect = true;
		     break;
	      case 1:
			  isCorrect = true;
		     total_Price += delivery_Price;
		     break;
	      default:
		     printf("Invalid choice! Try again.\n");
	   }
	}
	return total_Price;
}

//the function will print the order details
double printOrderDetails(int id, int pizza_Amount, double total_Price, double tax)
{
	double price_With_Tax;
	printf("\n");
	printf("Your order details:\n");
	printf("*******************\n");
	printf("ID number: %09d\n", id);
	printf("Number of pizzas: %d\n", pizza_Amount);
	printf("Total price: %.2lf\n", total_Price);
	price_With_Tax = total_Price * tax;
	printf("Total price with tax (rounded down): %d\n\n", (int)price_With_Tax);
	return (int)price_With_Tax;

}

//the function will calculate the remaining balance
void calculatePayment(double price_With_Tax)
{
	int payment_Received,payment_Remained, change, one_Shekel_Coins, two_Shekel_Coins, five_Shekel_Coins, ten_Shekel_Coins;
	printf("Please enter your payment: \n");
	scanf("%d", &payment_Received);
	// will get in if the payment was lower or higher than the price
	if (payment_Received != (int)price_With_Tax)
	{
		payment_Remained = (int)price_With_Tax - payment_Received;
		while (payment_Remained > 0)
		{
			printf("Your remaining balance is: %d\n", payment_Remained);
			printf("Please enter your payment: \n");
			scanf("%d", &payment_Received);
			payment_Remained = payment_Remained - payment_Received;
		}

		// will calculate the change in coins
		if (payment_Remained < 0)
		{
			change = (-1) * payment_Remained;
			printf("Your change is %d NIS using: \n", change);
			if ((change / ten_Shekel) > 0)
			{
				ten_Shekel_Coins = change / 10;
				printf("%d coin(s) of ten\n", ten_Shekel_Coins);
				change -= ten_Shekel_Coins * ten_Shekel;
			}
			if (change > 0 && (change / five_Shekel) > 0)
			{
				five_Shekel_Coins = change / five_Shekel;
				printf("%d coin(s) of five\n", five_Shekel_Coins);
				change -= five_Shekel_Coins * five_Shekel;
			}
			if (change > 0 && (change / two_Shekel) > 0)
			{
				two_Shekel_Coins = change / two_Shekel;
				printf("%d coin(s) of two\n", two_Shekel_Coins);
				change -= two_Shekel_Coins * two_Shekel;
			}
			if (change > 0 && (change / one_Shekel) > 0)
			{
				one_Shekel_Coins = change / one_Shekel;
				printf("%d coin(s) of one\n", one_Shekel_Coins);
				change -= one_Shekel_Coins * one_Shekel;
			}
			if (change == 0)
			{
				printf("Thank you for your order! \n");
			}
		}
		if (payment_Remained == 0)
			printf("Thank you for your order! \n");
	}
	else
		printf("Thank you for your order! \n");
}