#include<stdio.h>
#include<string.h>
#define NUM 30                                             //班级人数宏定义
struct student{
    char name[15];                                         //姓名
    int id;                                                //学号
    int usualScore;                                        //平时分数
    int interimScore;                                      //期中分数
    int finalScore;                                        //期末分数
    float overallScore;                                    //总评成绩
    char overallGrade;                                     //总评分级
};
void grade(struct student *stu){                           //实现总评成绩计算和等级统计
	float scoreall = 0,temp = 0;                           //总评成绩
	char gradescore = 0;                                   //等级统计
	scoreall = (((*stu).usualScore) * 0.3 )+ (((*stu).interimScore) * 0.3) + (((*stu).finalScore) * 0.4);  //总评成绩计算
	if (scoreall <= 100 && scoreall >= 90) {               //总评分级
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
	printf("学生成绩汇总与统计\n");
	printf("输入“-1”退出\n\n");
	while(count < NUM){                                    //循环输入学生成绩
		printf("请输入第%d位同学成绩：\n",count+1);
		printf("姓名：");
		scanf("%s",info[count].name);
		if (strcmp(info[count].name,"-1") != 0) {          //strcmp判断文本是否相等，当相等时返回0
			printf("学号：");
			scanf("%d",&info[count].id);
			printf("平时成绩：");
			scanf("%d",&info[count].usualScore);
			printf("期中成绩：");
			scanf("%d",&info[count].interimScore);
			printf("期末成绩：");
			scanf("%d",&info[count].finalScore);
			printf("\n");
			grade(p+count);                                //总评成绩计算和等级统计
			count++;
			numberall = count;                             //统计总输入条数
		} else {
			count = 30;                                    //当输入-1时，超出count循环变量范围，退出循环
		}
	}
	numberall--;
	//输出部分
	//输出详细信息
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("姓名      学号      平时成绩  期中成绩  期末成绩  总评成绩  总评成绩等级\n");
	printf("------------------------------------------------------------------------\n");
	for (count = 0; count <= numberall; count++){
		printf("%-10s%-12d%-10d%-10d%-10d%-10.2f%c\n",info[count].name,info[count].id,info[count].usualScore,\
		info[count].interimScore,info[count].finalScore,info[count].overallScore,info[count].overallGrade);
	}
	printf("------------------------------------------------------------------------\n");
	//输出统计信息
	count=0;
	while(count <= numberall) {                            //统计等级信息
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
	printf("成绩等级为A(90-100)的人数为：%d\n",printgrade[0]);
	printf("成绩等级为B(80- 89)的人数为：%d\n",printgrade[1]);
	printf("成绩等级为C(70- 79)的人数为：%d\n",printgrade[2]);
	printf("成绩等级为D(60- 69)的人数为：%d\n",printgrade[3]);
	printf("成绩等级为E(0 - 59)的人数为：%d\n",printgrade[4]);
	printf("------------------------------------------------------------------------\n");
}
