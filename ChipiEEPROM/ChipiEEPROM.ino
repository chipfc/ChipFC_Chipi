/*********************************************************************************
//  Chương trình: ChipiEEPROM
//  Tác giả: TP
//  Ngày: 28 Oct 2014
//  Mô tả: Chương trình này sẽ viết vào EEPROM ngoài và sau đó đọc giá trị từ EEPROM
//  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiEEPROM để tương thích hoàn toàn nhé.
//  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
//  Tham khảo http://chipfc.com/ để biết thêm chi tiết
*********************************************************************************/

#include <Wire.h> //Thư viện I2C
#define EepromAdressA0 0
#define EepromAdressA1 0
#define EepromAdressA2 0

int chipiEepromAdress = 0x50 & (EepromAdressA0 <<0) & (EepromAdressA1 <<1) & (EepromAdressA2 <<2);

void i2c_eeprom_write_byte( int deviceaddress, unsigned int eeaddress, byte data ) {
  int rdata = data;
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8)); // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.write(rdata);
  Wire.endTransmission();
}

// WARNING: address is a page address, 6-bit end will wrap around
// also, data can be maximum of about 30 bytes, because the Wire library has a buffer of 32 bytes
void i2c_eeprom_write_page( int deviceaddress, unsigned int eeaddresspage, byte* data, byte length ) {
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddresspage >> 8)); // MSB
  Wire.write((int)(eeaddresspage & 0xFF)); // LSB
  byte c;
  for ( c = 0; c < length; c++)
    Wire.write(data[c]);
  Wire.endTransmission();
}

byte i2c_eeprom_read_byte( int deviceaddress, unsigned int eeaddress ) {
  byte rdata = 0xFF;
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8)); // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.endTransmission();
  Wire.requestFrom(deviceaddress,1);
  if (Wire.available()) rdata = Wire.read();
  return rdata;
}

// maybe let's not read more than 30 or 32 bytes at a time!
void i2c_eeprom_read_buffer( int deviceaddress, unsigned int eeaddress, byte *buffer, int length ) {
  Wire.beginTransmission(deviceaddress);
  Wire.write((int)(eeaddress >> 8)); // MSB
  Wire.write((int)(eeaddress & 0xFF)); // LSB
  Wire.endTransmission();
  Wire.requestFrom(deviceaddress,length);
  int c = 0;
  for ( c = 0; c < length; c++ )
    if (Wire.available()) buffer[c] = Wire.read();
}

void setup() 
{
  char somedata[] = "dU LIEU DE GHI VAO eeprom"; //Dữ liệu để viết xuống EEPROM
  Wire.begin(); // Khởi tạo giao tiếp I2C
  Serial.begin(9600);
  i2c_eeprom_write_page(chipiEepromAdress, 0, (byte *)somedata, sizeof(somedata)); // Viết vào page EEPROM

  delay(10); //Delay một ít để viết dữ liệu

  Serial.println("Da viet.");
}

void loop() 
{
  int addr=0; //first address
  byte b = i2c_eeprom_read_byte(chipiEepromAdress, 0); // access the first address from the memory

  while (b!=0) 
  {
    Serial.print((char)b); //print content to serial port
    addr++; //increase address
    b = i2c_eeprom_read_byte(chipiEepromAdress, addr); //access an address from the memory
  }
  Serial.println(" ");
  delay(2000);

}


