/**
 * Licensed to Green Energy Corp (www.greenenergycorp.com) under one or
 * more contributor license agreements. See the NOTICE file distributed
 * with this work for additional information regarding copyright ownership.
 * Green Energy Corp licenses this file to you under the Apache License,
 * Version 2.0 (the "License"); you may not use this file except in
 * compliance with the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions andProcess
 * limitations under the License.
 *
 * This project was forked on 01/01/2013 by Automatak, LLC and modifications
 * may have been made to this file. Automatak, LLC licenses these modifications
 * to you under the terms of the License.
 */

#include "AuthRequestHandler.h"

#include <openpal/logging/LogMacros.h>
#include <opendnp3/LogLevels.h>

using namespace opendnp3;

namespace secauth
{


AuthRequestHandler::AuthRequestHandler(const openpal::ReadBufferView& fragment_, const APDUHeader& header_, OState& ostate, IAuthRequestHandler& handler) :
	logger(ostate.logger),
	fragment(fragment_),
	apduheader(header_),
	pOState(&ostate),
	pHandler(&handler)
{
	
}

bool AuthRequestHandler::IsAllowed(uint32_t count, GroupVariation gv, QualifierCode qc)
{
	// only 1 header allowed regardless of type
	if (count != 0)
	{
		return false;
	}

	// certain types allowed with certain qualifiers
	switch (gv)
	{
	case(GroupVariation::Group120Var4) :
		return qc == QualifierCode::UINT8_CNT;
	case(GroupVariation::Group120Var1) :
	case(GroupVariation::Group120Var2) :
	case(GroupVariation::Group120Var6) :
		return qc == QualifierCode::UINT16_FREE_FORMAT;
	default:
		return false;
	}	
}

IINField AuthRequestHandler::ProcessHeader(const opendnp3::FreeFormatHeader& header, const Group120Var1& value)
{
	pHandler->OnAuthChallenge(*pOState, fragment, apduheader, value);
	return IINField::Empty();
}

IINField AuthRequestHandler::ProcessHeader(const opendnp3::FreeFormatHeader& header, const Group120Var2& value)
{
	pHandler->OnAuthReply(*pOState, fragment, apduheader, value);
	return IINField::Empty();
}

IINField AuthRequestHandler::ProcessHeader(const opendnp3::FreeFormatHeader& header, const Group120Var6& value)
{
	pHandler->OnChangeSessionKeys(*pOState, fragment, apduheader, value);
	return IINField::Empty();
}

IINField AuthRequestHandler::ProcessHeader(const opendnp3::CountHeader& record, const ICollection<opendnp3::Group120Var4>& values)
{			
	Group120Var4 value;
	if (values.ReadOnlyValue(value))
	{
		pHandler->OnRequestKeyStatus(*pOState, fragment, apduheader, value);
		return IINField::Empty();
	}
	else
	{
		SIMPLE_LOG_BLOCK(pOState->logger, flags::WARN, "Unexpected count in key status request");
		return IINBit::PARAM_ERROR;
	}
}

}

