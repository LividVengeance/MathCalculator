//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2018 Media Design School
//
// File Name	: main.cpp
// Description	: Main file of calculator
// Author		: Andrew Barnes
// Mail			: andrew.bar8456@mediadesign.school.nz
//


#define WIN32_LEAN_AND_MEAN

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.
#include <math.h>
#include <time.h>

#include "utils.h"
#include "resource.h"

#define WINDOW_CLASS_NAME L"WINCLASS1"

HMENU g_hMenu;
HWND g_hDlgMatrix, g_hDlgTransformation, g_hDlgGaussian, g_hDlgQuaternion, g_hDlgSLERP;

void GameLoop()
{
	//One frame of game logic occurs here...
}

LRESULT CALLBACK WindowProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	// This is the main message handler of the system.
	PAINTSTRUCT ps; // Used in WM_PAINT.
	HDC hdc;        // Handle to a device context.

					// What is the message?
	switch (_msg)
	{
	case WM_CREATE:
	{
		// Do initialization stuff here.

		// Return Success.
		return (0);
	}
	break;

	case WM_PAINT:
	{
		// Simply validate the window.
		hdc = BeginPaint(_hwnd, &ps);

		// You would do all your painting here...

		EndPaint(_hwnd, &ps);

		// Return Success.
		return (0);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		case ID_EXIT:
		{
			PostQuitMessage(0);
			break;
		}
		case ID_CALCULATOR_MATRIX:
		{
			ShowWindow(g_hDlgMatrix, SW_SHOWNORMAL);
			break;
		}
		case ID_CALCULATOR_TRANSFORMATION:
		{
			ShowWindow(g_hDlgTransformation, SW_SHOWNORMAL);
			break;

		}
		//open the matrix dialog
		case ID_CALCULATOR_GAUSSIAN:
		{
			ShowWindow(g_hDlgGaussian, SW_SHOWNORMAL);
			break;
		}
		//open the gaussian dialog
		case ID_CALCULATOR_QUATERNION:
		{
			ShowWindow(g_hDlgQuaternion, SW_SHOWNORMAL);
			break;
		}
		//open the quaternion dialog
		case ID_CALCULATOR_SLERP:
		{
			ShowWindow(g_hDlgSLERP, SW_SHOWNORMAL);
			break;
		}
		default:
			break;
		}
		return(0);
	}
	break;

	case WM_DESTROY:
	{
		// Kill the application, this sends a WM_QUIT message.
		PostQuitMessage(0);

		// Return success.
		return (0);
	}
	break;

	default:break;
	} // End switch.

	  // Process any messages that we did not take care of...

	return (DefWindowProc(_hwnd, _msg, _wparam, _lparam));
}


