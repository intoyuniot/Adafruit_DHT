#include "Adafruit_DHT.h"

//传感器通讯引脚
#define DHTPIN 2

//选择传感器类型
//#define DHTTYPE DHT11  // DHT11
#define DHTTYPE DHT22  // DHT22 (AM2302)
//#define DHTTYPE DHT21  // DHT21 (AM2301)

Adafruit_DHT dht(DHTPIN, DHTTYPE);

void setup()
{
    Serial.begin(115200);
    Serial.println("DHTxx test!");
    dht.begin();
}

void loop()
{
    delay(2000);

    float h = dht.getHumidity();     //获取湿度
    float t = dht.getTempCelcius();  //获取摄氏温度
    float f = dht.getTempFarenheit();//获取华氏温度

    //检查是否获取数据失败(失败重新开始)
    if (isnan(h) || isnan(t) || isnan(f))
    {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    float hi = dht.getHeatIndex();  //获取热指数
    float dp = dht.getDewPoint();   //获取露点
    float k = dht.getTempKelvin();  //获取绝对温度

    Serial.print("Humid: ");
    Serial.print(h);
    Serial.print("% - ");
    Serial.print("Temp: ");
    Serial.print(t);
    Serial.print("*C ");
    Serial.print(f);
    Serial.print("*F ");
    Serial.print(k);
    Serial.print("*K - ");
    Serial.print("DewP: ");
    Serial.print(dp);
    Serial.print("*C - ");
    Serial.print("HeatI: ");
    Serial.print(hi);
    Serial.println("*C");
    Serial.println(Time.timeStr());
}
