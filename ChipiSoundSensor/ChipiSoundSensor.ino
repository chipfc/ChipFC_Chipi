/*********************************************************************************
 * //  Chương trình: ChipiSoundSensor
 * //  Tác giả: TP
 * //  Ngày: 25 Oct 2014
 * //  Mô tả: Chương trình này sẽ đọc giá trị từ cảm biến âm thanh được nối với chân 8 của Arduino và nháy led 13 có sẵn trên bo.
 * //  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với ShieldChipiBase và ChipiSoundsensor để tương thích hoàn toàn nhé.
 * //  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
 * //  Tham khảo http://chipfc.com/ để biết thêm chi tiết
 *********************************************************************************/

byte ledOnBoard = 13;  //Mỗi bo Arduino của ChipFC đều có một led xanh dương thiết kể sẵn trên bo tại chân D13.
byte chipiSoundSensor = 8;  //Sensor nối với chân Digital 8 của Arduino
boolean ledState = LOW;
void setup()
{
  pinMode(ledOnBoard,OUTPUT);  //Thiết lập chân điều khiển led là ngõ xuất (OUTPUT)
  digitalWrite(ledOnBoard,LOW); // sau đó đưa xuống mức thấp(LOW) để led tắt

  pinMode(chipiSoundSensor,INPUT);  
}

void loop()
{
  if(digitalRead(chipiSoundSensor) == HIGH) // Đọc tín hiệu sensor, khi có âm thanh thì tín hiệu sẽ lên mức HIGH, bạn có thể dùng ngắt để tăng độ nhạy cho sensor.
  {
    ledState = ~ledState ;  //Khi có tín hiệu sensor (vỗ tay) thì đảo trạng thái của led
    digitalWrite(ledOnBoard,ledState);  
    delay(500);
  }
}


