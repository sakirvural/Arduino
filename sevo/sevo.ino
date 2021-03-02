#include <Servo.h>

Servo sg90;

void setup() {

  sg90.attach(9);

}

void loop() {

  for(int i=0;i<=180;i+=10){
    sg90.write(i);
    delay(100);
  }
  
  for(int j=180;j>=0;j-=10){
    sg90.write(j);
    delay(100);
  }
 
}