BOOL CALLBACK MatrixDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{
	static float _value;
	switch (_msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
			//
			// Matrix A Buttons
			//
		case IDOK4: // Set A to I
		{
			WriteToEditBox(_hwnd, IDC_EDIT_A11, 1);
			WriteToEditBox(_hwnd, IDC_EDIT_A12, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_A13, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_A14, 0);

			WriteToEditBox(_hwnd, IDC_EDIT_A21, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_A22, 1);
			WriteToEditBox(_hwnd, IDC_EDIT_A23, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_A24, 0);

			WriteToEditBox(_hwnd, IDC_EDIT_A31, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_A32, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_A33, 1);
			WriteToEditBox(_hwnd, IDC_EDIT_A34, 0);

			WriteToEditBox(_hwnd, IDC_EDIT_A41, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_A42, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_A43, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_A44, 1);
			break;
		}
		case IDOK3: // | A |
		{
			break;
		}
		case IDOK9: // A Transpose
		{
			float A11 = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
			float A12 = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
			float tempA12 = A12;
			float A13 = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
			float tempA13 = A13;
			float A14 = ReadFromEditBox(_hwnd, IDC_EDIT_A14);
			float tempA14 = A14;

			float A21 = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
			float tempA21 = A21;
			float A22 = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
			float A23 = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
			float tempA23 = A23;
			float A24 = ReadFromEditBox(_hwnd, IDC_EDIT_A24);
			float tempA24 = A24;

			float A31 = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			float tempA31 = A31;
			float A32 = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
			float tempA32 = A32;
			float A33 = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
			float A34 = ReadFromEditBox(_hwnd, IDC_EDIT_A34);
			float tempA34 = A34;

			float A41 = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
			float tempA41 = A41;
			float A42 = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
			float tempA42 = A42;
			float A43 = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
			float tempA43 = A43;
			float A44 = ReadFromEditBox(_hwnd, IDC_EDIT_B44);


			WriteToEditBox(_hwnd, IDC_EDIT_R11, A11);
			WriteToEditBox(_hwnd, IDC_EDIT_R12, tempA21);
			WriteToEditBox(_hwnd, IDC_EDIT_R13, tempA31);
			WriteToEditBox(_hwnd, IDC_EDIT_R14, tempA41);

			WriteToEditBox(_hwnd, IDC_EDIT_R21, tempA12);
			WriteToEditBox(_hwnd, IDC_EDIT_R22, A22);
			WriteToEditBox(_hwnd, IDC_EDIT_R23, tempA32);
			WriteToEditBox(_hwnd, IDC_EDIT_R24, tempA42);

			WriteToEditBox(_hwnd, IDC_EDIT_R31, tempA12);
			WriteToEditBox(_hwnd, IDC_EDIT_R32, tempA23);
			WriteToEditBox(_hwnd, IDC_EDIT_R33, A33);
			WriteToEditBox(_hwnd, IDC_EDIT_R34, tempA43);

			WriteToEditBox(_hwnd, IDC_EDIT_R41, tempA14);
			WriteToEditBox(_hwnd, IDC_EDIT_R42, tempA24);
			WriteToEditBox(_hwnd, IDC_EDIT_R43, tempA34);
			WriteToEditBox(_hwnd, IDC_EDIT_R44, A44);

			break;
		}
		case IDCANCEL2: // A Inverse
		{
			break;
		}
		case IDOK6: // Multiply A by _
		{
			float aScaled = ReadFromEditBox(_hwnd, IDC_EDIT_AScaled);

			float A11 = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
			WriteToEditBox(_hwnd, IDC_EDIT_R11, A11 * aScaled);
			float A12 = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
			WriteToEditBox(_hwnd, IDC_EDIT_R12, A12 * aScaled);
			float A13 = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
			WriteToEditBox(_hwnd, IDC_EDIT_R13, A13 * aScaled);
			float A14 = ReadFromEditBox(_hwnd, IDC_EDIT_A14);
			WriteToEditBox(_hwnd, IDC_EDIT_R14, A14 * aScaled);

			float A21 = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
			WriteToEditBox(_hwnd, IDC_EDIT_R21, A21 * aScaled);
			float A22 = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
			WriteToEditBox(_hwnd, IDC_EDIT_R22, A22 * aScaled);
			float A23 = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
			WriteToEditBox(_hwnd, IDC_EDIT_R23, A23 * aScaled);
			float A24 = ReadFromEditBox(_hwnd, IDC_EDIT_A24);
			WriteToEditBox(_hwnd, IDC_EDIT_R24, A24 * aScaled);

			float A31 = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			WriteToEditBox(_hwnd, IDC_EDIT_R31, A31 * aScaled);
			float A32 = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			WriteToEditBox(_hwnd, IDC_EDIT_R32, A32 * aScaled);
			float A33 = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
			WriteToEditBox(_hwnd, IDC_EDIT_R33, A33 * aScaled);
			float A34 = ReadFromEditBox(_hwnd, IDC_EDIT_A34);
			WriteToEditBox(_hwnd, IDC_EDIT_R34, A34 * aScaled);

			float A41 = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
			WriteToEditBox(_hwnd, IDC_EDIT_R41, A41 * aScaled);
			float A42 = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
			WriteToEditBox(_hwnd, IDC_EDIT_R42, A42 * aScaled);
			float A43 = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
			WriteToEditBox(_hwnd, IDC_EDIT_R43, A43 * aScaled);
			float A44 = ReadFromEditBox(_hwnd, IDC_EDIT_A44);
			WriteToEditBox(_hwnd, IDC_EDIT_R44, A44 * aScaled);
			break;
		}
		//
		// Matrix B
		//
		case IDOK8: // Set B to I
		{
			WriteToEditBox(_hwnd, IDC_EDIT_B11, 1);
			WriteToEditBox(_hwnd, IDC_EDIT_B12, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_B13, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_B14, 0);

			WriteToEditBox(_hwnd, IDC_EDIT_B21, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_B22, 1);
			WriteToEditBox(_hwnd, IDC_EDIT_B23, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_B24, 0);

			WriteToEditBox(_hwnd, IDC_EDIT_B31, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_B32, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_B33, 1);
			WriteToEditBox(_hwnd, IDC_EDIT_B34, 0);

			WriteToEditBox(_hwnd, IDC_EDIT_B41, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_B42, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_B43, 0);
			WriteToEditBox(_hwnd, IDC_EDIT_B44, 1);
			break;
		}
		case IDOK7: // | B |
		{
			break;
		}
		case IDOK11: // B Transpose
		{
			float B11 = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
			float B12 = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
			float tempB12 = B12;
			float B13 = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
			float tempB13 = B13;
			float B14 = ReadFromEditBox(_hwnd, IDC_EDIT_B14);
			float tempB14 = B14;

			float B21 = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
			float tempB21 = B21;
			float B22 = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
			float B23 = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
			float tempB23 = B23;
			float B24 = ReadFromEditBox(_hwnd, IDC_EDIT_B24);
			float tempB24 = B24;

			float B31 = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
			float tempB31 = B31;
			float B32 = ReadFromEditBox(_hwnd, IDC_EDIT_B32);
			float tempB32 = B32;
			float B33 = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
			float B34 = ReadFromEditBox(_hwnd, IDC_EDIT_B34);
			float tempB34 = B34;

			float B41 = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
			float tempB41 = B41;
			float B42 = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
			float tempB42 = B42;
			float B43 = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
			float tempB43 = B43;
			float B44 = ReadFromEditBox(_hwnd, IDC_EDIT_B44);


			WriteToEditBox(_hwnd, IDC_EDIT_R11, B11);
			WriteToEditBox(_hwnd, IDC_EDIT_R12, tempB21);
			WriteToEditBox(_hwnd, IDC_EDIT_R13, tempB31);
			WriteToEditBox(_hwnd, IDC_EDIT_R14, tempB41);

			WriteToEditBox(_hwnd, IDC_EDIT_R21, tempB12);
			WriteToEditBox(_hwnd, IDC_EDIT_R22, B22);
			WriteToEditBox(_hwnd, IDC_EDIT_R23, tempB32);
			WriteToEditBox(_hwnd, IDC_EDIT_R24, tempB42);

			WriteToEditBox(_hwnd, IDC_EDIT_R31, tempB12);
			WriteToEditBox(_hwnd, IDC_EDIT_R32, tempB23);
			WriteToEditBox(_hwnd, IDC_EDIT_R33, B33);
			WriteToEditBox(_hwnd, IDC_EDIT_R34, tempB43);

			WriteToEditBox(_hwnd, IDC_EDIT_R41, tempB14);
			WriteToEditBox(_hwnd, IDC_EDIT_R42, tempB24);
			WriteToEditBox(_hwnd, IDC_EDIT_R43, tempB34);
			WriteToEditBox(_hwnd, IDC_EDIT_R44, B44);

			break;
		}
		case IDCANCEL3: // B Inverse
		{
			break;
		}
		case IDOK10: // Multiply B _
		{
			float bScaled = ReadFromEditBox(_hwnd, IDC_EDIT_BScaled);

			float B11 = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
			WriteToEditBox(_hwnd, IDC_EDIT_R11, B11 * bScaled);
			float B12 = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
			WriteToEditBox(_hwnd, IDC_EDIT_R12, B12 * bScaled);
			float B13 = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
			WriteToEditBox(_hwnd, IDC_EDIT_R13, B13 * bScaled);
			float B14 = ReadFromEditBox(_hwnd, IDC_EDIT_B14);
			WriteToEditBox(_hwnd, IDC_EDIT_R14, B14 * bScaled);

			float B21 = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
			WriteToEditBox(_hwnd, IDC_EDIT_R21, B21 * bScaled);
			float B22 = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
			WriteToEditBox(_hwnd, IDC_EDIT_R22, B22 * bScaled);
			float B23 = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
			WriteToEditBox(_hwnd, IDC_EDIT_R23, B23 * bScaled);
			float B24 = ReadFromEditBox(_hwnd, IDC_EDIT_B24);
			WriteToEditBox(_hwnd, IDC_EDIT_R24, B24 * bScaled);

			float B31 = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
			WriteToEditBox(_hwnd, IDC_EDIT_R31, B31 * bScaled);
			float B32 = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
			WriteToEditBox(_hwnd, IDC_EDIT_R32, B32 * bScaled);
			float B33 = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
			WriteToEditBox(_hwnd, IDC_EDIT_R33, B33 * bScaled);
			float B34 = ReadFromEditBox(_hwnd, IDC_EDIT_B34);
			WriteToEditBox(_hwnd, IDC_EDIT_R34, B34 * bScaled);

			float B41 = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
			WriteToEditBox(_hwnd, IDC_EDIT_R41, B41 * bScaled);
			float B42 = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
			WriteToEditBox(_hwnd, IDC_EDIT_R42, B42 * bScaled);
			float B43 = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
			WriteToEditBox(_hwnd, IDC_EDIT_R43, B43 * bScaled);
			float B44 = ReadFromEditBox(_hwnd, IDC_EDIT_B44);
			WriteToEditBox(_hwnd, IDC_EDIT_R44, B44 * bScaled);
			break;
		}
		// -----------------------------------
		// -------- Resultant Matrix ---------
		// -----------------------------------
		case IDOK: // A + B
		{
			float A11 = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
			float A12 = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
			float A13 = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
			float A14 = ReadFromEditBox(_hwnd, IDC_EDIT_A14);

			float B11 = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
			float B12 = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
			float B13 = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
			float B14 = ReadFromEditBox(_hwnd, IDC_EDIT_B14);

			WriteToEditBox(_hwnd, IDC_EDIT_R11, A11 + B11);
			WriteToEditBox(_hwnd, IDC_EDIT_R12, A12 + B12);
			WriteToEditBox(_hwnd, IDC_EDIT_R13, A13 + B13);
			WriteToEditBox(_hwnd, IDC_EDIT_R14, A14 + B14);


			float A21 = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
			float A22 = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
			float A23 = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
			float A24 = ReadFromEditBox(_hwnd, IDC_EDIT_A24);

			float B21 = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
			float B22 = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
			float B23 = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
			float B24 = ReadFromEditBox(_hwnd, IDC_EDIT_B24);

			WriteToEditBox(_hwnd, IDC_EDIT_R21, A21 + B21);
			WriteToEditBox(_hwnd, IDC_EDIT_R22, A22 + B22);
			WriteToEditBox(_hwnd, IDC_EDIT_R23, A23 + B23);
			WriteToEditBox(_hwnd, IDC_EDIT_R24, A24 + B24);


			float A31 = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			float A32 = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
			float A33 = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
			float A34 = ReadFromEditBox(_hwnd, IDC_EDIT_A34);

			float B31 = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
			float B32 = ReadFromEditBox(_hwnd, IDC_EDIT_B32);
			float B33 = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
			float B34 = ReadFromEditBox(_hwnd, IDC_EDIT_B34);

			WriteToEditBox(_hwnd, IDC_EDIT_R31, A31 + B31);
			WriteToEditBox(_hwnd, IDC_EDIT_R32, A32 + B32);
			WriteToEditBox(_hwnd, IDC_EDIT_R33, A33 + B33);
			WriteToEditBox(_hwnd, IDC_EDIT_R34, A34 + B34);


			float A41 = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
			float A42 = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
			float A43 = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
			float A44 = ReadFromEditBox(_hwnd, IDC_EDIT_A44);

			float B41 = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
			float B42 = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
			float B43 = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
			float B44 = ReadFromEditBox(_hwnd, IDC_EDIT_B44);

			WriteToEditBox(_hwnd, IDC_EDIT_R41, A41 + B41);
			WriteToEditBox(_hwnd, IDC_EDIT_R42, A42 + B42);
			WriteToEditBox(_hwnd, IDC_EDIT_R43, A43 + B43);
			WriteToEditBox(_hwnd, IDC_EDIT_R44, A44 + B44);
			break;
		}
		case IDCANCEL: // A - B
		{
			float A11 = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
			float A12 = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
			float A13 = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
			float A14 = ReadFromEditBox(_hwnd, IDC_EDIT_A14);

			float B11 = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
			float B12 = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
			float B13 = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
			float B14 = ReadFromEditBox(_hwnd, IDC_EDIT_B14);

			WriteToEditBox(_hwnd, IDC_EDIT_R11, A11 - B11);
			WriteToEditBox(_hwnd, IDC_EDIT_R12, A12 - B12);
			WriteToEditBox(_hwnd, IDC_EDIT_R13, A13 - B13);
			WriteToEditBox(_hwnd, IDC_EDIT_R14, A14 - B14);


			float A21 = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
			float A22 = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
			float A23 = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
			float A24 = ReadFromEditBox(_hwnd, IDC_EDIT_A24);

			float B21 = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
			float B22 = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
			float B23 = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
			float B24 = ReadFromEditBox(_hwnd, IDC_EDIT_B24);

			WriteToEditBox(_hwnd, IDC_EDIT_R21, A21 - B21);
			WriteToEditBox(_hwnd, IDC_EDIT_R22, A22 - B22);
			WriteToEditBox(_hwnd, IDC_EDIT_R23, A23 - B23);
			WriteToEditBox(_hwnd, IDC_EDIT_R24, A24 - B24);


			float A31 = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			float A32 = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
			float A33 = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
			float A34 = ReadFromEditBox(_hwnd, IDC_EDIT_A34);

			float B31 = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
			float B32 = ReadFromEditBox(_hwnd, IDC_EDIT_B32);
			float B33 = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
			float B34 = ReadFromEditBox(_hwnd, IDC_EDIT_B34);

			WriteToEditBox(_hwnd, IDC_EDIT_R31, A31 - B31);
			WriteToEditBox(_hwnd, IDC_EDIT_R32, A32 - B32);
			WriteToEditBox(_hwnd, IDC_EDIT_R33, A33 - B33);
			WriteToEditBox(_hwnd, IDC_EDIT_R34, A34 - B34);


			float A41 = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
			float A42 = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
			float A43 = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
			float A44 = ReadFromEditBox(_hwnd, IDC_EDIT_A44);

			float B41 = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
			float B42 = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
			float B43 = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
			float B44 = ReadFromEditBox(_hwnd, IDC_EDIT_B44);

			WriteToEditBox(_hwnd, IDC_EDIT_R41, A41 - B41);
			WriteToEditBox(_hwnd, IDC_EDIT_R42, A42 - B42);
			WriteToEditBox(_hwnd, IDC_EDIT_R43, A43 - B43);
			WriteToEditBox(_hwnd, IDC_EDIT_R44, A44 - B44);
			break;
		}
		case IDOK2: // A * B
		{
			// Reading Matrix A and Matrix B
			float A11 = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
			float A12 = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
			float A13 = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
			float A14 = ReadFromEditBox(_hwnd, IDC_EDIT_A14);

			float B11 = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
			float B12 = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
			float B13 = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
			float B14 = ReadFromEditBox(_hwnd, IDC_EDIT_B14);

			float A21 = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
			float A22 = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
			float A23 = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
			float A24 = ReadFromEditBox(_hwnd, IDC_EDIT_A24);

			float B21 = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
			float B22 = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
			float B23 = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
			float B24 = ReadFromEditBox(_hwnd, IDC_EDIT_B24);

			float A31 = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			float A32 = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
			float A33 = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
			float A34 = ReadFromEditBox(_hwnd, IDC_EDIT_A34);

			float B31 = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
			float B32 = ReadFromEditBox(_hwnd, IDC_EDIT_B32);
			float B33 = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
			float B34 = ReadFromEditBox(_hwnd, IDC_EDIT_B34);

			float A41 = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
			float A42 = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
			float A43 = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
			float A44 = ReadFromEditBox(_hwnd, IDC_EDIT_A44);

			float B41 = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
			float B42 = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
			float B43 = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
			float B44 = ReadFromEditBox(_hwnd, IDC_EDIT_B44);

			// Writing to Matrix R
			WriteToEditBox(_hwnd, IDC_EDIT_R11, ((A11 * B11) + (A12 * B21) + (A13 * B31) + (A14 * B41)));
			WriteToEditBox(_hwnd, IDC_EDIT_R12, ((A11 * B12) + (A12 * B22) + (A13 * B32) + (A14 * B42)));
			WriteToEditBox(_hwnd, IDC_EDIT_R13, ((A11 * B13) + (A12 * B23) + (A13 * B33) + (A14 * B43)));
			WriteToEditBox(_hwnd, IDC_EDIT_R14, ((A11 * B14) + (A12 * B24) + (A13 * B34) + (A14 * B44)));

			WriteToEditBox(_hwnd, IDC_EDIT_R21, ((A21 * B11) + (A22 * B21) + (A23 * B31) + (A24 * B41)));
			WriteToEditBox(_hwnd, IDC_EDIT_R22, ((A21 * B12) + (A22 * B22) + (A23 * B32) + (A24 * B42)));
			WriteToEditBox(_hwnd, IDC_EDIT_R23, ((A21 * B13) + (A22 * B23) + (A23 * B33) + (A24 * B43)));
			WriteToEditBox(_hwnd, IDC_EDIT_R24, ((A21 * B14) + (A22 * B24) + (A23 * B34) + (A24 * B44)));

			WriteToEditBox(_hwnd, IDC_EDIT_R31, ((A31 * B11) + (A32 * B21) + (A33 * B31) + (A34 * B41)));
			WriteToEditBox(_hwnd, IDC_EDIT_R32, ((A31 * B12) + (A32 * B22) + (A33 * B32) + (A34 * B42)));
			WriteToEditBox(_hwnd, IDC_EDIT_R33, ((A31 * B13) + (A32 * B23) + (A33 * B33) + (A34 * B43)));
			WriteToEditBox(_hwnd, IDC_EDIT_R34, ((A31 * B14) + (A32 * B24) + (A33 * B34) + (A34 * B44)));

			WriteToEditBox(_hwnd, IDC_EDIT_R41, ((A41 * B11) + (A42 * B21) + (A43 * B31) + (A44 * B41)));
			WriteToEditBox(_hwnd, IDC_EDIT_R42, ((A41 * B12) + (A42 * B22) + (A43 * B32) + (A44 * B42)));
			WriteToEditBox(_hwnd, IDC_EDIT_R43, ((A41 * B13) + (A42 * B23) + (A43 * B33) + (A44 * B43)));
			WriteToEditBox(_hwnd, IDC_EDIT_R44, ((A41 * B14) + (A42 * B24) + (A43 * B34) + (A44 * B44)));
			break;
		}
		case IDOK5: // B * A
		{
			// Reading Matrix A and Matrix B
			float A11 = ReadFromEditBox(_hwnd, IDC_EDIT_A11);
			float A12 = ReadFromEditBox(_hwnd, IDC_EDIT_A12);
			float A13 = ReadFromEditBox(_hwnd, IDC_EDIT_A13);
			float A14 = ReadFromEditBox(_hwnd, IDC_EDIT_A14);

			float B11 = ReadFromEditBox(_hwnd, IDC_EDIT_B11);
			float B12 = ReadFromEditBox(_hwnd, IDC_EDIT_B12);
			float B13 = ReadFromEditBox(_hwnd, IDC_EDIT_B13);
			float B14 = ReadFromEditBox(_hwnd, IDC_EDIT_B14);

			float A21 = ReadFromEditBox(_hwnd, IDC_EDIT_A21);
			float A22 = ReadFromEditBox(_hwnd, IDC_EDIT_A22);
			float A23 = ReadFromEditBox(_hwnd, IDC_EDIT_A23);
			float A24 = ReadFromEditBox(_hwnd, IDC_EDIT_A24);

			float B21 = ReadFromEditBox(_hwnd, IDC_EDIT_B21);
			float B22 = ReadFromEditBox(_hwnd, IDC_EDIT_B22);
			float B23 = ReadFromEditBox(_hwnd, IDC_EDIT_B23);
			float B24 = ReadFromEditBox(_hwnd, IDC_EDIT_B24);

			float A31 = ReadFromEditBox(_hwnd, IDC_EDIT_A31);
			float A32 = ReadFromEditBox(_hwnd, IDC_EDIT_A32);
			float A33 = ReadFromEditBox(_hwnd, IDC_EDIT_A33);
			float A34 = ReadFromEditBox(_hwnd, IDC_EDIT_A34);

			float B31 = ReadFromEditBox(_hwnd, IDC_EDIT_B31);
			float B32 = ReadFromEditBox(_hwnd, IDC_EDIT_B32);
			float B33 = ReadFromEditBox(_hwnd, IDC_EDIT_B33);
			float B34 = ReadFromEditBox(_hwnd, IDC_EDIT_B34);

			float A41 = ReadFromEditBox(_hwnd, IDC_EDIT_A41);
			float A42 = ReadFromEditBox(_hwnd, IDC_EDIT_A42);
			float A43 = ReadFromEditBox(_hwnd, IDC_EDIT_A43);
			float A44 = ReadFromEditBox(_hwnd, IDC_EDIT_A44);

			float B41 = ReadFromEditBox(_hwnd, IDC_EDIT_B41);
			float B42 = ReadFromEditBox(_hwnd, IDC_EDIT_B42);
			float B43 = ReadFromEditBox(_hwnd, IDC_EDIT_B43);
			float B44 = ReadFromEditBox(_hwnd, IDC_EDIT_B44);

			// Writing to Matrix R
			WriteToEditBox(_hwnd, IDC_EDIT_R11, ((B11 * A11) + (B12 * A21) + (B13 * A31) + (B14 * A41)));
			WriteToEditBox(_hwnd, IDC_EDIT_R12, ((B11 * A12) + (B12 * A22) + (B13 * A32) + (B14 * A42)));
			WriteToEditBox(_hwnd, IDC_EDIT_R13, ((B11 * A13) + (B12 * A23) + (B13 * A33) + (B14 * A43)));
			WriteToEditBox(_hwnd, IDC_EDIT_R14, ((B11 * A14) + (B12 * A24) + (B13 * A34) + (B14 * A44)));

			WriteToEditBox(_hwnd, IDC_EDIT_R21, ((B21* A11) + (B22 * A21) + (B23 * A31) + (B24 * A41)));
			WriteToEditBox(_hwnd, IDC_EDIT_R22, ((B21* A12) + (B22 * A22) + (B23 * A32) + (B24 * A42)));
			WriteToEditBox(_hwnd, IDC_EDIT_R23, ((B21* A13) + (B22 * A23) + (B23 * A33) + (B24 * A43)));
			WriteToEditBox(_hwnd, IDC_EDIT_R24, ((B21* A14) + (B22 * A24) + (B23 * A34) + (B24 * A44)));

			WriteToEditBox(_hwnd, IDC_EDIT_R31, ((B31* A11) + (B32 * A21) + (B33 * A31) + (B34 * A41)));
			WriteToEditBox(_hwnd, IDC_EDIT_R32, ((B31* A12) + (B32 * A22) + (B33 * A32) + (B34 * A42)));
			WriteToEditBox(_hwnd, IDC_EDIT_R33, ((B31* A13) + (B32 * A23) + (B33 * A33) + (B34 * A43)));
			WriteToEditBox(_hwnd, IDC_EDIT_R34, ((B31* A14) + (B32 * A24) + (B33 * A34) + (B34 * A44)));

			WriteToEditBox(_hwnd, IDC_EDIT_R41, ((B41* A11) + (B42 * A21) + (B43 * A31) + (B44 * A41)));
			WriteToEditBox(_hwnd, IDC_EDIT_R42, ((B41* A12) + (B42 * A22) + (B43 * A32) + (B44 * A42)));
			WriteToEditBox(_hwnd, IDC_EDIT_R43, ((B41* A13) + (B42 * A23) + (B43 * A33) + (B44 * A43)));
			WriteToEditBox(_hwnd, IDC_EDIT_R44, ((B41* A14) + (B42 * A24) + (B43 * A34) + (B44 * A44)));
			break;
		}
		}
		return TRUE;
		break;
	}
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	default:
		break;
	}
	return FALSE;
}

