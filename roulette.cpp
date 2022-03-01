/*
	"Mini Roulette"
	Autor: Tymoteusz Legiêæ
*/

//includes
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>

//namespace
using namespace std;

//variables
string bet, playerName;
int roulette, amount, betAmount;
char choice;
string colors[37] {"", "red", "black", "red", "black", "red", "black", "red", "black", "red", "black", "black", "red", "black", "red", "black", "red", "black", "red", "red", "black", "red", "black", "red", "black", "red", "black", "red", "black", "black", "red", "black", "red", "black", "red", "black", "red"};
int columns[37] {0, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};

//functions
void rules();
void drawLine(int n, char symbol);

//main function
int main()
{
	//seeding number gen
	srand(time(0));
	
	//title stuff
	drawLine(50,'=');
	cout << "\t\tMINI ROULETTE\n";
	drawLine(50,'=');
	cout << "\n\nEnter your name: ";
	cin >> playerName;
	cout << "\n\nEnter deposit amount to play the game: $";
	cin >> amount;
	
	//game loop
	do
  {
		system("cls");
    rules();
    cout << "\nYour current balance is $" << amount << "\n";
    
    //bet
    do
    {
    	cout << playerName << ", enter amount to bet: $";
    	cin >> betAmount;
    	if (betAmount > amount)
    	{
    		cout << "You can't bet more than your balance\n\nRe-enter data\n";
			}
		} while (betAmount > amount);
		do
		{
			cout << playerName << ", place a bet: ";
			cin >> bet;
			if (bet != "black" && bet != "red" && bet != "even" && bet != "odd" && bet != "dozen1" && bet != "dozen2" && bet != "dozen3" && bet != "column1" && bet != "column2" && bet != "column3")
			{
				cout << "That is not a valid bet\n\nRe-enter data\n";
			}
		} while (bet != "black" && bet != "red" && bet != "even" && bet != "odd" && bet != "dozen1" && bet != "dozen2" && bet != "dozen3" && bet != "column1" && bet != "column2" && bet != "column3");
		
		//spinning the roulette
		cout << "Dealer spinns the roulette\n";
		sleep(2);
		cout << "The ball slows down\n";
		sleep(2);
		cout << "The ball stops: ";
		roulette = rand()%38;
		
		//checking win/lose
		if (bet == "black" || bet == "red") //for black and red
		{
			if (bet == "black" && colors[roulette] == "black") {
				cout << roulette << " " << colors[roulette] << "\nYou win";
				amount = amount + betAmount;
			} else if (bet == "black" && colors[roulette] != "black") {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			} else if (bet == "red" && colors[roulette] == "red") {
				cout << roulette << " " << colors[roulette] << "\nYou win";
				amount = amount + betAmount;
			}else if (bet == "red" && colors[roulette] != "red") {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			}
		}
		if (bet == "even" || bet == "odd") //for odd and even numbers
		{
			if (roulette == 0) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			} else if (bet == "even" && roulette % 2 == 0) {
				cout << roulette << " " << colors[roulette] << "\nYou win";
				amount = amount + betAmount;
			} else if (bet == "even" && roulette % 2 != 0) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			} else if (bet == "odd" && roulette % 2 == 1) {
				cout << roulette << " " << colors[roulette] << "\nYou win";
				amount = amount + betAmount;
			}else if (bet == "odd" && roulette % 2 != 1) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			}
		}
		if (bet == "dozen1" || bet == "dozen2" || bet == "dozen3") //for dozens
		{
			if (roulette == 0) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			} else if (bet == "dozen1" && roulette <= 12) {
				cout << roulette << " " << colors[roulette] << "\nYou win";
				amount = amount + betAmount * 2;
			} else if (bet == "dozen1" && roulette > 12) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			} else if (bet == "dozen2" && roulette > 12 && roulette <= 24) {
				cout << roulette << " " << colors[roulette] << "\nYou win";
				amount = amount + betAmount * 2;
			} else if (bet == "dozen2" && roulette <= 12 || roulette > 24) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			} else if (bet == "dozen3" && roulette > 24 && roulette <= 36) {
				cout << roulette << " " << colors[roulette] << "\nYou win";
				amount = amount + betAmount * 2;
			} else if (bet == "dozen3" && roulette <= 24) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			}
		}
		if (bet == "column1" || bet == "column2" || bet == "column3") //for columns
		{
			if (roulette == 0) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			} else if (bet == "column1" && columns[roulette] == 1) {
				cout << roulette << " " << colors[roulette] << "\nYou win";
				amount = amount + betAmount * 2;
			} else if (bet == "column1" && columns[roulette] != 1) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			} else if (bet == "column2" && columns[roulette] == 2) {
				cout << roulette << " " << colors[roulette] << "\nYou win";
				amount = amount + betAmount * 2;
			} else if (bet == "column2" && columns[roulette] != 2) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			} else if (bet == "column3" && columns[roulette] == 3) {
				cout << roulette << " " << colors[roulette] << "\nYou win";
				amount = amount + betAmount * 2;
			} else if (bet == "column3" && columns[roulette] != 3) {
				cout << roulette << " " << colors[roulette] << "\nYou lose";
				amount = amount - betAmount;
			}
		}
		
		//play again?
		cout << "\n";
		drawLine(50,'-');
		cout << playerName << ", You have $" << amount;
    if(amount == 0)
    {
      cout << "\nYou have no money to play";
    }
    cout << "\n\nDo you want to play again (Y/n)? ";		
    cin >> choice;
  }while(choice == 'Y'|| choice == 'y');
  
  //goodbye
  cout << "\n\n\n";
  drawLine(50,'=');
  cout << "\n\nThanks for playing the game. Your balance amount is $ " << amount << "\n\n";
  drawLine(50,'=');
 
  return 0;
}

//function definitions
void drawLine(int n, char symbol) {
  for(int i=0; i<n; i++)
    cout << symbol;
  cout << "\n" ;
}

void rules() {
	cout << "\n";
  drawLine(50,'-');
  cout << "\t\tRULES OF THE GAME\n";
  drawLine(50,'-');
  cout << "1. Choose how much you want to bet\n"
  << "2. Choose what you want to bet on. Possible bets:\n - even\n - odd\n - black\n - red\n - dozen1\n - dozen2\n - dozen3\n - column1\n - column2\n - column3\n"
  << "3. Win or lose\n";
  drawLine(50,'-');
}
