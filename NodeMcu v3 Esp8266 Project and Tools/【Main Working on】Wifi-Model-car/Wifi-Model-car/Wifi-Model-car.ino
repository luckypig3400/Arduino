#include <ESP8266WiFi.h>
const char* ssid = "Chevrolet_Camaro_Concept_model"; //your WiFi Name
const char* password = "wirelessV1.0";  //Your Wifi Password
const int testLEDPin = 13;//D7 pin
const int MainMotorPin1 = 5;//D1
const int MainMotorPin2 = 4;//D2
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  delay(10); 
  pinMode(testLEDPin,OUTPUT);
  pinMode(MainMotorPin1,OUTPUT);
  pinMode(MainMotorPin2,OUTPUT);
  digitalWrite(testLEDPin,LOW); 
  digitalWrite(MainMotorPin1,LOW);
  digitalWrite(MainMotorPin2,LOW); 
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid); 
  WiFi.begin(ssid, password);//嘗試連線到設定好的SSID
  while (WiFi.status() != WL_CONNECTED) {//如果還沒連線到
    delay(500);
    Serial.print(".");
  }
  //以下為成功連線後所執行的動作
  Serial.println("");
  Serial.println("WiFi connected"); 
  server.begin();//開啟伺服器
  Serial.println("Server started");
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());//顯示出這塊板子的IP位置
  Serial.println("/"); 
}


void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;//如果Client還未做出回應(接資料)，就在從頭跑一次LOOP
  }
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(10);//如果Client還來不及做出回應(接資料)，等待他10毫秒
  }
  // Read the first line of the request
  String request = client.readStringUntil('\r');//讀取Client的回應直到換行符號出現
  Serial.println(request);
  client.flush();//丟棄遺失的封包
  // Match the request
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(testLEDPin, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(testLEDPin, LOW);
    value = LOW;
  }
  if (request.indexOf("/MotorForward") != -1)  {
    digitalWrite(MainMotorPin1, LOW);
    digitalWrite(MainMotorPin2, HIGH);
  }
  if (request.indexOf("/MotorBackward") != -1)  {
    digitalWrite(MainMotorPin2, LOW);
    digitalWrite(MainMotorPin1, HIGH);
  }
// Set testLEDPin according to the request
//digitalWrite(testLEDPin, value);

  //以下對客戶端(Client，像是手機)丟HTML語法，
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led is now: ");
 
  if(value == HIGH) {
    client.print("On");
  } else {
    client.print("Off");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>On </button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>Off </button></a><br />");  
  client.println("<a href=\"/MotorForward\"\"><button>Forward</button></a><br /><br /><br />");  
  client.println("<a href=\"/MotorBackward\"\"><button>Backward </button></a><br />");  
  client.println("</html>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
