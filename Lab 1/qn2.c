// WAP to implement Hill Cipher Technique (2x2 and 3x3 Key Matrix).
#include<stdio.h>
#include<string.h>
int main()
{
    char pt[60],ct[60];
    int key2[2][2],invKey2[2][2];
    int key3[3][3],invKey3[3][3],cof3[3][3];
    int i,j,det,detInv,a,choice;
    int len;

    printf("Select Key Matrix Size:\n");
    printf("1. 2x2\n");
    printf("2. 3x3\n");
    printf("Enter Choice:");
    scanf("%d",&choice);
    getchar();

    printf("Enter Plain Text:");
    scanf("%[^\n]s",pt);


    if(choice==1)
    {
        printf("Enter 2x2 Key Matrix (row by row):\n");
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
            {
                printf("Key[%d][%d]:",i,j);
                scanf("%d",&key2[i][j]);
            }

        len=strlen(pt);
        if(len%2!=0)
        {
            pt[len]='x';
            pt[len+1]='\0';
            len++;
        }

        printf("\n..............Encryption Process..............\n");
        printf("\nPlain Text:%s",pt);
        printf("\nKey Matrix:\n");
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
                printf("%d ",key2[i][j]);
            printf("\n");
        }

        // Encrypt
        for(i=0;i<len;i+=2)
        {
            int p0=pt[i]-97;
            int p1=pt[i+1]-97;
            ct[i]  =((key2[0][0]*p0+key2[0][1]*p1)%26)+65;
            ct[i+1]=((key2[1][0]*p0+key2[1][1]*p1)%26)+65;
        }
        ct[len]='\0';

        printf("\nCipher Text:%s\n",ct);

        printf("\n..............Decryption Process..............\n");
        printf("\nCipher Text:%s",ct);
        printf("\nKey Matrix:\n");
        for(i=0;i<2;i++)
        {
            for(j=0;j<2;j++)
                printf("%d ",key2[i][j]);
            printf("\n");
        }

        det=((key2[0][0]*key2[1][1]-key2[0][1]*key2[1][0])%26+26)%26;
        detInv=-1;
        for(a=1;a<26;a++)
            if((det*a)%26==1)
            {
                detInv=a;
                break;
            }

        invKey2[0][0]= key2[1][1];
        invKey2[0][1]=-key2[0][1];
        invKey2[1][0]=-key2[1][0];
        invKey2[1][1]= key2[0][0];

        for(i=0;i<len;i+=2)
        {
            int c0=ct[i]-65;
            int c1=ct[i+1]-65;
            pt[i]  =(detInv*((invKey2[0][0]*c0+invKey2[0][1]*c1)%26+26)%26)+97;
            pt[i+1]=(detInv*((invKey2[1][0]*c0+invKey2[1][1]*c1)%26+26)%26)+97;
        }
        pt[len]='\0';

        printf("\nPlain Text:%s\n",pt);
    }
    else if(choice==2)
    {
        printf("Enter 3x3 Key Matrix (row by row):\n");
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
            {
                printf("Key[%d][%d]:",i,j);
                scanf("%d",&key3[i][j]);
            }

        len=strlen(pt);
        while(len%3!=0)
        {
            pt[len]='x';
            len++;
        }
        pt[len]='\0';

        printf("\n..............Encryption Process..............\n");
        printf("\nPlain Text:%s",pt);
        printf("\nKey Matrix:\n");
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                printf("%d ",key3[i][j]);
            printf("\n");
        }

        for(i=0;i<len;i+=3)
        {
            int p0=pt[i]-97;
            int p1=pt[i+1]-97;
            int p2=pt[i+2]-97;
            ct[i]  =((key3[0][0]*p0+key3[0][1]*p1+key3[0][2]*p2)%26)+65;
            ct[i+1]=((key3[1][0]*p0+key3[1][1]*p1+key3[1][2]*p2)%26)+65;
            ct[i+2]=((key3[2][0]*p0+key3[2][1]*p1+key3[2][2]*p2)%26)+65;
        }
        ct[len]='\0';

        printf("\nCipher Text:%s\n",ct);

        printf("\n..............Decryption Process..............\n");
        printf("\nCipher Text:%s",ct);
        printf("\nKey Matrix:\n");
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
                printf("%d ",key3[i][j]);
            printf("\n");
        }

        det = key3[0][0]*(key3[1][1]*key3[2][2]-key3[1][2]*key3[2][1])
             -key3[0][1]*(key3[1][0]*key3[2][2]-key3[1][2]*key3[2][0])
             +key3[0][2]*(key3[1][0]*key3[2][1]-key3[1][1]*key3[2][0]);
        det=((det%26)+26)%26;

        detInv=-1;
        for(a=1;a<26;a++)
            if((det*a)%26==1)
            {
                detInv=a;
                break;
            }

        cof3[0][0]= (key3[1][1]*key3[2][2]-key3[1][2]*key3[2][1]);
        cof3[0][1]=-(key3[1][0]*key3[2][2]-key3[1][2]*key3[2][0]);
        cof3[0][2]= (key3[1][0]*key3[2][1]-key3[1][1]*key3[2][0]);
        cof3[1][0]=-(key3[0][1]*key3[2][2]-key3[0][2]*key3[2][1]);
        cof3[1][1]= (key3[0][0]*key3[2][2]-key3[0][2]*key3[2][0]);
        cof3[1][2]=-(key3[0][0]*key3[2][1]-key3[0][1]*key3[2][0]);
        cof3[2][0]= (key3[0][1]*key3[1][2]-key3[0][2]*key3[1][1]);
        cof3[2][1]=-(key3[0][0]*key3[1][2]-key3[0][2]*key3[1][0]);
        cof3[2][2]= (key3[0][0]*key3[1][1]-key3[0][1]*key3[1][0]);

        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                invKey3[i][j]=(detInv*((cof3[j][i]%26+26)%26))%26;

        for(i=0;i<len;i+=3)
        {
            int c0=ct[i]-65;
            int c1=ct[i+1]-65;
            int c2=ct[i+2]-65;
            pt[i]  =((invKey3[0][0]*c0+invKey3[0][1]*c1+invKey3[0][2]*c2)%26)+97;
            pt[i+1]=((invKey3[1][0]*c0+invKey3[1][1]*c1+invKey3[1][2]*c2)%26)+97;
            pt[i+2]=((invKey3[2][0]*c0+invKey3[2][1]*c1+invKey3[2][2]*c2)%26)+97;
        }
        pt[len]='\0';

        printf("\nPlain Text:%s\n",pt);
    }
    else
    {
        printf("Invalid Choice!\n");
    }

    return 0;
}