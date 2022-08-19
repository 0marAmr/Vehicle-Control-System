/*
 * main.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Omar Amr Mahmoud
 *      Group: 72
 */

#include <stdio.h>
#include "prototypes.h"

int main(){
	while(1){
		main_menu();
		sensors_set_menu();
	}
}

void main_menu(){
	while (1){
		char choice;
		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n");
		fflush(stdout);
		scanf(" %c",&choice);
		switch(choice){
		case 'a':
		case 'A':
			printf("Turn ON the vehicle engine\n\n");
			return;
		case 'b':
		case 'B':
			printf("Turn OFF the vehicle engine\n\n");
			break;
		case 'c':
			printf("Quit the system\n\n");
			exit(0);
		default:
			printf("Error, please choose a valid option!\n\n");
		}
	}
}

void sensors_set_menu(){
	char choice;

	printf("a. Turn off the engine\n");
	printf("b. Set the traffic light color\n");
	printf("c. Set the room temperature\n");
	printf("d. Set the engine temperature\n");
	fflush(stdout);
	scanf(" %c",&choice);

	switch(choice){
	case 'a':
	case 'A':
		printf("Turn OFF the vehicle engine\n\n");		return;
	case 'b':
	case 'B':
		printf("Set the traffic light color.\n\n");

		break;
	case 'c':
	case 'C':
		printf("Set the room temperature\n\n");
	case 'd':
	case 'D':
		printf("Set the engine temperature\n\n");
	default:
		printf("Error, please choose a valid option!\n\n");
	}

}


