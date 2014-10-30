/*********************************************************************************
 * //  Chương trình: ChipiSDCard
 * //  Tác giả: TP
 * //  Ngày cập nhật: 29 Oct 2014
 * //  Mô tả: Chương trình này sẽ đọc thông tin thẻ nhớ và xuất lên màn hình giao tiếp 
 * //         máy tính (bật bằng cách nhấn nút hình kính lúp phía trên bên phải của cửa sổ này).
 * //  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiSDCard để tương thích hoàn toàn nhé.
 * //  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
 * //  Tham khảo http://chipfc.com/ để biết thêm chi tiết
 *********************************************************************************/

#include <SD.h>  //  sử dụng thư viện SD cho SDCard

Sd2Card card;  //Khởi tạo các biến để sử dụng SDCard
SdVolume volume;
SdFile root;

const int chipSelect = 10;  //Chân Select cho SPI trên shieldChipiBase mặc định sẵn là chân 10

void setup()
{
  Serial.begin(9600);  //Bắt đầu cổng giao tiếp 
   while (!Serial) {
    ;   //Đợi cổng giao tiếp mở, chỉ cần khu dùng ChipiLeo hoặc A.Leonardo
  }


  Serial.print("\nInitializing SD card...");
  pinMode(10, OUTPUT);     // Chân SS của Arduino nên để là OUTPUT, thay bằng 53 nếu dùng bo Mega

  if (!card.init(SPI_HALF_SPEED, chipSelect)) {  //Kiểm tra thông số của thẻ nhó bằng cách init
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card is inserted?");
    Serial.println("* Is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
  } else {
   Serial.println("Wiring is correct and a card is present."); 
  }

  Serial.print("\nCard type: ");  //In loại thẻ
  switch(card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }

  if (!volume.init(card)) {  //Thử mở 'volume'/'partition' - xem nó là FAT16 hay FAT32
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    return;
  }


  uint32_t volumesize;  //In ra loại thẻ
  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  Serial.println();
  
  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize *= 512;                            // SD card blocks are always 512 bytes
  Serial.print("Volume size (bytes): ");
  Serial.println(volumesize);
  Serial.print("Volume size (Kbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Mbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);

  
  Serial.println("\nFiles found on the card (name, date and size in bytes): ");
  root.openRoot(volume);
  
  root.ls(LS_R | LS_DATE | LS_SIZE);  //Liệt kê file với thời gian và kích thước
}


void loop(void) {
  
}
