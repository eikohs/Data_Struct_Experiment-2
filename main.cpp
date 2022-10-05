#include "Experiment2.h"

/*����������
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
    int len;//����ĳ���ͨ�����еĽ��֤����ÿ����������ȷ��
    char* Test_Str = Get_Line();//�˴�������������ĵ�һ������
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
    int BLANK[MAXCAP] = {0}, Len;//BLANK������BLANK[i]���������ַ����е�i���ַ�ǰ��Ӧ�ü������������

    while (1)
    {
        Src = Get_Line();
        Len = strlen(Src);
        for (int i = 0; i < Len; i++) BLANK[i] = 0;//��ʼ��BLANK����Ϊ��
        StaPtr Sentence = Find_First_Bracket(Src, Len);//��ʼ��ƥ�䣬��������ʱ������ƥ�䣬����ֱ�����
        if (Sentence != NULL)
        {
            BLANK[0]++;//��ʼ���ɹ������һ����ס����ʽ�ӵ�����
            Len = Sentence->capacity;//������Ҫ����ı��ʽ�ĳ���
            while (Len > 0)//�˴�ͨ��ѭ��ƥ��������
            {
                if (Top_Element(Sentence) == '#') Len = Find_Bracket(Sentence, Src, Len);//û��������ʱ�ҵ�������
                while (Is_Bracket(Top_Element(Sentence))&&Len > 0) Len = Find_Operator(Sentence, Src, Len);//��������ʱ�ҵ������
                while (Is_Operator(Top_Element(Sentence))&&Len > 0) Len = Add_Bracket(Sentence, Src, BLANK, Len);//�������ʱ�������������������
                if(DEBUG&&WHETHER_PRINT) printf("Len:%d Top:%c\n", Len, Top_Element(Sentence));//���е�����
            }
            while (Top_Element(Sentence) != '#')//��������������
            {
                if (Top_Element(Sentence) == ')')   BLANK[0]++;
                pop(Sentence);
            }
        }
        if (DEBUG) puts("Solution:");//���е�����
        PRINT_SENTENCE(Src, BLANK);//��ӡ���ս��
        Dispose_Stack(Sentence);//���ջ
        free(Src);//���������ַ���
        if (DEBUG) putchar('\n');//���е�����
        if (!DEBUG)//��һ�ηǵ���ʱ����
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