//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//

#pragma once

#if !defined(__UTILS_H__)
#define __UTILS_H__

// Library Includes
#include <Windows.h>
#include <strstream>
#include <sstream>
#include <string>


// Local Includes

// Types

// Constants

// Prototypes

#define VALIDATE(a) if (!a) return (false)

template<typename T>
std::string ToString(const T& _value)
{
	std::strstream theStream;
	theStream << _value << std::ends;
	return (theStream.str());
}

template<typename T>
std::wstring ToWideString(const T& _value)
{
	std::wstringstream theStream;
	theStream << _value << std::ends;
	return (theStream.str());
}

float ReadFromEditBox(HWND _hDlg, int _iResourceID)
{
	wchar_t _pcValue[10];
	ZeroMemory(_pcValue, 10);
	GetDlgItemText(_hDlg, _iResourceID, _pcValue, 10);
	if (_pcValue[0] == 0)
	{
		return 0.0f;
	}
	else
	{
		return static_cast<float>(_wtof(_pcValue));
	}
}

void WriteToEditBox(HWND _hDlg, int _iResourceID, float _fValue)
{
	std::wstring _strValue = ToWideString(_fValue);
	SetDlgItemText(_hDlg, _iResourceID, _strValue.c_str());
}

#endif    // __UTILS_H__


