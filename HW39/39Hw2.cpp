#include <windows.h>
#include "resource.h"
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");
HICON hIcon;
HCURSOR hCursor1, hCursor2;

int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;
	wcl.cbSize = sizeof(wcl);
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	wcl.lpfnWndProc = WindowProc;
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hInst;
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szClassWindow;
	wcl.hIconSm = NULL;
	if (!RegisterClassEx(&wcl))
		return 0;
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Каркасное приложение"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);


	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

int x, y;
TCHAR buf[100];

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_RETURN)
			hIcon = (HICON)SetClassLong(hWnd, GCL_HICON, LONG(hIcon)); // устанавливаем иконку 
		break;
	case WM_LBUTTONDOWN:
		RECT rect;
		GetClientRect(hWnd, &rect);
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		if (x >= rect.right / 10 && x <= rect.right * 8 / 10 &&
			y >= rect.bottom / 10 && y <= rect.bottom * 8 / 10){
			SetWindowText(hWnd, TEXT("Вы внутри прямоугольника"));
		}
		else
			SetWindowText(hWnd, TEXT("Вы снаружи прямоугольника"));
		break;
	case WM_RBUTTONDOWN:
		GetClientRect(hWnd, &rect);
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		x = rect.bottom - rect.top;
		y = rect.right - rect.left;
		wsprintf(buf, TEXT("Высота =%d Ширина y=%d"),x,y);
		SetWindowText(hWnd, buf);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}