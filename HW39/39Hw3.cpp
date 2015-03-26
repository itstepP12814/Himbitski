#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void CALLBACK TimerProc(HWND, UINT, UINT_PTR, DWORD);

TCHAR szClassWindow[] = TEXT("Каркасное приложение");
HWND mass[3];
int windowX[2] = { 100, 200 };

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
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("Перечисление окон верхнего уровня"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	MessageBox(hWnd, TEXT("Для перечисления окон верхнего уровня нажмите <CTRL>"), TEXT("Перечисление окон верхнего уровня"), MB_OK | MB_ICONINFORMATION);


	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	HWND hWindow = (HWND)lParam; // дескриптор окна нашего приложения
	TCHAR caption[MAX_PATH] = { 0 }, classname[100] = { 0 }, text[500] = { 0 };
	GetWindowText(hWnd, caption, 100); // получаем текст заголовка текущего окна верхнего уровня
	GetClassName(hWnd, classname, 100); // получаем имя класса текущего окна верхнего уровня
	if (!lstrcmp(classname, TEXT("CalcFrame")))
	{
		mass[1] = hWnd;
		mass[2] = hWindow;
		return TRUE;
	}
	if (!lstrcmp(classname, TEXT("Button")))
	{
		mass[3] = hWnd;
		mass[2] = hWindow;
		return TRUE;
	}
	if (lstrlen(caption))
	{
		lstrcat(text, TEXT("Заголовок окна: "));
		lstrcat(text, caption);
		lstrcat(text, TEXT("\n"));
		lstrcat(text, TEXT("Класс окна: "));
		lstrcat(text, classname);
		MessageBox(hWindow, text, TEXT("Перечисление окон верхнего уровня"), MB_OK | MB_ICONINFORMATION);
	}
	return TRUE; // продолжаем перечисление окон верхнего уровня
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		if (wParam == VK_CONTROL){
			EnumWindows(EnumWindowsProc, (LPARAM)hWnd);
		}
		break;
	case WM_LBUTTONDOWN:
		SetWindowText(mass[1], TEXT("Бульбулятор"));
		break;
	case WM_RBUTTONDOWN:
		MoveWindow(mass[3], 2000, 0, CW_USEDEFAULT, CW_USEDEFAULT, true);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}