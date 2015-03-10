// Файл WINDOWS.H содержит определения, макросы, и структуры 
// которые используются при написании приложений под Windows. 
#include <iostream>
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <vector>
#include <time.h>

// прототип оконной процедуры
LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

TCHAR szClassWindow[] = TEXT("Угадайка");	/* Имя класса окна */


std::vector<TCHAR*>x{ TEXT(" Хочешь сыграть в игру"), TEXT("Загадай любое число до 10 и нажми Да"), TEXT(" Сыграем еще?") };

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

	srand(time(NULL));
	int count = 0; 
	int res;
	int count_of_try = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (i != x.size() - 1)
		{
			 res=MessageBox(0, x[i], TEXT("Игра в Угадайку"), MB_YESNO | MB_ICONQUESTION);
			 if (res == IDNO){
				 return 0;
			 }
		}
		else{
			TCHAR buf[100];
			count = rand()%10+1;
			wsprintf(buf, TEXT("Ты загадал число: %i"), count);
			int r = MessageBox(0, buf, TEXT("Игра в Угадайку"), MB_YESNO | MB_ICONINFORMATION);
			if (r==IDYES)
			{
				count_of_try++;
				TCHAR buf[100];
				wsprintf(buf, TEXT("Количество попыток: %i"), count_of_try);
				MessageBox(0, TEXT("Ура я угадал!!!"), buf, MB_OK | MB_ICONINFORMATION);
				count_of_try = 0;
			}
			else{
				count_of_try++;
				MessageBox(0, TEXT("Не угадал  :("), TEXT("Игра в Угадайку"), MB_OK | MB_ICONINFORMATION);
			}
			res = MessageBox(0, x[i], TEXT("Игра в Угадайку"), MB_YESNO | MB_ICONQUESTION);
			if (res == IDNO){
				return 0;
			}
			else{
				i = 0;
			}

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