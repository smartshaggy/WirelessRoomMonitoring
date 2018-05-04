# WirelessRoomMonitoring
Using Photons and the Particle IDE base to wirelessly monitor/control a rooms temp as well as sense the volume in a tank of honey as it fills.
This was for a client who wanted wireless monitoring capabilities in his production facility. Three photons were used in total.
The room control photon was subrcribed to the other two to make reading all the data and setting controls easier. This was connected to a relay to control the heater via overrriding the thermostat currently in use.
The gravity system was used to monitor flow into the collection tank of a gravity flow system and measures volume in a 50 gal drum. A HCSR04 sonic sensor was used to sense tank level and then converted to volume. A DHT22 was used to sense room temp.
Temp probe measures temp from a k-type thermocouple using a MAX6675 sensor
