#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define Max 1000
//ͳ��ĳ�����ʳ��ֵĴ���
int getWordNum(const char *sentence, const char word) {
	 int num = 0;

	return num;
}
//�Զ��帴�ƺ���
void myStrcpy(char* Destination, const char* Sourse,int len2) {
	while (*Sourse&&len2) {
		*Destination = *Sourse;
		Destination++;
		Sourse++;
		len2--;
	}*Destination = '\0';
}
//�Զ���strcmp����,�Ƚ�len������
_Bool myStrcmp(const char* str1, const char* str2) {
	if (strlen(str1) == strlen(str2)) {
		while (*str1) {
			if (*str1 != *str2) {
				return 0;
			}
			str1++; str2++;
		}
		return 1;
	}
	else return 0;

}
//ͳ��ĳһ�����ʳ��ֵĴ���
int num(const char *sentences, const char* word) {
	int lenSen = strlen(sentences);
	int lenWor = strlen(word);
	//��������
	char temp_sentence[Max];
	
	myStrcpy(temp_sentence,sentences,lenSen );
	char* ptemp_sentence = temp_sentence;
	while (*ptemp_sentence) {
		if (*ptemp_sentence == ' ')
			*ptemp_sentence = '\0';
		ptemp_sentence++;
	}
	static int num = 0;
	
	char* top = temp_sentence; char* tail = temp_sentence + lenSen -lenWor;//��⵽β���Ͳ��ڼ��
	while (top <= tail) {
		if (myStrcmp(top, word))
			num++;
		int len = strlen(top);
		if (len)
			top = top + len; top++;
		
	}
	return num;
}
//���������Ӣ�ľ��ӵ�ǰ���󵼿ո�

void dealTrim(char* str) {
	char temp[Max];
	char* top = str; char* tail = str + strlen(str);
	while (*top == ' ')  top++;  while (*tail == ' ') tail--; 
	int i = 0;

	while (top < tail) {
		if (*top!=' '|| (*top == ' ' && *(top + 1) != ' ')) {
			temp[i] = *top;
			i++;
		}top++;
	}temp[i] = (*tail); temp[i + 1] = '\0'; memset(str, '\0', sizeof(str));
	myStrcpy(str, temp, strlen(temp));
	//puts(temp);
	puts(str);
 	
}
//���Ҳ���ȥ�滻ĳ������
void repalce(char* sentence, const char* old,const char*new) {
	int lenSen = strlen(sentence);
	int lenWor = strlen(old);
	//��������
	char temp_sentence[Max];
	myStrcpy(temp_sentence, sentence, lenSen);
	char* ptemp_sentence = temp_sentence;
	while (*ptemp_sentence) {
		if (*ptemp_sentence == ' ')
			*ptemp_sentence = '\0';
		ptemp_sentence++;
	}
	char* top = temp_sentence; char* tail = temp_sentence + lenSen - lenWor;
	char mm[Max];
	char * pmm = mm;

	while (top <= tail) {
		if (!myStrcmp(top, old)) {
			myStrcpy(pmm, top,strlen(top));

			int len = strlen(top);
			if (len)
				top = top + len;else top++;
			pmm += len;
			*(pmm++) = ' ';
		}
		else {
			myStrcpy(pmm, new, strlen(new));
			pmm += strlen(new);
			*(pmm++) = ' ';
			int len = strlen(top);
			if (len)
				top = top + len; else top++;

		} 
	}
	*(pmm) = '\0';
	dealTrim(mm);

//	for (int i = 0; i < lenSen; i++) {
		//if (mm[i] == '\0')
		//	mm[i] = ' ';
	//}
	//puts(mm);
}
int main()
{
	printf("������һ���ַ�����");
	char str[Max];
	gets_s(str, Max);


	dealTrim(str);

	printf("��������Ҫͳ�������ĵ���:");
	char word[Max];
	gets_s(word, Max);
	printf("%s������%d��\n", word, num(str, word));

	printf("��������Ҫ�滻���ĵ��� ");
	char old[Max]; char new[Max];
	gets_s(old, Max); 
	printf("��������Ҫ�滻�ɵ��µ���");
		gets_s(new, Max);
	repalce(str, old,new);
	//puts(str);
	return 0;
}