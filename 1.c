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
	char grade = 0;            //�ȼ�ͳ��
	scoreall = (((*stu).usualScore) * 0.3 )+ (((*stu).interimScore) * 0.3) + (((*stu).finalScore) * 0.4);  //�����ɼ�����
	if (scoreall <= 100 && scoreall >= 90) {
		grade = 'A';
	} else if (scoreall <= 89 && scoreall >= 80) {
		grade = 'B'; 
	} else if (scoreall <= 79 && scoreall >= 70) {
		grade = 'C';
	} else if (scoreall <= 69 && scoreall >= 60) {
		grade = 'D';
	} else if (scoreall <= 59 && scoreall >= 0) {
		grade = 'E';
	}
	(*stu).overallScore = scoreall;
	(*stu).overallGrade = grade;
}
��3���ú���grade()ʵ�ֶԸð༶ÿ��ѧ���������ɼ����㲢���еȼ�ͳ�ƣ�
90-100��Ϊ��A����80-89��Ϊ��B����70-79��Ϊ��C����60-69��Ϊ��D����0-59��Ϊ��E����
main(){
	int count=0;
	struct student info[30];
	struct student *p;
	p = &info;
	while(count < 30){                   //�����2���޷��˳�ѭ�����������������ѭ��ͳ�Ʒ�Χ
		printf("(strcmp(info[%d].name,\"-1\"): %d\n",count, strcmp(info[1].name,"-1"));
		printf("Name:");
		scanf("%s",&info[1].name);      //�����1�����Ͳ��������������%c���滻Ϊ%s
		if (strcmp(info[1].name,"-1") != 0) {      //strcmp�ж��ı��Ƿ���ȣ������ʱ����0
			printf("Number:");
			scanf("%d",&info[1].id);
			printf("usualScore:");
			scanf("%d",&info[1].usualScore);
			printf("interimScore:");
			scanf("%d",&info[1].interimScore);
			printf("finalScore:");
			scanf("%d",&info[1].finalScore);
			count++;
			printf("%d",count);
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
}
