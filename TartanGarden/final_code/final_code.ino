#include <servo_code>
#include <water_sensor_code>
void setup() {
  Serial.begin(9600);
}

void loop() {
    if water_sensor_code.loop() > 3{
      servo_code.runOnce();
    }
}
