// ���� WINDOWS.H �������� �����������, �������, � ��������� 
// ������� ������������ ��� ��������� ���������� ��� Windows. 
#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <vector>
#include <time.h>

// �������� ������� ���������
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("��������");	/* ��� ������ ���� */


std::vector<TCHAR*>x{ TEXT(" ������ ������� � ����"), TEXT("������� ����� ����� �� 10 � ����� ��"), TEXT(" ������� ���?") };

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;



	// 1. ����������� ������ ����
	wcl.cbSize = sizeof(wcl);	// ������ ��������� WNDCLASSEX
	// ������������ �� ����, ���� ������ ������ �� ����������� ��� �� ���������
	wcl.style = CS_HREDRAW | CS_VREDRAW;	// CS (Class Style) - ����� ������ ����
	wcl.lpfnWndProc = WindowProc;	// ����� ������� ���������
	wcl.cbClsExtra = 0;		// ������������ Windows 
	wcl.cbWndExtra = 0; 	// ������������ Windows 
	wcl.hInstance = hInst;	// ���������� ������� ����������
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// �������� ����������� ������
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// �������� ������������ �������	
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// ���������� ���� ����� ������
	wcl.lpszMenuName = NULL;	// ���������� �� �������� ����
	wcl.lpszClassName = szClassWindow;	// ��� ������ ����
	wcl.hIconSm = NULL;	// ���������� ��������� ������ ��� ����� � ������� ����

	// 2. ����������� ������ ����
	if (!RegisterClassEx(&wcl))
		return 0; // ��� ��������� ����������� - �����

	// 3. �������� ����
	// ��������� ���� �  ���������� hWnd ������������� ���������� ����
	hWnd = CreateWindowEx(
		0,		// ����������� ����� ����
		szClassWindow,	//��� ������ ����
		TEXT("������������������ �� ������"), // ��������� ����
		WS_OVERLAPPEDWINDOW,			// ����� ����
		/* ���������, �����, ����������� ������ �������, ��������� ����, ������ ������������ � ���������� ����  */
		CW_USEDEFAULT,	// �-���������� ������ �������� ���� ����
		CW_USEDEFAULT,	// y-���������� ������ �������� ���� ����
		CW_USEDEFAULT,	// ������ ����
		CW_USEDEFAULT,	// ������ ����
		NULL,			// ���������� ������������� ����
		NULL,			// ���������� ���� ����
		hInst,		// ������������� ����������, ���������� ����
		NULL);		// ��������� �� ������� ������ ����������

	// 4. ����������� ����
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // ����������� ����

	srand(time(NULL));
	int count = 0; 
	int res;
	int count_of_try = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (i != x.size() - 1)
		{
			 res=MessageBox(0, x[i], TEXT("���� � ��������"), MB_YESNO | MB_ICONQUESTION);
			 if (res == IDNO){
				 return 0;
			 }
		}
		else{
			TCHAR buf[100];
			count = rand()%10+1;
			wsprintf(buf, TEXT("�� ������� �����: %i"), count);
			int r = MessageBox(0, buf, TEXT("���� � ��������"), MB_YESNO | MB_ICONINFORMATION);
			if (r==IDYES)
			{
				count_of_try++;
				TCHAR buf[100];
				wsprintf(buf, TEXT("���������� �������: %i"), count_of_try);
				MessageBox(0, TEXT("��� � ������!!!"), buf, MB_OK | MB_ICONINFORMATION);
				count_of_try = 0;
			}
			else{
				count_of_try++;
				MessageBox(0, TEXT("�� ������  :("), TEXT("���� � ��������"), MB_OK | MB_ICONINFORMATION);
			}
			res = MessageBox(0, x[i], TEXT("���� � ��������"), MB_YESNO | MB_ICONQUESTION);
			if (res == IDNO){
				return 0;
			}
			else{
				i = 0;
			}

		}
	}

	// 5. ������ ����� ��������� ���������
	while (GetMessage(&Msg, NULL, 0, 0)) // ��������� ���������� ��������� �� ������� ���������
	{
		TranslateMessage(&Msg);	// ���������� ���������
		DispatchMessage(&Msg);	// ��������������� ���������
	}
	return Msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
	switch (uMessage)
	{
	case WM_CLOSE:
	{
					 int res = MessageBox(
						 0,
						 TEXT("�� ������������� ������?"),
						 TEXT("������� ����������!"),
						 MB_YESNO | MB_ICONINFORMATION);
					 if (res == IDYES){
						 DestroyWindow(hWnd);
					 }


	} break;
	case WM_DESTROY: // ��������� � ���������� ���������
		//
		PostQuitMessage(0); // ������� ��������� WM_QUIT
		break;
	default:
		// ��� ���������, ������� �� �������������� � ������ ������� ������� 
		// ������������ ������� Windows �� ��������� �� ���������
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}