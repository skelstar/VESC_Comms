// #include <Arduino.h>
#include <vesc_comms.h>

vesc_comms vesc;

struct VESC_DATA
{
  float batteryVoltage;
  float motorCurrent;
  float ampHours;
  float odometer;
};
VESC_DATA vescdata;

uint8_t vesc_packet[PACKET_MAX_LENGTH];

void setup() {
  Serial.begin(9600);
  Serial.printf("\nReady\n");

  vesc.init(115200);
}


long now = 0;

void loop() {

  if ( millis() - now > 2000 ) {
    now = millis();
    int numbytes = vesc.fetch_packet( vesc_packet );
    if ( numbytes > 1 ) {
      vescdata.batteryVoltage = vesc.get_voltage(vesc_packet);
      vescdata.motorCurrent = vesc.get_motor_current(vesc_packet);
      vescdata.ampHours = vesc.get_amphours_discharged(vesc_packet);
    }
  }
}