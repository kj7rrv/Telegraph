/*
 * Telegraph - Arduino library for sending Morse code
 * 
 * Copyright (C) 2023 Samuel Sloniker KJ7RRV
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.                  
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.                                
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <https://www.gnu.org/licenses/>.      
 */

#include "Arduino.h"
#include "Telegraph.h"

Telegraph::Telegraph(int pin, int speed, int activeValue) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  _activeValue = activeValue;
  _inactiveValue = (activeValue == HIGH)?LOW:HIGH;
  digitalWrite(_pin, _inactiveValue);
  wpm = speed;
}

void Telegraph::on() {
  digitalWrite(_pin, _activeValue);
}

void Telegraph::off() {
  digitalWrite(_pin, _inactiveValue);
}

String Telegraph::_lookUpLetter(char letter) {
  switch(toupper(letter)) {
    case 'A' :
      return ".-";
    case 'B' :
      return "-...";
    case 'C' :
      return "-.-.";
    case 'D' :
      return "-..";
    case 'E' :
      return ".";
    case 'F' :
      return "..-.";
    case 'G' :
      return "--.";
    case 'H' :
      return "....";
    case 'I' :
      return "..";
    case 'J' :
      return ".---";
    case 'K' :
      return "-.-";
    case 'L' :
      return ".-..";
    case 'M' :
      return "--";
    case 'N' :
      return "-.";
    case 'O' :
      return "---";
    case 'P' :
      return ".--.";
    case 'Q' :
      return "--.-";
    case 'R' :
      return ".-.";
    case 'S' :
      return "...";
    case 'T' :
      return "-";
    case 'U' :
      return "..-";
    case 'V' :
      return "...-";
    case 'W' :
      return ".--";
    case 'X' :
      return "-..-";
    case 'Y' :
      return "-.--";
    case 'Z' :
      return "--..";
    case '1' :
      return ".----";
    case '2' :
      return "..---";
    case '3' :
      return "...--";
    case '4' :
      return "....-";
    case '5' :
      return ".....";
    case '6' :
      return "-....";
    case '7' :
      return "--...";
    case '8' :
      return "---..";
    case '9' :
      return "----.";
    case '0' :
      return "-----";
    case '.' :
      return ".-.-.-";
    case ',' :
      return "--..--";
    case '?' :
      return "..--..";
    case '\'' :
      return ".----.";
    case '!' :
      return "-.-.--";
    case '/' :
      return "-..-.";
    case '(' :
      return "-.--.";
    case ')' :
      return "-.--.-";
    case '&' :
      return ".-...";
    case ':' :
      return "---...";
    case ';' :
      return "-.-.-.";
    case '=' :
      return "-...-";
    case '+' :
      return ".-.-.";
    case '-' :
      return "-....-";
    case '_' :
      return "..--.-";
    case '"' :
      return ".-..-.";
    case '$' :
      return "...-..-";
    case '@' :
      return ".--.-.";
    default:
      return "";
  }
}

void Telegraph::_sendLetter(char letter, bool last) {
  int ditLength = 1200 / wpm;

  if (letter == ' ') {
    delay(ditLength * 4);
  } else {
    String symbols = _lookUpLetter(letter);
    for(int i = 0; i < symbols.length(); ++i) {
      on();
      delay(ditLength * ((symbols[i] == '-')?3:1));
      off();
      if (i != symbols.length()-1) {
        delay(ditLength);
      }
    }
    if (! last) {
      delay(ditLength * 3);
    }
  }
}

void Telegraph::send(String text) {
  for(int i = 0; i < text.length(); ++i) {
    _sendLetter(text[i], i == text.length()-1);
  }
}
