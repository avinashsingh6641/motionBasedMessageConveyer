/*
 Get scaled and calibrated output of MPU6050
 */
#include <basicMPU6050.h> 

// Create instance

basicMPU6050<> imu;
void setup() {
  // Set registers - Always required
  imu.setup();

  // Initial calibration of gyro
  imu.setBias();
  Serial.begin(9600);
}

void loop() { 
  // Update gyro calibration 
  imu.updateBias();
 
  //-- Scaled and calibrated output:
  // Accel
  float x=imu.ax();
  
  float y=imu.ay();

  //lcd.setCursor(0,0);
  if (x>0.20){
    Serial.print("water");
    delay(1000);
    
  }else if(x<-0.20){
    Serial.print("medicine");
    delay(1000);
    
  }else if(y>0.20){
    Serial.print("nursing");
    delay(1000);
    
  }else if(y<-0.20){
    Serial.print("check saline");
    delay(1000);
   
  }else{
    //lcd.clear();
    Serial.print("No Message");
    delay(1000);
  }

}
 
