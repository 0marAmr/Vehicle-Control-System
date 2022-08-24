# Vehicle-Control-System
<i><h3> Implement the following Vehicle Control system with the specifications listed below:</h3></i>

1. Ask the user if he/she wants:<br>
&nbsp;&nbsp;a. Turn on the vehicle engine<br>
&nbsp;&nbsp;b. Turn off the vehicle engine<br>
&nbsp;&nbsp;c. Quit the system<br>
2. If chose to “Quit the system”: Quit program<br>
3. If chose to “Turn off the vehicle engine”: Ask him/her again what he/she wants to do<br>
4. Once a choice has been chosen, print on screen the system state.<br>
5. If chose to “Turn on the vehicle engine”, display “Sensors set menu”, menu that simulates the vehicle sensors readings.<br>
&nbsp;&nbsp;a. Turn off the engine<br>
&nbsp;&nbsp;b. Set the traffic light color.<br>
&nbsp;&nbsp;c. Set the room temperature (Temperature Sensor)<br>
&nbsp;&nbsp;d. Set the engine temperature (Engine Temperature Sensor)<br>
6. While the engine is ON, menu in requirement 5 must be always displayed and waits for an answer.<br>
7. Based on the answer of requirement 6:<br>
**a. Based on traffic light data (Take it as input from console, we will assume that this is the sensor read value)**<br>
&emsp;&emsp;i. If the traffic light is ‘G’ set vehicle speed to 100 km/hr<br>
&emsp;&emsp;ii. If the traffic light is ‘O’ set vehicle speed to 30 km/hr<br>
&emsp;&emsp;iii. If the traffic light is ‘R’ set vehicle speed to 0 km/h<br>
**b. Based on room temperature data (Take it as input from console, we will assume that this is the sensor read value)<br>**
&emsp;&emsp;i. If temperature less than 10, Turn AC ON and set temperature to 20<br>
&emsp;&emsp;ii. If temperature is greater than 30, Turn AC ON and set temperature to 20<br>
&emsp;&emsp;iii. If temperature is otherwise, Turn AC OFF<br>
**c. Based on engine temperature data (Take it as input from console, we will assume that this is the sensor read value)<br>**
&emsp;&emsp;i. If temperature less than 100, Turn “Engine Temperature Controller” ON and set temperature to 125<br>
&emsp;&emsp;ii. If temperature is greater than 150, Turn “Engine Temperature Controller” ON and set temperature to 125<br>
&emsp;&emsp;iii. If temperature is otherwise, Turn “Engine Temperature Controller” OFF<br>
**d. If vehicle speed is 30 km/hr<br>**
&emsp;&emsp;i. Turn ON AC if it was OFF and set room temperature to: current temperature * (5/4) + 1<br>
&emsp;&emsp;ii. Turn ON “Engine Temperature Controller” if it was OFF and set engine temperature to: current temperature * (5/4) + 1
**e. Display the current vehicle state after applying 7.a to 7.d<br>**
&emsp;&emsp;i. Engine state: ON/OFF.<br>
&emsp;&emsp;ii. AC: ON/OFF.<br>
&emsp;&emsp;iii. Vehicle Speed.<br>
&emsp;&emsp;iv. Room Temperature.<br>
&emsp;&emsp;v. Engine Temperature Controller State.<br>
&emsp;&emsp;vi. Engine Temperature.<br>
8. If chose in menu of requirement 5 to “Turn off the engine”, the menu of requirement 1 must be displayed.<br>
