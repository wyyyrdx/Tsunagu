void setup() {
  Serial.begin(9600);
}

void loop() {
  int thumbRaw = analogRead(A0);
  int indexRaw = analogRead(A1);
  int middleRaw = analogRead(A2);
  int ringRaw = analogRead(A3);
  int pinkyRaw = analogRead(A4);

  int thumb = constrain(map(thumbRaw, 256, 59, 0, 100), 0, 100);
  int index = constrain(map(indexRaw, 256, 59, 0, 100), 0, 100);
  int middle = constrain(map(middleRaw, 256, 59, 0, 100), 0, 100);
  int ring = constrain(map(ringRaw, 256, 59, 0, 100), 0, 100);
  int pinky = constrain(map(pinkyRaw, 256, 59, 0, 100), 0, 100);

  Serial.print("T:");
  Serial.print(thumb);
  Serial.print(" I:");
  Serial.print(index);
  Serial.print(" M:");
  Serial.print(middle);
  Serial.print(" R:");
  Serial.print(ring);
  Serial.print(" P:");
  Serial.print(pinky);
  Serial.print(" --> ");

  if (thumb > 60 && index > 60 && middle > 60 && ring > 60 && pinky > 60) {
    Serial.println("Letter: A");
  }
  else if (thumb > 60 && index < 40 && middle < 40 && ring < 40 && pinky < 40) {
    Serial.println("Letter: B");
  }
  else if (thumb > 40 && thumb < 80 && index > 40 && index < 80 &&
           middle > 40 && middle < 80 && ring > 40 && ring < 80 &&
           pinky > 40 && pinky < 80) {
    Serial.println("Letter: C");
  }
  else {
    Serial.println("Unknown");
  }

  delay(300);
}