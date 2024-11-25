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

/***********************************************************************
 *   $Id: dmlpackageprocessorfactory.h 9210 2013-01-21 14:10:42Z rdempsey $
 *
 *
 ***********************************************************************/
/** @file */
#pragma once
#include <string>
#include "calpontdmlpackage.h"
#include "dmlpackageprocessor.h"

#define EXPORT

namespace dmlpackageprocessor
{
/** @brief create a DMLPackageProcessor object from a CalpontDMLPackage object
 *
 */
class DMLPackageProcessorFactory
{
 public:
  /** @brief static DMLPackageProcessor constructor method
   *
   * @param packageType the DML Package type
   * @param cpackage the CalpontDMLPackage from which the DMLPackageProcessor is constructed
   */
  EXPORT static DMLPackageProcessor* makePackageProcessor(int packageType,
                                                          dmlpackage::CalpontDMLPackage& cpackage);

 protected:
 private:
};

}  // namespace dmlpackageprocessor

#undef EXPORT
