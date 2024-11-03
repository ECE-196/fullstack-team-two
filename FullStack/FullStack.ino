// ECE 196 Full Stack 

const int LED {17}; 
const char S_OK {0xaa}; 
const char S_ERR {0xff}; 

void setup() {
    pinMode(LED, OUTPUT); 

    Serial.onEvent(ARDUINO_HW_CDC_RX_EVENT, on_receive); 
    Serial.begin(9600);
}

void on_receive(void* event_handler_arg, esp_event_base_t event_base, int32_t event_id, void* event_data) {

  char state { Serial.read() }; 

  if(!(state == LOW || state == HIGH)) {
    Serial.write(S_ERR); 
    delay(500); 
    return; 
  }

  digitalWrite(LED, state); 
  Serial.write(S_OK); 
  delay(500); 

}

void loop() {

} 