void GetIDTransformMatrixRMF(HWND _hwnd, float MatrixRMF[4][4])
{
	// Row 1
	MatrixRMF[0][0] = IDC_EDIT16;
	MatrixRMF[0][1] = IDC_EDIT18;
	MatrixRMF[0][2] = IDC_EDIT19;
	MatrixRMF[0][3] = IDC_EDIT20;

	// Row 2
	MatrixRMF[1][0] = IDC_EDIT21;
	MatrixRMF[1][1] = IDC_EDIT22;
	MatrixRMF[1][2] = IDC_EDIT23;
	MatrixRMF[1][3] = IDC_EDIT8;

	// Row 3
	MatrixRMF[2][0] = IDC_EDIT9;
	MatrixRMF[2][1] = IDC_EDIT10;
	MatrixRMF[2][2] = IDC_EDIT11;
	MatrixRMF[2][3] = IDC_EDIT12;

	//Row 4
	MatrixRMF[3][0] = IDC_EDIT24;
	MatrixRMF[3][1] = IDC_EDIT25;
	MatrixRMF[3][2] = IDC_EDIT26;
	MatrixRMF[3][3] = IDC_EDIT27;
}

void GetIDTransformMatrixCMF(HWND _hwnd, float MatrixCMF[4][4])
{
	// Row 1
	MatrixCMF[0][0] = IDC_EDIT47;
	MatrixCMF[0][1] = IDC_EDIT48;
	MatrixCMF[0][2] = IDC_EDIT49;
	MatrixCMF[0][3] = IDC_EDIT50;

	// Row 2
	MatrixCMF[1][0] = IDC_EDIT51;
	MatrixCMF[1][1] = IDC_EDIT52;
	MatrixCMF[1][2] = IDC_EDIT53;
	MatrixCMF[1][3] = IDC_EDIT54;

	// Row 3
	MatrixCMF[2][0] = IDC_EDIT55;
	MatrixCMF[2][1] = IDC_EDIT56;
	MatrixCMF[2][2] = IDC_EDIT57;
	MatrixCMF[2][3] = IDC_EDIT58;

	//Row 4
	MatrixCMF[3][0] = IDC_EDIT59;
	MatrixCMF[3][1] = IDC_EDIT60;
	MatrixCMF[3][2] = IDC_EDIT61;
	MatrixCMF[3][3] = IDC_EDIT62;
}

