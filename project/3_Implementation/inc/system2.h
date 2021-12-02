void setup(void) {

  startFingerprintSensor();
  display.begin();
  displayLockScreen(); 
}

void loop() {

  fingerprintID = getFingerprintID();
  delay(50);
  if(fingerprintID == 1)
  {
    display.drawBitmap(30,35,icon,60,60,GREEN);
    delay(2000);
    displayUnlockedScreen();
    displayIoanna();
    delay(5000);
    display.fillScreen(BLACK);
    displayLockScreen();

