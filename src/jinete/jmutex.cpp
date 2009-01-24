/* Jinete - a GUI library
 * Copyright (C) 2003-2009 David Capello.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of the author nor the names of its contributors may
 *     be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <allegro.h>
#include <assert.h>

#include "jinete/jmutex.h"

JMutex jmutex_new()
{
  assert(system_driver != NULL);
  assert(system_driver->create_mutex != NULL);

  return (JMutex)system_driver->create_mutex();
}

void jmutex_free(JMutex mutex)
{
  assert(system_driver != NULL);
  assert(system_driver->destroy_mutex != NULL);

  system_driver->destroy_mutex(mutex);
}

void jmutex_lock(JMutex mutex)
{
  assert(system_driver != NULL);
  assert(system_driver->lock_mutex != NULL);

  system_driver->lock_mutex(mutex);
}

void jmutex_unlock(JMutex mutex)
{
  assert(system_driver != NULL);
  assert(system_driver->unlock_mutex != NULL);

  system_driver->unlock_mutex(mutex);
}
