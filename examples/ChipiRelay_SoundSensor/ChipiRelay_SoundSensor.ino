/*********************************************************************************
 * //  Chương trình: ChipiRelay_SoundSensor
 * //  Tác giả: TP
 * //  Ngày: 28 Oct 2014
 * //  Mô tả: Chương trình này sẽ thay đổi bật tắt rờ le mỗi khi vỗ tay, bạn có thể chỉnh biến trở trên chipiSounSensor để chỉnh độ nhạy
 * //  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiRelay + chipiSoundSensor để tương thích hoàn toàn nhé.
 * //  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
 * //  Tham khảo http://chipfc.com/ để biết thêm chi tiết
 *********************************************************************************/

#define NC  LOW
#define NO HIGH

byte relayPin = 8;
boolean relayState = NC;
byte sensorPin = 10;
void setup()
{
  pinMode(relayPin,OUTPUT);  // Thiết lập chân điều khiển led là OUTPUT hay ngõ xuất
  digitalWrite(relayPin, relayState);
  pinMode(sensorPin,INPUT);
}

void loop()
{
  if(digitalRead(sensorPin) == HIGH){  //Mỗi khi có tín hiệu từ sensor thì bật tắt đèn 
    digitalWrite(relayPin,relayState);
    relayState = ~relayState;
    delay(1000);
  }
}



