
// MFCApplication2Dlg.cpp : файл реализации
//

#include "stdafx.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#define _USE_MATH_DEFINES
#include "math.h"
#include "Resource.h"

#include <initguid.h>

DEFINE_GUID(imageFormatBMP, 0xb96b3cab, 0x0728, 0x11d3, 0x9d, 0x7b, 0x00, 0x00, 0xf8, 0x1e, 0xf3, 0x2e);


#define ID_TIMERA 1

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CMFCApplication2Dlg

// Обработчики сообщений CMFCApplication2Dlg

CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
	, m_R(1), m_f(1), m_r(1)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_EDIT_A, m_EditA); 
	DDX_Control(pDX, IDC_EDIT_2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT_3, m_Edit3);
	DDX_Control(pDX, IDC_SLIDER1, m_SliderSc);
	DDX_Control(pDX, IDC_STATIC_SCALE, m_StaticScale);
	DDX_Control(pDX, IDC_STATIC_HINT, m_StaticHint);

	
}


BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT_A, &CMFCApplication2Dlg::OnEnChangeEditA)
	ON_EN_CHANGE(IDC_EDIT_2, &CMFCApplication2Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT_3, &CMFCApplication2Dlg::OnEnChangeEdit3)
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_ANIME, &CMFCApplication2Dlg::OnBnClickedBtnAnime)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication2Dlg::OnBnClickedCancel)
	ON_CBN_SELCHANGE(IDC_COMBO_COL, &CMFCApplication2Dlg::OnCbnSelchangeComboCol)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER1, &CMFCApplication2Dlg::OnNMCustomdrawSlider1)
	

ON_BN_CLICKED(IDC_BTN_INSERT_F, &CMFCApplication2Dlg::OnBnClickedBtnInsertF)
END_MESSAGE_MAP()


// обработчики сообщений CMFCApplication2Dlg

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_SliderSc.SetRange(-2, 2);    // Диапазон значений от 1 до 10
	m_SliderSc.SetPos(0);           // Начальное положение ползунка
	m_SliderSc.SetTicFreq(1);       // Деления через каждую единицу



	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	m_rotationAngle = 0.0;

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
		
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	m_artist.SubclassDlgItem(IDD_CARTIST, this);
	CRect rc;
	m_artist.GetClientRect(&rc);
	m_Trans.SetTransParam(rc.Width(), rc.Height());
	m_artist.SetIdataPtr(this);
	bCreated = true;
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);

		CRgn clipRgn;
		clipRgn.CreateRectRgnIndirect(&rect);

		// Ограничиваем область рисования
		dc.SelectClipRgn(&clipRgn);

	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication2Dlg::OnCancel()
{
	// Здесь можно добавить дополнительные действия перед закрытием
	CDialogEx::OnCancel();  // Закрывает диалог
}


// Обработчик события изменения текста в поле ввода EditA
void CMFCApplication2Dlg::OnEnChangeEditA()
{
	UpdateData();
	CString strR;                        // Создать строку для хранения текста
	m_EditA.GetWindowTextW(strR);        // Получить текст из поля ввода
	m_R = _wtof(strR);                   // Преобразовать строку в число с плавающей точкой
	Calc();                              // Вычислить новые точки            
	m_artist.RedrawWindow(nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW | RDW_ALLCHILDREN); // Перерисовать окно (+ ещё несколько флагов)
	UpdateHintText(); 
}

// Метод для получения точек
size_t CMFCApplication2Dlg::GetPoints(std::vector<CPoint>& vecPt)
{
	vecPt = m_vecPt;                    // Скопировать вектор точек
	return m_vecPt.size();              // Вернуть количество точек
}

// Метод для вычисления точек
bool CMFCApplication2Dlg::Calc()
{
	m_vecPt.clear();                    // Очистить вектор точек
	CRect rc;                           // Создать клиентскую область (прямоугольник)
	m_artist.GetClientRect(&rc);        // Получить размеры клиентской области

	//Задать шаг, с которым будут откладываться точки графика, равный 1 пикселю:

	int pixelsPerCycle = rc.Width(); //получить длину клиентской области
	
	double f_max = 2 * M_PI * m_R/m_r;
	// Вычислить максимальное значение параметра f, как бы "длинны линии, которой нарисован график" (то, при котором гипоциклоида замыкается).

	double step = f_max / pixelsPerCycle;
	// Рассчитать шаг по параметру f таким образом, чтобы каждый шаг f соответствовал примерно одному пикселю по ширине.

	// Цикл для вычисления этих точек
	for (double X = 0.; X < m_f; X += step)
	{
		CPoint pt = m_Trans.GetPoint(m_R, X, m_r);  // Применить функцию GetPoint (преобразование и выравнивание по центру) к полю m_Trans класса  
		// Преобразуем в double, т.к. CPoint — целочисленный
		double x = pt.x;
		double y = pt.y;

		// Применим поворот вокруг начала координат (0,0)
		double cosA = cos(m_rotationAngle);
		double sinA = sin(m_rotationAngle);

		double xRot = x * cosA - y * sinA;
		double yRot = x * sinA + y * cosA;

		//m_vecPt.push_back(pt);                     // Добавить точку в вектор

		// Сохраняем обратно как целую точку
		m_vecPt.push_back(CPoint((int)xRot, (int)yRot));

		
	}

	return m_vecPt.size() > 0;                     // Вернуть true, если точки есть
}

