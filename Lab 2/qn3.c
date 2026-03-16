// WAP to implement Rail Fence Cipher.
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char pt[100],ct[100],dt[100];
    int key,i,j,len;
    int rail,dir;

    printf("Enter Plain Text:");
    scanf("%[^\n]s",pt);
    for(i=0;i<strlen(pt);i++)
        pt[i]=tolower(pt[i]);

    printf("Enter the value of Key (number of rails):");
    scanf("%d",&key);

    len=strlen(pt);

    printf("\n..............Encryption Process..............\n");
    printf("\nPlain Text:%s",pt);
    printf("\nKey:%d\n",key);

    // Create rail matrix and mark positions
    int matrix[key][len];
    for(i=0;i<key;i++)
        for(j=0;j<len;j++)
            matrix[i][j]=0;

    // Fill zigzag pattern
    rail=0;
    dir=1;
    for(i=0;i<len;i++)
    {
        matrix[rail][i]=1;
        if(rail==0)
            dir=1;
        else if(rail==key-1)
            dir=-1;
        rail+=dir;
    }

    // Display rail pattern
    printf("\nRail Pattern:\n");
    for(i=0;i<key;i++)
    {
        printf("Rail %d: ",i+1);
        for(j=0;j<len;j++)
        {
            if(matrix[i][j]==1)
                printf("%c",pt[j]);
            else
                printf(".");
        }
        printf("\n");
    }

    // Read off rail by rail to get cipher text
    j=0;
    for(i=0;i<key;i++)
        for(int k=0;k<len;k++)
            if(matrix[i][k]==1)
                ct[j++]=pt[k];
    ct[j]='\0';

    printf("\nCipher Text:%s\n",ct);

    printf("\n..............Decryption Process..............\n");
    printf("\nCipher Text:%s",ct);
    printf("\nKey:%d\n",key);

    // Find rail lengths
    int railLen[key];
    for(i=0;i<key;i++)
        railLen[i]=0;

    rail=0;
    dir=1;
    for(i=0;i<len;i++)
    {
        railLen[rail]++;
        if(rail==0)
            dir=1;
        else if(rail==key-1)
            dir=-1;
        rail+=dir;
    }

    // Fill cipher text into rails
    char rails[key][len];
    int idx=0;
    for(i=0;i<key;i++)
        for(j=0;j<railLen[i];j++)
            rails[i][j]=ct[idx++];

    // Display rail pattern during decryption
    printf("\nRail Pattern:\n");
    int railIdx[key];
    for(i=0;i<key;i++)
        railIdx[i]=0;

    for(i=0;i<key;i++)
    {
        printf("Rail %d: ",i+1);
        railIdx[i]=0;
        rail=0;
        dir=1;
        for(j=0;j<len;j++)
        {
            if(matrix[i][j]==1)
                printf("%c",rails[i][railIdx[i]++]);
            else
                printf(".");
        }
        printf("\n");
    }

    // Read zigzag to get plain text
    for(i=0;i<key;i++)
        railIdx[i]=0;

    rail=0;
    dir=1;
    for(i=0;i<len;i++)
    {
        dt[i]=rails[rail][railIdx[rail]++];
        if(rail==0)
            dir=1;
        else if(rail==key-1)
            dir=-1;
        rail+=dir;
    }
    dt[len]='\0';

    printf("\nPlain Text:%s\n",dt);

    return 0;
}