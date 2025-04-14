/*******************************************************************************

 Bare Conductive Capacitive Proximity Sensor
 -------------------------------------------

 For Arduino boards. Use a large resistor, about 1M between pin 2 and 4 and
 connect pin 2 to a sensor, for example Electric Paint.

 Based on code by Paul Badger.

 Bare Conductive code written by Pascal Loose

 This work is licensed under a MIT license https://opensource.org/licenses/MIT

 Copyright (c) 2020, Bare Conductive

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.

*******************************************************************************/
// capacitive sensing includes
#include <CapacitiveSensor.h>

// capacitive sensing constant
CapacitiveSensor sensor1 = CapacitiveSensor(22,23);  // 1M resistor between pins 5 & 2, pin 2 is sensor pin
CapacitiveSensor sensor2 = CapacitiveSensor(24,25);
CapacitiveSensor sensor3 = CapacitiveSensor(26,27);
CapacitiveSensor sensor4 = CapacitiveSensor(28,29);

CapacitiveSensor sensor5 = CapacitiveSensor(30,31);
CapacitiveSensor sensor6 = CapacitiveSensor(32,33);
CapacitiveSensor sensor7 = CapacitiveSensor(34,35);
CapacitiveSensor sensor8 = CapacitiveSensor(36,37);

CapacitiveSensor sensor9 = CapacitiveSensor(38,39);
CapacitiveSensor sensor10 = CapacitiveSensor(40,41);
CapacitiveSensor sensor11 = CapacitiveSensor(42,43);
CapacitiveSensor sensor12 = CapacitiveSensor(44,45);

CapacitiveSensor sensor13 = CapacitiveSensor(46,47);
CapacitiveSensor sensor14 = CapacitiveSensor(48,49);
CapacitiveSensor sensor15 = CapacitiveSensor(50,51);
CapacitiveSensor sensor16 = CapacitiveSensor(52,53);

float led1val = 0;
float led2val = 0;
float led3val = 0;
float led4val = 0;

int potvals[16];
int potvals2[14];
  
#define led1 1
#define led2 2
// #define led3 11

int strand1[] = {0, 0, 0, 0};
int strand2[] = {0, 0, 0, 0};
int strand3[] = {0, 0, 0, 0};
int strand4[] = {0, 0, 0, 0};

bool strand1_locked = false;
bool strand2_locked = false;
bool strand3_locked = false;
bool strand4_locked = false;

bool core1_locked = false;
bool core2_locked = false;
bool core3_locked = false;
bool core4_locked = false;
bool core5_locked = false;
bool core6_locked = false;
bool core7_locked = false;
bool core8_locked = false;
bool core9_locked = false;
bool core10_locked = false;
bool core11_locked = false;
bool core12_locked = false;
bool core13_locked = false;
bool core14_locked = false;
bool core15_locked = false;
bool core16_locked = false;

bool braid1 = false;
bool braid2 = false;
bool braid3 = false;
bool braid4 = false;

int braid1val = 0;
int braid2val = 0;
int braid3val = 0;
int braid4val = 0;

//Mux control pins
// int s0 = 10;
// int s1 = 11;
// int s2 = 12;
// int s3 = 13;

// int s4 = 5;
// int s5 = 6;
// int s6 = 7;
// int s7 = 8;

//Mux in "SIG" pin
// int SIG_pin1 = 0;
// int SIG_pin2 = 1;

// bool braidListen = true;
// bool potListen = false;
// bool braid1Listen = false;
bool strand1Listen = true;
bool braid4Listen = false;
bool resetListen1 = false;
bool resetListen4 = false;

int tempo1 = 60;
int tempo2 = 60;
int tempo3 = 60;
int tempo4 = 60;

void setup() {
  Serial.begin(115200);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // pinMode(led3, OUTPUT);

  sensor1.capacitiveSensor(1); // allow one (single) calibration
  sensor2.capacitiveSensor(1);
  sensor3.capacitiveSensor(1);
  sensor4.capacitiveSensor(1);
  sensor5.capacitiveSensor(1);
  sensor6.capacitiveSensor(1);
  sensor7.capacitiveSensor(1);
  sensor8.capacitiveSensor(1);
  sensor9.capacitiveSensor(1);
  sensor10.capacitiveSensor(1);
  sensor11.capacitiveSensor(1);
  sensor12.capacitiveSensor(1);
  sensor13.capacitiveSensor(1);
  sensor14.capacitiveSensor(1);
  sensor15.capacitiveSensor(1);
  sensor16.capacitiveSensor(1);

  // pinMode(6, OUTPUT);

  // MUX stuff
  // pinMode(s0, OUTPUT); 
  // pinMode(s1, OUTPUT); 
  // pinMode(s2, OUTPUT); 
  // pinMode(s3, OUTPUT); 

  // digitalWrite(s0, LOW);
  // digitalWrite(s1, LOW);
  // digitalWrite(s2, LOW);
  // digitalWrite(s3, LOW);

  // pinMode(s4, OUTPUT); 
  // pinMode(s5, OUTPUT); 
  // pinMode(s6, OUTPUT); 
  // pinMode(s7, OUTPUT); 

  // digitalWrite(s4, LOW);
  // digitalWrite(s5, LOW);
  // digitalWrite(s6, LOW);
  // digitalWrite(s7, LOW);

  // delay(500);
}