void ReadTransformInputs(HWND _hwnd)
{
	// Scale Factor
	float scaleX = ReadFromEditBox(_hwnd, IDC_EDIT1);
	float scaleY = ReadFromEditBox(_hwnd, IDC_EDIT2);
	float scaleZ = ReadFromEditBox(_hwnd, IDC_EDIT3);

	// Translation Amount
	float transX = ReadFromEditBox(_hwnd, IDC_EDIT4);
	float transY = ReadFromEditBox(_hwnd, IDC_EDIT5);
	float transZ = ReadFromEditBox(_hwnd, IDC_EDIT6);

	// Rotation Details
	float rotX = ReadFromEditBox(_hwnd, IDC_EDIT7);
	float rotY = ReadFromEditBox(_hwnd, IDC_EDIT28);
	float rotZ = ReadFromEditBox(_hwnd, IDC_EDIT30);

	float rotAngle = ReadFromEditBox(_hwnd, IDC_EDIT13);

	// Projection
	float proX = ReadFromEditBox(_hwnd, IDC_EDIT14);
	float proY = ReadFromEditBox(_hwnd, IDC_EDIT24);
	float proZ = ReadFromEditBox(_hwnd, IDC_EDIT31);

	float proDist = ReadFromEditBox(_hwnd, IDC_EDIT13);
}