// Обработчик изменения размера диалогового окна
void CMFCApplication2Dlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);              // Вызвать базовый метод

	if (bCreated)                                   // Если окно уже создано...
	{
		CRect rc;                                   // ... то нужно создать прямоугольник
		m_artist.GetClientRect(&rc);               //... и получить его размеры

		// Установить параметры преобразования
		m_Trans.SetTransParam(rc.Width(), rc.Height());
		Calc();           // Вычислить новые точки

		

	}
		}



// Интерфейсный метод для получения точек
size_t CMFCApplication2Dlg::IGetPoints(std::vector<CPoint>& vec)
{
	return GetPoints(vec);                         // Вызвать основной метод получения точек
}





void CMFCApplication2Dlg::OnEnChangeEdit2() // Обработчик события изменения текста в поле ввода Edit2 (по аналогии с EditA)
{
	UpdateData();
	CString str_F;
	m_Edit2.GetWindowTextW(str_F);
	m_f = _wtof(str_F);
	Calc();

	m_artist.RedrawWindow(nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);

	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the __super::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CMFCApplication2Dlg::OnEnChangeEdit3() // Обработчик события изменения текста в поле ввода Edit3 (по аналогии с EditA)
{
	UpdateData();
	CString str_r;
	m_Edit3.GetWindowTextW(str_r);
	m_r = _wtof(str_r);
	Calc();

	m_artist.RedrawWindow(nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
	UpdateHintText();
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the __super::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}



void CMFCApplication2Dlg::OnTimer(UINT_PTR nIDEvent)
{
		m_rotationAngle += 0.03; // шаг поворота (чем меньше — тем плавнее)
		Calc(); // пересчитываем точки с новым углом
		m_artist.RedrawWindow(nullptr, nullptr, RDW_INVALIDATE | RDW_ERASE | RDW_UPDATENOW | RDW_ALLCHILDREN);
		// Вызов реализации базового класса
		__super::OnTimer(nIDEvent);
	}


void CMFCApplication2Dlg::OnBnClickedBtnAnime()
{
	// Получить указатель на кнопку по её ID
	// GetDlgItem возвращает базовый указатель CWnd, поэтому требуется приведение типа
	CButton* pB = (CButton*)GetDlgItem(IDC_BTN_ANIME);

	// Проверить, что кнопка найдена корректно
	if (pB)
	{
		// Проверить состояние кнопки (включена/выключена)
		if (pB->GetCheck())
		{
			// Если кнопка включена, запустить таймер
			// ID_TIMERA - идентификатор таймера
			// 40 - интервал в миллисекундах (25 кадров в секунду)
			// nullptr - указатель на функцию обратного вызова (использовать дефолтное поведение)
			SetTimer(ID_TIMERA, 40, nullptr);
		}
		else
		{
			// Если кнопка выключена, остановить таймер
			KillTimer(ID_TIMERA);
		}
	}
}


void CMFCApplication2Dlg::OnBnClickedCancel()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCApplication2Dlg::OnCbnSelchangeComboCol()
{
	// Получение указателя на элемент управления ComboBox
	// Приведение базового указателя к конкретному типу
	CComboBox* pCmb = (CComboBox*)GetDlgItem(IDC_COMBO_COL);

	// Проверка корректности полученного указателя
	if (pCmb)
	{
		// Получение текущего выбранного индекса в ComboBox
		int nSel = pCmb->GetCurSel();

		// Инициализация переменной для хранения цвета
		COLORREF col = 0;

		// Определение цвета в зависимости от выбранного индекса
		switch (nSel)
		{
		case 0: col = RGB(135, 206, 235); break; //Аквамарин
		case 1: col = RGB(0, 0, 150); break; //Темный ультрамариновый
		case 2: col = RGB(129, 216, 208); break; //Городское небо (Пасмурно-небесный)
		}

		// Установка нового цвета фона для объекта m_artist
		m_artist.SetBkColor(col);

		// Перерисовка окна для отображения изменений
		m_artist.RedrawWindow();
	}
}

void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// Отключить перерисовку для оптимизации
	m_artist.SetRedraw(FALSE);

	// Очистить вектор точек
	m_vecPt.clear();

	// Включить перерисовку и обновить окно
	m_artist.SetRedraw(TRUE);
	m_artist.RedrawWindow();
}


void CMFCApplication2Dlg::OnBnClickedButton2()
{
	// Создание объекта памяти для работы с графическим контекстом
	CDC MemDc;

	// Создание объекта для работы с растровым изображением
	CBitmap BitMap;

	// Получение графического контекста окна
	CDC* pDca = m_artist.GetDC();

	// Создание совместимого графического контекста для буфера
	MemDc.CreateCompatibleDC(pDca);

	// Получение размеров клиентской области окна
	CRect rc;
	m_artist.GetClientRect(&rc);

	// Создание совместимого растрового объекта с размерами клиентской области
	BitMap.CreateCompatibleBitmap(pDca, rc.Width(), rc.Height());

	// Сохранение текущего выбранного объекта в памяти и загрузка нового растрового объекта
	HGDIOBJ ob = MemDc.SelectObject(&BitMap);

	// Копирование содержимого окна в растровый объект
	MemDc.BitBlt(0, 0, rc.Width(), rc.Height(), pDca, 0, 0, SRCCOPY);

	// Освобождение графического контекста окна
	m_artist.ReleaseDC(pDca);

	// Восстановление предыдущего выбранного объекта в памяти
	MemDc.SelectObject(ob);

	// Настройка фильтра для диалога сохранения файлов
	static wchar_t szFilter[] = _T("BMP files (*.bmp)|.bmp||");

	// Создание диалога сохранения файла
	CFileDialog dlg(FALSE, _T("bmp"), NULL, 6, szFilter);

	// Обработка выбора пользователя
	if (IDOK == dlg.DoModal())
	{
		// Создание объекта изображения
		CImage image;

		// Привязка растрового объекта к изображению
		image.Attach(HBITMAP(BitMap));

		// Получение полного пути к файлу
		CString strFull = dlg.GetOFN().lpstrFile;

		// Сохранение изображения в файл
		HRESULT hr = image.Save(strFull, imageFormatBMP);
	}

	// Отображение сообщения об успешном сохранении
	AfxMessageBox(L"Файл сохранен успешно!");

	}


void CMFCApplication2Dlg::OnNMCustomdrawSlider1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// Преобразовать указатель в нужный тип
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);

	// Получить текущее положение слайдера
	double nPos = m_SliderSc.GetPos();

	// Установить новый масштаб
	m_Trans.SetScale(nPos);

	// Обновить перерисовку и пересчитать точки
	m_artist.SetRedraw(FALSE);
	Calc();
	m_artist.SetRedraw(TRUE);
	m_artist.RedrawWindow();

	// Обновить текст с текущим масштабом
	CString str;
	str.Format(L"Масштаб: %.2fx", nPos);
	m_StaticScale.SetWindowTextW(str);

	// Установить результат обработки
	*pResult = 0;
}

