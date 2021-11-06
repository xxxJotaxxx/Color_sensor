#include <Arduino.h>

#define s0 8 //Module pins wiring
#define s1 9
#define s2 10
#define s3 11
#define out 12
// LED pins connected to Arduino

int red = 0;
int green = 0;
int blue = 0;
int umbralColorMax = 120;

void setup()
{
    Serial.begin(9600);
    pinMode(s0, OUTPUT);
    pinMode(s1, OUTPUT);
    pinMode(s2, OUTPUT);
    pinMode(s3, OUTPUT);
    pinMode(out, INPUT);

    digitalWrite(s0, HIGH);
    digitalWrite(s1, HIGH);
}

void color()
{
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    //count OUT, pRed, RED
    red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
    digitalWrite(s3, HIGH);
    //count OUT, pBLUE, BLUE
    blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
    digitalWrite(s2, HIGH);
    //count OUT, pGreen, GREEN
    green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
}

//en valor mas bajo es el color que está leyendo
void colorPrint(int red, int green, int blue)
{
    if (red < blue && red < green && red < umbralColorMax)
    {
        Serial.println(" - (Red Color)");
    }

    else if (blue < red && blue < green && blue < umbralColorMax)
    {
        Serial.println(" - (Blue Color)");
    }

    else if (green < red && green < blue && green < umbralColorMax)
    {
        Serial.println(" - (Green Color)");
    }
    else
    {
        Serial.println("  - (None Color)");
    }
}

void loop()
{
    color();
    Serial.print("RED: ");
    Serial.print(red, DEC);
    Serial.print("    GREEN: ");
    Serial.print(green, DEC);
    Serial.print("    BLUE: ");
    Serial.print(blue, DEC);
    colorPrint(red,green,blue);
    delay(300);
}
