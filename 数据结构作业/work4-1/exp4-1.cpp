#include "sqstring.cpp"
#pragma execution_character_set("utf-8")

int main() {
    SqString s, s1, s2, s3, s4;

    // ������sΪ"abcdefghefghijklmn"�ʹ�s1Ϊ"xyz"
    init_sqstring(&s, "abcdefghefghijklmn");
    init_sqstring(&s1, "xyz");

    // �����s
    printf("��s: ");
    print_sqstring(&s);

    // ������ĳ���
    printf("��s�ĳ���: %zu\n", get_length(&s));

    // �ڴ�s�ĵ�9���ַ�λ�ò��봮s1��������s2
    init_sqstring(&s2, s.str); // ����s��s2
    insert_substring(&s2, &s1, 8);
    printf("�ڴ�s�ĵ�9���ַ�λ�ò��봮s1��Ĵ�s2: ");
    print_sqstring(&s2);

    // ɾ����s�ĵ�2���ַ���ʼ��5���ַ���������s2
    init_sqstring(&s2, s.str); // �ٴθ���s��s2
    delete_substring(&s2, 1, 5);
    printf("ɾ����s�ĵ�2���ַ���ʼ��5���ַ���Ĵ�s2: ");
    print_sqstring(&s2);

    // ����s�ĵ�2���ַ���ʼ��5���ַ��滻�ɴ�s1��������s2
    init_sqstring(&s2, s.str); // �ٴθ���s��s2
    replace_substring(&s2, &s1, 1, 5);
    printf("����s�ĵ�2���ַ���ʼ��5���ַ��滻�ɴ�s1��Ĵ�s2: ");
    print_sqstring(&s2);

    // ��ȡ��s�ĵ�2���ַ���ʼ��10���ַ���������s3
    s3 = extract_substring(&s, 1, 10);
    printf("��ȡ��s�ĵ�2���ַ���ʼ��10���ַ���Ĵ�s3: ");
    print_sqstring(&s3);

    // ����s1�ʹ�s2����������������s4
    init_sqstring(&s4, s1.str); // ����s1��s4
    concatenate(&s4, &s2);
    printf("����s1�ʹ�s2����������Ĵ�s4: ");
    print_sqstring(&s4);

    // �ͷŶ�̬������ڴ�
    destroy_sqstring(&s);
    destroy_sqstring(&s1);
    destroy_sqstring(&s2);
    destroy_sqstring(&s3);
    destroy_sqstring(&s4);

    return 0;
}
