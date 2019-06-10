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

#include "opendnp3/gen/ServerAcceptMode.h"
#include <cstring>
#include <stdexcept>

namespace opendnp3 {

uint8_t ServerAcceptModeToType(ServerAcceptMode arg)
{
  return static_cast<uint8_t>(arg);
}
ServerAcceptMode ServerAcceptModeFromType(uint8_t arg)
{
  switch(arg)
  {
    case(0):
      return ServerAcceptMode::CloseNew;
    case(1):
      return ServerAcceptMode::CloseExisting;
    default:
      throw new std::invalid_argument("Unknown value");
  }
}
char const* ServerAcceptModeToString(ServerAcceptMode arg)
{
  switch(arg)
  {
    case(ServerAcceptMode::CloseNew):
      return "CloseNew";
    case(ServerAcceptMode::CloseExisting):
      return "CloseExisting";
    default:
      return "UNDEFINED";
  }
}
ServerAcceptMode ServerAcceptModeFromString(char const* arg)
{
  if(std::strncmp(arg, "CloseNew", 8)) return ServerAcceptMode::CloseNew;
  if(std::strncmp(arg, "CloseExisting", 13)) return ServerAcceptMode::CloseExisting;
  else throw new std::invalid_argument(std::string("Unknown value: ") + arg);
}

}