void IDMatrix(HWND _hwnd, float Matrix[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == i)
			{
				Matrix[i][j] = 1;
			}
			else
			{
				Matrix[i][j] =  0;
			}
		}
	}
}

void TrasnsToEdit(HWND _hwnd, float Matrix2[4][4], float Matrix[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			WriteToEditBox(_hwnd, Matrix2[i][j], Matrix[i][j]);
			
		}
	}
}

BOOL CALLBACK TransformationDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}

	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
			// Compute
		case IDC_BUTTON4:
		{
			float MatrixRMF[4][4], MatrixRMFID[4][4], MatrixCMF[4][4], MatrixCMFID[4][4];
			
			// Setting RMF Matrix to Identity Matrix
			GetIDTransformMatrixRMF(_hwnd, MatrixRMFID);
			IDMatrix(_hwnd, MatrixRMF);
			TrasnsToEdit(_hwnd, MatrixRMFID, MatrixRMF);

			// Setting CMF Matrix to Identity Matrix
			GetIDTransformMatrixCMF(_hwnd, MatrixCMFID);
			IDMatrix(_hwnd, MatrixCMF);
			TrasnsToEdit(_hwnd, MatrixCMFID, MatrixCMF);
			
			break;
		}

		}
	}
	default:
		break;
	}
	return FALSE;
}

void GaussianRead(float Matrix[3][4]) 
{
	// Row 1
	Matrix[0][0] = IDC_EDIT1;
	Matrix[0][1] = IDC_EDIT4;
	Matrix[0][2] = IDC_EDIT2;
	Matrix[0][3] = IDC_EDIT3;

	// Row 2
	Matrix[1][0] = IDC_EDIT5;
	Matrix[1][1] = IDC_EDIT8;
	Matrix[1][2] = IDC_EDIT6;
	Matrix[1][3] = IDC_EDIT7;

	// Row 3
	Matrix[2][0] = IDC_EDIT9;
	Matrix[2][1] = IDC_EDIT12;
	Matrix[2][2] = IDC_EDIT10;
	Matrix[2][3] = IDC_EDIT11;
}

