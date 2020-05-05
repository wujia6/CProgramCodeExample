#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define BUF_SIZE 1024
#define MAXCOUNT 3

typedef struct _goods
{
    int id;
    char name[24];
    float price;
    int quantity;
} goods;

void file_character(char *);
void file_string(char *, char *);
int fileWrite_binary(char *);
int fileCopy_binary(char *, char *);
int formatterIO(char *);
void randomReader(char *, int);

int main111()
{
    //从键盘输入若干个字符，同时把这些字符输出到 D 盘根目录下的文件 data_file.txt 中及屏幕上
    //file_character("e:/demo/exp1.txt");

    //字符串读写文件
    //file_string("D:\\Users\\ms-wu\\Documents\\VSCode-workspance\\Code Example\\.vscode\\launch.json", "e:/demo/exp2.txt");

    //二进制读写文件
    // if (fileWrite_binary("e:/demo/backup.dat", 2))
    //     puts("success");
    // fileCopy_binary(".vscode/tasks.json","task.txt");

    //格式化读写
    if (formatterIO("source.txt"))
        puts("success");

	//随机读写
    FILE *fptr=fopen("./source.txt","w");
    if (fptr==NULL)
    {
        puts("open file failure");
        exit(0);
    }
    printf("%d\n",ftell(fptr));
    fputs("Hunan Shaoyang,China HongXiang School",fptr);
    printf("%d\n", ftell(fptr));

    fileWrite_binary("./backup.dat");
    int offset;
    while (1)
    {
        printf("输入商品序列：");
        scanf("%d", &offset);
        randomReader("./backup.dat", offset);
    }
    return 0;
}

//字符读写
void file_character(char *dst)
{
    int ch;
    FILE *dest = fopen(dst, "w"); //打开文件
    if (dest == NULL)
    {
        puts("未能与文件建立连接，打开失败");
        exit(0);
    }
    printf("请输入字符按回车键结束：");
    while ((ch = fgetc(stdin)) != '\n') //从标准输入设备接收字符
    {
        fputc(ch, stdout); //stdout:标准输出设备（屏幕）
        fputc(ch, dest);
    }
    fclose(dest);
}

//字符串读写
void file_string(char *src, char *dst)
{
    char buf[32];
    char *addr;
    FILE *source = fopen(src, "r"); //打开文件
    if (source == NULL)
    {
        puts("未能与文件建立连接，打开失败");
        exit(0);
    }

    FILE *dest = fopen(dst, "w");
    while ((addr = fgets(buf, BUF_SIZE, source)) != NULL) //读取源文件
    {
        //写入目标文件
        fputs(buf, dest);
    }
    puts("success");
    fclose(source);
    fclose(dest);
}

//二进制写
int fileWrite_binary(char *fileComplete)
{
    goods gds[MAXCOUNT];
    for (int i = 0; i < MAXCOUNT; i++)
    {
        printf("请输入第 %d 个商品信息：", i + 1);
        scanf("%d %s %f %d", &gds[i].id, gds[i].name, &gds[i].price, &gds[i].quantity);
    }
    FILE *fptr = fopen(fileComplete, "wb");
    if (fptr == NULL)
        return 0;
    int rc = fwrite(gds, sizeof(goods), MAXCOUNT, fptr);
    int error = ferror(fptr);
    printf("已对目标文件写入 %d 条数据,错误 %d 次\n", rc, error);
    fclose(fptr);
    return 1;
}

//二进制读写
int fileCopy_binary(char *fileSrc, char *fileDest)
{
    int rc = 0;
    char buf[BUF_SIZE];
    FILE *outfile, *infile;
    infile = fopen(fileSrc, "rb");
    outfile = fopen(fileDest, "wb");
    if (infile == NULL || outfile == NULL)
        return 0;
    while (rc = fread(buf, sizeof(char), BUF_SIZE, infile) != 0)
    {
        fwrite(buf, sizeof(char), rc, outfile);
    }
    fclose(infile);
    fclose(outfile);
    return 1;
}

//格式化读写
int formatterIO(char *fileDest)
{
    int x, y, z;
    FILE *fptr = fopen(fileDest, "a+");
    if (fptr == NULL)
        return 0;
    fscanf(fptr, "%d,%d,%d", &x, &y, &z);
    fprintf(fptr, "%d,%d,%d", x, y, z);
    fclose(fptr);
    return 1;
}

//随机读
void randomReader(char *fileSrc, int offset)
{
    goods selected;
    FILE *src = fopen(fileSrc, "rb");
    if (src == NULL)
    {
        puts("源文件打开失败");
        return;
    }
    fseek(src, (offset - 1) * sizeof(goods), SEEK_SET); //使位置指针指向随机读取的位置
    fread(&selected, sizeof(goods), 1, src);
    printf("商品序列 [%d] 名称：%s\t价格：%.2f\t数量：%d\n", offset, selected.name, selected.price, selected.quantity);
}
