#include <IRremote.h>

const int c=262;
const int d=294;
const int e=330;
const int f=349;
const int g=392;
const int a=440;
const int b=494;
const int C=523;
const byte recv_pin=8;
const byte buzzer_pin=10;

IRrecv receiver(recv_pin);

void setup() {

  Serial.begin(9600);
  receiver.enableIRIn();
  pinMode(buzzer_pin, OUTPUT);
}

void loop() {

  if(receiver.decode()){
    int response=receiver.decodedIRData.command;
    Serial.println(response);
    if(response==48) play_tone(c);
    else if(response==24) play_tone(d);
    else if(response==122) play_tone(e);
    else if(response==16) play_tone(f);
    else if(response==56) play_tone(g);
    else if(response==90) play_tone(a);
    else if(response==66) play_tone(b);
    else if(response==74) play_tone(C);
    else receiver.resume();

  }
  
}

void play_tone(int pitch){
  tone(buzzer_pin , pitch);
  delay(500);
  noTone(buzzer_pin);
  receiver.enableIRIn();
