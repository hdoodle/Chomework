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
	} else if (scoreall <= 89 && scoreall >= 80) {
		gradescore = 'B'; 
	} else if (scoreall <= 79 && scoreall >= 70) {
		gradescore = 'C';
	} else if (scoreall <= 69 && scoreall >= 60) {
		gradescore = 'D';
	} else if (scoreall <= 59 && scoreall >= 0) {
		gradescore = 'E';
	}
	(*stu).overallScore = scoreall;
	(*stu).overallGrade = gradescore;
	//printf("%f,%c\n",(*stu).overallScore,(*stu).overallGrade);      //�������ָ��ָ������
	//��3���ú���grade()ʵ�ֶԸð༶ÿ��ѧ���������ɼ����㲢���еȼ�ͳ�ƣ�
    //90-100��Ϊ��A����80-89��Ϊ��B����70-79��Ϊ��C����60-69��Ϊ��D����0-59��Ϊ��E����
}
main(){
	int count=0;
	struct student info[30];
	struct student *p;
	p = &info;
	while(count < 30){                   //�����2���޷��˳�ѭ�����������������ѭ��ͳ�Ʒ�Χ
		printf("(strcmp(info[%d].name,\"-1\"): %d\n",count, strcmp(info[1].name,"-1"));
		printf("Name:");
		scanf("%s",info[count].name);      //�����1�����Ͳ��������������%c���滻Ϊ%s  //�����2��info[count].name�Ѿ�Ϊ��ַ������Ҫ��&���š�
		if (strcmp(info[count].name,"-1") != 0) {      //strcmp�ж��ı��Ƿ���ȣ������ʱ����0
			printf("Number:");
			scanf("%d",&info[count].id);
			printf("usualScore:");
			scanf("%d",&info[count].usualScore);
			printf("interimScore:");
			scanf("%d",&info[count].interimScore);
			printf("finalScore:");
			scanf("%d",&info[count].finalScore);
			
			printf("%d",count);
			grade(p+count);
			printf("*****%f,%c*****",info[count].overallScore,info[count].overallGrade);
			count++;                      //�����3������++�ڴ�ӡprintf()ǰ�棬������ӡ��һ�����ݵ���������ʾ����
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
