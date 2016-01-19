/**
 * @file SchedulerDemoNamespaces.ino
 * @version 1.0
 *
 * @section License
 * Copyright (C) Mikael Patel, 2015
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * @section Description
 * This Arduino sketch shows how to use the Scheduler library.
 * Rewrite of the SchedulerDemo sketch using namespaces for
 * each task.
 */

#include <Scheduler.h>

#include "Trace.h"
#include "BlinkTask.h"
#include "ShellTask.h"

void setup()
{
  Serial.begin(57600);
  Serial.println(F("SchedulerDemoNamespaces: started"));

  // Initiate tasks
  Scheduler.start(BlinkTask::setup, BlinkTask::loop);
  Scheduler.start(ShellTask::setup, ShellTask::loop);

  // Print stack size
  TRACE("stack=");
  Serial.println(Scheduler.stack());
}

void loop()
{
  // Main loop iteration count
  static int i = 0;

  // Print main loop iterations
  TRACE("i=");
  Serial.println(i++);
  delay(500);
}

