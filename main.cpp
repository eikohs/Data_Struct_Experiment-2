#include "Experiment2.h"

/*测试用例：
1+2)*3-4)*5-6)))
x*y-a)/a-b)+c)
1+1+1+1+1+1
123412341-456586 - 1382740132)*73124659123)/3241)
yes)
15+20)*3)
240/20-5))
124-85)*12/2628+32/4-3)*18*400-120*2))
280+80/4)*12)
72-4)*6/3)*75+360/20-5))
42+18)*156-26))
4+5)))
5)+3)-4)+6)//

*/
int main(void)
{
#if TEST
    int len;//下面的程序通过运行的结果证明了每个函数的正确性
    char* Test_Str = Get_Line();//此处输入测试用例的第一个用例
    len = strlen(Test_Str);
    printf("%d\n%s\n",len, Test_Str);
    StaPtr TestExperi = Find_First_Bracket(Test_Str, len);
    len = TestExperi->capacity;
    printf("len1 : %d top : %c\n", len, Top_Element(TestExperi));
    len = Find_Bracket(TestExperi, Test_Str, len);
    printf("len2 : %d top : %c\n", len, Top_Element(TestExperi));
    len = Find_Bracket(TestExperi, Test_Str, len);
    printf("len2.5 : %d top : %c\n", len, Top_Element(TestExperi));
    len = Find_Operator(TestExperi, Test_Str, len);
    printf("len3 : %d top : %c\n", len, Top_Element(TestExperi));
    len = Find_Operator(TestExperi, Test_Str, len);
    printf("len4 : %d top : %c\n", len, Top_Element(TestExperi));
    len = Find_Operator(TestExperi, Test_Str, len);
    printf("len5 : %d top : %c\n", len, Top_Element(TestExperi));
    while (!isEmpty(TestExperi))
        printf("%c", Top_Pop_Element(TestExperi));
    StaPtr Test_Sta = Creat_Stack(MAXCAP);
    push('y', Test_Sta);
    push('e', Test_Sta);
    push('s', Test_Sta);
    for (int i = 0; i < 3; i++)
    {
        printf("%c", Top_Pop_Element(Test_Sta));
    }
    push('f', Test_Sta);
    pop(Test_Sta);
    printf("\n%d\n", isEmpty(Test_Sta));
    Dispose_Stack(Test_Sta);
#elif !(PROGRAM_MODE-1)
    char Flag;
    char* Src;
    int BLANK[MAXCAP] = {0}, Len;//BLANK数组中BLANK[i]代表输入字符串中第i个字符前面应该加入的括号数量

    while (1)
    {
        Src = Get_Line();
        Len = strlen(Src);
        for (int i = 0; i < Len; i++) BLANK[i] = 0;//初始化BLANK数组为零
        StaPtr Sentence = Find_First_Bracket(Src, Len);//初始化匹配，有右括号时才启动匹配，否则直接输出
        if (Sentence != NULL)
        {
            BLANK[0]++;//初始化成功，添加一个括住整个式子的括号
            Len = Sentence->capacity;//更新需要处理的表达式的长度
            while (Len > 0)//此处通过循环匹配右括号
            {
                if (Top_Element(Sentence) == '#') Len = Find_Bracket(Sentence, Src, Len);//没有右括号时找到右括号
                while (Is_Bracket(Top_Element(Sentence))&&Len > 0) Len = Find_Operator(Sentence, Src, Len);//有右括号时找到运算符
                while (Is_Operator(Top_Element(Sentence))&&Len > 0) Len = Add_Bracket(Sentence, Src, BLANK, Len);//有运算符时添加左括号消除右括号
                if(DEBUG&&WHETHER_PRINT) printf("Len:%d Top:%c\n", Len, Top_Element(Sentence));//此行调试用
            }
            while (Top_Element(Sentence) != '#')//处理多余的右括号
            {
                if (Top_Element(Sentence) == ')')   BLANK[0]++;
                pop(Sentence);
            }
        }
        if (DEBUG) puts("Solution:");//此行调试用
        PRINT_SENTENCE(Src, BLANK);//打印最终结果
        Dispose_Stack(Sentence);//清除栈
        free(Src);//清除输入的字符串
        if (DEBUG) putchar('\n');//此行调试用
        if (!DEBUG)//这一段非调试时加入
        {
            printf("Want to run again?(q/Q to quit):");
            while ((Flag = getchar()) == '\n') continue;
            if (Flag == 'Q' || Flag == 'q') break;
        }
    }
#else
    char* Src;


#endif

    return 0;
}