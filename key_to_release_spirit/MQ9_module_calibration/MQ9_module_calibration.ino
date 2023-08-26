// https://electropeak.com/learn/how-to-calibrate-and-use-mq9-gas-sensor-w-arduino/

/* 
 
MQ9 Calibration 
 
modified on 19 Feb 2019 
by Saeed Hosseini 
https://electropeak.com/learn/ 
 
*/ 
 
void setup() { 
  Serial.begin(9600); 
} 
  
void loop() { 
  float sensor_volt = 0;
  float RS_air = 0;  //  Rs in clean air
  float R0 = 0;      // R0 in 1000 ppm LPG
  float sensorValue = 0;
 
//Average   
    for(int x = 0 ; x < 100 ; x++) 
  { 
    sensorValue = sensorValue + analogRead(A0); 
  } 
  sensorValue = sensorValue/100.0; 
//-----------------------------------------------/ 
 
  sensor_volt = (sensorValue/1024)*5.0; 
  RS_air = (5.0-sensor_volt)/sensor_volt; // Depend on RL on yor module 
  R0 = RS_air/9.9; // According to MQ9 datasheet table 
   
  Serial.print("sensor_volt = "); 
  Serial.print(sensor_volt); 
  Serial.println("V");
  
  Serial.print("R0 = "); 
  Serial.println(R0); 
  delay(1000); 

}