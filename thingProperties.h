#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>
#include "arduino_secrets.h"


const char THING_ID[] = "REPLACE_ME_WITH_THE_THING_ID_FOR_YOUR_PORTENTA_ON_ARDUINO_CLOUD_THING";
// ^ex: const char THING_ID[] = "bd6xgdyzz-2697-3335-4343-c95x99cx89ae";


const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)

float temp;
int seconds;

void initProperties(){

  ArduinoCloud.setThingId(THING_ID);
  ArduinoCloud.addProperty(temp, READ, 1 * SECONDS, NULL);
  ArduinoCloud.addProperty(seconds, READ, 1 * SECONDS, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
