#ifndef IM920_HPP_
#define IM920_HPP_

#include <SoftwareSerial.h>

SoftwareSerial IM920Serial(8, 9);    // RX, TX

char send_data[255];
char receive_data[255];
int i;

namespace IM920
{
  inline void setup(void) 
  {
    IM920Serial.begin(19200);
  }

  inline void send(char number, char send_data) 
  { 
    IM920Serial.print("TXDU");
    IM920Serial.print(number);
    IM920Serial.print(",");
    IM920Serial.println(send_data);
  }

  inline char receive(void)
  {
    if(IM920Serial.available()) 
    {
      receive_data[i] = IM920Serial.read();
      if (receive_data[i] == '\n') 
      {
        receive_data[i] = '\n';
        Serial.print(receive_data);
        i = 0;
      }
      else
      {
        i++;
      }
    }

    return receive_data;
  }
}
#endif