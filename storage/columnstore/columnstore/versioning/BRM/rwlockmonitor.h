/* Copyright (C) 2014 InfiniDB, Inc.

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; version 2 of
   the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
   MA 02110-1301, USA. */

/*
 * rwlockmonitor.h
 *
 *  Created on: Aug 15, 2011
 *      Author: pleblanc
 */

#pragma once

#include <unistd.h>
#include <boost/scoped_ptr.hpp>

#include "rwlock.h"
#include <atomic>

#define EXPORT

namespace BRM
{
class RWLockMonitor
{
 public:
  // d = die, ls = lock status, k = key
  EXPORT RWLockMonitor(const std::atomic<bool>* d, const std::atomic<bool>* ls, const uint32_t k);

  EXPORT virtual ~RWLockMonitor();

  EXPORT void operator()();

 private:
  // Are these defaults okay?
  // RWLockMonitor(const RWLockMonitor&rhs);
  // RWLockMonitor& operator=(const RWLockMonitor&rhs);

  /* Some of these vars are only useful once we implement write_lock checking. */
  const std::atomic<bool>* die;
  const std::atomic<bool>* lockStatus;
  uint32_t key;
  boost::shared_ptr<rwlock::RWLock> lock;

  struct timespec ts;            // 3:30 timer
  uint32_t secsBetweenAttempts;  // :30
};

} /* namespace BRM */

#undef EXPORT
