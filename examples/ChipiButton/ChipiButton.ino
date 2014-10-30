/*********************************************************************************
//  Chương trình: ChipiButton
//  Tác giả: TP
//  Ngày: 25 Oct 2014
//  Mô tả: Chương trình này sẽ đọc giá trị từ nút nhấn được nối với chân 8 của Arduino và nháy led 13 có sẵn trên bo.
//  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiButton để tương thích hoàn toàn nhé.
//  Ngoài ChipiButton, chương trình này cũng sử dụng được cho các loại sensor dạng nút nhấn như công tắc từ, công tắc thủy ngân, công tắc hành trình ...
//  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
//  Tham khảo http://chipfc.com/ để biết thêm chi tiết
*********************************************************************************/

byte ledOnBoard = 13;  //Mỗi bo Arduino của ChipFC đều có một led xanh dương thiết kể sẵn trên bo tại chân D13.
byte chipiButton = 8;  //
void setup()
{
  pinMode(ledOnBoard,OUTPUT);  //Thiết lập chân điều khiển led là ngõ xuất (OUTPUT)
  digitalWrite(ledOnBoard,LOW); // sau đó đưa xuống mức thấp(LOW) để led tắt
  
  pinMode(chipiButton,INPUT);  
}

void loop()
{
  if(digitalRead(chipiButton) == LOW) digitalWrite(ledOnBoard,HIGH); // Nếu nút nhấn được nhấn (LOW) thì sáng led
  else   digitalWrite(ledOnBoard,LOW);                    // nếu không thì tắt led
  delay(10);  
}

