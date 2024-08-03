#include<SoftwareSerial.h>

SoftwareSerial IM920Serial(8, 9);  //RX, TX

char buf[256];
int i = 0;  

void setup() {
  Serial.begin(115200);
  IM920Serial.begin(115200);
}

void loop() {
  if (IM920Serial.available()) 
  {
    buf[i] = IM920Serial.read();
    if (buf[i] == '\n') 
    {
      String read(buf);
      String data = read.substring(11);

      //Serial.print(data);

      int first_com = data.indexOf(',');
      String x_str = data.substring(0, first_com);
      String non_first = data.substring(first_com+1);

      int second_com = non_first.indexOf(',');
      String y_str = non_first.substring(0, second_com);
      String non_second = non_first.substring(second_com+1);

      int third_com = non_second.indexOf(',');
      String z_str = non_second.substring(0, third_com);
      String non_third = non_second.substring(third_com+1);

      int four_com = non_third.indexOf(',');
      String m1_str = non_third.substring(0, four_com);
      String non_four = non_third.substring(four_com+1);

      int five_com = non_four.indexOf(',');
      String m2_str = non_four.substring(0, five_com);
      String non_five = non_four.substring(five_com+1);

      int x_hold = x_str.toInt();
      int y_hold = y_str.toInt();
      int z_hold = z_str.toInt();
      int m1_hold = m1_str.toInt();
      int m2_hold = m2_str.toInt();

      float x = x_hold - 10;
      x = x / 10.0;
      float y = y_hold - 10;
      y = y / 10.0;
      float z = z_hold - 10;
      z = z / 10.0;
      float m1 = m1_hold - 10;
      m1 = m1 / 10.0;
      float m2 = m2_hold - 10;
      m2 = m2 / 10.0;

      Serial.print(x);
      Serial.print(",");
      Serial.print(y);
      Serial.print(",");
      Serial.print(z);
      Serial.print(",");
      Serial.print(m1);
      Serial.print(",");
      Serial.println(m2);

      for(int j = 0; j <= i; j++)
      {
         buf[j] = 0;
      }
      i = 0;
    }
    else
    {
        i++;
    }
  }
}