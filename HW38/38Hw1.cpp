// Файл WINDOWS.H содержит определения, макросы, и структуры 
// которые используются при написании приложений под Windows. 
#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <vector>

// прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Последовательность Резюме");	/* Имя класса окна */


std::vector<TCHAR*>x { TEXT(" Семен 27 лет программист стаж 3 года"),TEXT(" Чашбр 65 лет политик стаж 32 года"), TEXT(" Иосиф 46 лет Актер стаж 15 лет") };

INT WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG Msg;
	WNDCLASSEX wcl;



	// 1. Определение класса окна
	wcl.cbSize = sizeof(wcl);	// размер структуры WNDCLASSEX
	// Перерисовать всё окно, если изменён размер по горизонтали или по вертикали
	wcl.style = CS_HREDRAW | CS_VREDRAW;	// CS (Class Style) - стиль класса окна
	wcl.lpfnWndProc = WindowProc;	// адрес оконной процедуры
	wcl.cbClsExtra = 0;		// используется Windows 
	wcl.cbWndExtra = 0; 	// используется Windows 
	wcl.hInstance = hInst;	// дескриптор данного приложения
	wcl.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// загрузка стандартной иконки
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);	// загрузка стандартного курсора	
	wcl.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	// заполнение окна белым цветом
	wcl.lpszMenuName = NULL;	// приложение не содержит меню
	wcl.lpszClassName = szClassWindow;	// имя класса окна
	wcl.hIconSm = NULL;	// отсутствие маленькой иконки для связи с классом окна

	// 2. Регистрация класса окна
	if (!RegisterClassEx(&wcl))
		return 0; // при неудачной регистрации - выход

	// 3. Создание окна
	// создается окно и  переменной hWnd присваивается дескриптор окна
	hWnd = CreateWindowEx(
		0,		// расширенный стиль окна
		szClassWindow,	//имя класса окна
		TEXT("Последовательность из Резюме"), // заголовок окна
		WS_OVERLAPPEDWINDOW,			// стиль окна
		/* Заголовок, рамка, позволяющая менять размеры, системное меню, кнопки развёртывания и свёртывания окна  */
		CW_USEDEFAULT,	// х-координата левого верхнего угла окна
		CW_USEDEFAULT,	// y-координата левого верхнего угла окна
		CW_USEDEFAULT,	// ширина окна
		CW_USEDEFAULT,	// высота окна
		NULL,			// дескриптор родительского окна
		NULL,			// дескриптор меню окна
		hInst,		// идентификатор приложения, создавшего окно
		NULL);		// указатель на область данных приложения

	// 4. Отображение окна
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd); // перерисовка окна

	int count = 0;
	for (int i = 0; i < x.size(); i++)
	{
		count += wcslen(x[i]);
		if (i != x.size()-1)
		{
			MessageBox(0, x[i], TEXT("Резюме"), MB_OK | MB_ICONINFORMATION);
		}
		else{
			TCHAR buf[100];
			count = (double)count / x.size();
			wsprintf(buf, TEXT("Среднее число Символов: "), count);
			MessageBox(0, x[i], buf, MB_OK | MB_ICONINFORMATION);
		}
	}


	// 5. Запуск цикла обработки сообщений
	while (GetMessage(&Msg, NULL, 0, 0)) // получение очередного сообщения из очереди сообщений
	{
		TranslateMessage(&Msg);	// трансляция сообщения
		DispatchMessage(&Msg);	// диспетчеризация сообщений
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
						 TEXT("Вы действительно хотите?"),
						 TEXT("Скажите пожалуйста!"),
						 MB_YESNO | MB_ICONINFORMATION);
					 if (res == IDYES){
						 DestroyWindow(hWnd);
					 }


	} break;
	case WM_DESTROY: // сообщение о завершении программы
		//
		PostQuitMessage(0); // посылка сообщения WM_QUIT
		break;
	default:
		// все сообщения, которые не обрабатываются в данной оконной функции 
		// направляются обратно Windows на обработку по умолчанию
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}
	return 0;
}