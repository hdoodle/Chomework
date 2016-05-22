#include<stdio.h>
#include<string.h>
#define NUM 30   /*班级人数宏定义，使用链表可动态开辟存储空间，无需此项设置*/
struct student{         /*结构体类型*/
    char name[15];      //姓名
    int id;             //学号
    int usualScore;     //平时分数
    int interimScore;   //期中分数
    int finalScore;     //期末分数
    float overallScore; //总评成绩
    char overallGrade;  //总评分级
};
void grade(struct student *stu){ /*实现总评成绩计算和等级统计*/
	float scoreall = 0,temp = 0;        //总评成绩
	char gradescore = 0;            //等级统计
	scoreall = (((*stu).usualScore) * 0.3 )+ (((*stu).interimScore) * 0.3) + (((*stu).finalScore) * 0.4);  //总评成绩计算
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
	//printf("%f,%c\n",(*stu).overallScore,(*stu).overallGrade);      //调试输出指针指向内容
	//（3）用函数grade()实现对该班级每个学生的总评成绩计算并进行等级统计：
    //90-100分为“A”、80-89分为“B”、70-79分为“C”、60-69分为“D”、0-59分为“E”；
}
main(){
	int count=0,numberall=0,printgrade[5]={0};
	struct student info[30];
	struct student *p;
	p = &info;
	printf("学生成绩汇总与统计\n");
	printf("输入“-1”退出\n\n");
	while(count < 30){                   //问题点2，无法退出循环，解决方案：超过循环统计范围
		//printf("(strcmp(info[%d].name,\"-1\"): %d\n",count, strcmp(info[1].name,"-1"));
		printf("请输入第%d位同学成绩：\n",count+1);
		printf("姓名：");
		scanf("%s",info[count].name);      //问题点1，类型不符，解决方案：%c被替换为%s  //问题点2，info[count].name已经为地址，不需要加&符号。
		if (strcmp(info[count].name,"-1") != 0) {      //strcmp判断文本是否相等，当相等时返回0
			printf("学号：");
			scanf("%d",&info[count].id);
			printf("平时成绩：");
			scanf("%d",&info[count].usualScore);
			printf("期中成绩：");
			scanf("%d",&info[count].interimScore);
			printf("期末成绩：");
			scanf("%d",&info[count].finalScore);
			printf("\n");
			//printf("%d",count);
			grade(p+count);
			//printf("*****%f,%c*****",info[count].overallScore,info[count].overallGrade);
			count++;                      //问题点3，不能++在打印printf()前面，否则会打印下一条内容导致数据显示错误。
			numberall = count;
		} else {
			count = 30;                            //当相等时，超出count循环变量范围，退出循环
		}
	}
  //for(i=0;i<NUM;i++){
       /*读入每个学生的相关信息*/
   /*调用grade()函数实现总评成绩计算和等级及其人数统计*/
  //}
  /*输出学生的姓名、学号、平时、期中、期末、总评成绩和等级*/
/*输出每个等级的学生人数*/
	//输出部分开始
	numberall--;
	printf("\n");
	printf("------------------------------------------------------------------------\n");
	printf("姓名      学号      平时成绩  期中成绩  期末成绩  总评成绩  总评成绩等级\n");
	printf("------------------------------------------------------------------------\n");
	//printf("\n%d,%d\n",count,numberall);
	for (count = 0; count <= numberall; count++){
		//printf("%d,%d",count,numberall);
		printf("%-10s%-10d%-10d%-10d%-10d%-10.2f%c\n",info[count].name,info[count].id,info[count].usualScore,\
		info[count].interimScore,info[count].finalScore,info[count].overallScore,info[count].overallGrade);
	}
	printf("------------------------------------------------------------------------\n");
	count=0;
	//printf("循环输出1%d\n",printgrade[4]);
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
			//printf("循环输出%5d\n",printgrade[4]);
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
