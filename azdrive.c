#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     leftDrive,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     rightDrive,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     rotator,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     flagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     leftTread,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     rightTread,    tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    flagExtender,         tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/* Copyright (c) 2013 AJ Stubberud. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
*/

#define DEBUG

#include "lib/util.h"
#include "lib/event.h"

#define MOTOR_SPEED_ROTATOR 100
#define TREAD_SPEED 50

task main()
{
    waitForStart();

    while (true) {
        // Drive controls
        motor[leftDrive] = joystickValue(1, 1, 2);
        motor[rightDrive] = joystickValue(1, 2, 2);

        // Tread controls
        if (joy1Btn(CONTROLLER_R1)) {
            // Suck in
            motor[leftTread] = TREAD_SPEED;
            motor[rightTread] = TREAD_SPEED;
        } else if (joy1Btn(CONTROLLER_R2)) {
            // Push out
            motor[leftTread] = -TREAD_SPEED;
            motor[rightTread] = -TREAD_SPEED;
        } else {
            motor[leftTread] = 0;
            motor[rightTread] = 0;
        }

        // Rotation controls
        if (joy1Btn(CONTROLLER_L1)) {
            motor[rotator] = MOTOR_SPEED_ROTATOR;
        } else if (joy1Btn(CONTROLLER_L2)) {
            motor[rotator] = -MOTOR_SPEED_ROTATOR;
        } else {
            motor[rotator] = 0;
        }

        // Twister controls
        if (joy1Btn(CONTROLLER_Y)) {
            servo[flagExtender] = 152;
        } else if (joy1Btn(CONTROLLER_A)) {
            servo[flagExtender] = 115;
        } else {
            //servo[flagExtender] = 135;
        }

        if (joy1Btn(CONTROLLER_X)) {
            motor[flagMotor] = 100;
        } else if (joy1Btn(CONTROLLER_B)) {
            motor[flagMotor] = -100;
        } else {
            motor[flagMotor] = 0;
        }
    }
}
