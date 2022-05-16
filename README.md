# XDUER大一下C语言程序设计
简单文件数据库-模拟图书馆管理系统
涉及知识点：文件读写、内存管理、结构体定义、基本数据结构、高级格式化输入输出
要求：   

编写一个程序模拟图书管理系统。用户分为**管理员**和**读者**两类，分别显示不同文本格式菜单，通过菜单项对应数字进行选择。   

**读者菜单**包括**借书、还书、查询**等功能。**管理员菜单**包括**图书**和**读者**信息**录入、修改和删除。**   

**图书信息**至少应包括：**编号、书名、数量**，**读者信息**至少应包括：**编号、姓名、所借图书。**   

可根据图书名称或编号进行图书信息查询，可查询某本书现在被哪些读者借走。   

命令行参数如下：   

Libsim –a(-u) xxxx   

第一个参数为可执行程序名称；第二个参数为用户身份，-a表示管理员，-u表示读者；第三个参数为用户名

---

## 程序的解析 
### 数据方面

#### 图书的信息
```C
  trpedef struct Book{
    unsigned int number;
    char name[20];
    unsigned int amount ;
  }Book;
```
#### 读者的信息
```C
typedef struct Reader{
   int number;
  char name [20];
  int passwd;
}Reader;
```
#### 管理员的信息
```C
typedef struct Administartor{
  int num;
  char name[10];
  int passwd;
}Administartor;
```
### 一些基本的数据存储类型
```C
Book books[SIZE];//图书的信息
Reader readers[SIZE];//读者的信息
//管理员是只有一个的即root
``` 


### 具体的实现函数

#### 1.展示所有的读者信息和书籍信息
```C
showReader(char * readers)//展示所有的读者的信息
showBooks(char * books)//展示出所有的书籍的信息
 ```
 #### 2.图书的借阅和归还
```C
void BookLend(char *rname, char *bname);
void BookReturn(char *rname, char* bname);
```
#### 3.图书和读者的增删改查
```C
 void addBook(char * bname);
 void delBook(char * bname);
```
#### 2.读者的所有操作
```C
void borrowBook(char *bname);
void returnBook(char *bname);
void 
```
