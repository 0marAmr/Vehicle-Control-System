/*
 * prototypes.h
 *
 *  Created on: Aug 19, 2022
 *      Author: Omar
 */

#ifndef PROTOTYPES_H_
#define PROTOTYPES_H_
#define WITH_ENGINE_TEMP_CONTROLLER 1

struct vehicle_state{
	float vehicle_speed, room_temp,engine_temp;
	char engine_state, ETC_state, AC_state; //ETC: engine temperature controller
};
typedef struct vehicle_state vehicleState;

enum control_values{
	OFF,ON
};

void print_status(vehicleState* v_state);
void speed_protocol_30(struct vehicle_state* v_state);
void set_engine_temp(struct vehicle_state* v_state);
void set_traffic_light(float *speed);
void set_room_temp(struct vehicle_state* v_state);
void sensors_set_menu(struct vehicle_state* v_state);
void main_menu();

#endif /* PROTOTYPES_H_ */
