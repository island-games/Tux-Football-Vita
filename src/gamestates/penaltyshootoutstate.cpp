/***************************************************************************
 *   Copyright (C) 2003-2011 by Tux Football development team              *
 *   Authors: Jason Wood <jasonwood@blueyonder.co.uk>                      *
 *            Christoph Brill <egore911@egore911.de>                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
	
#include "penaltyshootoutstate.h"

#include "../gameengine.h"

#include "../logger/logger.h"

PenaltyShootoutState::PenaltyShootoutState(GameEngine &engine) :
				m_engine(engine)
{
}

PenaltyShootoutState::~PenaltyShootoutState()
{
}

void PenaltyShootoutState::enterState()
{
	// TODO this is just a shortcut for now
	WARN("Penalty shootout not implemented")
	m_engine.setState(GameEngine::Finished);
}

void PenaltyShootoutState::leaveState()
{
}

void PenaltyShootoutState::updateLoop()
{
}

bool PenaltyShootoutState::isGameInProgress() const
{
	return false;
}

void PenaltyShootoutState::renderFrame()
{
}
