// REF: https://github.com/miguel5612/MQSensorsLib/blob/master/examples/Calibration/Calibration.ino

/*
  MQUnifiedsensor Library - calibrating an MQ9

  Demonstrates the use a MQ9 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 27 May 2019
  by Miguel Califa 

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>
/************************Hardware Related Macros************************************/
#define         Board                   ("Arduino MEGA")
#define         Pin                     (A14)  //Analog input 2 of your arduino
/***********************Software Related Macros************************************/
#define         Type                    ("MQ-9") //MQ9
#define         Voltage_Resolution      (5)
#define         ADC_Bit_Resolution      (10) // For arduino UNO/MEGA/NANO

/*****************************Globals***********************************************/
double          alcoholPPM          =   (0);
//Defaults, uncomment if you need
// #define RatioMQ2CleanAir 9.83 //RS / R0 = 9.83 ppm 
//#define RatioMQ3CleanAir 60   //RS / R0 = 60 ppm 
//#define RatioMQ4CleanAir 4.4  //RS / R0 = 4.4 ppm 
//#define RatioMQ5CleanAir 6.5  //RS / R0 = 6.5 ppm 
//#define RatioMQ6CleanAir 10   //RS / R0 = 10 ppm 
//#define RatioMQ7CleanAir 27.5 //RS / R0 = 27.5 ppm  
//#define RatioMQ8CleanAir 70   //RS / R0 = 70 ppm   
#define RatioMQ9CleanAir 9.6  //RS / R0 = 9.6 ppm    
//#define RatioMQ131CleanAir 15 //RS / R0 = 15 ppm
//#define RatioMQ135CleanAir 3.6//RS / R0 = 3.6 ppm     
//#define RatioMQ303CleanAir 1  //RS / R0 = 1 ppm    
//#define RatioMQ309CleanAir 11 //RS / R0 = 11 ppm    
unsigned long contador = 0;
/**************************Object_Sensor********************************************/

MQUnifiedsensor MQ9(Board, Voltage_Resolution, ADC_Bit_Resolution, Pin, Type);

void setup() {
  //Init serial port
  Serial.begin(115200);
  MQ9.setRegressionMethod(1); //_PPM =  a*ratio^b
  MQ9.setA(599.65); MQ9.setB(-2.244); // Configure the equation to to calculate CO concentration
  // https://github.com/miguel5612/MQSensorsLib/blob/master/examples/MQ-9/MQ-9.ino
  /* 
    //If the RL value is different from 10K please assign your RL value with the following method:
    MQ3.setRL(10);
  */
  //init the sensor
  MQ9.init(); 
  //Print in serial monitor
  Serial.println("MQ9 - Calibracion");
  Serial.println("Note - Make sure you are in a clean room and the sensor has pre-heated almost 4 hours");
  Serial.println("Autonumeric | lecture (R0)");
}

void loop() {
  MQ9.update();
  //Read the sensor and print in serial port
  float lecture =  MQ9.calibrate(RatioMQ9CleanAir);
  //Print in serial monitor
  Serial.print(contador);
  Serial.print(" | ");
  Serial.println(lecture);
  //Increment counter
  contador++;
  //Wait to measure next sample
  delay(400);
}