#include "sqstring.cpp"
#pragma execution_character_set("utf-8")

int main() {
    SqString s, s1, s2, s3, s4;

    // 建立串s为"abcdefghefghijklmn"和串s1为"xyz"
    init_sqstring(&s, "abcdefghefghijklmn");
    init_sqstring(&s1, "xyz");

    // 输出串s
    printf("串s: ");
    print_sqstring(&s);

    // 输出串的长度
    printf("串s的长度: %zu\n", get_length(&s));

    // 在串s的第9个字符位置插入串s1而产生串s2
    init_sqstring(&s2, s.str); // 复制s到s2
    insert_substring(&s2, &s1, 8);
    printf("在串s的第9个字符位置插入串s1后的串s2: ");
    print_sqstring(&s2);

    // 删除串s的第2个字符开始的5个字符而产生串s2
    init_sqstring(&s2, s.str); // 再次复制s到s2
    delete_substring(&s2, 1, 5);
    printf("删除串s的第2个字符开始的5个字符后的串s2: ");
    print_sqstring(&s2);

    // 将串s的第2个字符开始的5个字符替换成串s1而产生串s2
    init_sqstring(&s2, s.str); // 再次复制s到s2
    replace_substring(&s2, &s1, 1, 5);
    printf("将串s的第2个字符开始的5个字符替换成串s1后的串s2: ");
    print_sqstring(&s2);

    // 提取串s的第2个字符开始的10个字符而产生串s3
    s3 = extract_substring(&s, 1, 10);
    printf("提取串s的第2个字符开始的10个字符后的串s3: ");
    print_sqstring(&s3);

    // 将串s1和串s2连接起来而产生串s4
    init_sqstring(&s4, s1.str); // 复制s1到s4
    concatenate(&s4, &s2);
    printf("将串s1和串s2连接起来后的串s4: ");
    print_sqstring(&s4);

    // 释放动态分配的内存
    destroy_sqstring(&s);
    destroy_sqstring(&s1);
    destroy_sqstring(&s2);
    destroy_sqstring(&s3);
    destroy_sqstring(&s4);

    return 0;
}
