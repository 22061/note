char buf[256];
int i = 0;

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200);
}
 
void loop() 
{
  if(Serial.available())
  {
    buf[i] = Serial.read();
    if (buf[i] == 'e') 
    {
      buf[i] = 0;
      Serial2.print("TXDU0002,");
      Serial2.println(buf);
      Serial.println(buf);

      for(int j = 0; j < 256; j++)
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