void Echelon(HWND _hwnd)
{
	float Matrix[3][4];
	GaussianRead(Matrix);

	float echelonOne = ReadFromEditBox(_hwnd, Matrix[1][0]);
	float echelonTwo = ReadFromEditBox(_hwnd, Matrix[2][0]);
	float echelonThree = ReadFromEditBox(_hwnd, Matrix[2][1]);

	float echelonFour = ReadFromEditBox(_hwnd, Matrix[0][1]);
	float echelonFive = ReadFromEditBox(_hwnd, Matrix[0][2]);
	float echelonSix = ReadFromEditBox(_hwnd, Matrix[1][2]);

	// Row Echelon and Reduced Row Echelon Check
	if ((echelonOne && echelonTwo && echelonThree) == 0)
	{
		// Reduced Row Echelon
		if ((echelonFour && echelonFive && echelonSix) == 0)
		{
			MessageBox(nullptr, TEXT("The matrix is a reduced row Echelon"), TEXT("Reduced Row Echelon"), MB_OK);
		}
		// Row Echelon
		else
		{
			MessageBox(nullptr, TEXT("The matrix is a row Echelon"), TEXT("Row Echelon"), MB_OK);
		}
	}
}

BOOL CALLBACK GaussianDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		// Multiply Row _ By _
		case IDC_BUTTON1:
		{
			float Matrix[3][4];
			GaussianRead(Matrix);

			int inputMult = ReadFromEditBox(_hwnd, IDC_EDIT14);
			int inputRow = ReadFromEditBox(_hwnd, IDC_EDIT13) - 1;

			// Set input boxe to 0 if row input larger than matrix
			if (inputRow > 2)
			{
				MessageBox(nullptr, TEXT("Please enter a vail row"), TEXT("Row Out Of Range"), MB_OK);
				WriteToEditBox(_hwnd, IDC_EDIT13, 0);
			}

			for (int i = 0; i <= 3; i++)
			{
				float temp = ReadFromEditBox(_hwnd, Matrix[inputRow][i]);

				WriteToEditBox(_hwnd, Matrix[inputRow][i], temp * inputMult);
			}
			Echelon(_hwnd);
			break;
		}
		// Swap Row _ With Row _
		case IDC_BUTTON2:
		{
			float Matrix[3][4];
			GaussianRead(Matrix);

			int inputRowOne = ReadFromEditBox(_hwnd, IDC_EDIT16) - 1;
			int inputRowTwo = ReadFromEditBox(_hwnd, IDC_EDIT17) -1;

			// Set input boxes to 0 if row input larger than matrix
			if ((inputRowOne > 2) || (inputRowTwo > 2))
			{
				MessageBox(nullptr, TEXT("Please enter a vail row"), TEXT("Row Out Of Range"), MB_OK);
				WriteToEditBox(_hwnd, IDC_EDIT16, 0);
				WriteToEditBox(_hwnd, IDC_EDIT17, 0);
				break;
			}

			float Temp[4];

			for (int i = 0; i < 4; i++)
			{
				float temp = ReadFromEditBox(_hwnd, Matrix[inputRowOne][i]);
				Temp[i] = temp;
				WriteToEditBox(_hwnd, Matrix[inputRowOne][i], ReadFromEditBox(_hwnd, Matrix[inputRowTwo][i]));
			}

			for (int j = 0; j < 4; j++)
			{
				WriteToEditBox(_hwnd, Matrix[inputRowTwo][j], Temp[j]);
			}

			break;
		}
		// Add _ Times Row _ To Row _
		case IDC_BUTTON3:
		{
			float Matrix[3][4];
			GaussianRead(Matrix);

			int inputAdd = ReadFromEditBox(_hwnd, IDC_EDIT19);
			int inputTimes = ReadFromEditBox(_hwnd, IDC_EDIT20) -1;
			int inputRow = ReadFromEditBox(_hwnd, IDC_EDIT22) - 1;

			float Temp[4];

			for (int i = 0; i < 4; i++)
			{
				float temp = ReadFromEditBox(_hwnd, Matrix[inputTimes][i]);
				temp *= inputAdd;
				Temp[i] = temp;
			}

			for (int j = 0; j < 4; j++)
			{
				float temp = ReadFromEditBox(_hwnd, Matrix[inputRow][j]);
				temp += Temp[j];
				WriteToEditBox(_hwnd, Matrix[inputRow][j], temp);
			}
			break;
		}
		
		case IDC_BUTTON10:
		{
			float Matrix[3][4];
			GaussianRead(Matrix);

			srand(time(NULL));

			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					float randNum = rand() % 100 + 1;
					WriteToEditBox(_hwnd, Matrix[i][j], randNum);
				}
			}
			break;
		}

		}
	}
	default:
		break;
	}
	return FALSE;
}

