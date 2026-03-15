// WAP to implement ceaser and shift cipher techniques.
#include<stdio.h>
#include<string.h>
int main()
{
    char pt[20],ct[20];
    int key,i;
    printf("Enter Plain Text:");
    scanf("%[^\n]s",pt);
    printf("Enter the value of Key:");
    scanf("%d",&key);
    printf("\n..............Encryption Process..............\n");
    printf("\nPlain Text:");
    puts(pt);
    printf("\nKey:%d",key);
    for(i=0;i<strlen(pt);i++)
    {
        if(pt[i]==' ')
        {
            ct[i]=' ';
            continue;
        }
        ct[i]=(((pt[i]-97)+key)%26)+65;
    }
    ct[i] = '\0';
    printf("\nCipher Text:");
    puts(ct);
    printf("\n..............Decryption Process..............\n");
    printf("\nCypher Text:");
    puts(ct);
    printf("\nKey:%d",key);
    for(i=0;i<strlen(ct);i++)
    {
        if(ct[i]==' ')
        {
            pt[i]=' ';
            continue;
        }
        pt[i]=(((26+ct[i]-65)-key)%26)+97;
    }
     pt[i] = '\0';
    printf("\nPlain Text:");
    puts(pt);
    return 0;
}