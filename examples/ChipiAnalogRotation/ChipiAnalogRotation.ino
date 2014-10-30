/*********************************************************************************
//  Chương trình: ChipiAnalogRotation
//  Tác giả: TP
//  Ngày cập nhật: 26 Oct 2014
//  Mô tả: Chương trình này sẽ đọc giá trị từ biến trở được nối với chân A0 của Arduino và in qua cổng Serial, đồng thời nháy led blue trên bo
//  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiAnalogRotation để tương thích hoàn toàn nhé.
//  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
//  Tham khảo http://chipfc.com/ để biết thêm chi tiết
*********************************************************************************/

byte ledOnBoard = 13;  //Mỗi bo Arduino của ChipFC đều có một led xanh dương thiết kể sẵn trên bo tại chân D13.
byte chipiPotentionMeterPin = A0;  //Biến trở được nối với chân A0 của Arduino
void setup()
{
  pinMode(ledOnBoard,OUTPUT);  //Thiết lập chân điều khiển led là ngõ xuất (OUTPUT)
  digitalWrite(ledOnBoard,LOW); // sau đó đưa xuống mức thấp(LOW) để led tắt
  
  //pinMode(chipiPotentionMeterPin,INPUT);  //Thiết lập chân biến trở là input hay ngõ nhập

  Serial.begin(9600);  //Khởi tạo cổng giao tiếp với máy tính, bấm nút hình kính lúp phía trên phải của chương trình Arduino để dùng
  Serial.println("begin!");
}

void loop()
{
  int sensorValue = analogRead(A0);// Đọc giá trị của sensor
  Serial.print("value is: ");
  Serial.println(sensorValue);  //In giá trị của sensor
  //Giá trị của sensor đọc về là 10 bit, có giá trị từ 0 -> 1024
  map(sensorValue,0,1024, 100, 800); //nên ta dùng hàm map để 
                                              
  digitalWrite(ledOnBoard,HIGH); //Nháy led theo giá trị điện trở
  delay(sensorValue);
  digitalWrite(ledOnBoard,LOW);
  delay(200);
  
}

