#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <windows.h> 

//����ȫ��������ֱ�ӵ��ü���
void FullScreen(){ 

HWND hwnd=GetForegroundWindow();
int x=GetSystemMetrics(SM_CXSCREEN)+300,y=GetSystemMetrics(SM_CYSCREEN)+300;
char setting[30];
sprintf(setting,"mode con:cols=%d lines=%d",x,y);//���ÿ���̨��������
system(setting); 

SetWindowPos(hwnd, HWND_TOPMOST,0,0,x+300,y+300,NULL);//�ö�


MoveWindow(hwnd,-10,-40,x+300,y+300,1);//�ƶ�
printf("\n\n");
}

int main(void)
{
	int choice=2016;
	//char su[80]={"busybox\ndate\nsu\nexit"};
	//char so[80]={"\n"};
	//char *psu=su;
	
	system("color 4E");
	system("title �쾯2������ 1.0");
	system("mode con cols=39 lines=20");    
	
	//printf("ָ�����%s\n",psu);
	//puts(su);
	
	while (choice != 0)
	{
	int choice=2016;
	system("cls");
	printf("�X�T�T�T�T�k�T�T�T�T�T�T�T�k�T�T�T�T�[\n");
    printf("�U��           ��ɫ����2          ���U\n");
    printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
	//����
	//printf("\n��������������:\n");
	printf("          1. ���� �쾯2\n");
	printf("          2. ���� ����ĸ���\n");
	printf("\n");
	printf("          3. ���� �쾯2\n");
	printf("          4. ���� ����ĸ��� \n");
	printf(" \n");
	printf("          9. ��������� \n");
	printf("          0. �˳�\n");
	printf("  �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T  \n");
	//ѡ��
		//����ѡ��
		
		printf("\n           ��ѡ��:");
		scanf("%d",&choice);
		system("cls");
		
		//�жϲ�ִ�� ��switch
		 switch (choice)
		 {
		 	case 1:
		    system("start ra2.exe -speedcontrol");
		 	break;
		 	
		 	case 11:
		    system("start ra2.exe -win -speedcontrol");
		 	break;
		 	
		 	case 2:
		 	system("start ra2md.exe -speedcontrol");
		 	break;
		 	
		 	case 22:
		 	system("start ra2md.exe -win -speedcontrol");
		 	break;
		 	
		 	case 3:
		 	system("taskkill /f /im ra2.exe");
		 	system("taskkill /f /im game.exe");
		 	break;
		 	
		 	case 4:
		 	system("taskkill /f /im ra2md.exe");
		 	system("taskkill /f /im gamemd.exe");
		 	break;
		 	
		 	case 9:
		 	system("cls");
		    printf("  �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
	        printf("               ���������           \n");
	        printf("  �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
	        printf("  �Ѵ˳�����ں쾯2�ļ����ڡ�\n");
	        printf("  �����Թ���Ա������д˳���\n");
	        printf("  ����ģʽ��Ҫ������ɫ���Ϊ16λɫ��\n");
	        printf("  ��������Ϸ�������п��Ե��١�\n");
	        printf("\n");
	        printf("  ������ָ��:\n");
	        printf("  \"11\"��\"22\"��������ģʽ\n");
	        printf("  \"233\" ��������\"Matrix\"\n");
	        //printf("   \"s\"�� \"r\"�����ػ�/����\n");
	        printf("\n");
	        printf("  �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
	        system("pause");
			break; 
			
			case 233:
        	system("title ȫ��");
        	FullScreen();
        	system("date /T");
        	system("TIME /T");
        	system("color 0A");
            printf("�X�T�T�T�T�k�T�T�T�T�T�T�T�k�T�T�T�T�[\n");
            printf("�U��        ��������ѡ��!!        ���U\n");
            printf("�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
            system("color 0A");
            printf("           ��������������:");
            sleep(1); 
            system("color 09");sleep(1); 
            system("color 0C");sleep(1); 
            system("color 0A");
            scanf("%ld",&choice);
            there: printf("%ld   ",++choice);
	        goto there;
			break;
			
			case 0:
			system("cls");
	        printf("���������");
        	return 0;
        	break;
				
			default :
			printf("  �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
			printf("                δѡ��            \n");
			printf("  �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
			sleep(1); 
			break;
		 }
		
		//printf("ѡ����: %d",choice);
	}
	
	//��������


	return 0;
}


