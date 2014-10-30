/*********************************************************************************
 * //  Chương trình: ChipiBuzzer
 * //  Tác giả: TP
 * //  Ngày: 25 Oct 2014
 * //  Mô tả: Chương trình này sẽ kêu loa bíp được nối với Arduino ở chân số 8
 * //  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiBuzzer để tương thích hoàn toàn nhé.
 * //  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
 * //  Tham khảo http://chipfc.com/ để biết thêm chi tiết
 *********************************************************************************/

byte buzzerPin = 8;  //Gắn Buzzer hay loa bíp vào chân số 8 của Arduino

void setup()
{
  pinMode(buzzerPin,OUTPUT);  // Thiết lập chân điều khiển loa là OUTPUT hay ngõ xuất
}

void loop()
{
  digitalWrite(buzzerPin,HIGH);
  delay(800);
  digitalWrite(buzzerPin,LOW);
  delay(1200);
}




