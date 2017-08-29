/*
 * Provide HIGH to row pin, and LOW to column pin to turn on led. Reverse to turn off. 
 *
 * 1k resistors attached to each row pin.
 *
 * Refer to datasheet and pin diagram.
 *
 */

int rowPin[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int colPin[8] = {9, 10, 11, 12, 13, 14, 15, 16};

int timeDel = 200;

int grid1[8][8] = {
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 1, 1, 1, 1},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
};

int grid2[8][8] = {
  {1, 1, 0, 0, 0, 0, 1, 1},
  {1, 1, 1, 0, 0, 1, 1, 1},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {1, 1, 1, 0, 0, 1, 1, 1},
  {1, 1, 0, 0, 0, 0, 1, 1},
};

void led(int posx, int posy, int delayTime = timeDel) {
  digitalWrite(rowPin[posx], HIGH);
  digitalWrite(colPin[posy], LOW);
  delayMicroseconds(delayTime);
  digitalWrite(rowPin[posx], LOW);
  digitalWrite(colPin[posy], HIGH);
}

void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i < 8; i++) {
    pinMode(rowPin[i], OUTPUT);
    pinMode(colPin[i], OUTPUT);
    //led(i, i);
    //led(i, 8 - i);
    //    led(8 - i, 8 - i);
    //    led(8 - i, i);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

for (int a=0;a<100;a++)
  for (int j = 0; j < 8; j++)
    for (int k = 0; k < 8; k++)
    {
      if (grid1[j][k])
        led(j, k);

      //led(j, k);
      //led(k, j);
    }

for (int a=0;a<100;a++)    
  for (int j = 0; j < 8; j++)
    for (int k = 0; k < 8; k++)
    {
      if (grid2[j][k])
        led(j, k);

      //led(j, k);
      //led(k, j);
    }


}
