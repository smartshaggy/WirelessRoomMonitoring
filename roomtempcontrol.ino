int Thermostat = D7;
int RoomTemp;
int TankVolume;
int HighTemp;
int LowTemp;
int HighT;
int LowT;
int HoneyT;
STARTUP(WiFi.selectAntenna(ANT_EXTERNAL));

//The subscriptions come from published values fromt the GravSystem and TempProbe Photons
//Functions take the desired temp range from the user via the HotRoomControl Photon
//Variables visible to user allow them to decide how to set temp range to fit desired room temp

void setup() {
pinMode(Thermostat, OUTPUT);
Particle.subscribe("volume", GetVolume, "24002a001947343438323536");
Particle.subscribe("ReadTemp", GetTemp, "24002a001947343438323536");
Particle.subscribe("TempF", HoneyTemp, "4f002a001051363036373538");

Particle.function("HighTemp", HandleHighTempInput);
Particle.function("LowTemp", HandleLowTempInput);

Particle.variable("TankVolume", TankVolume);
Particle.variable("RoomTemp", RoomTemp);
Particle.variable("HoneyTemp", HoneyT);
Particle.variable("LowSet", LowT);
Particle.variable("HighSet", HighT);
}

//This handles the subscription to the room temperature from the GravSystem Photon
void GetTemp(String eventname, String dataT)
{
    RoomTemp = dataT.toInt();
}

//This handles the subscription to the tank volume from the GravSystem Photon
int GetVolume(String volume, String dataV)
{
    TankVolume = dataV.toInt();
    return TankVolume;
}
//This handles the subscription to the honey temp from the TempProbe Photon
int HoneyTemp(String TempF, String dataH)
{
    HoneyT = dataH.toInt();
    return HoneyT;
}
//The following two statements handle the user inputs to set the temp range of the hot room
int HandleHighTempInput(String command)
{
    HighT = command.toInt();
    return HighT;
}

int HandleLowTempInput(String command)
{
    LowT = command.toInt();
    return LowT;
}


//Thermostat set to LOW turns heater OFF
//Thermostat set to HIGH turns heater ON
void loop() {

if (RoomTemp <= LowT) 
{
    digitalWrite(Thermostat, HIGH);
}
else if (RoomTemp > HighT) 
{
    digitalWrite(Thermostat, LOW);
}
else if (RoomTemp < HighT && RoomTemp >= LowT)
{
    digitalWrite(Thermostat, LOW);
}
}
