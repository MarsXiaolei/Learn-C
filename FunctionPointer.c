/*******************************************************************
 * C语言函数指针和回调函数的使用
 * 参考资料：
 * [0] 《C和指针》
 * [1] https://blog.csdn.net/miao19920101/article/details/75648491
 * [2] https://blog.csdn.net/weixin_47921628/article/details/117688224
 ******************************************************************/
#include <stdio.h>
#include <string.h>

#define ADD_CMD_STRING          "Add"
#define SUBTRACT_CMD_STRING     "Subtract"
#define MULTIPLY_CMD_STRING     "Multiply"
#define DIVIDE_CMD_STRING       "Divide"

int add(int a, int b)
{
    return a+b;
}

int subtract(int a, int b)
{
    return a-b;
}

int multiply(int a, int b)
{
    return a*b;
}

int divide(int a, int b)
{
    return a/b;
}

typedef int (*CallbackFunc)(int a, int b);

struct _FuncList{
    char cmd[16];
    CallbackFunc func;
}S_FuncList;

struct _FuncList funcList[] = {
    {ADD_CMD_STRING, add},
    {SUBTRACT_CMD_STRING, subtract},
    {MULTIPLY_CMD_STRING, multiply},
    {DIVIDE_CMD_STRING, divide}
};

void procFunc(const char *cmd, int a, int b)
{
    unsigned int i = 0 ;
    int result = 0;
    for(;i < sizeof(funcList)/sizeof(S_FuncList);++i)
    {
        if(0 == strcmp(cmd, funcList[i].cmd))
        {
            result = funcList[i].func(a, b);
        }
    }
    printf("cmd = %s    result = %d\n",cmd, result);
}

void procFunc_2(int (*CallbackFunc)(int a, int b), int a, int b)
{
    int result = CallbackFunc(a, b);
    printf("a = %d b = %d result = %d\n",a, b, result);
}

int main()
{
    ///[0x01] 函数指针使用
    CallbackFunc callbackFunc = add;
    printf("%d\n",callbackFunc(1,3));

    callbackFunc = subtract;
    printf("%d\n",callbackFunc(1,3));

    callbackFunc = multiply;
    printf("%d\n",callbackFunc(1,3));

    callbackFunc = divide;
    printf("%d\n",callbackFunc(1,3));

    printf("\n");
    ///[0x02] 回调函数使用
    procFunc_2(multiply, 5, 8);

    printf("\n");
    ///[0x03] 转移表使用
    procFunc(ADD_CMD_STRING, 10, 20);
    procFunc(SUBTRACT_CMD_STRING, 10, 20);
    procFunc(MULTIPLY_CMD_STRING, 10, 20);
    procFunc(DIVIDE_CMD_STRING, 10, 20);
    return 0;
}
