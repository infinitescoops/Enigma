/*
 * mainDecoder.c
 *
 *  Created on: Jan 29, 2016
 *      Author: moran
 */

#include<stdio.h>
#include<conio.h>

void army();
void navy();
void airForce();

int main() {

	int flag = 1;

	while(flag) {

		printf("\n\nUS Military Encryption Service\n");
		printf("Please input your branch of service:\n");
		printf("0-Exit\t1-Army\t2-Navy\t3-Air Force\n");
		kbhit();
		fflush(stdout);
		char in = getch();

		switch(in) {
			case '0':
				flag = 0;
				break;
			case '1':
				army();
				break;
			case '2':
				navy();
				break;
			case '3':
				airForce();
				break;
			default:
				printf("Error, please enter a valid military branch.\n");
				break;
		}
	}
	return 0;
}

void army() {
	printf("\nArmy decryption: Press '$' to exit\n:");
	while(1) {
		kbhit();
		char b = getch();
		//decryption algorithm: Wrap around
		if(b == '$') //EXIT CODE
			break;
		else if(b >= 49 && b <= 57) //NUMBERS
			printf("%c", b-1);
		else if(b == 48)
			printf("%c", 57);
		else if(b >= 66 && b <= 90) //CAPTIAL LETTERS
			printf("%c", b-1);
		else if(b == 65)
			printf("%c", 90);
		else if(b >= 98 && b <= 122) //LOWERCASE LETTERS
			printf("%c", b-1);
		else if(b == 97)
			printf("%c", 122);
		else if(b == 33) //SPACE
			printf("%c", 32);
		else if(b == 44) //EXCLAMATION POINT
			printf("%c", 33);
		else if(b == 46) //COMMA
			printf("%c", 44);
		else if(b == 63) //PERIOD
			printf("%c", 46);
		else if(b == 32) //QUESTION MARK
			printf("%c", 63);
		else {}
	}
}

void navy() {
	printf("\nNavy decryption: Press '$' to exit\n:");
	while(1) {
		kbhit();
		char b = getch();
		//decryption algorithm: Fold and Flip
		if(b == '$') //EXIT CODE
			break;
		else if(b >= 43 && b <= 52) { //if input is a number
			if(b == 32)
				printf("%c", 48); //print space
			else if(b == 33)
				printf("%c", 49); //print exclamation point
			else if(b == 44)
				printf("%c", 50); //print comma
			else if(b == 46)
				printf("%c", 51); //print period
			else if(b == 63)
				printf("%c", 52); //print question mark
			else
				printf("%c", b+5); //other numbers get swapped
		} else if(b == 53)
			printf("%c", 32); //space becomes 5
		else if(b == 54)
			printf("%c", 33); //exclamation becomes 6
		else if(b == 55)
			printf("%c", 44); //comma becomes 7
		else if(b == 56)
			printf("%c", 46); //period becomes 8
		else if(b == 57)
			printf("%c", 63); //question becomes 9
		else if(b >= 65 && b <= 90) { //upper case
					if(b >= 77 && b <= 90)
						printf("%c", b-13);
					else
						printf("%c", b+13);
				}
				else if(b >= 97 && b <= 122) { //lower case
					if(b >= 110 && b <= 122)
						printf("%c", b-13);
					else
						printf("%c", b+13);
				}
				else {}
	}
}

void airForce() {
	printf("\nAir Force decryption: Press '$' to exit\n:");
	while(1) {
		kbhit();
		char b = getch();
		//Encryption algorithm: Evens and Odds
		if(b == '$') //EXIT CODE
			break;
		else if(b >= 48 && b <= 57) { //NUMBERS
			if(b % 2)
				printf("%c", b+1);
			else
				printf("%c", b-1);
		}
		else if(b >= 65 && b <= 90) { //UPPERCASE
			if(b % 2)
				printf("%c", b+1);
			else
				printf("%c", b-1+32);
		}
		else if(b >= 97 && b <= 122) { //LOWERCASE
			if(b % 2)
				printf("%c", b+1);
			else
				printf("%c", b-1-32);
		}
		else if(b == 63) //SPACE
			printf("%c", 32);
		else if(b == 46) //EXCLAMATION POINT
			printf("%c", 33);
		else if(b == 44) //COMMA
			printf("%c", 44);
		else if(b == 33) //PERIOD
			printf("%c", 46);
		else if(b == 32) //QUESTION MARK
			printf("%c", 63);
		else {}
	}
}
