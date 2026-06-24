const int tempPin = A0;

const int motorEnable = 9;

const int motorIn1 = 2;

const int motorIn2 = 3;

const int greenLED = 8;

void setup()

{

  Serial.begin(9600);

  pinMode(motorEnable, OUTPUT);

  pinMode(motorIn1, OUTPUT);

  pinMode(motorIn2, OUTPUT);

  pinMode(greenLED, OUTPUT);

}

void loop()

{

  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);

  float celsius = (voltage - 0.5) * 100.0;

  Serial.print("Temperature: ");

  Serial.print(celsius);

  Serial.println(" C");

  digitalWrite(greenLED, HIGH);

  if (celsius < 25)

  {

    analogWrite(motorEnable, 0);

  }

  else if (celsius >= 25 && celsius <= 35)

  {

    int speed = map((int)celsius, 25, 35, 100, 255);

    digitalWrite(motorIn1, HIGH);

    digitalWrite(motorIn2, LOW);

    analogWrite(motorEnable, speed);

  }

  else

  {

    digitalWrite(motorIn1, HIGH);

    digitalWrite(motorIn2, LOW);

    analogWrite(motorEnable, 255);

  }

  delay(500);

}
