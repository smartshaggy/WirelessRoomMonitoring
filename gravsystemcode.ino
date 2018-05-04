{  
  
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // convert the time into a distance
  cm = (duration/2.00) / 29.1;
  inches = (duration/2.00) / 74.00; 
  //Serial.println(cm);
  
  // This code gets the volume of the drum in gallons
  volume = 397.61 * (33.5 - inches);
  volume = volume / 231;
  
  /*
  //Volume for test bucket  below
  volume = 95.0*(11.0 - inches);
  //volume = volume/231.0;
  */
  Particle.publish("volume" , String(volume, 2));
  
  delay(1000);

  // The valve will be normally open
  if (cm < 20)
  {
     digitalWrite(solenoidPin, LOW);     //Switch Solenoid valve off
  }
  else
  {
    digitalWrite(solenoidPin, HIGH);     //Switch Solenoid on
  }
  
 //The following is for the temperature and humidity sensor
  //Read data and store it to variables hum and temp
  //hum = dht.getHumidity();
  actualtemp = dht.getTempFarenheit();
  //actualtemp = (UnfilteredTemp > double(60));
  //Print temp and humidity values to particle app
  Particle.publish("ReadTemp" , String(actualtemp, 2));
  //Particle.publish("humidity" , String(hum, 2));
  
  delay(1000); //Delay 1 sec.
  

}
