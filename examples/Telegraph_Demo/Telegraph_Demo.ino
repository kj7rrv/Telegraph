/*
 * Telegraph_Demo - demonstration of Telegraph library
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

#include <Telegraph.h>

Telegraph telegraph(LED_BUILTIN, 5, HIGH);

void setup() {
}

void loop() {
  for (int i = 1; i <= 5; i++) {
    telegraph.on();
    delay(500);
    telegraph.off();
    delay(500);
  }

  delay(1500);

  telegraph.send("CQ CQ CQ");
  
  telegraph.wpm += 5;
  if (telegraph.wpm > 50) {
    telegraph.wpm = 5;
  }
  
  delay(2000);
}
