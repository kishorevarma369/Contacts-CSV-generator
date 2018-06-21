#include<stdio.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
  char s[100],ch,phoneup[7],phonedown[7];
  if(argc!=2)
  {
    printf("Usage:\n progrm-name filename\n\nNote:file should contain name followed by phone number with comma \(,\) as delimitter");
    system("pause");
    return 1;
  }
  FILE *fp=fopen(argv[1],"r"),*fp1=fopen("output.csv","w");
  if(fp==NULL)
  {
    printf("Unable to access the file\n");
    system("pause");
    return 0;
  }
  int i=0;
  while(1)
  {
    i=0;
    ch=getc(fp);
    if(ch==EOF) break;
    else s[i++]=ch;
    while((ch=fgetc(fp))!=',')
    {
      s[i++]=ch;
    }
    s[i]=0;
    for(i=0;i<5;i++) phoneup[i]=fgetc(fp);
    for(i=0;i<5;i++) phonedown[i]=fgetc(fp);
    phoneup[i]=phonedown[i]=0;
    fprintf(fp1,"%s,%s,,,,,,,,,,,,,,,,,,,,,,,,,* My Contacts,,,Mobile,+91 %s %s,,,,,,,,,,,,,,,,,,,\n",s,s,phoneup,phonedown);
    ch=getc(fp);
  }
  printf("successfully created output.csv , upload it to get contacts into your account\n\nHave a great day");
  system("pause");

  return 0;
}
