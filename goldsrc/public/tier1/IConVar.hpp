/*
 * This file is part of OGS Engine SDK
 *
 * Copyright (C) 2015-2018, 2023 BlackPhrase
 *
 * OGS Engine SDK is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGS Engine SDK is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGS Engine SDK. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file
/// @brief console/config variable interface

#pragma once

#include <next/CommonTypes.hpp>

interface IConVarValueListener
{
	/// This method will be called when a certain cvar has its value changed
	/// @param asName A name of the cvar
	/// @param asOldValue The previous value of the cvar
	/// @param asNewValue This new value this cvar has
	virtual void OnValueChanged(const char *asName, const char *asOldValue, const char *asNewValue) = 0;
};

interface IConVar
{
	//virtual void Release() = 0;
	
	/// Resets the value to default
	virtual void Reset() = 0; // TODO: ResetValue? Revert?
	
	/**
	* Sets a listener to listen for value changes and react to them
	*
	* @param apListener A pointer to a listener interface implementation
	*/
	//virtual void SetChangeValueListener(IConVarValueListener *apListener) = 0;
	
	/// @return Name of the variable
	virtual const char *GetName() const = 0;
	
	/// @return The variable's description string
	virtual const char *GetDesc() const = 0;
	
	/// @return The default value of the variable
	virtual const char *GetDefValue() const = 0;
	
	/**
	* Set variable flags (override)
	*
	* @param anFlags - new flag bitsum that overrides the previous
	*/
	//virtual void SetFlags(int anFlags) = 0;
	
	/**
	* Add flags to current bitsum
	*
	* @param anFlags - flag bitsum to add
	*/
	//virtual void AddFlags(int anFlags) = 0;
	
	/**
	* Check if specified flags are present
	*
	* @param anFlags - flag bitsum that need to be present
	* @return true if specified bitsum is present
	*/
	virtual bool HasFlags(int anFlags) const = 0;
	
	/// @return Current flags bitsum
	//virtual int GetFlags() const = 0;
	
	/**
	* Set value to the specified string
	*
	* @param asValue A new string value to set
	*/
	virtual void SetString(const char *asValue) = 0;
	
	/**
	* Set value to the specified int
	*
	* @param anValue A new integer value to set
	*/
	virtual void SetInt(int anValue) = 0;
	
	/**
	* Set value to the specified float
	*
	* @param afValue A new float value to set
	*/
	virtual void SetFloat(float afValue) = 0;
	
	/**
	* Set value to the specified bool
	*
	* @param abValue A new boolean value to set
	*/
	virtual void SetBool(bool abValue) = 0;
	
	/// @return Current value as string
	virtual const char *GetString() const = 0; // TODO: make inline?
	
	/// @return Current value as int
	virtual int GetInt() const = 0; // TODO: make inline?
	
	/// @return Current value as float
	virtual float GetFloat() const = 0; // TODO: make inline?
	
	/// @return Current value as bool
	virtual bool GetBool() const = 0; // TODO: make inline?
};