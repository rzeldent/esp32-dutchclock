#include <Arduino.h>


void setup()
{
}

void loop()
{
  // put your main code here, to run repeatedly:
}

String number[] = {
    ""
    "Een",
    "Twee",
    "Drie",
    "Vier",
    "Vijf",
    "Zes",
    "Zeven",
    "Acht",
    "Negen",
    "Tien",
    "Elf",
    "Twaalf"
    "Dertien",
    "Veertien",
    "Kwart"};

String ampm[] = {
    "'s morgens",
    "'s middags"};

String DutchTime(byte hour, byte minute)
{
  if (minute == 0)
    return number[hour % 12] + " uur " + ampm[hour / 12];

  if (minute <= 15)
    return number[minute] + " over " + number[hour % 12] + ampm[hour / 12];

  if (minute <= 29)
    return number[minute] + " voor half " + number[(hour + 1) % 12] + ampm[hour / 12];

  if (minute == 30)
    return "half " + number[(hour + 1) % 12] + ampm[hour / 12];

  if (minute <= 44)
    return number[minute - 30] + " over half " + number[(hour + 1) % 12] + ampm[hour / 12];

  return number[60 - minute] + " voor " + number[(hour + 1) % 12] + ampm[hour / 12];
}