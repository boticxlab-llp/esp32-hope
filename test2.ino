#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <ESPmDNS.h>

#define RXD2 16
#define TXD2 17
// Replace with your network credentials
// const char *ssid = "Hp";
// const char *password = "123456788";

const char *ssid = "hope";
const char *password = "123456788";

// Create AsyncWebServer object on port 80
AsyncWebServer server_esp(80);
WiFiServer server(8080);
char myData[50] = "0,0,0,0";

// int in;
// int out;
// int net;
// int total;

char in[5];
char out[5];
char net[5];
char total[5];

// char ins[5];
// char outs[5];

void trunck()
{
  char *token;
  /* get the first token */
  token = strtok(myData, ",");
  int count = 0;
  /* walk through other tokens */
  while (token != NULL)
  {
    //   printf( " %s\n", token );
    if (count == 0)
    {
      strcpy(in, token);
    }

    if (count == 1)
    {
      strcpy(out, token);
    }

    if (count == 2)
    {
      strcpy(net, token);
    }

    if (count == 3)
    {
      strcpy(total, token);
    }
    count++;
    token = strtok(NULL, ",");
  }
}

String totalcount()
{
  //  total = 1;
  // total++;
  // Serial.println(total);
  // return String(total);
  return total;
}

String incount()
{
  // in = 1;
  // in++;
  // Serial.println(in);
  // return String(in);
  return in;
}

String outcount()
{
  //  out = 1;
  // out++;
  // Serial.println(out);
  // return String(out);
  return out;
}

String netcount()
{
  // float net = 1;
  // net++;
  // Serial.println(net);
  // return String(net);

  return net;
}

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html>
<head>   
    <meta http-equiv="refresh" content="5">
    <!-- add the following google font / icon to the webpage -->  
    <link rel="stylesheet" href="https://fonts.googleapis.com/icon?family=Material+Icons">
     
<style>   
    * {   
        box-sizing: border-box;   
    }
    
    body {  
    background-color: powderblue;
    
      background-size: cover;
  
  overflow: hidden; 
     }
      
    .column {   
        /* box toward left of the window screen */  
        float: left;   
        /*divide each counter box in equal size*/  
        /* 4 counters of 25% of screen size*/  
        width: 25%;   
        /*spacing between each box */  
        padding: 4px;
      margin-left:70px;
          
    }   
          
    .row {   
        /* Specify the margin for the row class */  
        margin: 3px;  
    }   
          
    /* Style the class named block*/  
    .block {   
        padding: 10px;   
        text-align: center;   
        background-color: #0100ca;   
        color: white;   
        }   
   /* Style the class named block*/  
    .block2 {   
        padding: 10px;   
        text-align: center;   
        background-color: #5efc82;   
        color: white;   
        }             
    .fa {   
        font-size: 50px;   
    }
    </style>   
      
</head>

<body>   
<center>  
    <h1 style="color:black"> Hope Security </h1>
    <h3 style="color:black"> Visitor Counter </h3>
          
     <div class="row">   
    <div class="column">   
        <div class="block">
        
            <!-- Add visitor icon -->  
           
        <h1>&nbsp&nbsp&nbsp&nbsp InCount &nbsp&nbsp&nbsp&nbsp</h1>   
        </div>
        <div class="block2">  
            <h1 style="color:black"> %IN% </h1>   
            <h3 style="color:black"> Visitor entry count </h3>   
        </div>
    </div>  
          
    <div class="column">   
        <div class="block"> 
        
                <!-- Add Visitor icon -->  
           
        <h1>&nbsp&nbsp&nbsp&nbsp OutCount &nbsp&nbsp&nbsp&nbsp</h1>   
        </div>
        <div class="block2">  
            <h1 style="color:black"> %OUT% </h1>   
            <h3 style="color:black"> Visitors exit count </h3>   
        </div>
    </div>   
          
    <div class="column">   
        <div class="block">
        
            <!-- Add Visitor icon -->  
           
        <h1>&nbsp&nbsp&nbsp&nbsp NetCount &nbsp&nbsp&nbsp&nbsp</h1>    
        </div>
        <div class="block2">  
            <h1 style="color:black"> %NET% </h1>   
            <h3 style="color:black"> Visitors inside count </h3>   
        </div>
    </div>   
  
    <div class="column">   
        <div class="block">
        
            <!-- Add Visitor icon -->  
        
        <h1>&nbsp&nbsp TotalCount &nbsp&nbsp</h1>   
        </div>
        <div class="block2">  
            <h1 style="color:black"> %TOTAL% </h1>   
            <h3 style="color:black"> Visitors Total count </h3>   
        </div>
    </div>   
    </div>
