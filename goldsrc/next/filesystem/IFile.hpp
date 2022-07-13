/*
 * This file is part of OGSNext Engine
 *
 * Copyright (C) 2017-2022 BlackPhrase
 *
 * OGSNext Engine is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OGSNext Engine is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OGSNext Engine. If not, see <http://www.gnu.org/licenses/>.
*/

/// @file
/// @brief file handle wrapper interface

#pragma once

#include "CommonTypes.hpp"

interface IFile
{
	///
	//virtual bool Open(const char *asName, const char *asMode) = 0;
	
	///
	//virtual bool Reopen(const char *asName, const char *asMode) = 0;
	
	///
	//virtual void Close() = 0;
	
	///
	virtual bool IsOpen() const = 0;
	
	/// Write data from the buffer to the file
	virtual size_t Write(const void *apInput, size_t anCount) = 0; // TODO: const?
	
	/// Read data from the file to the buffer
	virtual size_t Read(void *apOutput, size_t anCount) const = 0;
	
	/// Reads a line into the specified buffer with the specified size
	///
	/// @param asOutput - mutable output buffer
	/// @param anMaxChars - output buffer size
	/// @return
	//virtual char *ReadLine(char *asOutput, int anMaxChars) const = 0;
	
	/// Like fprintf
	virtual int Printf(/*VERIFY_FORMAT_STRING*/ const char *asText, ...) = 0;
	
	enum class SeekMode : int
	{
		Set = 0, // TODO: Head?
		Current,
		End, // TODO: Tail?
	};
	
	/// Seek on a file
	virtual int Seek(long anOffset, SeekMode aeMode) const = 0;
	
	/// @return offset in file
	virtual long Tell() const = 0;
	
	/// Go back to the beginning of the file
	virtual void Rewind() = 0;
	
	/// Causes any buffered data to be written to the file
	/// @param abForce - Forces flush on files being writting to
	virtual void Flush(/*bool abForce*/) = 0;
	
	///
	virtual int SetVBuf(char *apBuffer, int anMode, size_t anSize) = 0;
	
	///
	virtual void *GetReadBuffer(int *apOutBufferSize, bool abFailIfNotInCache = false) const = 0;
	
	///
	virtual void ReleaseReadBuffer(void *apBuffer) = 0;
	
	///
	virtual bool IsOk() const = 0; // TODO: IsValid? IsOK?
	
	///
	virtual bool IsEOF() const = 0; // TODO: return uint?
	
	/// Get the full file path
	virtual const char *GetPath() const = 0; // TODO: GetFullPath?
	
	/// @return name of the file
	virtual const char *GetName() const = 0;
	
	/// @return extension of the file (if present)
	virtual const char *GetExt() const = 0;
	
	///
	//virtual int GetTime() const = 0;
	
	/// @return the length of the file
	virtual /*unsigned*/ int GetSize() const = 0; // TODO: int GetLength?
	
	/// Return a time value for reload operations
	//virtual ID_TIME_T GetTimeStamp() const = 0;
	
	///
	//virtual int PutChar(byte anChar) = 0; // TODO
	
	///
	virtual int GetChar() const = 0;
	
	///
	//virtual int PutStr(const char *asStr) = 0; // TODO
	
	///
	//virtual const char *GetStr() const = 0; // TODO
	
	///
	//virtual FileHandle_t GetHandle() const = 0;
	//operator bool(){return GetHandle() != nullptr;}
	operator bool() const {return IsOk();}
};