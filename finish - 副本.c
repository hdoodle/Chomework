#include<stdio.h>
#include<string.h>
#define NUM 30                                             //�༶�����궨��
struct student{
    char name[15];                                         //����
    int id;                                                //ѧ��
    int usualScore;                                        //ƽʱ����
    int interimScore;                                      //���з���
    int finalScore;                                        //��ĩ����
    float overallScore;                                    //�����ɼ�
    char overallGrade;                                     //�����ּ�
};
void grade(struct student *stu){                           //ʵ�������ɼ�����͵ȼ�ͳ��
	float scoreall = 0,temp = 0;                           //�����ɼ�
	char gradescore = 0;                                   //�ȼ�ͳ��
	scoreall = (((*stu).usualScore) * 0.3 )+ (((*stu).interimScore) * 0.3) + (((*stu).finalScore) * 0.4);  //�����ɼ�����
	if (scoreall <= 100 && scoreall >= 90) {               //�����ּ�
		gradescore = 'A';
	} else if (scoreall < 90 && scoreall >= 80) {
		gradescore = 'B'; 
	} else if (scoreall < 80 && scoreall >= 70) {
		gradescore = 'C';
	} else if (scoreall < 70 && scoreall >= 60) {
		gradescore = 'D';
	} else if (scoreall < 60 && scoreall >= 0) {
		gradescore = 'E';
	}
	(*stu).overallScore = scoreall;
	(*stu).overallGrade = gradescore;
}
main(){
	int count=0,numberall=0,printgrade[5]={0};
	struct student info[NUM];
	struct student *p;
	p = &info;
	printf("ѧ���ɼ�������ͳ��\n");
	printf("���롰-1���˳�\n\n");
	while(count < NUM){                                    //ѭ������ѧ���ɼ�
		printf("�������%dλͬѧ�ɼ���\n",count+1);
		printf("������");
		scanf("%s",info[count].name);
		if (strcmp(info[count].name,"-1") != 0) {          //strcmp�ж��ı��Ƿ���ȣ������ʱ����0
			printf("ѧ�ţ�");
			scanf("%d",&info[count].id);
			printf("ƽʱ�ɼ���");
			scanf("%d",&info[count].usualScore);
			printf("���гɼ���");
			scanf("%d",&info[count].interimScore);
			printf("��ĩ�ɼ���");
			scanf("%d",&info[count].finalScore);
			printf("\n");
			grade(p+count);                                //�����ɼ�����͵ȼ�ͳ��
			count++;
			numberall = count;                             //ͳ������������
		} else {
			count = 30;                                    //������-1ʱ������countѭ��������Χ���˳�ѭ��
		}
	}
	numberall--;
	//�������
	//�����ϸ��Ϣ
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("����      ѧ��      ƽʱ�ɼ�  ���гɼ�  ��ĩ�ɼ�  �����ɼ�  �����ɼ��ȼ�\n");
	printf("------------------------------------------------------------------------\n");
	for (count = 0; count <= numberall; count++){
		printf("%-10s%-12d%-10d%-10d%-10d%-10.2f%c\n",info[count].name,info[count].id,info[count].usualScore,\
		info[count].interimScore,info[count].finalScore,info[count].overallScore,info[count].overallGrade);
	}
	printf("------------------------------------------------------------------------\n");
	//���ͳ����Ϣ
	count=0;
	while(count <= numberall) {                            //ͳ�Ƶȼ���Ϣ
		if (info[count].overallScore <= 100 && info[count].overallScore >= 90) {
			printgrade[0]++;
		} else if (info[count].overallScore < 90 && info[count].overallScore >= 80) {
			printgrade[1]++;
		} else if (info[count].overallScore < 80 && info[count].overallScore >= 70) {
			printgrade[2]++;
		} else if (info[count].overallScore < 70 && info[count].overallScore >= 60) {
			printgrade[3]++;
		} else if (info[count].overallScore < 60 && info[count].overallScore >= 0) {
			printgrade[4]++;
		}
	count++;
	}
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("�ɼ��ȼ�ΪA(90-100)������Ϊ��%d\n",printgrade[0]);
	printf("�ɼ��ȼ�ΪB(80- 89)������Ϊ��%d\n",printgrade[1]);
	printf("�ɼ��ȼ�ΪC(70- 79)������Ϊ��%d\n",printgrade[2]);
	printf("�ɼ��ȼ�ΪD(60- 69)������Ϊ��%d\n",printgrade[3]);
	printf("�ɼ��ȼ�ΪE(0 - 59)������Ϊ��%d\n",printgrade[4]);
	printf("------------------------------------------------------------------------\n");
}
