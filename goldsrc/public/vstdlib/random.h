/*
 * This file is part of OGS Engine SDK
 * Copyright (C) 2024 BlackPhrase
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
/// @brief random number generator

#include "vstdlib.h"

#define NTAB 32

//#pragma warning(push)
//#pragma warning(disable:4251)

/// A generator of uniformly distributed random numbers
class IUniformRandomStream
{
public:
	/// Sets the seed of the random number generator
	virtual void SetSeed(int anSeed) = 0;
	
	/// Generates random numbers
	virtual float RandomFloat(float afMinValue = 0.0f, float afMaxValue = 1.0f) = 0;
	virtual int RandomInt(int anMinValue, int anMaxValue) = 0;
	//virtual float RandomFloatExp(float afMinValue = 0.0f, float afMaxValue = 1.0f, float afExponent = 1.0f) = 0;
};

/// The standard generator of uniformly distributed random numbers
class VSTDLIB_CLASS CUniformRandomStream : public IUniformRandomStream
{
public:
	CUniformRandomStream();
	
	/// Sets the seed of the random number generator
	virtual void SetSeed(int anSeed) override;
	
	/// Generates random numbers
	virtual float RandomFloat(float afMinValue = 0.0f, float afMaxValue = 1.0f) override;
	virtual int RandomInt(int anMinValue, int anMaxValue) override;
	//virtual float RandomFloatExp(float afMinValue = 0.0f, float afMaxValue = 1.0f, float afExponent = 1.0f) override; // TODO: not present in gs
private:
	int GenerateRandomNumber(); // TODO: make public?
private:
	CThreadFastMutex mMutex; // TODO: non-gs?
	
	int mnDum;
	int mnY;
	int mnV[NTAB]{};
};

/// A generator of gaussian distributed random numbers
class VSTDLIB_CLASS CGaussianRandomStream
{
public:
	/// Passing in nullptr cause the gaussian stream to use the
	/// preinstalled global random number generator
	CGaussianRandomStream(IUniformRandomStream *apUniformStream = nullptr);
	
	/// Attaches to a random uniform stream
	void AttachToStream(IUniformRandomStream *apUniformStream = nullptr);
	
	/// Generates random numbers
	float RandomFloat(float afMean = 0.0f, float afStdDev = 1.0f);
private:
	CThreadFastMutex mMutex; // TODO: non-gs?
	
	IUniformRandomStream *mpUniformStream{nullptr};
	
	float mfRandomValue{0.0f};
	
	bool mbHaveValue{false};
};

/// A couple of convenience functions to access the library's global uniform stream
VSTDLIB_INTERFACE void RandomSeed(int anSeed);
VSTDLIB_INTERFACE float RandomFloat(float afMinValue = 0.0f, float afMaxValue = 1.0f);
VSTDLIB_INTERFACE int RandomInt(int anMinValue, int anMaxValue);
VSTDLIB_INTERFACE float RandomGaussianFloat(float afMean = 0.0f, float afStdDev = 1.0f);

/// Installs a global random number generator, which will affect the Random* functions above
VSTDLIB_INTERFACE void InstallUniformRandomStream(IUniformRandomStream *apStream);

//#pragma warning(pop)