void loop() {

  Serial.print(braid1val);
  Serial.print(" ");
  Serial.print(braid2val);
  Serial.print(" ");
  Serial.print(braid3val);
  Serial.print(" ");
  Serial.print(braid4val);
  Serial.print(" ");

  Serial.print(led1val);
  Serial.print(" ");
  Serial.print(led2val);
  Serial.print(" ");
  Serial.print(led3val);
  Serial.print(" ");
  Serial.print(led4val);
  Serial.print(" ");

  // for (int i = 0; i < 16; i++){
  //   Serial.print(potvals[i]);
  //   Serial.print(" ");

  //   if (i < 14){
  //     Serial.print(potvals2[i]);
  //     Serial.print(" ");
  //   } 
  // }

  Serial.println(" ");

  // Serial.println(resetListen1);

  // Serial.println(String("strand1_locked: ") + strand1_locked);
  // Serial.println(String("strand2_locked: ") + strand2_locked);
  // Serial.println(String("strand3_locked: ") + strand3_locked);

  // Serial.println(String("led1val: ") + led1val);
  // Serial.println(String("led2val: ") + led2val);
  // Serial.println(String("led3val: ") + led3val);

  // button press to select braids and begin braidListen

  // if (braidListen){

    if (strand1Listen){
      // listen to first strand only to determine braidval
      // Serial.println("strand1listen");

      for (int i = 0; i < 8; i++){

        if (!strand1_locked && !strand2_locked && !strand3_locked && !strand4_locked){

          float strand1_poss[] = {sensor1.capacitiveSensorRaw(20), sensor5.capacitiveSensorRaw(80), sensor6.capacitiveSensorRaw(100), sensor9.capacitiveSensorRaw(80), sensor11.capacitiveSensorRaw(100), sensor13.capacitiveSensorRaw(80), sensor14.capacitiveSensorRaw(80), sensor15.capacitiveSensorRaw(100)};

          if (strand1_poss[0] != -2 && strand1_poss[0] < 3350 && strand1_poss[1] != -2 && strand1_poss[1] < 1700 && strand1_poss[2] != -2 && strand1_poss[2] <= 1885 && strand1_poss[3] != -2 && strand1_poss[3] < 1860){
            strand1_locked = false;
            // Serial.println("strand1 is unlocked");
            } 
            
            // Serial.println("strand1 is listening");
            // Serial.println(String("strand1_poss: ") + strand1_locked);

            // core 1
            if (strand1_poss[0] >= 3545 || strand1_poss[0] == -2 && !core1_locked){
              // digitalWrite(led1, HIGH);
              led1val = .2;
              strand1[0] = 1;
              // strand1_poss[0] = sensor1.capacitiveSensorRaw(0);
              // strand1_locked = true;
              core1_locked = true;
            } else if (strand1_poss[0] != -2 && strand1_poss[0] < 3350 && core1_locked){
              // digitalWrite(led1, LOW);
              led1val = 0;
              strand1[0] = 0;
              core1_locked = false;
              // strand1_poss[0] = sensor1.capacitiveSensorRaw(20);
            }

            // core 5
            // if (strand1_poss[1] >= 1720 && !core6_locked){
            if (strand1_poss[1] == -2 && !core5_locked){
              // digitalWrite(led2, HIGH);
              led1val = .4;
              strand1[1] = 6;
              // strand1_poss[2] = sensor6.capacitiveSensorRaw(0);
              // strand1_locked = true;
              core5_locked = true;
            } else if (strand1_poss[1] != -2 && strand1_poss[1] < 1700 && core5_locked){
              // digitalWrite(led2, LOW);
              led1val = 0;
              strand1_poss[1] = sensor6.capacitiveSensorRaw(100);
              core5_locked = false;
            }

            // core 6
            // if (strand1_poss[1] >= 1720 && !core6_locked){
            if (strand1_poss[2] == -2 && !core6_locked){
              // digitalWrite(led2, HIGH);
              led1val = .4;
              strand1[1] = 6;
              // strand1_poss[2] = sensor6.capacitiveSensorRaw(0);
              // strand1_locked = true;
              core6_locked = true;
            } else if (strand1_poss[2] != -2 && strand1_poss[2] < 1700 && core6_locked){
              // digitalWrite(led2, LOW);
              led1val = 0;
              // strand1_poss[2] = sensor6.capacitiveSensorRaw(100);
              core6_locked = false;
            }

            // core 9
            // if (strand1_poss[1] >= 1720 && !core6_locked){
            if (strand1_poss[3] == -2 && !core6_locked){
              // digitalWrite(led2, HIGH);
              led1val = .6;
              strand1[1] = 6;
              // strand1_poss[2] = sensor6.capacitiveSensorRaw(0);
              // strand1_locked = true;
              core9_locked = true;
            } else if (strand1_poss[3] != -2 && core6_locked){
              // digitalWrite(led2, LOW);
              led1val = 0;
              // strand1_poss[2] = sensor6.capacitiveSensorRaw(100);
              core9_locked = false;
            }

            // core 11 // 1885 if strand 10 intersected
            // if (strand1_poss[2] >= 1900 && !core11_locked){
            if (strand1_poss[4] == -2 && !core11_locked){
              // digitalWrite(led3, HIGH);
              led1val = .6;
              strand1[2] = 11;
              // strand1_poss[4] = sensor11.capacitiveSensorRaw(0);
              // strand1_locked = true;
              core11_locked = true;
            } else if (strand1_poss[4] != -2 && strand1_poss[4] <= 1885 && core11_locked){
              // digitalWrite(led3, LOW);
              led1val = 0;
              strand1[2] = 0;
              // strand1_poss[4] = sensor11.capacitiveSensorRaw(100);
              core11_locked = false;
            }

            // core 13
            if (strand1_poss[5] == -2 && !core11_locked){
              // digitalWrite(led3, HIGH);
              led1val = .8;
              strand1[2] = 11;
              // strand1_poss[4] = sensor11.capacitiveSensorRaw(0);
              // strand1_locked = true;
              core13_locked = true;
            } else if (strand1_poss[5] != -2 && strand1_poss[5] <= 1885 && core11_locked){
              // digitalWrite(led3, LOW);
              led1val = 0;
              strand1[2] = 0;
              // strand1_poss[4] = sensor11.capacitiveSensorRaw(100);
              core13_locked = false;
            }

            // core 15 // 2083 if strand 14 intersected
            // if (strand1_poss[3] >= 2050 && !core15_locked){
            if (strand1_poss[7] == -2 && !core15_locked){
              // digitalWrite(led3, HIGH);
              led1val = .8;
              strand1[3] = 15;
              // strand1_poss[7] = sensor15.capacitiveSensorRaw(0);
              // strand1_locked = true;
              core15_locked = true;
            } else if (strand1_poss[7] != -2 && strand1_poss[3] < 1850 && core15_locked){
              // digitalWrite(led3, LOW);
              led1val = 0;
              strand1[3] = 0;
              // strand1_poss[7] = sensor15.capacitiveSensorRaw(100);
              core15_locked = false;
            }

            // float checkstrand1[] = {sensor2.capacitiveSensorRaw(20), sensor5.capacitiveSensorRaw(20), sensor7.capacitiveSensorRaw(20), sensor10.capacitiveSensorRaw(20), sensor12.capacitiveSensorRaw(20), sensor14.capacitiveSensorRaw(20), sensor16.capacitiveSensorRaw(20)};
            // Serial.print("strand 2: ");
            // Serial.println(checkstrand1[0]); // 2
            // Serial.print("strand 5: ");
            // Serial.println(checkstrand1[1]); // 5
            // Serial.print("strand 7: ");
            // Serial.println(checkstrand1[2]); // 7
            // Serial.print("strand 10: ");
            // Serial.println(checkstrand1[3]); // 10
            // Serial.print("strand 12: ");
            // Serial.println(checkstrand1[4]); // 12
            // Serial.print("strand 14: ");
            // Serial.println(checkstrand1[5]); // 14
            // Serial.print("strand 16: ");
            // Serial.println(checkstrand1[6]); // 16

            // Serial.print("core 1: ");
            // Serial.println(strand1_poss[0]); // 1
            // Serial.print("core 5: ");
            // Serial.println(strand1_poss[1]); // 5
            // Serial.print("core 6: ");
            // Serial.println(strand1_poss[2]); // 6
            // Serial.print("core 9: ");
            // Serial.println(strand1_poss[3]); // 9
            // Serial.print("core 11: ");
            // Serial.println(strand1_poss[4]); // 11
            // Serial.print("core 13: ");
            // Serial.println(strand1_poss[5]); // 13
            // Serial.print("core 14: ");
            // Serial.println(strand1_poss[6]); // 14
            // Serial.print("core 15: ");
            // Serial.println(strand1_poss[7]); // 15

            if (core1_locked && core6_locked && core11_locked && core15_locked){
              led1val = 1;
              strand1_locked = true;
              braid1 = true;
              strand1Listen = false;
              // Serial.println("STRAND 1 IS LOCKED");
            } else if (core1_locked && core5_locked && core9_locked && core13_locked){
              led1val = 1;
              strand1_locked = true;
              braid4 = true;
              braid4Listen = true;
              strand1Listen = false;
            }
            
            else {
              // led1val = 0;
              strand1Listen = true;
              braid1 = false;
              braid4 = false;
            }

            // Serial.print("strand_1 ");
            // Serial.print(i);
            // Serial.print(": ");
            // Serial.println(strand1_poss[i]);

            // Serial.print("strand1_ locked is: ");
            // Serial.println(strand1_locked);

            delay(5);

          // Serial.print("core_poss: ");
          // Serial.print(i);
          // Serial.print(" ");
          // Serial.println(strand1_poss[i]);

        } // if loop (all strands unlocked)

      } // for loop

    } // strand1Listen

    // check for reset

    if (resetListen1){

          // listen to strand1
          float strand1_in[] = {sensor1.capacitiveSensorRaw(20), sensor6.capacitiveSensorRaw(100), sensor11.capacitiveSensorRaw(100), sensor15.capacitiveSensorRaw(100)};

          // check to see if all intersections in strand1_in have been removed
          // if (strand1_in[0] < 2390 && strand1_in[1] < 296 && strand1_in[2] < 290 && strand1_in[3] < 359){ // old vals
          // if (strand1_in[0] < 3280 && strand1_in[1] < 1700 && strand1_in[2] < 1802 && strand1_in[3] < 1860){ // new vals
          // if (strand1_in[0] != -2 && strand1_in[0] < 3200 && strand1_in[1] != -2 && strand1_in[1] < 1700 && strand1_in[2] != -2 && strand1_in[2] <= 1885 && strand1_in[3] != -2 && strand1_in[3] < 1860){
            if (strand1_in[0] != -2 && strand1_in[1] != -2 && strand1_in[2] != -2 && strand1_in[3] != -2){
            led1val = 0;
            strand1_locked = false;
            // Serial.println("strand1 is unlocked");
           } 

          // listen to strand2
          float strand2_in[] = {sensor2.capacitiveSensorRaw(20), sensor5.capacitiveSensorRaw(20), sensor9.capacitiveSensorRaw(20), sensor14.capacitiveSensorRaw(20)};

          // check to see if all intersections in strand2 have been removed
          // if (strand2_in[0] < 2552 && strand2_in[1] < 272 && strand2_in[2] < 342 && strand2_in[3] < 336){ // old vals
          // if (strand2_in[0] != -2 && strand2_in[0] < 3600 && strand2_in[1] != -2 && strand2_in[1] < 1550 && strand2_in[2] != -2 && strand2_in[3] != -2 && strand2_in[3] < 1880){ // new vals
          if (strand2_in[0] != -2 && strand2_in[1] != -2  && strand2_in[2] != -2 && strand2_in[3] != -2){ // new vals
            led2val = 0;
            strand2_locked = false;
            // Serial.println("strand2_in is unlocked");
          }

          // listen to strand3
          float strand3_in[] = {sensor3.capacitiveSensorRaw(20), sensor7.capacitiveSensorRaw(20), sensor10.capacitiveSensorRaw(20), sensor13.capacitiveSensorRaw(20)};

          // check to see if all intersections in strand3 have been removed
          // if (strand3_in[0] < 2960 && strand3_in[1] <= 297 && strand3_in[2] < 280 && strand3_in[3] < 321){ // old vals
          //  if (strand3_in != -2 && strand3_in[0] < 3590 && strand3_in[1] != -2 && strand3_in[1] < 1600 && strand3_in[2] != -2 && strand3_in[3] != -2 && strand3_in[3] <= 1890){
            if (strand3_in[0] != -2  && strand3_in[1] != -2 && strand3_in[2] != -2 && strand3_in[3] != -2){
            led3val = 0;
            strand3_locked = false;
            // Serial.println("strand3 is unlocked");
          }

          else if (!strand1_locked && !strand2_locked && !strand3_locked){
            delay(4000);
            strand1Listen = true;
            resetListen1 = false;
          }

          // delay(3000);
        
        } // resetListen1

    if (resetListen4){

          // listen to strand1
          float strand1_in[] = {sensor1.capacitiveSensorRaw(20), sensor5.capacitiveSensorRaw(100), sensor9.capacitiveSensorRaw(100), sensor13.capacitiveSensorRaw(100)};

            if (strand1_in[0] != -2 && strand1_in[1] != -2 && strand1_in[2] != -2 && strand1_in[3] != -2){
            led1val = 0;
            strand1_locked = false;
            // Serial.println("strand1 is unlocked");
           } 

          // listen to strand2
          float strand2_in[] = {sensor2.capacitiveSensorRaw(20), sensor7.capacitiveSensorRaw(20), sensor12.capacitiveSensorRaw(20), sensor16.capacitiveSensorRaw(20)};

          if (strand2_in[0] != -2 && strand2_in[1] != -2  && strand2_in[2] != -2 && strand2_in[3] != -2){ // new vals
            led2val = 0;
            strand2_locked = false;
            // Serial.println("strand2_in is unlocked");
          }

          // listen to strand3
          float strand3_in[] = {sensor3.capacitiveSensorRaw(20), sensor6.capacitiveSensorRaw(20), sensor10.capacitiveSensorRaw(20), sensor15.capacitiveSensorRaw(20)};

            if (strand3_in[0] != -2  && strand3_in[1] != -2 && strand3_in[2] != -2 && strand3_in[3] != -2){
            led3val = 0;
            strand3_locked = false;
            // Serial.println("strand3 is unlocked");
          }

          // listen to strand3
          float strand4_in[] = {sensor4.capacitiveSensorRaw(20), sensor8.capacitiveSensorRaw(20), sensor11.capacitiveSensorRaw(20), sensor14.capacitiveSensorRaw(20)};

            if (strand3_in[0] != -2  && strand3_in[1] != -2 && strand3_in[2] != -2 && strand3_in[3] != -2){
            led4val = 0;
            strand4_locked = false;
            // Serial.println("strand3 is unlocked");
          }

          else if (!strand1_locked && !strand2_locked && !strand3_locked && !strand4_locked){
            delay(4000);
            strand1Listen = true;
            resetListen4 = false;
          }
        
        } // resetListen4

    if (braid1){
      
      for (int i = 0; i < 4; i++){

        // check if any strands are unlocked

        if (!strand2_locked || !strand3_locked) {

          braid1val = 0;

          // Serial.write(braid1val); ///////////////////////////////
          // Serial.write(led1val);
          // Serial.write(led2val);
          // Serial.write(led3val);
          // Serial.println(); /////////////////////////////////////

          // Serial.println();
          // Serial.print(String("braid1val is: ") + braid1val);
          // Serial.print(String(" led1val: ") + led1val);
          // Serial.print(String(" led2val: ") + led2val);
          // Serial.println(String(" led3val: ") + led3val);

          // listen to strand1 // not sure why i was checking outside of the loop

          // check to see if all intersections in strand1_in have been removed
          
          
          // if (!strand1_locked){ // 

          //   float strand1_in[] = {sensor1.capacitiveSensorRaw(20), sensor6.capacitiveSensorRaw(100), sensor11.capacitiveSensorRaw(100), sensor15.capacitiveSensorRaw(100)};

          //   if (strand1_in[0] != -2 && strand1_in[0] < 3200 && strand1_in[1] != -2 && strand1_in[1] < 1700 && strand1_in[2] != -2 && strand1_in[2] <= 1885 && strand1_in[3] != -2 && strand1_in[3] < 1860){
          //   strand1_locked = false;
          //   // Serial.println("strand1 is unlocked");
          //   } 
            
          //   // Serial.println("strand1 is listening");
          //   // Serial.println(String("strand1_in: ") + strand1_locked);

          //   // core 1
          //   if (strand1_in[0] >= 3250 && !core1_locked || strand1_in[0] == -2 && !core1_locked){
          //     // digitalWrite(led1, HIGH);
          //     // led1val = 1;
          //     strand1[0] = 1;
          //     strand1_in[0] = sensor1.capacitiveSensorRaw(0);
          //     // strand1_locked = true;
          //     core1_locked = true;
          //   } else if (strand1_in[0] != -2 && strand1_in[0] < 3200 && core1_locked){
          //     // digitalWrite(led1, LOW);
          //     // led1val = 0;
          //     strand1[0] = 0;
          //     core1_locked = false;
          //     strand1_in[0] = sensor1.capacitiveSensorRaw(20);
          //   }

          //   // core 6
          //   // if (strand1_in[1] >= 1720 && !core6_locked){
          //   if (strand1_in[1] == -2 && !core6_locked){
          //     // digitalWrite(led2, HIGH);
          //     // led6val = 1;
          //     strand1[1] = 6;
          //     strand1_in[1] = sensor6.capacitiveSensorRaw(0);
          //     // strand1_locked = true;
          //     core6_locked = true;
          //   } else if (strand1_in[1] != -2 && strand1_in[1] < 1700 && core6_locked){
          //     // digitalWrite(led2, LOW);
          //     // led6val = 0;
          //     strand1_in[1] = sensor6.capacitiveSensorRaw(100);
          //     core6_locked = false;
          //   }

          //   // core 11 // 1885 if strand 10 intersected
          //   // if (strand1_in[2] >= 1900 && !core11_locked){
          //   if (strand1_in[2] == -2 && !core11_locked){
          //     // digitalWrite(led3, HIGH);
          //     // led11val = 1;
          //     strand1[2] = 11;
          //     strand1_in[2] = sensor11.capacitiveSensorRaw(0);
          //     // strand1_locked = true;
          //     core11_locked = true;
          //   } else if (strand1_in[2] != -2 && strand1_in[2] <= 1885 && core11_locked){
          //     // digitalWrite(led3, LOW);
          //     // led11val = 0;
          //     strand1[2] = 0;
          //     strand1_in[2] = sensor11.capacitiveSensorRaw(100);
          //     core11_locked = false;
          //   }

          //   // core 15 // 2083 if strand 14 intersected
          //   // if (strand1_in[3] >= 2050 && !core15_locked){
          //   if (strand1_in[3] == -2 && !core15_locked){
          //     // digitalWrite(led3, HIGH);
          //     // led15val = 1;
          //     strand1[3] = 15;
          //     strand1_in[3] = sensor15.capacitiveSensorRaw(0);
          //     // strand1_locked = true;
          //     core15_locked = true;
          //   } else if (strand1_in[3] != -2 && strand1_in[3] < 1850 && core15_locked){
          //     // digitalWrite(led3, LOW);
          //     // led15val = 0;
          //     strand1[3] = 0;
          //     strand1_in[3] = sensor15.capacitiveSensorRaw(100);
          //     core15_locked = false;
          //   }

          //   // float checkstrand1[] = {sensor2.capacitiveSensorRaw(20), sensor5.capacitiveSensorRaw(20), sensor7.capacitiveSensorRaw(20), sensor10.capacitiveSensorRaw(20), sensor12.capacitiveSensorRaw(20), sensor14.capacitiveSensorRaw(20), sensor16.capacitiveSensorRaw(20)};
          //   // Serial.print("strand 2: ");
          //   // Serial.println(checkstrand1[0]); // 2
          //   // Serial.print("strand 5: ");
          //   // Serial.println(checkstrand1[1]); // 5
          //   // Serial.print("strand 7: ");
          //   // Serial.println(checkstrand1[2]); // 7
          //   // Serial.print("strand 10: ");
          //   // Serial.println(checkstrand1[3]); // 10
          //   // Serial.print("strand 12: ");
          //   // Serial.println(checkstrand1[4]); // 12
          //   // Serial.print("strand 14: ");
          //   // Serial.println(checkstrand1[5]); // 14
          //   // Serial.print("strand 16: ");
          //   // Serial.println(checkstrand1[6]); // 16

          //   if (core1_locked && core6_locked && core11_locked && core15_locked){
          //     led1val = 1;
          //     strand1_locked = true;
          //     // Serial.println("STRAND 1 IS LOCKED");
          //   } else {
          //     led1val = 0;
          //   }

          //   // Serial.print("strand_1 ");
          //   // Serial.print(i);
          //   // Serial.print(": ");
          //   // Serial.println(strand1_in[i]);

          //   // Serial.print("strand1_ locked is: ");
          //   // Serial.println(strand1_locked);

          //   delay(5);

          // } 

          if (!strand2_locked){

            // listen to strand2
            float strand2_in[] = {sensor2.capacitiveSensorRaw(20), sensor5.capacitiveSensorRaw(80), sensor9.capacitiveSensorRaw(80), sensor14.capacitiveSensorRaw(80)};

            // check to see if all intersections in strand2 have been removed
            // if (strand2_in[0] < 3600 && strand2_in[1] < 1425 && strand2_in[2] < 1480 && strand2_in[3] < 1520){
              if (strand2_in[0] != -2 && strand2_in[0] < 3600 && strand2_in[1] != -2 && strand2_in[1] < 1550 && strand2_in[2] != -2 && strand2_in[3] != -2 && strand2_in[3] < 1820){
              strand2_locked = false;
              // Serial.println("strand2_in is unlocked");
            }

            // if (!strand2_locked){ // 

              // Serial.println("strand2 is listening");
              // Serial.println(String("strand2_in: ") + strand2_locked);

              // core 2
              // if (strand2_in[0] >= 3660 && !core2_locked){
              if (strand2_in[0] >= 3660 || strand2_in[0] == -2 && !core2_locked){
                // digitalWrite(led1, HIGH);
                led2val = .2;
                strand2[0] = 2;
                core2_locked = true;
              // 
              } else if (strand2_in[0] != -2 || strand2_in[0] < 3600 && core2_locked){
                // digitalWrite(led1, LOW);
                led2val = 0;
                strand2[0] = 0;
                core2_locked = false;
              }

              // core 5
              // if (strand2_in[1] >= 1480 && !core5_locked){
              if (strand2_in[1] == -2 || strand2_in[1] >= 1600 && !core5_locked){
                // digitalWrite(led2, HIGH);
                led2val = .4;
                strand2[1] = 5;
                core5_locked = true;
              // } else if (strand2_in[1] < 1425 && core5_locked){
                } else if (strand2_in[1] != -2 || strand2_in[1] < 1550 && core5_locked){
                // digitalWrite(led2, LOW);
                led2val = 0;
                strand2[1] = 0;
                core5_locked = false;
              }

              // core 9
              // if (strand2_in[2] >= 1510 && !core9_locked){
              if (strand2_in[2] == -2 || strand2_in[2] > 1700 && !core9_locked){
                // digitalWrite(led3, HIGH);
                led2val = .6;
                strand2[2] = 9;
                core9_locked = true;
              // } else if (strand2_in[2] < 1480 && core9_locked){
              } else if (strand2_in[2] != -2 && core9_locked){
                // digitalWrite(led3, LOW);
                led2val = 0;
                strand2[2] = 0;
                core9_locked = false;
              }

              // ledval 14
              // if (strand2_in[3] >= 1530 && !core14_locked){
              if (strand2_in[3] == -2 || strand2_in[3] > 1880 && !core14_locked){
                // digitalWrite(led3, HIGH);
                led2val = .8;
                strand2[3] = 14;
                core14_locked = true;
              // } else if (strand2_in[3] < 1520 && core14_locked){
              } else if (strand2_in[3] != -2 && strand2_in[3] < 1820 && core14_locked){
                // digitalWrite(led3, LOW);
                led2val = 0;
                strand2[3] = 0;
                core14_locked = false;
              }

              float checkstrand2[] = {sensor3.capacitiveSensorRaw(3), sensor4.capacitiveSensorRaw(20), sensor7.capacitiveSensorRaw(20), sensor8.capacitiveSensorRaw(20), sensor10.capacitiveSensorRaw(20), sensor12.capacitiveSensorRaw(20), sensor13.capacitiveSensorRaw(20), sensor16.capacitiveSensorRaw(20)};
              // Serial.print("core 3: ");
              // Serial.println(checkstrand2[0]); // 3
              // Serial.print("core 4: ");
              // Serial.println(checkstrand2[1]); // 4
              // Serial.print("core 8: ");
              // Serial.println(checkstrand2[2]); // 8
              // Serial.print("core 10: ");
              // Serial.println(checkstrand2[3]); // 10
              // Serial.print("core 12: ");
              // Serial.println(checkstrand2[4]); // 12
              // Serial.print("core 13: ");
              // Serial.println(checkstrand2[5]); // 13
              // Serial.print("core 16: ");
              // Serial.println(checkstrand2[6]); // 16

              for (int i = 0; i < 8; i++){
                if (checkstrand2[i] != -2){
                  if (core2_locked && core5_locked && core9_locked && core14_locked){
                  led2val = 1;
                  strand2_locked = true;
                  // Serial.println("STRAND 2 IS LOCKED");
                  } else {
                    // led2val = 0;
                  }
                }
              }

              // Serial.print("strand_2 ");
              // Serial.print(i);
              // Serial.print(": ");
              // Serial.println(strand2_in[i]);

              // Serial.print("strand2_locked is: ");
              // Serial.println(strand2_locked);

              delay(5);

            // }

          }

          else if (!strand3_locked){

            // listen to strand3
            float strand3_in[] = {sensor3.capacitiveSensorRaw(20), sensor7.capacitiveSensorRaw(80), sensor10.capacitiveSensorRaw(80), sensor13.capacitiveSensorRaw(80)};

            // check to see if all intersections in strand3 have been removed
            // if (strand3_in[0] < 3350 && strand3_in[1] < 1490 && strand3_in[2] < 1380 && strand3_in[3] < 1620){
              if (strand3_in != -2 && strand3_in[0] < 3590 && strand3_in[1] != -2 && strand3_in[1] < 1600 && strand3_in[2] != -2 && strand3_in[3] != -2 && strand3_in[3] <= 1890){
              strand3_locked = false;
              // Serial.println("strand3_in is unlocked");
            }

            // if (!strand3_locked){ // 

              // Serial.println("strand3 is listening");
              // Serial.println(String("strand3_in: ") + strand3_locked);

              // core 3
              // if (strand3_in[0] >= 3430 && !core3_locked){
                if (strand3_in[0] >= 3700 || strand3_in[0] == -2 && !core3_locked){
                // digitalWrite(led1, HIGH);
                led3val = .2;
                strand3[0] = 3;
                core3_locked = true;
              // } else if (strand3_in[0] < 3350 && core3_locked){
                } else if (strand3_in[0] < 3500 && strand3_in[0] != -2 && core3_locked){
                // digitalWrite(led1, LOW);
                led3val = 0;
                strand3[0] = 0;
                core3_locked = false;
              }

              // Serial.println(String("core3_locked: ") + core3_locked);

              // core 7
              // if (strand3_in[1] >= 1505 && !core7_locked){ // not registering with strand
              if (strand3_in[1] == -2 || strand3_in[1] > 1640 && !core7_locked){
                // digitalWrite(led2, HIGH);
                led3val = .4;
                strand3[1] = 7;
                core7_locked = true;
              // } else if (strand3_in[1] < 1490 && core7_locked){
              } else if (strand3_in[1] != -2 && strand3_in[1] < 1600 && core7_locked){
                // digitalWrite(led2, LOW);
                led3val = 0;
                strand3[1] = 0;
                core7_locked = false;
              }

              // Serial.println(String("core7_locked: ") + core7_locked);

              // core 10
              // if (strand3_in[2] >= 1435 && !core10_locked){
              if (strand3_in[2] == -2 && !core10_locked){
                // digitalWrite(led3, HIGH);
                led3val = .6;
                strand3[2] = 10;
                core10_locked = true;
              // } else if (strand3_in[2] < 1380 && core10_locked){
              } else if (strand3_in[2] != -2 && core10_locked){
                // digitalWrite(led3, LOW);
                led3val = 0;
                strand3[2] = 0;
                core10_locked = false;
              }

              // Serial.println(String("core10_locked: ") + core10_locked);

              // core 13
              // if (strand3_in[3] >= 4000 && !core13_locked){
              if (strand3_in[3] == -2 || strand3_in[3] >= 1900 && !core13_locked){
                // digitalWrite(led3, HIGH);
                led3val = .8;
                strand3[3] = 13;
                core13_locked = true;
              // } else if (strand3_in[3] < 1620 && core13_locked){
              } else if (strand3_in[3] != -2 && strand3_in[3] < 1890 && core13_locked){
                // digitalWrite(led3, LOW);
                led3val = 0;
                strand3[3] = 0;
                core13_locked = false;
              }

              float checkstrand3[] = {sensor4.capacitiveSensorRaw(20), sensor8.capacitiveSensorRaw(20), sensor12.capacitiveSensorRaw(20), sensor16.capacitiveSensorRaw(20)};
              

              if (core3_locked && core7_locked && core10_locked && core13_locked && checkstrand3[i] != -2){
                led3val = 1;
                strand3_locked = true;
                // Serial.println("STRAND 3 IS LOCKED");
              } else {
                // led3val = 0;
              }

              // Serial.print("strand_3 ");
              // Serial.print(i);
              // Serial.print(": ");
              // Serial.println(strand3_in[i]);

              // Serial.print("strand3_locked is: ");
              // Serial.println(strand3_locked);

              delay(5);

            // }

          } // strand 3

        } // if loop

        // check for complete braid

        else if (strand1_locked && strand2_locked && strand3_locked){

          // three strand
          // if (strand1[0] == 1 && strand1[1] == 6 && strand1[2] == 11 && strand1[3] == 15 && strand2[0] == 2 && strand2[1] == 5 && strand2[2] == 9 && strand2[3] == 14 && strand3[0] == 3 && strand3[1] == 7 && strand3[2] == 10 && strand3[3] == 13){
            
            braid1val = 1;
            delay(3000);
            resetListen1 = true;
            braid1 = false;

            // Serial.println(String("braid1val is: ") + braid1val);
            
            // Serial.write(braid1val); //////////////////////////////////
            // Serial.write(led1val);
            // Serial.write(led2val);
            // Serial.write(led3val);
            // Serial.println(); ////////////////////////////////////////

            // Serial.print(String("braid1val is: ") + braid1val);
            // Serial.print(String(" led1val: ") + led1val);
            // Serial.print(String(" led2val: ") + led2val);
            // Serial.println(String(" led3val: ") + led3val);

            // braidListen = false;
            // potListen = true;

          // } 

          // unlock strands here? maybe need a check strands function

          
        } // if all strands locked

      } // for loop

    } // braid1 (3 strand)

    else if (braid4){

      for (int i = 0; i < 4; i++){

        // check if any strands are unlocked

        if (!strand2_locked || !strand3_locked || !strand4_locked) {

          braid4val = 0;

          // check to see if all intersections in strand2_in have been removed
          
          if (!strand2_locked){ // 

            float strand2_in[] = {sensor2.capacitiveSensorRaw(20), sensor7.capacitiveSensorRaw(100), sensor12.capacitiveSensorRaw(100), sensor16.capacitiveSensorRaw(100)};

            if (strand2_in[0] != -2 && strand2_in[0] < 3995 && strand2_in[1] != -2 && strand2_in[1] < 1700 && strand2_in[2] != -2 && strand2_in[2] <= 1885 && strand2_in[3] != -2 && strand2_in[3] < 2200){
            strand2_locked = false;
            // Serial.println("strand1 is unlocked");
            } 
            
            // Serial.println("strand2 is listening");
            // Serial.println(String("strand2_in: ") + strand1_locked);

            // core 2
            if (strand2_in[0] >= 4050 && !core2_locked || strand2_in[0] == -2 && !core2_locked){
              // digitalWrite(led1, HIGH);
              led2val = .2;
              strand2[0] = 2;
              // strand1_locked = true;
              core2_locked = true;
            } else if (strand2_in[0] != -2 && strand2_in[0] < 3995 && core2_locked){
              // digitalWrite(led1, LOW);
              led2val = 0;
              strand2[0] = 0;
              core2_locked = false;
            }

            // core 7
            // if (strand2_in[1] >= 1720 && !core6_locked){
            if (strand2_in[1] == -2 && !core7_locked){
              // digitalWrite(led2, HIGH);
              led2val = .4;
              strand2[1] = 7;
              // strand1_locked = true;
              core7_locked = true;
            } else if (strand2_in[1] != -2 && strand2_in[1] < 1700 && core7_locked){
              // digitalWrite(led2, LOW);
              strand2[1] = 0;
              led2val = 0;
              core7_locked = false;
            }

            // core 12
            // if (strand2_in[2] >= 1900 && !core11_locked){
            if (strand2_in[2] == -2 && !core12_locked){
              // digitalWrite(led3, HIGH);
              led2val = .6;
              strand2[2] = 12;
              // strand1_locked = true;
              core12_locked = true;
            } else if (strand2_in[2] != -2 && strand2_in[2] <= 1885 && core12_locked){
              // digitalWrite(led3, LOW);
              led2val = 0;
              strand2[2] = 0;
              core12_locked = false;
            }

            // core 16
            // if (strand2_in[3] >= 2050 && !core15_locked){
            if (strand2_in[3] == -2 && !core16_locked){
              // digitalWrite(led3, HIGH);
              led2val = .8;
              strand2[3] = 16;
              // strand1_locked = true;
              core16_locked = true;
            } else if (strand2_in[3] != -2 && strand2_in[3] <= 2200 && core16_locked){
              // digitalWrite(led3, LOW);
              led2val = 0;
              strand2[3] = 0;
              core16_locked = false;
            }

            float checkstrand2[] = {sensor3.capacitiveSensorRaw(20), sensor4.capacitiveSensorRaw(20), sensor6.capacitiveSensorRaw(20), sensor8.capacitiveSensorRaw(20), sensor10.capacitiveSensorRaw(20), sensor11.capacitiveSensorRaw(20), sensor14.capacitiveSensorRaw(20), sensor15.capacitiveSensorRaw(20)};

            for (int i = 0; i < 8; i ++){
              if (core2_locked && core7_locked && core12_locked && core16_locked && checkstrand2[i] != -2){
              led2val = 1;
              strand2_locked = true;
              // Serial.println("STRAND 2 IS LOCKED");
              } else {
                // led2val = 0;
              }
            }

            // Serial.print("strand_2: ");
            // Serial.print(i);
            // Serial.print(": ");
            // Serial.println(strand2_in[i]);

            // Serial.print("strand2_locked is: ");
            // Serial.println(strand2_locked);

            delay(5);

          } 

          else if (!strand3_locked){

            // listen to strand2
            float strand3_in[] = {sensor3.capacitiveSensorRaw(20), sensor6.capacitiveSensorRaw(80), sensor10.capacitiveSensorRaw(80), sensor15.capacitiveSensorRaw(80)};

            // check to see if all intersections in strand2 have been removed
            // if (strand3_in[0] < 3600 && strand3_in[1] < 1425 && strand3_in[2] < 1480 && strand3_in[3] < 1520){
              if (strand3_in[0] != -2 && strand3_in[0] < 3700 && strand3_in[1] != -2 && strand3_in[1] < 1550 && strand3_in[2] != -2 && strand3_in[3] != -2 && strand3_in[3] < 1880){
              strand3_locked = false;
              // Serial.println("strand3_in is unlocked");
            }

            // if (!strand2_locked){ // 

              // Serial.println("strand3 is listening");
              // Serial.println(String("strand3_in: ") + strand3_locked);

              // core 3
              // if (strand3_in[0] >= 3660 && !core2_locked){
              if (strand3_in[0] >= 3720 || strand3_in[0] == -2 && !core3_locked){
                // digitalWrite(led1, HIGH);
                led3val = .2;
                strand3[0] = 3;
                core3_locked = true;
              // 
              } else if (strand3_in[0] != -2 || strand3_in[0] < 3700 && core3_locked){
                // digitalWrite(led1, LOW);
                led3val = 0;
                strand3[0] = 0;
                core3_locked = false;
              }

              // core 6
              // if (strand3_in[1] >= 1480 && !core5_locked){
              if (strand3_in[1] == -2 || strand3_in[1] >= 1600 && !core6_locked){
                // digitalWrite(led2, HIGH);
                led3val = .4;
                strand3[1] = 6;
                core6_locked = true;
              // } else if (strand3_in[1] < 1425 && core5_locked){
                } else if (strand3_in[1] != -2 || strand3_in[1] < 1550 && core6_locked){
                // digitalWrite(led2, LOW);
                led3val = 0;
                strand3[1] = 0;
                core6_locked = false;
              }

              // core 10
              // if (strand3_in[2] >= 1510 && !core9_locked){
              if (strand3_in[2] == -2 && !core10_locked){
                // digitalWrite(led3, HIGH);
                led3val = .6;
                strand3[2] = 10;
                core10_locked = true;
              // } else if (strand3_in[2] < 1480 && core9_locked){
              } else if (strand3_in[2] != -2 && core10_locked){
                // digitalWrite(led3, LOW);
                led3val = 0;
                strand3[2] = 0;
                core10_locked = false;
              }

              // core 15
              if (strand3_in[3] == -2 || strand3_in[3] > 1920 && !core15_locked){
                // digitalWrite(led3, HIGH);
                led3val = .8;
                strand2[3] = 15;
                core15_locked = true;
              } else if (strand3_in[3] != -2 && strand3_in[3] < 1880 && core15_locked){
                // digitalWrite(led3, LOW);
                led3val = 0;
                strand2[3] = 0;
                core15_locked = false;
              }

              float checkstrand3[] = {sensor4.capacitiveSensorRaw(20), sensor8.capacitiveSensorRaw(20), sensor11.capacitiveSensorRaw(20), sensor14.capacitiveSensorRaw(20)};

              if (core3_locked && core6_locked && core10_locked && core15_locked && checkstrand3[i] != -2){
                led3val = 1;
                strand3_locked = true;
                // Serial.println("STRAND 3 IS LOCKED");
              } else {
                // led2val = 0;
              }

              // Serial.print("strand_3 ");
              // Serial.print(i);
              // Serial.print(": ");
              // Serial.println(strand3_in[i]);

              // Serial.print("strand3_locked is: ");
              // Serial.println(strand3_locked);

              delay(5);

            // }

          }

          else if (!strand4_locked){

            // listen to strand3
            float strand4_in[] = {sensor4.capacitiveSensorRaw(100), sensor8.capacitiveSensorRaw(80), sensor11.capacitiveSensorRaw(80), sensor14.capacitiveSensorRaw(80)};

            // check to see if all intersections in strand3 have been removed
            // if (strand4_in[0] < 3350 && strand4_in[1] < 1490 && strand4_in[2] < 1380 && strand4_in[3] < 1620){
              if (strand4_in[0] != -2 && strand4_in[0] < 3590 && strand4_in[1] != -2 && strand4_in[1] < 1600 && strand4_in[2] != -2 && strand4_in[3] != -2 && strand4_in[3] <= 1890){
              strand4_locked = false;
              // Serial.println("strand4_in is unlocked");
            }

            // if (!strand3_locked){ // 

              // Serial.println("strand4 is listening");
              // Serial.println(String("strand4_in: ") + strand4_locked);

              // core 4
              // if (strand4_in[0] >= 3430 && !core3_locked){
                if (strand4_in[0] >= 3700 || strand4_in[0] == -2 && !core4_locked){
                // digitalWrite(led1, HIGH);
                led4val = .2;
                strand4[0] = 4;
                core4_locked = true;
              // } else if (strand4_in[0] < 3350 && core3_locked){
                } else if (strand4_in[0] < 3500 && strand4_in[0] != -2 && core4_locked){
                // digitalWrite(led1, LOW);
                led4val = 0;
                strand4[0] = 0;
                core4_locked = false;
              }

              // Serial.println(String("core3_locked: ") + core3_locked);

              // core 8
              // if (strand4_in[1] >= 1505 && !core7_locked){ // not registering with strand
              if (strand4_in[1] == -2 || strand4_in[1] > 1640 && !core8_locked){
                // digitalWrite(led2, HIGH);
                led4val = .4;
                strand4[1] = 8;
                core8_locked = true;
              // } else if (strand4_in[1] < 1490 && core7_locked){
              } else if (strand4_in[1] != -2 && strand4_in[1] < 1600 && core8_locked){
                // digitalWrite(led2, LOW);
                led4val = 0;
                strand4[1] = 0;
                core8_locked = false;
              }

              // Serial.println(String("core7_locked: ") + core7_locked);

              // core 11
              // if (strand4_in[2] >= 1435 && !core10_locked){
              if (strand4_in[2] == -2 && !core11_locked){
                // digitalWrite(led3, HIGH);
                led4val = .6;
                strand4[2] = 11;
                core11_locked = true;
              // } else if (strand4_in[2] < 1380 && core10_locked){
              } else if (strand4_in[2] != -2 && core11_locked){
                // digitalWrite(led3, LOW);
                led4val = 0;
                strand4[2] = 0;
                core11_locked = false;
              }

              // Serial.println(String("core10_locked: ") + core10_locked);

              // core 14
              // if (strand4_in[3] >= 4000 && !core13_locked){
              if (strand4_in[3] == -2 || strand4_in[3] >= 1900 && !core14_locked){
                // digitalWrite(led3, HIGH);
                led4val = .8;
                strand4[3] = 14;
                core14_locked = true;
              // } else if (strand4_in[3] < 1620 && core13_locked){
              } else if (strand4_in[3] != -2 && strand4_in[3] < 1890 && core14_locked){
                // digitalWrite(led3, LOW);
                led4val = 0;
                strand4[3] = 0;
                core14_locked = false;
              }

              if (core4_locked && core8_locked && core11_locked && core14_locked){
                led4val = 1;
                strand4_locked = true;
                // Serial.println("STRAND 4 IS LOCKED");
              } else {
                // led4val = 0;
              }

              // Serial.print("strand_4 ");
              // Serial.print(i);
              // Serial.print(": ");
              // Serial.println(strand4_in[i]);

              // Serial.print("strand4_locked is: ");
              // Serial.println(strand4_locked);

              delay(5);

            // }

          } // strand 3

        } // if loop

        // check for complete braid

        else if (strand1_locked && strand2_locked && strand3_locked && strand4_locked){

          // one + three 
          // if (strand1[0] == 1 && strand1[1] == 5 && strand1[2] == 9 && strand1[3] == 13 && strand2[0] == 2 && strand2[1] == 7 && strand2[2] == 12 && strand2[3] == 16 && strand3[0] == 3 && strand3[1] == 6 && strand3[2] == 10 && strand3[3] == 15 && strand4[0] == 4 && strand4[1] == 8 && strand4[2] == 11 && strand4[3] == 14){
            braid4val = 1;
            delay(3000);
            resetListen4 = true;
            braid4 = false;

          // } 
          
        } // if all strands locked

      } // for loop
      
    } // braid 4

  // } // braidListen
  
  // else if (potListen){

  // Loop through and read all 16 values
  // Reports back Value at channel 6 is: 346
  // for(int i = 0; i < 14; i ++){

    // potvals[i] = readMux(i);
    // potvals2[i] = readMux2(i);

    // potval1 = readMux(0);
    // potval2 = readMux(1);
    // potval3 = readMux(2);
    // potval4 = readMux(3);
    // potval5 = readMux(4);
    // potval6 = readMux(5);
    // potval7 = readMux(6);
    // potval8 = readMux(7);
    // potval9 = readMux(8);
    // potval10 = readMux(9);
    // potval11 = readMux(10);
    // potval12 = readMux(11);
    // potval13 = readMux(12);
    // potval14 = readMux(13);
    // potval15 = readMux(14);
    // potval16 = readMux(15);
    
    // Serial.print("Value at channel ");
    // Serial.print(i);
    // Serial.print("is : ");
    // Serial.println(readMux(i));

    // delay(5);

    // }

  // } // if potListen

  // Serial.println((String)"measurement 1: " + measurement1);
  // Serial.println((String)"measurement 2: " + measurement2);
  // Serial.println((String)"measurement 3: " + measurement3);
  // Serial.println((String)"measurement 4: " + measurement4);
  // Serial.println((String)"measurement 5: " + measurement5);
  // Serial.println((String)"measurement 6: " + measurement6);

  // Serial.println((String)"ledval 1: " + ledval1);
  // Serial.println((String)"ledval 2: " + ledval2);
  // Serial.println((String)"ledval 3: " + ledval3);
  // Serial.println((String)"ledval 4: " + ledval4);
  // Serial.println((String)"ledval 5: " + ledval5);
  // Serial.println((String)"ledval 6: " + ledval6);

  // // ledval 1
  // if (measurement1 >= 2410 && ledval1 == 0 && !locked1)
  // {
  //   // digitalWrite(led1, HIGH);
  //   ledval1 = 1;
  //   locked1 = true;
  // }

  // else if (measurement1 < 2410 && ledval1 == 1 && locked1){
  //   // digitalWrite(led1, LOW);
  //   ledval1 = 0;
  //   locked1 = false;
  // }

  // // ledval 2
  // if (measurement2 >= 2530 && ledval2 == 0 && !locked2)
  // {
  //   // digitalWrite(led2, HIGH);
  //   ledval2 = 1;
  //   locked2 = true;
  // }

  // else if (measurement2 < 2530 && ledval2 == 1 && locked2){
  //   // digitalWrite(led2, LOW);
  //   ledval2 = 0;
  //   locked2 = false;
  // }

  // ledval 3
  // if (measurement3 >= 1000 && ledval3 == 0 && !locked3)
  // {
  //   // digitalWrite(led3, HIGH);
  //   ledval3 = 1;
  //   locked3 = true;
  // }

  // else if (measurement3 < 1000 && ledval3 == 1 && locked3){
  //   // digitalWrite(led3, LOW);
  //   ledval3 = 0;
  //   locked3 = false;
  // }

  // if (led1val == 1){
  //   digitalWrite(led1, HIGH);
  //   // Bank0.digitalWrite(bPin8, HIGH);
  // } else {
  //   digitalWrite(led1, LOW);
  //   // Bank0.digitalWrite(bPin8, LOW);
  // }

  // if (led1val == 1){
  //   digitalWrite(led2, HIGH);
  // } else {
  //   digitalWrite(led2, LOW);
  // }

  // if (ledval1 == 1 && ledval2 == 1){
  //   braid1 == 1;
  // } else {
  //   braid1 == 0;
  // }

  // row 1 test
  // if (ledval1 == 1 && ledval2 == 1 && ledval3 == 1){
  //   digitalWrite(led1, HIGH);
  // }

  // else if (ledval1 == 0 && ledval2 == 0 && ledval3 == 0){
  //   digitalWrite(led1, LOW);
  // }

  // ledval 4
  // if (measurement4 >= 80 && ledval4 == 0 && !locked4)
  // {
  //   // digitalWrite(led1, HIGH);
  //   ledval4 = 1;
  //   locked4 = true;
  // }

  // else if (measurement4 < 80 && ledval4 == 1 && locked4){
  //   // digitalWrite(led1, LOW);
  //   ledval4 = 0;
  //   locked4 = false;
  // }

  // ledval 5
  // if (measurement5 >= 80 && ledval5 == 0 && !locked5)
  // {
  //   // digitalWrite(led2, HIGH);
  //   ledval5 = 1;
  //   locked5 = true;
  // }

  // else if (measurement5 < 80 && ledval5 == 1 && locked5){
  //   // digitalWrite(led2, LOW);
  //   ledval5 = 0;
  //   locked5 = false;
  // }

  // ledval 6
  // if (measurement6 >= 80 && ledval6 == 0 && !locked6)
  // {
  //   // digitalWrite(led3, HIGH);
  //   ledval6 = 1;
  //   locked6 = true;
  // }

  // else if (measurement6 < 80 && ledval6 == 1 && locked6){
  //   // digitalWrite(led3, LOW);
  //   ledval6 = 0;
  //   locked6 = false;
  // }

  // row 2 test
  // if (ledval4 == 1 && ledval5 == 1 && ledval6 == 1){
  //   digitalWrite(led2, HIGH);
  // }

  // else if (ledval4 == 0 && ledval5 == 0 && ledval6 == 0){
  //   digitalWrite(led2, LOW);
  // }

  // Serial.print("row 1: ");
  // Serial.print(measurement1);
  // Serial.print(",");
  // Serial.print(measurement2);
  // Serial.print(",");
  // Serial.print(measurement3);
  // Serial.print(",");
  // Serial.println(measurement4);

  // Serial.print("row 2: ");
  // Serial.print(measurement5);
  // Serial.print(",");
  // Serial.print(measurement6);
  // Serial.print(",");
  // Serial.print(measurement7);
  // Serial.print(",");
  // Serial.println(measurement8);

  // Serial.print("row 3: ");
  // Serial.print(measurement9);
  // Serial.print(",");
  // Serial.print(measurement10);
  // Serial.print(",");
  // Serial.print(measurement11);
  // Serial.print(",");
  // Serial.println(measurement12);

  // Serial.print("row 4: ");
  // Serial.print(measurement13);
  // Serial.print(",");
  // Serial.print(measurement14);
  // Serial.print(",");
  // Serial.print(measurement15);
  // Serial.print(",");
  // Serial.println(measurement16);

  // Serial.print(ledval1);
  // Serial.print(ledval2);
  // Serial.println();

  // Serial.write(ledval1);
  // Serial.write(ledval2);
  // Serial.println();

  // Serial.println(measurement1);
  // Serial.print(",");
  // Serial.println(measurement2);

  delay(5);
}

