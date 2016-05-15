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
	char grade = 0;            //等级统计
	scoreall = (((*stu).usualScore) * 0.3 )+ (((*stu).interimScore) * 0.3) + (((*stu).finalScore) * 0.4);  //总评成绩计算
	
}
main(){
	int count=0;
	struct student info[30];
	struct student *p;
	p = &info;
	while(count < 30){                   //问题点2，无法退出循环，解决方案：超过循环统计范围
		printf("(strcmp(info[%d].name,\"-1\"): %d\n",count, strcmp(info[1].name,"-1"));
		printf("Name:");
		scanf("%s",&info[1].name);      //问题点1，类型不符，解决方案：%c被替换为%s
		if (strcmp(info[1].name,"-1") != 0) {      //strcmp判断文本是否相等，当相等时返回0
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
			count = 30;                            //当相等时，超出count循环变量范围，退出循环
		}
	}
  //for(i=0;i<NUM;i++){
       /*读入每个学生的相关信息*/
   /*调用grade()函数实现总评成绩计算和等级及其人数统计*/
  //}
  /*输出学生的姓名、学号、平时、期中、期末、总评成绩和等级*/
/*输出每个等级的学生人数*/
}
