#include <Arduino.h>
#include <SerialCommand.h>

SerialCommand cli;

void sendOK(){
    Serial.print("OK\r\n"); /* Send "OK" message */
}

void sendError(){
    Serial.print("ERROR\r\n"); /* Send "OK" message */
}

void keyBoardText(){
    char* arg = cli.next();
    if(!arg){
        sendError();
        return;
    }
    Serial.print("+TEXT:");
    Serial.print(arg);
    Serial.print("\r\n");
    sendOK();
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  cli.begin(Serial);
  cli.addExecuteCommand((char *)"AT", sendOK);
  cli.addCommand((char *)"AT+KBTEXT", sendOK, sendError, keyBoardText, sendError);
}

void loop() {
  // put your main code here, to run repeatedly:
  cli.loop();

}

