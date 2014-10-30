/*********************************************************************************
 * //  Chương trình: ChipiLEDBiColor
 * //  Tác giả: TP
 * //  Ngày: 25 Oct 2014
 * //  Mô tả: Chương trình này sẽ thay đổi độ sáng của led (2 màu) để tạo ra sự trộn màu, led đỏ gắn chân 10, led xanh gắn chân 11
 * //  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiLEDBiColor để tương thích hoàn toàn nhé.
 * //  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
 * //  Tham khảo http://chipfc.com/ để biết thêm chi tiết
 *********************************************************************************/
#define NON_BRIGHT 0
#define LOW_BRIGHT 100
#define MEDIUM_BRIGHT 175
#define HIGH_BRIGHT 255

byte ledRed = 10;
byte ledGreen = 11;
byte brightValue[4] = {NON_BRIGHT, LOW_BRIGHT, MEDIUM_BRIGHT, HIGH_BRIGHT};  //Định nghĩa các giá trị độ sáng

void setup()
{
  pinMode(ledRed,OUTPUT);  // Thiết lập chân điều khiển led là OUTPUT hay ngõ xuất
  pinMode(ledGreen,OUTPUT);
}

void loop()
{
  byte i,j;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++)
    {
      analogWrite(ledRed, brightValue[i]);  //Chúng ta sẽ lận lượt pha trộn màu xanh và đỏ 
      analogWrite(ledGreen,brightValue[j]);  //để tạo ra các màu hiệu ứng 
      delay(800);
    }
  }
}



