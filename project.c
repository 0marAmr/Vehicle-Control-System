/*
 * main.c
 *
 *  Created on: Aug 19, 2022
 *      Author: Omar Amr Mahmoud
 *      Group: 72
 */

#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"



int main(void){
	vehicleState VS = {0.0,18.0,60.0,OFF,OFF,OFF}; //initial sensors readings & states
	while(1){
		main_menu(&VS.engine_state);
		sensors_set_menu(&VS);
	}
	return 0;
}

void main_menu(char* eng_state){
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
			printf("\nTurn ON the vehicle engine\n\n");
			*eng_state=ON;
			return;
		case 'b':
		case 'B':
			printf("\nTurn OFF the vehicle engine\n\n");
			break;
		case 'c':
		case 'C':
			printf("\nQuit the system\n\n");
			exit(0);
		default:
			printf("Error, please choose a valid option!\n\n");
		}
	}
}

void sensors_set_menu(vehicleState* v_state){
	while(1){
		char choice;

		printf("a. Turn off the engine\n");
		printf("b. Set the traffic light color\n");
		printf("c. Set the room temperature\n");
#if WITH_ENGINE_TEMP_CONTROLLER
		printf("d. Set the engine temperature\n");
#endif
		fflush(stdout);
		scanf(" %c",&choice);

		switch(choice){
		case 'a':
		case 'A':
			return;
		case 'b':
		case 'B':
			set_traffic_light(&v_state->vehicle_speed);//Set the traffic light color.
			break;
		case 'c':
		case 'C':
			set_room_temp(v_state);					  //Set the room temperature
			break;
#if WITH_ENGINE_TEMP_CONTROLLER
		case 'd':
		case 'D':
			set_engine_temp(v_state); 				 //Set the engine temperature
#endif
			break;
		default:
			printf("Error, please choose a valid option!\n\n");
			continue;
		}
		if(v_state->vehicle_speed==30){
			speed_protocol_30(v_state);
		}
		print_status(v_state);
	}
}

void set_traffic_light(float *speed){
	char trr_light;

	printf("Enter the traffic light color: ");
	fflush(stdout);
	scanf(" %c",&trr_light);

	switch(trr_light){
	case 'g':
	case 'G':
		*speed = 100;
		break;
	case 'O':
	case 'o':
		*speed = 30;
		break;
	case 'R':
	case 'r':
		*speed = 0;
		break;
	default:
		printf("An error has occurred !\n\n");
	}
}

void set_room_temp(vehicleState* v_state){
	float room_temperature;

	printf("Enter room temperature value: ");
	fflush(stdout);
	scanf(" %f",&room_temperature);

	if(room_temperature<10 || room_temperature>30){
		v_state->AC_state=1;
		v_state->room_temp=20;
	}
	else{
		v_state->AC_state=0;
		v_state->room_temp=room_temperature;
	}
}

#if WITH_ENGINE_TEMP_CONTROLLER
void set_engine_temp(vehicleState* v_state){
	float engine_temperature;

	printf("Enter engine temperature value: ");
	fflush(stdout);
	scanf(" %f",&engine_temperature);

	if(engine_temperature<100 || engine_temperature>150){
		v_state->ETC_state=ON;
		v_state->engine_temp=125;
	}
	else{
		v_state->ETC_state=OFF;
		v_state->engine_temp=engine_temperature;
	}
}
#endif
void speed_protocol_30(vehicleState* v_state){
	if(!v_state->AC_state){
		v_state->AC_state=ON;
		v_state->room_temp = v_state->room_temp*(5.0/4)+1;}

#if WITH_ENGINE_TEMP_CONTROLLER
	if(!v_state->ETC_state){
		v_state->ETC_state=ON;
		v_state->engine_temp = v_state->engine_temp*(5.0/4)+1;
	}
#endif
}

void print_status(vehicleState* v_state){
	printf("\nEngine state:");
	v_state->engine_state?printf("ON\n"):printf("OFF\n");

	printf("AC: ");
	v_state->AC_state?printf("ON\n"):printf("OFF\n");

	printf("Vehicle Speed: %.2f Km/Hr\n",v_state->vehicle_speed);
	printf("Room Temperature: %.2f\n",v_state->room_temp);

#if WITH_ENGINE_TEMP_CONTROLLER
	printf("Engine Temperature Controller is ");
	v_state->ETC_state?printf("ON\n"):printf("OFF\n");
#endif

	printf("Engine Temperature: %.2f C\n\n",v_state->engine_temp);
}