BOOL CALLBACK QuaternionDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
			// A + B
		case IDC_BUTTON1:
		{
			float iA = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float jA = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float kA = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float cA = ReadFromEditBox(_hwnd, IDC_EDIT4);

			float iB = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float jB = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float kB = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float cB = ReadFromEditBox(_hwnd, IDC_EDIT8);

			WriteToEditBox(_hwnd, IDC_EDIT10, (iA + iB));
			WriteToEditBox(_hwnd, IDC_EDIT11, (jA + jB));
			WriteToEditBox(_hwnd, IDC_EDIT12, (kA + kB));
			WriteToEditBox(_hwnd, IDC_EDIT13, (cA + cB));
			break;
		}
		// A - B
		case IDC_BUTTON5:
		{
			float iA = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float jA = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float kA = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float cA = ReadFromEditBox(_hwnd, IDC_EDIT4);

			float iB = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float jB = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float kB = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float cB = ReadFromEditBox(_hwnd, IDC_EDIT8);

			WriteToEditBox(_hwnd, IDC_EDIT10, (iA - iB));
			WriteToEditBox(_hwnd, IDC_EDIT11, (jA - jB));
			WriteToEditBox(_hwnd, IDC_EDIT12, (kA - kB));
			WriteToEditBox(_hwnd, IDC_EDIT13, (cA - cB));
			break;
		}
		// B - A
		case IDC_BUTTON6:
		{
			float iA = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float jA = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float kA = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float cA = ReadFromEditBox(_hwnd, IDC_EDIT4);

			float iB = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float jB = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float kB = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float cB = ReadFromEditBox(_hwnd, IDC_EDIT8);

			WriteToEditBox(_hwnd, IDC_EDIT10, (iB - iA));
			WriteToEditBox(_hwnd, IDC_EDIT11, (jB - jA));
			WriteToEditBox(_hwnd, IDC_EDIT12, (kB - kA));
			WriteToEditBox(_hwnd, IDC_EDIT13, (cB - cA));
			break;
		}
		// AB
		case IDC_BUTTON2:
		{
			float iA = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float jA = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float kA = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float cA = ReadFromEditBox(_hwnd, IDC_EDIT4);

			float iB = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float jB = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float kB = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float cB = ReadFromEditBox(_hwnd, IDC_EDIT8);

			WriteToEditBox(_hwnd, IDC_EDIT10, (cA * iB) + (iA * cB) + (jA * kB) - (kA * jB));
			WriteToEditBox(_hwnd, IDC_EDIT11, (cA * jB) - (iA * kB) + (jB * cB) + (kA * iB));
			WriteToEditBox(_hwnd, IDC_EDIT12, (cA * kB) + (iA * jB) - (kA * iB) + (kA * cB));
			WriteToEditBox(_hwnd, IDC_EDIT13, (cA * cB) - (iA * iB) - (jA * jB) - (kA * kB));
			break;
		}
		// BA
		case IDC_BUTTON7:
		{
			float iA = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float jA = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float kA = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float cA = ReadFromEditBox(_hwnd, IDC_EDIT4);

			float iB = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float jB = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float kB = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float cB = ReadFromEditBox(_hwnd, IDC_EDIT8);

			WriteToEditBox(_hwnd, IDC_EDIT10, (cB * iA) + (iB * cA) + (jB * kA) - (kB * jA));
			WriteToEditBox(_hwnd, IDC_EDIT11, (cB * jA) - (iB * kA) + (jB * cA) + (kB * iA));
			WriteToEditBox(_hwnd, IDC_EDIT12, (cB * kA) + (iB * jA) - (kB * iA) + (kB * cA));
			WriteToEditBox(_hwnd, IDC_EDIT13, (cB * cA) - (iB * iA) - (jB * jA) - (kB * kA));
			break;
		}
		// A dot B
		case IDC_BUTTON8:
		{
			float iA = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float jA = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float kA = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float cA = ReadFromEditBox(_hwnd, IDC_EDIT4);

			float iB = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float jB = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float kB = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float cB = ReadFromEditBox(_hwnd, IDC_EDIT8);

			float result = (iA * iB);

			WriteToEditBox(_hwnd, IDC_EDIT9, result);
			break;
		}
		// A*
		case IDC_BUTTON3:
		{
			float iA = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float jA = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float kA = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float cA = ReadFromEditBox(_hwnd, IDC_EDIT4);

			WriteToEditBox(_hwnd, IDC_EDIT10, (iA * -1));
			WriteToEditBox(_hwnd, IDC_EDIT11, (jA * -1));
			WriteToEditBox(_hwnd, IDC_EDIT12, (kA * -1));
			WriteToEditBox(_hwnd, IDC_EDIT13, cA);
			break;
		}
		// B*
		case IDC_BUTTON9:
		{
			float iB = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float jB = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float kB = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float cB = ReadFromEditBox(_hwnd, IDC_EDIT8);

			WriteToEditBox(_hwnd, IDC_EDIT10, (iB * -1));
			WriteToEditBox(_hwnd, IDC_EDIT11, (jB * -1));
			WriteToEditBox(_hwnd, IDC_EDIT12, (kB * -1));
			WriteToEditBox(_hwnd, IDC_EDIT13, cB);
			break;
		}
		// |A|
		case IDC_BUTTON10:
		{
			float iA = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float jA = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float kA = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float cA = ReadFromEditBox(_hwnd, IDC_EDIT4);

			float result = sqrt((iA * iA) + (jA * jA) + (kA * kA) + (cA * cA));

			WriteToEditBox(_hwnd, IDC_EDIT9, result);
			break;
		}
		// |B|
		case IDC_BUTTON11:
		{
			float iB = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float jB = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float kB = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float cB = ReadFromEditBox(_hwnd, IDC_EDIT8);

			float result = sqrt((iB * iB) + (jB * jB) + (kB * kB) + (cB * cB));

			WriteToEditBox(_hwnd, IDC_EDIT9, result);
			break;
		}
		// A Inv
		case IDC_BUTTON12:
		{
			float iA = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float jA = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float kA = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float cA = ReadFromEditBox(_hwnd, IDC_EDIT4);

			float result = sqrt((iA * iA) + (jA * jA) + (kA * kA) + (cA * cA));

			WriteToEditBox(_hwnd, IDC_EDIT10, (iA * -1) / result);
			WriteToEditBox(_hwnd, IDC_EDIT11, (jA * -1) / result);
			WriteToEditBox(_hwnd, IDC_EDIT12, (kA * -1) / result);
			WriteToEditBox(_hwnd, IDC_EDIT13, cA / result);
			break;
		}
		// B Inv
		case IDC_BUTTON13:
		{
			float iB = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float jB = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float kB = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float cB = ReadFromEditBox(_hwnd, IDC_EDIT8);

			float result = sqrt((iB * iB) + (jB * jB) + (kB * kB) + (cB * cB));

			WriteToEditBox(_hwnd, IDC_EDIT10, ((iB * -1) / result));
			WriteToEditBox(_hwnd, IDC_EDIT11, ((jB * -1) / result));
			WriteToEditBox(_hwnd, IDC_EDIT12, ((kB * -1) / result));
			WriteToEditBox(_hwnd, IDC_EDIT13, (cB / result));
			break;
		}
		// TA
		case IDC_BUTTON14:
		{
			float iA = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float jA = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float kA = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float cA = ReadFromEditBox(_hwnd, IDC_EDIT4);

			float T = ReadFromEditBox(_hwnd, IDC_EDIT9);

			WriteToEditBox(_hwnd, IDC_EDIT10, (iA * T));
			WriteToEditBox(_hwnd, IDC_EDIT11, (jA * T));
			WriteToEditBox(_hwnd, IDC_EDIT12, (kA * T));
			WriteToEditBox(_hwnd, IDC_EDIT13, (cA * T));
			break;
		}
		// TB
		case IDC_BUTTON15:
		{
			float iB = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float jB = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float kB = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float cB = ReadFromEditBox(_hwnd, IDC_EDIT8);

			float T = ReadFromEditBox(_hwnd, IDC_EDIT9);

			WriteToEditBox(_hwnd, IDC_EDIT10, (iB * T));
			WriteToEditBox(_hwnd, IDC_EDIT11, (jB * T));
			WriteToEditBox(_hwnd, IDC_EDIT12, (kB * T));
			WriteToEditBox(_hwnd, IDC_EDIT13, (cB * T));
			break;
		}
		}
	}
	default:
		break;
	}
	return FALSE;
}

void ReadSlerpQuater(HWND _hwnd)
{
	float t = ReadFromEditBox(_hwnd, IDC_EDIT9);

	float aI = ReadFromEditBox(_hwnd, IDC_EDIT1);
	float aJ = ReadFromEditBox(_hwnd, IDC_EDIT2);
	float aK = ReadFromEditBox(_hwnd, IDC_EDIT3);
	float aC = ReadFromEditBox(_hwnd, IDC_EDIT4);

	float bI = ReadFromEditBox(_hwnd, IDC_EDIT5);
	float bJ = ReadFromEditBox(_hwnd, IDC_EDIT6);
	float bK = ReadFromEditBox(_hwnd, IDC_EDIT7);
	float bC = ReadFromEditBox(_hwnd, IDC_EDIT8);
}

