void setup() {
  int note_duration = 1000;
  for(int freq = 50; freq <= 4950; freq+=50){
    tone(8, freq);
    delay(note_duration);
    noTone(8);
    delay(note_duration);
  }
}

void loop() {
 
}
