#pragma once

#include <windows.h>   // Include all the windows headers.
#include <windowsx.h>  // Include useful macros.
#include <math.h>
#include <time.h>

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
	bool rotX = IsDlgButtonChecked(_hwnd, IDC_CHECK1);
	bool rotY = IsDlgButtonChecked(_hwnd, IDC_CHECK2);
	bool rotZ = IsDlgButtonChecked(_hwnd, IDC_CHECK3);

	float rotAngle = ReadFromEditBox(_hwnd, IDC_EDIT13);

	// Projection
	float proX = IsDlgButtonChecked(_hwnd, IDC_EDIT28);
	float proY = IsDlgButtonChecked(_hwnd, IDC_EDIT30);
	float proZ = IsDlgButtonChecked(_hwnd, IDC_EDIT29);

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
				Matrix[i][j] = 0;
			}
		}
	}
}

void TrasnsToEdit(HWND _hwnd, float MatrixID[4][4], float Matrix[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			WriteToEditBox(_hwnd, MatrixID[i][j], Matrix[i][j]);

		}
	}
}

void ScaleFactorMatrix(float Matrix[4][4], float scaleX, float scaleY, float scaleZ)
{
	// Creating a Scale Matrix
	float scaleMatrix[4][4];

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 and j == 0)
			{
				Matrix[i][j] = scaleX;

			}
			else if (i == 1 and j == 1)
			{
				Matrix[i][j] = scaleY;
			}
			else if (i == 2 and j == 2)
			{
				Matrix[i][j] = scaleZ;
			}
			else if (i == 3 and j == 3)
			{
				Matrix[i][j] = 1;
			}
			else
			{
				Matrix[i][j] = 0;
			}
		}
	}
}

void MultiplyMatrix(float Matrix[4][4], float Matrix2[4][4])
{
	float Temp[4][4];
	float temp = 0;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp = 0;
			for (int k = 0; k < 4; k++)
			{
				temp += Matrix[i][k] * Matrix2[k][j];
			}
			Temp[i][j] = temp;
		}
	}

	for (int q = 0; q < 4; q++)
	{
		for (int w = 0; w < 4; w++)
		{
			Matrix[q][w] = Temp[q][w];
		}
	}

}

void TransposeMatrix(float Matrix[4][4], float Matrix2[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Matrix2[j][i] = Matrix[i][j];
		}
	}
}

void TranslateMatrix(float Matrix[4][4], float transX, float transY, float transZ)
{

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 and j == 3)
			{
				Matrix[i][j] = transX;
			}
			else if (i == 1 and j == 3)
			{
				Matrix[i][j] = transY;
			}
			else if (i == 2 and j == 3)
			{
				Matrix[i][j] = transZ;
			}
			else if (i == 3 and j == 3)
			{
				Matrix[i][j] = 1;
			}
			else if (i == 0 and j == 0)
			{
				Matrix[i][j] = 1;
			}
			else if (i == 1 and j == 1)
			{
				Matrix[i][j] = 1;
			}
			else if (i == 2 and j == 2)
			{
				Matrix[i][j] = 1;
			}
			else
			{
				Matrix[i][j] = 0;
			}
		}
	}
}

void XRotationMatrix(float Matrix[4][4], float angle)
{

	// Rotation X Matrix

	float TempX[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 and j == 0)
			{
				TempX[i][j] = 1;
			}
			else if (i == 1 and j == 1)
			{
				TempX[i][j] = cos(angle);
			}
			else if (i == 1 and j == 2)
			{
				TempX[i][j] = -sin(angle);
			}
			else if (i == 2 and j == 1)
			{
				TempX[i][j] = sin(angle);
			}
			else if (i == 2 and j == 2)
			{
				TempX[i][j] = cos(angle);
			}
			else if (i == 3 and j == 3)
			{
				TempX[i][j] = 1;
			}
			else
			{
				TempX[i][j] = 0;
			}
		}
	}
}

void YRotationMatrix(float Matrix[4][4], float angle)
{
	// Rotation Y Matrix

	float TempX[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 and j == 0)
			{
				TempX[i][j] = cos(angle);
			}
			else if (i == 0 and j == 2)
			{
				TempX[i][j] = sin(angle);
			}
			else if (i == 1 and j == 1)
			{
				TempX[i][j] = 1;
			}
			else if (i == 2 and j == 0)
			{
				TempX[i][j] = -sin(angle);
			}
			else if (i == 2 and j == 2)
			{
				TempX[i][j] = cos(angle);
			}
			else if (i == 3 and j == 3)
			{
				TempX[i][j] = 1;
			}
			else
			{
				TempX[i][j] = 0;
			}
		}
	}
}

void ZRotationMatrix(float Matrix[4][4], float angle)
{
	// Rotation Z Matrix

	float TempX[4][4];
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 and j == 0)
			{
				TempX[i][j] = cos(angle);
			}
			else if (i == 0 and j == 1)
			{
				TempX[i][j] = -sin(angle);
			}
			else if (i == 1 and j == 0)
			{
				TempX[i][j] = sin(angle);
			}
			else if (i == 1 and j == 1)
			{
				TempX[i][j] = cos(angle);
			}
			else if (i == 2 and j == 2)
			{
				TempX[i][j] = 1;
			}
			else if (i == 3 and j == 3)
			{
				TempX[i][j] = 1;
			}
			else
			{
				TempX[i][j] = 0;
			}
		}
	}
}

void ProjectionMatrix()
{

}