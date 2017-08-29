/*
 * When one col pin is HIGH, the corresponding row pin must be LOW, to turn ON the LED at (row/x,col/y) position.
 * to turn the LED at (row/x,col/y) position OFF, the col pin must be LOW, and the corresponding row pin must be HIGH. 
 * 
 * This is because the anode side of the LED must be given power, while the cathode side must be given ground, in order for current to flow and turn on the LED,
 * and the inverse so the LED turns off without distrupting the other LEDs in the grid
 */


int grid[3][5][5] = {
  {
    {1, 0, 0, 0, 1},
    {0, 1, 0, 1, 0},
    {0, 0, 1, 0, 0},
    {0, 1, 0, 1, 0},
    {1, 0, 0, 0, 1}
  },
  {
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 1, 0, 0},
    {0, 0, 1, 0, 0}
  },
  {
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1},
    {1,1,1,1,1}
  }

};

int row[5] = {3, 4, 5, 6, 7}, col[5] = {9, 10, 11, 12, 13};


void setup() {
  // put your setup code here, to run once:
  for (int thisPin = 0; thisPin < 5; thisPin++) {
    // initialize the output pins:
    pinMode(col[thisPin], OUTPUT);
    pinMode(row[thisPin], OUTPUT);
  }
}

void loop() {
  for (int fr = 0; fr < 2; fr++)
    for (int fr_delay = 0; fr_delay < 1000; fr_delay++)
      for (int x = 0; x < 5; x++)
        for (int y = 0; y < 5; y++)
          if (grid[fr][x][y] == 1) {
            // LED ON
            digitalWrite(row[x], LOW);
            digitalWrite(col[y], HIGH);
            // LED OFF
           // delay(180);
            digitalWrite(row[x], HIGH);
            digitalWrite(col[y], LOW);
          }


}
