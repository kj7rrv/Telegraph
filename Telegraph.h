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

#ifndef Telegraph_h
#define Telegraph_h

#include "Arduino.h"

class Telegraph {
  public:
    Telegraph(int pin, int speed, int activeValue);
    void on();
    void off();
    void send(String text);
    int wpm;
  private:
    int _pin;
    int _activeValue;
    int _inactiveValue;
    void _sendLetter(char letter, bool last);
    String _lookUpLetter(char letter);
};

#endif
