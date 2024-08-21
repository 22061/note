char buf[256];
int i = 0;  

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(115200);
  Serial2.begin(115200);
}

void loop() {
  if (Serial2.available()) 
  {
    buf[i] = Serial2.read();
    if (buf[i] == '\n') 
    {
      String read(buf);
      String data = read.substring(11);

      Serial.print(data);

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

      float x_hold = x_str.toFloat();
      float y_hold = y_str.toFloat();
      float z_hold = z_str.toFloat();
      float m1_hold = m1_str.toFloat();
      float m2_hold = m2_str.toFloat();

      x_hold = (x_hold - 10) / 10.0 * 255.0;
      int x = (int)x_hold;
      y_hold = (y_hold - 10) / 10.0 * 255.0;
      int y = (int)y_hold;
      z_hold = (z_hold - 10) / 10.0 * 255.0;
      int z = (int)z_hold;
      m1_hold = (m1_hold - 10) / 10.0 * 255.0;
      int m1 = (int)m1_hold;
      m2_hold = (m2_hold - 10) / 10.0 * 255.0;
      int m2 = (int)m2_hold;

      // Serial.println(x);

      if(x > 0)
      {
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        analogWrite(5, x);
        analogWrite(6, x);
      }
      else
      {
        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);
        analogWrite(5, abs(x));
        analogWrite(6, abs(x));
      }

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