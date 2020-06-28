/*
  Calibration

 Demonstrates one technique for calibrating sensor input.  The
 sensor readings during the first five seconds of the sketch
 execution define the minimum and maximum of expected values
 attached to the sensor pin.

 The sensor minimum and maximum initial values may seem backwards.
 Initially, you set the minimum high and listen for anything
 lower, saving it as the new minimum. Likewise, you set the
 maximum low and listen for anything higher as the new maximum.

 The circuit:
 * Analog sensor (potentiometer will do) attached to analog input 0
 * LED attached from digital pin 9 to ground

 created 29 Oct 2008
 By David A Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Calibration

 This example code is in the public domain.

 */

// These constants won't change:
const int sensorPin = A0;    //传感器所连接的针脚
const int ledPin = 9;        // 发光二极管连接的别针

// variables:
int sensorValue = 0;         // 传感器值（归零）
int sensorMin = 1023;        // 传感器值（最小）
int sensorMax = 0;           // 传感器值（最大）


void setup() {
  // 开启发光二极管，开始校准周期:
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);
    // 校准前五秒
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }  // 31/5000 记录大于定义传感器最大值的值，并将保存为新的最大值
  if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }   // 记录小于定义传感器最小值的值，并将保存为新的最小值

  digitalWrite(13, LOW);  // 标示校正周期结束
}

void loop() {

  sensorValue = analogRead(sensorPin);  // 读取传感器的数值:

  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);  // 对传感器读数进行校准

  sensorValue = constrain(sensorValue, 0, 255);  //以防传感器值超出校准时可见的范围

  analogWrite(ledPin, sensorValue);  // 使用校准后的数值来淡出 led
}	
//校准是一种校准传感器的技术，草图执行的前五秒，读数定义了连接到传感器引脚的预期值的最小和最大值。 
//传感器的最小值和最大值是反向的。
//开始时，设置最小值，然后监听任何低于最小值的地方，保存为新的最小值。
// 同样的，设置最大值，监听任何高于最大值的东西。