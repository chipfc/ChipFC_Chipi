/*********************************************************************************
//  Chương trình: ChipiTouchSensor
//  Tác giả: TP
//  Ngày: 25 Oct 2014
//  Mô tả: Chương trình này sẽ đọc giá trị từ cảm biến chạm được nối với chân 8 của Arduino và nháy led 13 có sẵn trên bo.
//  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiTouchsensor để tương thích hoàn toàn nhé.
//  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
//  Tham khảo http://chipfc.com/ để biết thêm chi tiết
*********************************************************************************/

byte ledOnBoard = 13;  //Mỗi bo Arduino của ChipFC đều có một led xanh dương thiết kể sẵn trên bo tại chân D13.
byte chipiTouchSensor = 8;  //Sensor nối với chân Digital 8 của Arduino
void setup()
{
  pinMode(ledOnBoard,OUTPUT);  //Thiết lập chân điều khiển led là ngõ xuất (OUTPUT)
  digitalWrite(ledOnBoard,LOW); // sau đó đưa xuống mức thấp(LOW) để led tắt
  
  pinMode(chipiTouchSensor,INPUT);  
}

void loop()
{
  if(digitalRead(chipiTouchSensor) == HIGH) digitalWrite(ledOnBoard,HIGH); // Nếu nút nhấn được nhấn (HIGH) thì sáng led
  else   digitalWrite(ledOnBoard,LOW);                    // nếu không thì tắt led
  delay(10);  
}

