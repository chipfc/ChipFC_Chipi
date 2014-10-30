/*********************************************************************************
//  Chương trình: ChipiHumidity_Temperature
//  Tác giả: TP
//  Ngày: 28 Oct 2014
//  Mô tả: Chương trình này sẽ đọc giá trị nhiệt độ và độ ẩm từ cảm biến DHT11 và in lên màn hình giao tiếp máy tính
//  Hãy sử dụng hệ thống Arduino của ChipFC (ChipiUno, ChipiPro ...) với shieldChipiBase và ChipiHumid&Temp để tương thích hoàn toàn nhé.
//  Chương trình này hoàn toàn mở và được sử dụng theo điều khoản của mã nguồn mở
//  Tham khảo http://chipfc.com/ để biết thêm chi tiết
*********************************************************************************/

#include "Arduino.h"
#include "Dht11.h"

enum {
    DHT_DATA_PIN = 2,  //Định nghĩa chân giao tiếp của DHT11 được nối với chân số 2 của Arduino

    SERIAL_BAUD  = 9600,  //Tốc độ giao tiếp với máy tính là baud = 9600

    POLL_DELAY   = 2000,  //Thời gian nghỉ giữa các lần đọc dữ liệu là 2 giây
};

void setup() {
    Serial.begin(SERIAL_BAUD);
    Serial.print("Dht11 Lib version ");
    Serial.println(Dht11::VERSION);
}

void loop() {
    static Dht11 sensor(DHT_DATA_PIN);  //Khai báo đối tượng cảm biến(sensor)

    switch (sensor.read()) {    //Đọc dữ liệu từ cảm biến, giá trị trả về là một trong các giá trị OK, ERROR_CHECKSUM, ERROR_TIMEOUT
    case Dht11::OK:
        Serial.print("Humidity (%): ");
        Serial.println(sensor.getHumidity());    //In ra giá trị độ ẩm theo %

        Serial.print("Temperature (C): ");
        Serial.println(sensor.getTemperature());  //In ra giá trị nhiệt độ theo độ C
        break;

    case Dht11::ERROR_CHECKSUM:
        Serial.println("Checksum error");  //Báo lỗi checksum
        break;

    case Dht11::ERROR_TIMEOUT:
        Serial.println("Timeout error");  //Báo lỗi timeout
        break;

    default:
        Serial.println("Unknown error");
        break;
    }

    delay(POLL_DELAY);
}

