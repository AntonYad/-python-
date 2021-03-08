#define _CRT_SECURE_NO_WARNINGS 1
intmain(){
	charstr[21] = { 0 }; while (EOF != scanf("%s", str))    {intcount[256] = {0};intlen=strlen(str);for(inti=0; i<len; ++i)count[str[i]]++;for(inti=0; i<256; ++i)        {while(count[i]--)            {printf("%c", i);            }        }printf("\n");    }return0;}
