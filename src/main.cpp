#include <Arduino.h>
#include <Servo.h>

//create servo class object (total of 5 servo motors)
Servo servo1,servo2,servo3,servo4,servo5;

//initial position of each servo motors
byte angle1 = 20;
byte angle2 = 70;
byte angle3 = 150;
byte angle4 = 140;
byte angle5 = 150;

void setup()
{
  //Setup UART communication port (TX, RX)
  Serial.begin(9600);

  //servo motor pin setup
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  servo4.attach(12);
  servo5.attach(13);

  //setup angle position for each servo motors
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
  servo4.write(angle4);
  servo5.write(angle5);

  //ensure that each servo motor reached the desired positions
  while(servo1.read() != angle1){
    servo1.write(angle1);
    delay(25);
  }
  while(servo2.read() != angle2){
    servo2.write(angle2);
    delay(25);
  }
  while(servo3.read() != angle3){
    servo3.write(angle3);
    delay(25);
  }
  while(servo4.read() != angle4){
    servo4.write(angle4);
    delay(25);
  }
  while(servo5.read() != angle5){
    servo5.write(angle5);
    delay(25);
  }
}

// Number of assembly required to be collected
byte totalNumberOfAssembly = 0;

int currentAssembly = 0;

void loop()
{

  if(Serial.available()){
    byte incomingByte = Serial.read();

    if(incomingByte == 1){
      totalNumberOfAssembly++;
    }
  }

  if(currentAssembly != totalNumberOfAssembly){

    //initial angle values
    angle1 = 20;
    angle2 = 70;
    angle3 = 150;
    angle4 = 140;
    angle5 = 150;

    //setup servo motors angle
    servo1.write(angle1);
    servo2.write(angle2);
    servo3.write(angle3);
    servo4.write(angle4);
    servo5.write(angle5);

    // delay(1000);

    while(angle4 > 105){
      servo4.write(angle4);
      angle4 -= 2;
      delay(40);
    }

    while(angle2 < 95){
      servo2.write(angle2);
      angle2 += 2;
      delay(40);
    }

    //get the assembly
    while(angle1 < 75){
      servo1.write(angle1);
      angle1 += 2;
      delay(30);
    }

    while(angle2 > 90){
      servo2.write(angle2);
      angle2 -= 2;
      delay(40);
    }

    while(angle4 < 135){
      servo4.write(angle4);
      angle4 += 2;
      delay(40);
    }

    while(angle2 < 110){
      servo2.write(angle2);
      angle2 += 2;
      delay(40);
    }

    //changing angle due to different in final position of the assmembly
    byte targetangle4;
    byte targetangle5;

    //seperate the product by having 2 rows
    byte firstRowAngle = 50;
    byte secondRowAngle = 45;

    switch (currentAssembly)
    {
      case 0:
        targetangle4 = 100;
        targetangle5 = firstRowAngle;
        break;
      
      case 1:
        targetangle4 = 105;
        targetangle5 = secondRowAngle;
        break;

      case 2:
        targetangle4 = 105;
        targetangle5 = firstRowAngle;
        break;
      
      //if error remain infinite loop to avoid any errors
      default:
        targetangle4 = 115;
        if(currentAssembly % 2 == 0){
          targetangle5 = firstRowAngle;
        }else{
          targetangle5 = secondRowAngle;
        }
        break;
    }

    while(angle5 > targetangle5){
      servo5.write(angle5);
      angle5 -= 2;
      delay(30);
    }

    while(angle2 < 165){
      servo2.write(angle2);
      angle2 += 2;
      delay(40);
    }

    while(angle4 > targetangle4){
      servo4.write(angle4);
      servo3.write(angle3);
      //0.75
      angle3 -= 0.75;
      angle4 -= 2;
      delay(40);
    }

    while(angle2 > 150){
      servo2.write(angle2);
      angle2 -= 2;
      delay(40);
    }

    while(angle1 > 35){
      servo1.write(angle1);
      angle1 -= 2;
      delay(40);
    }

    while(angle4 < 140){
      servo4.write(angle4);
      angle4 += 2;
      delay(40);
    }

    while(angle3 < 150){
      servo3.write(angle3);
      angle3 += 2;
      delay(30);
    }

    while(angle2 > 70){
      servo2.write(angle2);
      angle2 -= 2;
      delay(30);
    }

    while(angle5 < 150){
      servo5.write(angle5);
      angle5 += 2;
      delay(30);
    }

    while(angle1 > 20){
      servo1.write(angle1);
      angle1 -= 2;
      delay(30);
    }

    currentAssembly++;
  }
  else{
    delay(50);
  }
}