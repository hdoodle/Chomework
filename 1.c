#include<stdio.h>
#include<string.h>
#define NUM 30   /*�༶�����궨�壬ʹ������ɶ�̬���ٴ洢�ռ䣬�����������*/
struct student{         /*�ṹ������*/
    char name[15];      //����
    int id;             //ѧ��
    int usualScore;     //ƽʱ����
    int interimScore;   //���з���
    int finalScore;     //��ĩ����
    float overallScore; //�����ɼ�
    char overallGrade;  //�����ּ�
};
void grade(struct student *stu){ /*ʵ�������ɼ�����͵ȼ�ͳ��*/
	float scoreall = 0,temp = 0;        //�����ɼ�
	char gradescore = 0;            //�ȼ�ͳ��
	scoreall = (((*stu).usualScore) * 0.3 )+ (((*stu).interimScore) * 0.3) + (((*stu).finalScore) * 0.4);  //�����ɼ�����
	if (scoreall <= 100 && scoreall >= 90) {
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
	//printf("%f,%c\n",(*stu).overallScore,(*stu).overallGrade);      //�������ָ��ָ������
	//��3���ú���grade()ʵ�ֶԸð༶ÿ��ѧ���������ɼ����㲢���еȼ�ͳ�ƣ�
    //90-100��Ϊ��A����80-89��Ϊ��B����70-79��Ϊ��C����60-69��Ϊ��D����0-59��Ϊ��E����
}
main(){
	int count=0,numberall=0,printgrade[5]={0};
	struct student info[30];
	struct student *p;
	p = &info;
	printf("ѧ���ɼ�������ͳ��\n");
	printf("���롰-1���˳�\n\n");
	while(count < 30){                   //�����2���޷��˳�ѭ�����������������ѭ��ͳ�Ʒ�Χ
		//printf("(strcmp(info[%d].name,\"-1\"): %d\n",count, strcmp(info[1].name,"-1"));
		printf("�������%dλͬѧ�ɼ���\n",count+1);
		printf("������");
		scanf("%s",info[count].name);      //�����1�����Ͳ��������������%c���滻Ϊ%s  //�����2��info[count].name�Ѿ�Ϊ��ַ������Ҫ��&���š�
		if (strcmp(info[count].name,"-1") != 0) {      //strcmp�ж��ı��Ƿ���ȣ������ʱ����0
			printf("ѧ�ţ�");
			scanf("%d",&info[count].id);
			printf("ƽʱ�ɼ���");
			scanf("%d",&info[count].usualScore);
			printf("���гɼ���");
			scanf("%d",&info[count].interimScore);
			printf("��ĩ�ɼ���");
			scanf("%d",&info[count].finalScore);
			printf("\n");
			//printf("%d",count);
			grade(p+count);
			//printf("*****%f,%c*****",info[count].overallScore,info[count].overallGrade);
			count++;                      //�����3������++�ڴ�ӡprintf()ǰ�棬������ӡ��һ�����ݵ���������ʾ����
			numberall = count;
		} else {
			count = 30;                            //�����ʱ������countѭ��������Χ���˳�ѭ��
		}
	}
  //for(i=0;i<NUM;i++){
       /*����ÿ��ѧ���������Ϣ*/
   /*����grade()����ʵ�������ɼ�����͵ȼ���������ͳ��*/
  //}
  /*���ѧ����������ѧ�š�ƽʱ�����С���ĩ�������ɼ��͵ȼ�*/
/*���ÿ���ȼ���ѧ������*/
	//������ֿ�ʼ
	numberall--;
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("����      ѧ��      ƽʱ�ɼ�  ���гɼ�  ��ĩ�ɼ�  �����ɼ�  �����ɼ��ȼ�\n");
	printf("------------------------------------------------------------------------\n");
	//printf("\n%d,%d\n",count,numberall);
	for (count = 0; count <= numberall; count++){
		//printf("%d,%d",count,numberall);
		printf("%-10s%-10d%-10d%-10d%-10d%-10.2f%c\n",info[count].name,info[count].id,info[count].usualScore,\
		info[count].interimScore,info[count].finalScore,info[count].overallScore,info[count].overallGrade);
	}
	printf("------------------------------------------------------------------------\n");
	count=0;
	//printf("ѭ�����1%d\n",printgrade[4]);
	while(count <= numberall) {
		if (info[count].overallScore <= 100 && info[count].overallScore >= 90) {
			printgrade[0]++;
		} else if (info[count].overallScore < 90 && info[count].overallScore >= 80) {
			printgrade[1]++;
		} else if (info[count].overallScore < 80 && info[count].overallScore >= 70) {
			printgrade[2]++;
		} else if (info[count].overallScore < 70 && info[count].overallScore >= 60) {
			printgrade[3]++;
		} else if (info[count].overallScore < 60 && info[count].overallScore >= 0) {
			//printf("ѭ�����%5d\n",printgrade[4]);
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
