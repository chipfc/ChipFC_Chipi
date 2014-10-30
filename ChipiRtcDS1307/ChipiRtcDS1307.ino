/*********************************************************************************
 * //  Chương trình: ChipiRtcDS1307
 * //  Tác giả: TP
 * //  Ngày cập nhật: 29 Oct 2014
 * //  Mô tả: Chương trình này sẽ đọc giá trị thời gian từ ChipiRTCDS1307 và xuất lên màn hình giao tiếp 
 * //         máy tính (bật bằng cách nhấn nút hình kính lúp phía trên bên phải của cửa sổ này).
 * //  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiRTCDS1307 để tương thích hoàn toàn nhé.
 * //  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
 * //  Tham khảo http://chipfc.com/ để biết thêm chi tiết
 *********************************************************************************/

#include <Time.h>  
#include <Wire.h>  
#include <DS1307RTC.h>  //Thư viện Time và thư viện DS1307RTC cần được giải nén trong thư mục arduino->libraries

void setup()  {
  Serial.begin(9600);  //Khởi động màn hình giao tiếp 
  setSyncProvider(RTC.get);   // Hàm lấy giá trị thời gian
  if(timeStatus()!= timeSet) 
     Serial.println("Unable to sync with the RTC");
  else
     Serial.println("RTC has set the system time");      
}

void loop()
{
   digitalClockDisplay();  //Lấy giá trị thời gian và hiển thị lên máy tính qua cổng Serial
   delay(1000);
}

void digitalClockDisplay(){
  Serial.print(hour());  //Giờ
  printDigits(minute());  //Phút
  printDigits(second());  //Giây
  Serial.print(" ");
  Serial.print(day());  //Ngày
  Serial.print(" ");
  Serial.print(month());  //Tháng
  Serial.print(" ");
  Serial.print(year());   //Năm
  Serial.println(); 
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

