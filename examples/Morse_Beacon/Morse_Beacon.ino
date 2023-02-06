/*
 * Morse_Beacon - CW beacon keyer for ham radio                             
 * 
 * Be sure to change the configuration in config.h!
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

#include "config.h"
#include <Telegraph.h>

Telegraph telegraph(PIN, SPEED, TX_ON);

void setup() {
}

void loop() {
  telegraph.on();
  delay(TEST_LENGTH);
  telegraph.off();
  delay(AFTER_TEST_PAUSE);
  telegraph.send(MESSAGE);
  delay(AFTER_ID);
}
