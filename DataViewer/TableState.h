/**
 * GeoDa TM, Copyright (C) 2011-2013 by Luc Anselin - all rights reserved
 *
 * This file is part of GeoDa.
 * 
 * GeoDa is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * GeoDa is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GEODA_CENTER_TABLE_STATE_H__
#define __GEODA_CENTER_TABLE_STATE_H__

#include <list>

class TableStateObserver; // forward declaration

class TableState {
public:
	TableState();
	virtual ~TableState();
	
	/** Signal that TableState should be closed, but wait until
	 all observers have deregistered themselves. */
	void closeAndDeleteWhenEmpty();
	
	virtual void registerObserver(TableStateObserver* o);
	virtual void removeObserver(TableStateObserver* o);
	virtual void notifyObservers();
	
private:
	/** The list of registered TableStateObserver objects. */
	std::list<TableStateObserver*> observers;
	/** When the project is being closed, this is set to true so that
	 when the list of observers is empty, the TableState instance
	 will automatically delete itself. */
	bool delete_self_when_empty;
};

#endif
