#define THUMB_PIN 1
#define INDEX_PIN 2
#define MIDDLE_PIN 3
#define RING_PIN 4
#define PINKY_PIN 5



int thumb, indexfinger, middle, ring, pinky;

void setup() {
  Serial.begin(115200);
  delay(1000);
}

void loop() {
  readsensors();
  printvalues();
  detectletter();
  delay(300);
}

void readsensors() {
  int thumbRaw = analogRead(THUMB_PIN);
  int indexRaw = analogRead(INDEX_PIN);
  int middleRaw = analogRead(MIDDLE_PIN);
  int ringRaw = analogRead(RING_PIN);
  int pinkyRaw = analogRead(PINKY_PIN);

  thumb = constrain(map(thumbRaw, 256, 59, 0, 100), 0, 100);
  indexfinger = constrain(map(indexRaw, 256, 59, 0, 100), 0, 100);
  middle = constrain(map(middleRaw, 256, 59, 0, 100), 0, 100);
  ring = constrain(map(ringRaw, 256, 59, 0, 100), 0, 100);
  pinky = constrain(map(pinkyRaw, 256, 59, 0, 100), 0, 100);
}


void printvalues() {
  Serial.print("T:");
  Serial.print(thumb);
  Serial.print(" I:");
  Serial.print(indexfinger);
  Serial.print(" M:");
  Serial.print(middle);
  Serial.print(" R:");
  Serial.print(ring);
  Serial.print(" P:");
  Serial.print(pinky);
  Serial.print(" --> ");
}


void detectletter() {
  if (thumb > 60 && indexfinger > 60 && middle > 60 && ring > 60 && pinky > 60) {
    Serial.println("Letter: A");
  }
  else if (thumb > 60 && indexfinger < 40 && middle < 40 && ring < 40 && pinky < 40) {
    Serial.println("Letter: B");
  }
  else if (thumb > 40 && thumb < 80 && indexfinger > 40 && indexfinger < 80 &&
           middle > 40 && middle < 80 && ring > 40 && ring < 80 &&
           pinky > 40 && pinky < 80) {
    Serial.println("Letter: C");
  }
  else {
    Serial.println("Unknown");
  }
}