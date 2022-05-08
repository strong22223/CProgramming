#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define Max 1000
//统计某个单词出现的次数
int getWordNum(const char *sentence, const char word) {
	 int num = 0;

	return num;
}
//自定义复制函数
void myStrcpy(char* Destination, const char* Sourse,int len2) {
	while (*Sourse&&len2) {
		*Destination = *Sourse;
		Destination++;
		Sourse++;
		len2--;
	}*Destination = '\0';
}
//自定义strcmp函数,比较len个长度
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
//统计某一个单词出现的次数
int num(const char *sentences, const char* word) {
	int lenSen = strlen(sentences);
	int lenWor = strlen(word);
	//创建副本
	char temp_sentence[Max];
	
	myStrcpy(temp_sentence,sentences,lenSen );
	char* ptemp_sentence = temp_sentence;
	while (*ptemp_sentence) {
		if (*ptemp_sentence == ' ')
			*ptemp_sentence = '\0';
		ptemp_sentence++;
	}
	static int num = 0;
	
	char* top = temp_sentence; char* tail = temp_sentence + lenSen -lenWor;//检测到尾部就不在检测
	while (top <= tail) {
		if (myStrcmp(top, word))
			num++;
		int len = strlen(top);
		if (len)
			top = top + len; top++;
		
	}
	return num;
}
//来处理这个英文句子的前导后导空格

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
//查找并且去替换某个单词
void repalce(char* sentence, const char* old,const char*new) {
	int lenSen = strlen(sentence);
	int lenWor = strlen(old);
	//创建副本
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
	printf("请输入一个字符串：");
	char str[Max];
	gets_s(str, Max);


	dealTrim(str);

	printf("请输入需要统计数量的单词:");
	char word[Max];
	gets_s(word, Max);
	printf("%s出现了%d次\n", word, num(str, word));

	printf("请输入需要替换掉的单词 ");
	char old[Max]; char new[Max];
	gets_s(old, Max); 
	printf("请输入需要替换成的新单词");
		gets_s(new, Max);
	repalce(str, old,new);
	//puts(str);
	return 0;
}