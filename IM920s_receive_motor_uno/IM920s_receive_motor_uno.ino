char buf[256];
int i = 0;  

void setup() {
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) 
  {
    buf[i] = Serial.read();
    if (buf[i] == '\n') 
    {
      String read(buf);
      String data = read.substring(11);

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
      int x_pow = x * 255;
      float y = y_hold - 10;
      y = y / 10.0;
      int y_pow = y * 255;
      float z = z_hold - 10;
      z = z / 10.0;
      int z_pow = z * 255;
      float m1 = m1_hold - 10;
      m1 = m1 / 10.0;
      int m1_pow = m1 * 255;
      float m2 = m2_hold - 10;
      m2 = m2 / 10.0;
      int m2_pow = m2 * 255;

      if(x > 0)
      {
        digitalWrite(12, HIGH);
        analogWrite(5, x_pow);
      }
      else if(x < 0)
      {
        digitalWrite(12, LOW);
        analogWrite(5, -x_pow);
      }
      else 
      {
        digitalWrite(12, LOW);
        analogWrite(5, 0); 
      }

      if(y > 0)
      {
        digitalWrite(13, HIGH);
        analogWrite(6, y_pow);
      }
      else if(y < 0)
      {
        digitalWrite(13, LOW);
        analogWrite(6, -y_pow);
      }
      else 
      {
        digitalWrite(13, LOW);
        analogWrite(6, 0); 
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