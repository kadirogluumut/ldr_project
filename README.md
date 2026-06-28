# LDR Photo Light Arduino Project

An Arduino project that uses an LDR light sensor to control one LED.  
When there is no shadow and the LDR receives light, the LED turns on.  
When a shadow covers the LDR, the LED turns off.

## Circuit Diagram

![LDR Photo Light Arduino Diagram](ldr_led_diagram.svg)

## Required Components

| Component | Quantity |
|---|---:|
| Arduino Uno or Arduino Nano | 1 |
| LDR light sensor | 1 |
| LED | 1 |
| 220 ohm resistor | 1 |
| Jumper wires | As needed |
| Breadboard | 1 |
| 10K resistor | 1 recommended |

## Project Behavior

| Light Condition | LDR State | LED State |
|---|---|---|
| No shadow / bright light | Receives more light | ON |
| Shadow / low light | Receives less light | OFF |

## How It Works

The LDR changes its resistance depending on the amount of light it receives.  
The Arduino reads this value from analog pin `A0`.

If the light value is above the threshold, the Arduino turns the LED on.  
If the light value is below the threshold, the Arduino turns the LED off.

## Wiring

### LDR Sensor

| LDR Circuit Part | Arduino Pin |
|---|---|
| One LDR leg | 5V |
| Other LDR leg | A0 |
| 10K resistor | A0 to GND |

### LED

| LED Part | Arduino Pin |
|---|---|
| LED long leg, anode (+) | D9 |
| LED short leg, cathode (-) | 220 ohm resistor to GND |

## Arduino Code

```cpp
const int ldrPin = A0;
const int ledPin = 9;

int lightValue = 0;
int threshold = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  lightValue = analogRead(ldrPin);

  Serial.print("LDR Value: ");
  Serial.println(lightValue);

  if (lightValue > threshold) {
    digitalWrite(ledPin, HIGH);  // No shadow: LED ON
  } else {
    digitalWrite(ledPin, LOW);   // Shadow: LED OFF
  }

  delay(100);
}
```

## Calibration

The `threshold` value may need to be changed depending on your room light.

1. Upload the code to the Arduino.
2. Open the Serial Monitor.
3. Check the LDR values with and without shadow.
4. Change the `threshold` value if needed.

Example:

```cpp
int threshold = 500;
```

If the LED turns on and off at the wrong time, try a different value such as `400`, `600`, or `700`.

## Important Note

The 220 ohm resistor is used to protect the LED.  
For the LDR sensor, a 10K resistor is recommended to create a voltage divider so the Arduino can read stable analog values.

## License

This project is free to use for learning and educational purposes.
