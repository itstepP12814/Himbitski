#include <windows.h>
#include <tchar.h>

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);


TCHAR szClassWindow[] = TEXT("��������� ����������");
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
	hWnd = CreateWindowEx(0, szClassWindow, TEXT("������������ ���� �������� ������"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInst, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	MessageBox(hWnd, TEXT("��� ������������ ���� �������� ������ ������� <CTRL>"), TEXT("������������ ���� �������� ������"), MB_OK | MB_ICONINFORMATION);


	while (GetMessage(&Msg, NULL, 0, 0))
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	HWND hWindow = (HWND)lParam; // ���������� ���� ������ ����������
	TCHAR caption[MAX_PATH] = { 0 }, classname[100] = { 0 }, text[500] = { 0 };
	GetWindowText(hWnd, caption, 100); // �������� ����� ��������� �������� ���� �������� ������
	GetClassName(hWnd, classname, 100); // �������� ��� ������ �������� ���� �������� ������
	if (!lstrcmp(classname, TEXT("CalcFrame")))
	{
		SetWindowText(hWnd, TEXT("�����������"));
		mass[1] = hWnd;
		mass[2] = hWindow;
		return TRUE;
	}
	if (lstrlen(caption))
	{
		lstrcat(text, TEXT("��������� ����: "));
		lstrcat(text, caption);
		lstrcat(text, TEXT("\n"));
		lstrcat(text, TEXT("����� ����: "));
		lstrcat(text, classname);
		MessageBox(hWindow, text, TEXT("������������ ���� �������� ������"), MB_OK | MB_ICONINFORMATION);
	}
	return TRUE; // ���������� ������������ ���� �������� ������
}
void CALLBACK TimerProc(HWND hWnd, UINT message, UINT_PTR idTimer, DWORD dwTimer){
	hWnd = mass[1];
	RECT x;
	GetWindowRect(hWnd, &x);
	int H = x.bottom - x.top;
	int W = x.right - x.left;

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
		if (wParam==VK_RETURN)
		{
			SetTimer(mass[2], 0, 1000 / 50, TimerProc);
		///� ��� ������� ��� ���� ����� �� ������� ��� ���������� ������ � ������������ �� � ��� �� ����� �����
		if (wParam == VK_ESCAPE)
		{
			///?????
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
