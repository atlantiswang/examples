#include "stdafx.h"
#include "resource.h"
HINSTANCE g_hInstance=0;
INT CALLBACK DlgProc(HWND hwndlg,UINT msg,
						WPARAM wParam,LPARAM lParam)
{
	switch(msg)
	{
	case WM_INITDIALOG:
		MessageBox(hwndlg,"WM_INITDIALOG","infor",MB_OK);
		break;
	case WM_CREATE:
		MessageBox(hwndlg,"WM_CREATE","infor",MB_OK);
		break;
	case WM_SYSCOMMAND:
		if(wParam == SC_CLOSE)
		{
			//����ģʽ�Ի���,ֻ����EndDialog,������DestroyWindow�Ⱥ���
			//��Ȼ�����ٶԻ��򣬵�����ʹDIALOGBOX�����������
			EndDialog(hwndlg,1001);
			return true;
		}
		break;
	}
	//����Ϣ���������Ի�����������Ĭ�ϴ���
	return FALSE;
}
void OnModel(HWND hWnd)
{
	//��������
	int nRet = DialogBox(g_hInstance,
		MAKEINTRESOURCE(IDD_DIALOG1),hWnd,DlgProc);
	if(nRet == 1001)
		MessageBox(hWnd,"successful","infor",MB_OK);
}
void OnCommand(HWND hWnd,WPARAM wParam)
{
	switch(LOWORD(wParam))
	{
	case ID_MODEL:
		OnModel(hWnd);//����ģʽ�Ի���
		break;
	}
}
//���ڴ�������
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg,
						 WPARAM wParam,LPARAM lParam)
{
	switch(msg)
	{
	case WM_COMMAND:
		OnCommand(hWnd,wParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd,msg,wParam,lParam);
}
BOOL Register(LPSTR lpClassName,WNDPROC WndProc)
{
	WNDCLASSEX wce={0};
	wce.cbSize=sizeof(wce);
	wce.cbClsExtra=0;
	wce.cbWndExtra=0;
	wce.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	wce.hCursor=NULL;
	wce.hIcon=NULL;
	wce.hIconSm=NULL;
	wce.hInstance=g_hInstance;
	wce.lpfnWndProc=WndProc;
	wce.lpszClassName=lpClassName;
	wce.lpszMenuName=MAKEINTRESOURCE(IDR_MENU1);
	wce.style=CS_HREDRAW | CS_VREDRAW;
	ATOM nAtom=RegisterClassEx(&wce);//ע������
	if(nAtom==0)
		return FALSE;
	return TRUE;
}
HWND CreateMain(LPSTR lpClassName,LPSTR lpWndName)
{
	HWND hWnd=CreateWindowEx(0,lpClassName,lpWndName,
							WS_OVERLAPPEDWINDOW,
							CW_USEDEFAULT,CW_USEDEFAULT,
							CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,
							g_hInstance,NULL);
	return hWnd;
}
//��ʾ����
void Display(HWND hWnd)
{
	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);
}
//��Ϣѭ��
void Message()
{
	MSG nMsg={0};
	while(GetMessage(&nMsg,NULL,0,0))
	{
		TranslateMessage(&nMsg);
		DispatchMessage(&nMsg);
	}
}
int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	g_hInstance=hInstance;
	Register("Main",WndProc);
	HWND hWnd=CreateMain("Main","window");
	Display(hWnd);
	Message();
	return 0;
}


