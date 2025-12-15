#include <math.h>

float noiseIntensity = 0.3;
float step = 0.0;
float speed = 0.05;
int seed = 7846123;

void setup() {
  randomSeed(seed);
  pinMode(9, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() {
  step += speed;
  float value = sin(step);
  float noise = random(-(int)(noiseIntensity * 1000.0), (int)(noiseIntensity * 1000.0)) / 1000.0;
  float sum = value + noise;
  float normalized = (sum + 1.0 + noiseIntensity)/(2.0 + 2.0 * noiseIntensity);
  float fitsRange = normalized * 255.0;
  analogWrite(9, (int)fitsRange);
  analogWrite(11, (int)(255 - fitsRange));
  delay(20);
}
