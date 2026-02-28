// by shm for desinv 23

int potpin = A0;
int reading = 0;
int val;

void setup(){
  Serial.begin(115200);
}

void loop(){
  //read what's coming in to A0
  reading = analogRead(potpin);
   if (reading != val){   //if its not the same as what we have saved in "val"... 
    val = reading; // change val to the new reading
    Serial.println(val); //optionally, print to the Serial Monitor
  }
  
  delay(15);
}