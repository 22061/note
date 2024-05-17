#include <ArduinoJson.h>
#include<SoftwareSerial.h>

StaticJsonDocument<200> doc;
SoftwareSerial IM920Serial(8, 9);  //RX, TX

char data[50];
int i = 0;  
String value;
float x1 = 0;
float y1 = 0;

void setup() {
  Serial.begin(19200);
  IM920Serial.begin(19200);
}

void loop()
{
  if (IM920Serial.available()) 
  {
    data[i] = IM920Serial.read();
    if (data[i] == '\n') 
    {
      data[i] = '\n';
      //Serial.print(data);
      i = 0;
    }
    else
    {
        i++;
    }

    value = data;
    value = value.substring(11);

    DeserializationError error = deserializeJson(doc, value);

    x1=doc["x_axis"];
    y1=doc["y_axis"];
    Serial.print(x1);
    Serial.print(",");
    Serial.println(y1);
  }
}
