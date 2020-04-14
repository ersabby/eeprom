
/*
   Title: EEPROM opereations
   Author: Saurabh Patil
   Date: 31-03-2020
   Details:
          The eeprom (Electrically Erasable and Programmable Read Only Memory) is a non-volatile memory often used to embed value in the microcontroller.
          Maximum write operations that can be performed on EEPROM are 10000 after which it can no longer retain the value.

          Operations that can be performed on EEPROM are:
            -EEPROM.read(addr)          -> used to read values stored in EEPROM.
            -EEPROM.write(addr, value)  -> used to store/write value in specified address
            -EEPROM.update(addr, value) -> used to write value in specified address
              The EEPROM.update function helps in reducing write operations since it eliminates the operation if value to be writeen is similar to the new value.
            -EEPROM.clear()             -> used to clear EEPROM memory.

          Remark:
                To write any value at specified location, the location needs to be set to zero using eeprom.write(0, address)

          The following code is for esp controller.
*/

#include <EEPROM.h>

void writeString(char addr, String data);
String read_String(char addr);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  EEPROM.begin(512);    //To initiate the eeprom function
  String data = " Hello welcome to eeprom operation code...!!!  ";

  Serial.print("Writing data to eeprom:");
  Serial.println(data);

  writeString(10, data);  //addrress 10 and String type data
  delay(10);
}

void loop() {
  // put your main code here, to run repeatedly:
  String recivedData;
  recivedData = read_String(10);
  Serial.print("Read data from eeprom:  ");
  Serial.println(recivedData);
  delay(800);
}

void writeString(char addr, String data)
{

  int _size = data.length();
  int i;

  for (i = 0; i < _size; i++)
  {
    EEPROM.write(addr + i, 0);
  }
  EEPROM.commit();

  for (i = 0; i < _size; i++)
  {
    EEPROM.write(addr + i, data[i]);
  }
  EEPROM.write(addr + _size, '\0'); //addr a null character for termination of string
  EEPROM.commit();
}

String read_String(char addr)
{
  int i;
  char data[100]; //Max 100 Bytes
  int len = 0;
  unsigned char k;
  k = EEPROM.read(addr);
  while (k != '\0' && len < 500) //Read until null character gets encountered
  {
    k = EEPROM.read(addr + len);
    data[len] = k;
    len++;
  }
  data[len] = '\0';
  return String(data);
}
