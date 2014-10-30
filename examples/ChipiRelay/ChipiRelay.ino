/*********************************************************************************
 * //  Chương trình: ChipiRelay
 * //  Tác giả: TP
 * //  Ngày: 25 Oct 2014
 * //  Mô tả: Chương trình này sẽ thay đổi trạng thái của rờ le
 * //  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiRelay để tương thích hoàn toàn nhé.
 * //  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
 * //  Tham khảo http://chipfc.com/ để biết thêm chi tiết
 *********************************************************************************/

#define NC  LOW
#define NO HIGH

byte relayPin = 8;
boolean relayState = NC;

void setup()
{
  pinMode(relayPin,OUTPUT);  // Thiết lập chân điều khiển led là OUTPUT hay ngõ xuất
  digitalWrite(relayPin, relayState);
}

void loop()
{
  digitalWrite(relayPin,relayState);
  relayState = ~relayState;
  delay(2000);
}