// Функция для вычисления наибольшего общего делителя (НОД)

int gcd(int a, int b)
{
	// Если b равно 0, НОД равен a
	// Иначе вызываем функцию рекурсивно с параметрами (b, остаток от деления a на b)
	return b == 0 ? a : gcd(b, a % b);
}

// Метод обновления подсказки для пользователя
void CMFCApplication2Dlg::UpdateHintText()
{
	// Преобразуем значения R и r из double в int
	int R_int = static_cast<int>(m_R);
	int r_int = static_cast<int>(m_r);

	// Проверяем, что оба значения не равны нулю
	if (R_int == 0 || r_int == 0)
	{
		// Если одно из значений равно нулю, выводим сообщение об ошибке
		m_StaticHint.SetWindowTextW(L"Введите ненулевые значения R и r");
		return;
	}

	//условие замкнутости гипоциклоиды
	double f = 2 * M_PI * m_r /gcd(m_r, m_R);

	// Формируем строку подсказки
	CString str;
	str.Format(L"Чтобы график был замкнутым, введите f = %.2f", f);

	// Устанавливаем текст подсказки
	m_StaticHint.SetWindowTextW(str);

	// Сохраняем вычисленное значение f для последующего использования
	m_autoF = f;
}

void CMFCApplication2Dlg::OnBnClickedBtnInsertF()
{
	CString strF;
	strF.Format(L"%.2f", m_autoF); // округляем до 2 знаков
	m_Edit2.SetWindowTextW(strF); // вставляем в поле ввода f
	OnEnChangeEdit2(); // принудительно обновляем график

	// TODO: добавьте свой код обработчика уведомлений
}