void ReadSlerpMatrix(float Matrix[3][4])
{
	// Row 1
	Matrix[0][0] = IDC_EDIT34;
	Matrix[0][1] = IDC_EDIT35;
	Matrix[0][2] = IDC_EDIT36;
	Matrix[0][3] = IDC_EDIT37;

	// Row 2
	Matrix[1][0] = IDC_EDIT38;
	Matrix[1][1] = IDC_EDIT39;
	Matrix[1][2] = IDC_EDIT40;
	Matrix[1][3] = IDC_EDIT41;

	// Row 3
	Matrix[2][0] = IDC_EDIT42;
	Matrix[2][1] = IDC_EDIT43;
	Matrix[2][2] = IDC_EDIT44;
	Matrix[2][3] = IDC_EDIT45;
}
BOOL CALLBACK SLERPDlgProc(HWND _hwnd,
	UINT _msg,
	WPARAM _wparam,
	LPARAM _lparam)
{

	switch (_msg)
	{
	case WM_CLOSE:
	{
		ShowWindow(_hwnd, SW_HIDE);
		return TRUE;
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(_wparam))
		{
		// slerp a, b, t
		case IDC_BUTTON1:
		{
			float t = ReadFromEditBox(_hwnd, IDC_EDIT9);

			float aI = ReadFromEditBox(_hwnd, IDC_EDIT1);
			float aJ = ReadFromEditBox(_hwnd, IDC_EDIT2);
			float aK = ReadFromEditBox(_hwnd, IDC_EDIT3);
			float aC = ReadFromEditBox(_hwnd, IDC_EDIT4);

			float bI = ReadFromEditBox(_hwnd, IDC_EDIT5);
			float bJ = ReadFromEditBox(_hwnd, IDC_EDIT6);
			float bK = ReadFromEditBox(_hwnd, IDC_EDIT7);
			float bC = ReadFromEditBox(_hwnd, IDC_EDIT8);
				  
			float rI, rJ, rK, rC;

			float dotProd = ((aC * bC) + (aI * bI) + (aJ * bJ) + (aK * bK));

			if (dotProd < 0)
			{
				bC = -bC;
				bI = -bI;
				bJ = -bJ;
				dotProd = -dotProd;
			}

			float angle = acos(dotProd);
			float angleTwo = sqrt(1 - dotProd * dotProd);

			float ratA = (sin((1 - t) * angle) / (angleTwo));
			float ratB = (sin(t * angle) / (angleTwo));

			if (abs(dotProd) >= 1) {
				rC = aC;
				rI = aI;
				rJ = aJ;
				rK = aK;
			}
			else if (abs(angleTwo) < .001) {
				rC = (aC * 0.5 + bC * 0.5);
				rI = (aI * 0.5 + bI * 0.5);
				rJ = (aJ * 0.5 + bJ * 0.5);
				rK = (aK * 0.5 + bK * 0.5);
			}
			else
			{
				rC = (aC * ratA + bC * ratB);
				rI = (aI * ratA + bI * ratB);
				rJ = (aJ * ratA + bJ * ratB);
				rK = (aK * ratA + bK * ratB);
			}

			WriteToEditBox(_hwnd, IDC_EDIT10, rI);
			WriteToEditBox(_hwnd, IDC_EDIT11, rJ);
			WriteToEditBox(_hwnd, IDC_EDIT12, rK);
			WriteToEditBox(_hwnd, IDC_EDIT13, rC);
			break;
		}
		// a
		case IDC_BUTTON2:
		{
			break;
		}
		// b
		case IDC_BUTTON3:
		{
			break;
		}
		// Matrix slerp a, b, t
		case IDC_BUTTON4:
		{
			break;
		}
		}
	}
	default:
		break;
	}
	return FALSE;
}


int WINAPI WinMain(HINSTANCE _hInstance,
	HINSTANCE _hPrevInstance,
	LPSTR _lpCmdLine,
	int _nCmdShow)
{
	WNDCLASSEX winclass; // This will hold the class we create.
	HWND hwnd;           // Generic window handle.
	MSG msg;             // Generic message.

						 // First fill in the window class structure.
	winclass.cbSize = sizeof(WNDCLASSEX);
	winclass.style = CS_DBLCLKS | CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	winclass.lpfnWndProc = WindowProc;
	winclass.cbClsExtra = 0;
	winclass.cbWndExtra = 0;
	winclass.hInstance = _hInstance;
	winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	winclass.hbrBackground =
		static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
	winclass.lpszMenuName = NULL;
	winclass.lpszClassName = WINDOW_CLASS_NAME;
	winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	// register the window class
	if (!RegisterClassEx(&winclass))
	{
		return (0);
	}

	//Laod the Menu
	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));

	// create the window
	hwnd = CreateWindowEx(NULL, // Extended style.
		WINDOW_CLASS_NAME,      // Class.
		L"Your Basic Window",   // Title.
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0,                    // Initial x,y.
		400, 100,                // Initial width, height.
		NULL,                   // Handle to parent.
		g_hMenu,                   // Handle to menu.
		_hInstance,             // Instance of this application.
		NULL);                  // Extra creation parameters.

	if (!(hwnd))
	{
		return (0);
	}

	//Create the modeless dialog boxes for the calculators
	//Matrix Calculator
	g_hDlgMatrix = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogMatrix), hwnd, (DLGPROC)MatrixDlgProc);
	g_hDlgTransformation = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogTransformations), hwnd, (DLGPROC)TransformationDlgProc);
	g_hDlgGaussian = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogGaussian), hwnd, (DLGPROC)GaussianDlgProc);
	g_hDlgQuaternion = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogQuaternion), hwnd, (DLGPROC)QuaternionDlgProc);
	g_hDlgSLERP = CreateDialog(_hInstance, MAKEINTRESOURCE(IDD_DialogSLERP), hwnd, (DLGPROC)SLERPDlgProc);

	// Enter main event loop
	while (true)
	{
		// Test if there is a message in queue, if so get it.
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// Test if this is a quit.
			if (msg.message == WM_QUIT)
			{
				break;
			}

			if ((g_hDlgMatrix == 0 && g_hDlgTransformation == 0 && g_hDlgGaussian == 0 && g_hDlgQuaternion == 0 && g_hDlgSLERP == 0) ||
				(!IsDialogMessage(g_hDlgMatrix, &msg) && !IsDialogMessage(g_hDlgTransformation, &msg) && !IsDialogMessage(g_hDlgGaussian, &msg) && !IsDialogMessage(g_hDlgQuaternion, &msg) && !IsDialogMessage(g_hDlgSLERP, &msg)))
			{
				// Translate any accelerator keys.
				TranslateMessage(&msg);
				// Send the message to the window proc.
				DispatchMessage(&msg);
			}
		}

		// Main game processing goes here.
		GameLoop(); //One frame of game logic occurs here...
	}

	// Return to Windows like this...
	return (static_cast<int>(msg.wParam));
}