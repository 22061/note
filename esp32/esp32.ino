#include <WiFi.h>
#include <WiFiUdp.h>
#include "zikoichi_kun_api.hpp"

String wifi_name = "mcuServer";
String wifi_pass = "mcu64205";
uint8_t local_port = 64205;
IPAddress wifi_ip(192, 168, 4, 1);
IPAddress wifi_gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
WiFiUDP udp;

char packetBuffer[256];
int packetSize;
int i;

void setup() 
{
  Serial.begin(115200);
  zk_api::setup();

  WiFi.mode(WIFI_AP);
  WiFi.softAP(wifi_name, wifi_pass);
  delay(100);
  WiFi.softAPConfig(wifi_ip, wifi_gateway, subnet);

  udp.begin(local_port);
}

void loop() 
{
  packetSize = udp.parsePacket();
  if (packetSize) 
  {
    for (i = 0 ; i < 256 ; i++) 
    {
      packetBuffer[i] = 0;
    }
    udp.read(packetBuffer, 256);

    Serial.println(packetBuffer);

    String read(packetBuffer);

    int si = read.indexOf('s');
    int ei = read.indexOf('e');
    String data = read.substring(si+1, ei);


    int first_com = data.indexOf(',');
    String x_str = data.substring(0, first_com);
    String non_first = data.substring(first_com+1);

    int second_com = non_first.indexOf(',');
    String y_str = non_first.substring(0, second_com);
    String non_second = non_first.substring(second_com+1);

    int third_com = non_second.indexOf(',');
    String z_str = non_second.substring(0, third_com);

    int x_hold = x_str.toInt();
    int y_hold = y_str.toInt();
    int z_hold = z_str.toInt();

    float x = x_hold - 10;
    x = x / 10.0;
    float y = y_hold - 10;
    y = y / 10.0;
    float z = z_hold - 10;
    z = z / 10.0;

    // Serial.print(x);
    // Serial.print(",");
    // Serial.print(y);
    // Serial.print(",");
    // Serial.println(z);

    zk_api::xyz_control(x, y, z, 50);
  }
}
