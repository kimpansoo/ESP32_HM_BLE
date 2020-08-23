#include <ETH.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include <WiFi.h>
#define RXD2 16
#define TXD2 17

const char* WIFI_NAME = "KT_WLAN_A78D";
const char* WIFI_PASSWORD = "00000088d4";
WiFiServer server(80);

String header;


const int GPIO_PIN_NUMBER_22 = 22; //HM10-RESET
const int GPIO_PIN_NUMBER_23 = 23;//ESP32 RESET

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  pinMode(GPIO_PIN_NUMBER_22, OUTPUT);
  pinMode(GPIO_PIN_NUMBER_23, OUTPUT);

  digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
  digitalWrite(GPIO_PIN_NUMBER_23, HIGH);

  Serial.print("Connecting to ");
  Serial.println(WIFI_NAME);
  WiFi.begin(WIFI_NAME, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Trying to connect to Wifi Network");
  }
  Serial.println("");
  Serial.println("Successfully connected to WiFi network");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    Serial.println("New Client is requesting web page");
    String current_data_line = "";
    while (client.connected()) {
      if (client.available()) {
        char new_byte = client.read();
        Serial.write(new_byte);
        header += new_byte;
        if (new_byte == '\n') {

          if (current_data_line.length() == 0)
          {

            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("LED0=ON") != -1) // LED 켜
            {
              Serial2.write("AT+CON90E2028D6225"); delay(500);
              Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write("AT+PIO31"); delay(200);
              Serial2.write("AT+PIO30"); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("LED0=OFF") != -1) // LED 꺼
            {
              Serial2.write("AT+CON90E2028D6225"); delay(500);
              Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write("AT+PIO21"); delay(200);
              Serial2.write("AT+PIO20"); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("LED1=ON") != -1)  // 탁상등 켜
            {
              Serial2.write("AT+CONF8300205F0D7"); delay(500);
              Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write("AT+PIO31"); delay(200);
              Serial2.write("AT+PIO30"); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("LED1=OFF") != -1) // 탁상등 꺼
            {
              Serial2.write("AT+CONF8300205F0D7"); delay(500);
              Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write("AT+PIO21"); delay(200);
              Serial2.write("AT+PIO20"); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("LED2=ON") != -1) // 전등 켜
            {
              Serial2.write("AT+CON0035FF0B2C5A"); delay(500);
              Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write('a'); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("LED2=OFF") != -1) //전등 꺼
            {
              Serial2.write("AT+CON0035FF0B2C5A"); delay(500);
              Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write('b'); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("FAN=ON") != -1) //선풍기 켜  , 1단
            {
              Serial2.write("AT+CON0035FF0BAB97"); delay(500);
              Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write('A'); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("FAN=OFF") != -1) //선풍기 꺼
            {
              Serial2.write("AT+CON0035FF0BAB97"); delay(500);
              Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write('a'); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("TWO=ON") != -1) //2단
            {
              Serial2.write("AT+CON0035FF0BAB97"); delay(500);
              Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write('B'); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("THREE=ON") != -1) //3단
            {
              Serial2.write("AT+CON0035FF0BAB97"); delay(500);
              Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write('G'); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("ROT=ON") != -1) //회전
            {
              Serial2.write("AT+CON0035FF0BAB97"); delay(500);
              //Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write('D'); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }
            if (header.indexOf("STOP=ON") != -1) //정지
            {
              Serial2.write("AT+CON0035FF0BAB97"); delay(500);
              //Serial2.write("lkmjgdfsawetvvcfgyuyujhiolwqeesacbnmgfdhlppiughvffdddfvcvccdddeetrygdsfyujjghjkknbvdsaeerffc"); delay(200);
              Serial2.write('d'); delay(200);
              Serial2.write("AT+SLEEP"); delay(200);
              Serial2.write("AT+RESET"); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, LOW); delay(200);
              digitalWrite(GPIO_PIN_NUMBER_22, HIGH);
            }

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #4CAF50; border: 2px solid #4CAF50;; color: white; padding: 15px 32px; text-align: center; text-decoration: none; display: inline-block; font-size: 16px; margin: 4px 2px; cursor: pointer; }");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            // Web Page Heading
            client.println("</style></head>");
            client.println("<body><center><h1>HOME LED controlling</h1></center>");
            client.println("<center><h2>LED1,2, LIGHT, FAN, ETC</h2></center>" );
            client.println("<form><center>");
            // If the PIN_NUMBER_22State is off, it displays the ON button
            client.println("<center> <button class=\"button\" name=\"LED0\" value=\"ON\" type=\"submit\">LED ON</button>") ;
            client.println("<button class=\"button\" name=\"LED0\" value=\"OFF\" type=\"submit\">LED OFF</button><br>");
            client.println("<button class=\"button\" name=\"LED1\" value=\"ON\" type=\"submit\">LED ON</button>");
            client.println("<button class=\"button\" name=\"LED1\" value=\"OFF\" type=\"submit\">LED OFF</button> <br>");
            client.println ("<button class=\"button\" name=\"LED2\" value=\"ON\" type=\"submit\">LIGT ON</button>");
            client.println ("<button class=\"button\" name=\"LED2\" value=\"OFF\" type=\"submit\">LIGT OFF</button> <br>");
            client.println("<button class=\"button\" name=\"FAN\" value=\"ON\" type=\"submit\">FAN ON</button>");
            client.println("<button class=\"button\" name=\"FAN\" value=\"OFF\" type=\"submit\">FAN OFF</button> <br>");
            client.println("<button class=\"button\" name=\"TWO\" value=\"ON\" type=\"submit\">2</button>");
            client.println("<button class=\"button\" name=\"THREE\" value=\"ON\" type=\"submit\">3</button>");
            client.println("<button class=\"button\" name=\"ROT\" value=\"ON\" type=\"submit\">R</button>");
            client.println("<button class=\"button\" name=\"STOP\" value=\"ON\" type=\"submit\">S</button> <br>");
            client.println("<button class=\"button\" name=\"RESET\" value=\"ON\" type=\"submit\">RESET</button> ");
            client.println("</center></form></body></html>");
            client.println();
            break;
          }
          else
          {
            current_data_line = "";
          }
        }
        else if (new_byte != '\r')
        {
          current_data_line += new_byte;
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