// void checkCores(){

//   // listen to strand1
//   float strand1_in[] = {sensor1.capacitiveSensorRaw(20), sensor6.capacitiveSensorRaw(20), sensor11.capacitiveSensorRaw(20), sensor15.capacitiveSensorRaw(20)};

//   // check to see if all intersections in strand1_in have been removed
//   if (strand1_in[0] < 2390 && strand1_in[1] < 296 && strand1_in[2] < 290 && strand1_in[3] < 359){
//     strand1_locked = false;
//     // Serial.println("strand1 is unlocked");
//   } 

// }

// int readMux(int channel){
//   int controlPin[] = {s0, s1, s2, s3};

//   int muxChannel[16][4]={
//     {0,0,0,0}, //channel 0
//     {1,0,0,0}, //channel 1
//     {0,1,0,0}, //channel 2
//     {1,1,0,0}, //channel 3
//     {0,0,1,0}, //channel 4
//     {1,0,1,0}, //channel 5
//     {0,1,1,0}, //channel 6
//     {1,1,1,0}, //channel 7
//     {0,0,0,1}, //channel 8
//     {1,0,0,1}, //channel 9
//     {0,1,0,1}, //channel 10
//     {1,1,0,1}, //channel 11
//     {0,0,1,1}, //channel 12
//     {1,0,1,1}, //channel 13
//     {0,1,1,1}, //channel 14
//     {1,1,1,1}  //channel 15
//   };

