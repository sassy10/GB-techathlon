#include<TinyGPS.h>
#include<SoftwareSerial.h>

SoftwareSerial Gsm(7,8);
char phone_no[]="919164560609";

TinyGPS gps;

void setup()
{
  Serial.begin(9600);
  Gsm.begin(9600);
}

void loop()
{
  bool newData=false;
  unsigned long char;
  unsigned short sentences,failed;

  for(unsigned long start = millis();millis()-start<1000;)
  {
    while(Serial.available())
    {
      char c=Serial.read();
      Serial.print(c);
      if(gps.encode(c))
        newData=true;
    }
  }
  if(newData)
  {
    float flat,flon;
    unsigned long age;
    gps.f_get_position(&flat,&flon,&age);
    Gsm.print("AT+CMGF=1\r");
    delay(400);
    Gsm.print("AT+CMGS=\"");
    Gsm.print(phone_no);
    Gsm.println("\"");

    delay(300);
    Serial.print("Hi");
    Gsm.print("Hi");
    Gsm.print("http://maps.google.com/maps?q=loc:");
    Gsm.print(flat==TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat,6);
    Serial.print(",");
    Gsm.print(flon==TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon,6);
    delay(200);
    Gsm.println((char)26);
    delay(200);
    Gsm.println();
    delay(20000);
  }

  Serial.println(failed);
}