</center>  
</body>
 
<script>
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("in").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/in", true);
  xhttp.send();
}, 1000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("out").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/out", true);
  xhttp.send();
}, 1000 ) ;
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("net").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/net", true);
  xhttp.send();
}, 1000 ) ;

setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("total").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "/total", true);
  xhttp.send();
}, 1000 ) ;
</script>
</html>)rawliteral";

// Replaces placeholder with DHT values
String processor(const String &var)
{
  // Serial.println(var);
  if (var == "IN")
  {
    return incount();
    // return ins;
  }
  else if (var == "OUT")
  {
    return outcount();
    // return outs;
  }
  else if (var == "NET")
  {
    return netcount();
  }
  else if (var == "TOTAL")
  {
    return totalcount();
  }

  return String();
}

/*
in = 20
out = 50
total = 20+50
net = total -out
*/

void setup()
{
  // Serial port for debugging purposes
  Serial.begin(9600);
  Serial2.begin(9600, SERIAL_8N1, RXD2, TXD2);
  // dht.begin();

  // Connect to Wi-Fi
  // WiFi.begin(ssid, password);
  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   delay(1000);
  //   Serial.println("Connecting to WiFi..");
  // }
   Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();

  // Set your Static IP address
IPAddress local_IP(192, 168, 0, 100);
// Set your Gateway IP address
IPAddress gateway(192, 168, 0, 1);

IPAddress subnet(255, 255, 0, 0);

  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("server_esp started");

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

      // Set up mDNS responder:
    // - first argument is the domain name, in this example
    //   the fully-qualified domain name is "esp32.local"
    // - second argument is the IP address to advertise
    //   we send our IP address on the WiFi network
    if (!MDNS.begin("hope")) {
        Serial.println("Error setting up MDNS responder!");
        while(1) {
            delay(1000);
        }
    }
    Serial.println("mDNS responder started");
  // Route for root / web page
  server_esp.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", index_html, processor); });
  server_esp.on("/in", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", incount().c_str()); });
  server_esp.on("/out", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", outcount().c_str()); });
  server_esp.on("/net", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", netcount().c_str()); });
  server_esp.on("/total", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", totalcount().c_str()); });

  // Start server_esp
  server_esp.begin();
}

// in -out, in+out
void loop()
{

  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("New Client.");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> to turn ON the LED.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn OFF the LED.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {    // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        // if (currentLine.endsWith("GET /H")) {
        //   digitalWrite(LED_BUILTIN, HIGH);               // GET /H turns the LED on
        // }
        // if (currentLine.endsWith("GET /L")) {
        //   digitalWrite(LED_BUILTIN, LOW);                // GET /L turns the LED off
        // }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }


  //....................................

  if (Serial2.available() > 0)
  {
    // String myData1 =Serial2.readString();// s1 is String type variable.
    String myData1 = Serial2.readStringUntil('=');
    // myData1.trim();
    int len = myData1.length();
    myData1.toCharArray(myData, len + 1);

    Serial.println(myData1); // display same received Data back in serial monitor.
  }

  trunck();
  delay(200);
}

//       int count = 0;
//       while( token != NULL ) {
//       printf( " %s\n", token ); //printing each token
// // myString.toCharArray(buf, len)
//       token = strtok(NULL, ",");
//       // if(count == 0)
//       //   {
//       //     strcpy(a,token);
//       //   }
//       //   if(count == 1)
//       //   {
//       //     strcpy(b,token);
//       //   }
//       count++;
//    }
//    count = 0;

//   //  printf( "a: %s\n", a );
//   //   printf( "b: %s\n", a );
