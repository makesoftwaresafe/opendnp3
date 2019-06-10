//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2013-2019 Automatak, LLC
// 
// Licensed to Green Energy Corp (www.greenenergycorp.com) and Automatak
// LLC (www.automatak.com) under one or more contributor license agreements.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership. Green Energy Corp and Automatak LLC license
// this file to you under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may obtain
// a copy of the License at:
// 
//   http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "opendnp3/gen/StaticFrozenCounterVariation.h"
#include <cstring>
#include <stdexcept>

namespace opendnp3 {

uint8_t StaticFrozenCounterVariationToType(StaticFrozenCounterVariation arg)
{
  return static_cast<uint8_t>(arg);
}
StaticFrozenCounterVariation StaticFrozenCounterVariationFromType(uint8_t arg)
{
  switch(arg)
  {
    case(0):
      return StaticFrozenCounterVariation::Group21Var1;
    case(1):
      return StaticFrozenCounterVariation::Group21Var2;
    case(2):
      return StaticFrozenCounterVariation::Group21Var5;
    case(3):
      return StaticFrozenCounterVariation::Group21Var6;
    case(4):
      return StaticFrozenCounterVariation::Group21Var9;
    case(5):
      return StaticFrozenCounterVariation::Group21Var10;
    default:
      throw new std::invalid_argument("Unknown value");
  }
}
char const* StaticFrozenCounterVariationToString(StaticFrozenCounterVariation arg)
{
  switch(arg)
  {
    case(StaticFrozenCounterVariation::Group21Var1):
      return "Group21Var1";
    case(StaticFrozenCounterVariation::Group21Var2):
      return "Group21Var2";
    case(StaticFrozenCounterVariation::Group21Var5):
      return "Group21Var5";
    case(StaticFrozenCounterVariation::Group21Var6):
      return "Group21Var6";
    case(StaticFrozenCounterVariation::Group21Var9):
      return "Group21Var9";
    case(StaticFrozenCounterVariation::Group21Var10):
      return "Group21Var10";
    default:
      return "UNDEFINED";
  }
}
StaticFrozenCounterVariation StaticFrozenCounterVariationFromString(char const* arg)
{
  if(std::strncmp(arg, "Group21Var1", 11)) return StaticFrozenCounterVariation::Group21Var1;
  if(std::strncmp(arg, "Group21Var2", 11)) return StaticFrozenCounterVariation::Group21Var2;
  if(std::strncmp(arg, "Group21Var5", 11)) return StaticFrozenCounterVariation::Group21Var5;
  if(std::strncmp(arg, "Group21Var6", 11)) return StaticFrozenCounterVariation::Group21Var6;
  if(std::strncmp(arg, "Group21Var9", 11)) return StaticFrozenCounterVariation::Group21Var9;
  if(std::strncmp(arg, "Group21Var10", 12)) return StaticFrozenCounterVariation::Group21Var10;
  else throw new std::invalid_argument(std::string("Unknown value: ") + arg);
}

}