//   //loop through the 4 sig
//   for(int i = 0; i < 4; i ++){
//     digitalWrite(controlPin[i], muxChannel[channel][i]);
//   }

//   //read the value at the SIG pin
//   int val = analogRead(SIG_pin1);

//   //return the value
//   // val = map(val, 0, 1023, 0, 16);
//   return val;
// }

// int readMux2(int channel){
//   int controlPin[] = {s4, s5, s6, s7};

//   int muxChannel[16][4]={
//     {0,0,0,0}, //channel 0
//     {1,0,0,0}, //channel 1
//     {0,1,0,0}, //channel 2
//     {1,1,0,0}, //channel 3
//     {0,0,1,0}, //channel 4
//     {1,0,1,0}, //channel 5
//     {0,1,1,0}, //channel 6
//     {1,1,1,0}, //channel 7
//     {0,0,0,1}, //channel 8
//     {1,0,0,1}, //channel 9
//     {0,1,0,1}, //channel 10
//     {1,1,0,1}, //channel 11
//     {0,0,1,1}, //channel 12
//     {1,0,1,1}, //channel 13
//     {0,1,1,1}, //channel 14
//     {1,1,1,1}  //channel 15
//   };

//   //loop through the 4 sig
//   for(int i = 0; i < 4; i ++){
//     digitalWrite(controlPin[i], muxChannel[channel][i]);
//   }

//   //read the value at the SIG pin
//   int val = analogRead(SIG_pin2);

//   //return the value
//   // val = map(val, 0, 1023, 0, 16);
//   return val;
// }
