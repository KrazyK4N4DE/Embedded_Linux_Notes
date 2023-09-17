#include <stdio.h>
#include <string.h>

// 去除字符串中的重复字母
void removeDuplicates(char* str) {
        int len = strlen(str);
        int tail = 1;

        if (len <= 1) {
                return; // 字符串太短或为空，无需去重
        }

        for (int i = 1; i < len; ++i) {
                int j;
                for (j = 0; j < tail; ++j) {
                        if (str[i] == str[j]) {
                                break; // 字母重复，跳过
                        }
                }
                if (j == tail) {
                        str[tail] = str[i]; // 字母不重复，将其保存到新位置
                        ++tail;
                }
        }

        str[tail] = '\0'; // 添加字符串终止符
}

int areStringsEqual(const char* str1, const char* str2) {
        // 首先，将两个字符串去重后再排序以确保它们包含相同的字母
        char sortedStr1[256]; // 假设字符串长度不超过256
        char sortedStr2[256];

        strcpy(sortedStr1, str1);
        strcpy(sortedStr2, str2);

        removeDuplicates(sortedStr1);
        removeDuplicates(sortedStr2);

        // 使用标准库函数 strcmp 比较去重后的字符串是否相等
        return strcmp(sortedStr1, sortedStr2) == 0;
}

int main() {
        char str1[256], str2[256];

        // 输入两个字符串
        scanf("%s", str1);
        scanf("%s", str2);

        // 检查两个字符串是否仅包含相同的字母并输出结果
        printf("%s\n", (areStringsEqual(str1, str2) ? "true" : "false"));

        return 0;
}
