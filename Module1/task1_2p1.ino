// C++ code
//
volatile byte led = 0;
volatile bool Mo_status = false;

void setup()
{
  
  DDRD |= B00010000;	//set Pin4 as output
  DDRB |= B00100000;	//set Pin13 as output
  
  PCICR |= B00000100;	//turn interrupts on on PortD 
  
  PCMSK2 |= 0b0000100;	//enalbe interrupts on pin2
  
  Serial.begin(9600);	//enalbe Serial port
  turn_onLED();			//Initialise LED

}

void loop()
{
  	//print the motion sensor status to serial monitor
  	if (Mo_status)
  	{
  		Serial.println("Motion detected");
  	}
  	else
  	{
    	Serial.println("Motion not detected");
  	}
  
  	delay(1000);	//wait 1 sec
}

void turn_onLED()
{
	digitalWrite(4, led);	//turn on/off LED
  	digitalWrite(13, led); 	//turn on/off built-in LED
}


ISR(PCINT2_vect)
{
	led = PIND & 0b00000100;	//read the status of pin2
  	Mo_status = (0 != (PIND & 0b00000100));	//read the status of pin2 as bool
  	
  	turn_onLED();	//update the LEDs
}
  