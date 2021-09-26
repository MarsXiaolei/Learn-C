#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// 常规
struct StudentInfo{
    char            name[32];
    char            sex[16];
    unsigned int    age;
}studentInfo = {"xiaolei", "male", 26};

/// 不能再定义变量
//struct{
//    char            name[32];
//    char            sex[16];
//    unsigned int    age;
//}studentInfo = {"xiaolei", "male", 26};

typedef struct _TeacherInfo{
    char            name[32];
    char            sex[16];
    unsigned int    age;
}TeacherInfo, *pTeacherInfo;

struct WorkerInfo{
    char            *name;
    char            sex[16];
    unsigned int    age;
};

typedef struct
{
    char            name[32];
    char            sex[16];
    unsigned int    age;
}BankStaffInfo;

void out_student_info(struct StudentInfo *info)
{
    printf("name  = %s\n", info->name);
    printf("sex  = %s\n", info->sex);
    printf("age  = %d\n", info->age);
}

void out_teacher_info(struct _TeacherInfo *info)
{
    printf("name  = %s\n", info->name);
    printf("sex  = %s\n", info->sex);
    printf("age  = %d\n", info->age);
}

void out_worker_info(const struct WorkerInfo *info)
{
    //info->age = 18; 结构体只读，不可修改，否则报错
    printf("name  = %s\n", info->name);
    printf("sex  = %s\n", info->sex);
    printf("age  = %d\n", info->age);
}

int main()
{
    //[0x01] 常规结构
    out_student_info(&studentInfo);

    printf("\n");
    struct StudentInfo info;
    strcpy(info.name, "A");
    strcpy(info.sex, "male");
    info.age = 78;
    out_student_info(&info);

    //[0x02] typedef 结构
    printf("\n");
    struct _TeacherInfo info_1;
    strcpy(info_1.name, "B");
    strcpy(info_1.sex, "male");
    info_1.age = 78;
    out_teacher_info(&info_1);

    printf("\n");
    TeacherInfo info_2;
    strcpy(info_2.name, "C");
    strcpy(info_2.sex, "male");
    info_2.age = 78;
    out_teacher_info(&info_2);

    //[0x03] 结构体指针
    printf("\n");
    pTeacherInfo info_3 = (pTeacherInfo)malloc(sizeof(TeacherInfo));
    strcpy(info_3->name, "D");
    strcpy(info_3->sex, "male");
    info_3->age = 78;
    out_teacher_info(info_3);

    printf("\n");
    TeacherInfo *info_4 = (TeacherInfo *)malloc(sizeof(TeacherInfo));
    strcpy(info_4->name, "E");
    strcpy(info_4->sex, "male");
    info_4->age = 78;
    out_teacher_info(info_4);

    //[0x05] 结构体内包含指针
    printf("\n");
    struct WorkerInfo info_5;
    info_5.name = (char *)malloc(sizeof(char));
    strcpy(info_5.name, "F");
    strcpy(info_5.sex, "male");
    info_5.age = 78;
    out_worker_info(&info_5);
    printf("info_5.age = %d\n",info_5.age);

    /// 释放内存
    free(info_3);
    info_3 = NULL;

    free(info_4);
    info_4 = NULL;

    free(info_5.name);
    info_5.name = NULL;

    return 0;
}
