#include <stdio.h>
#include <string.h>

// ȥ���ַ����е��ظ���ĸ
void removeDuplicates(char* str) {
        int len = strlen(str);
        int tail = 1;

        if (len <= 1) {
                return; // �ַ���̫�̻�Ϊ�գ�����ȥ��
        }

        for (int i = 1; i < len; ++i) {
                int j;
                for (j = 0; j < tail; ++j) {
                        if (str[i] == str[j]) {
                                break; // ��ĸ�ظ�������
                        }
                }
                if (j == tail) {
                        str[tail] = str[i]; // ��ĸ���ظ������䱣�浽��λ��
                        ++tail;
                }
        }

        str[tail] = '\0'; // ����ַ�����ֹ��
}

int areStringsEqual(const char* str1, const char* str2) {
        // ���ȣ��������ַ���ȥ�غ���������ȷ�����ǰ�����ͬ����ĸ
        char sortedStr1[256]; // �����ַ������Ȳ�����256
        char sortedStr2[256];

        strcpy(sortedStr1, str1);
        strcpy(sortedStr2, str2);

        removeDuplicates(sortedStr1);
        removeDuplicates(sortedStr2);

        // ʹ�ñ�׼�⺯�� strcmp �Ƚ�ȥ�غ���ַ����Ƿ����
        return strcmp(sortedStr1, sortedStr2) == 0;
}

int main() {
        char str1[256], str2[256];

        // ���������ַ���
        scanf("%s", str1);
        scanf("%s", str2);

        // ��������ַ����Ƿ��������ͬ����ĸ��������
        printf("%s\n", (areStringsEqual(str1, str2) ? "true" : "false"));

        return 0;
}
