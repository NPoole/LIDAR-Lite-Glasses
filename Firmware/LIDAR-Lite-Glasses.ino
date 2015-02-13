/*

LIDAR-Lite Obstacle Avoidance Glasses
Nick Poole @ SparkFun Electronics
Based on original demo code from PulsedLight3D for "continuous PWM" operation of LIDAR-Lite

http://pulsedlight3d.com
http://pulsedlight3d.com/pl3d/wp-content/uploads/2014/11/LIDAR-Lite-Operating-Manual.pdf

You can see this project in action at: http://youtu.be/Qt29I6pTHzE

*/

unsigned long pulse_width;


void setup()
{
  
  pinMode( 2, OUTPUT ); // Set pin 2 as trigger pin
  digitalWrite( 2, LOW ); // Set trigger LOW for continuous read
  pinMode( 3, INPUT ); // Set pin 3 as monitor pin

  pinMode( 9, OUTPUT ); // Vibe motor output

  pinMode( 5, OUTPUT ); // Using this pin as the buzzer ground
  digitalWrite( 5, LOW ); // Using this pin as the buzzer ground
  
}

void loop()
{

  pulse_width = pulseIn ( 3, HIGH ); // Count how long the pulse is high in microseconds

  if ( pulse_width != 0 ) { 

        pulse_width = pulse_width / 10; // 10usec = 1 cm of distance for LIDAR-Lite

    if ( pulse_width < 80 ) { digitalWrite( 9, HIGH ); // Signal the user w/ vibe motor
  
    } else { digitalWrite( 9, LOW ); }

  tone( 8, map( pulse_width, 0, 500, 1000, 0 ), 10 ); // Generate Proximity Tone

  }

  delay(20);

}
