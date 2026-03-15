// WAP To implement Vernam Cipher technique.
#include<stdio.h>
#include<string.h>
int main()
{
    char pt[20], ct[20], key[20], key1[20];
    int i, lenkey, lenpt;
    printf("Enter Plain Text:");
    scanf("%[^\n]s",pt);
    printf("Enter the value of Key:");
    scanf("%s",key);
    lenkey = strlen(key);
    lenpt = strlen(pt);
    if(lenkey != lenpt)
    {
        for(i = 0; i < lenpt; i++)
        {
            key1[i] = key[i % lenkey];
        }
        key1[i] = '\0';
    }
    else
    {
        strcpy(key1, key);
    }
    printf("\n..............Encryption Process..............\n");
    printf("\nPlain Text:");
    puts(pt);
    printf("\nKey:");
    puts(key1);
    for(i = 0; i < lenpt; i++)
    {
        if(pt[i] == ' ')
        {
            ct[i] = ' ';
        }
        else
        {
            ct[i] = (((pt[i] - 97) + (key1[i] - 97)) % 26) + 65;
        }
    }
    ct[i] = '\0';
    printf("\nCipher Text:");
    puts(ct);
    printf("\n..............Decryption Process..............\n");
    printf("\nCypher Text:");
    puts(ct);
    printf("\nKey:");
    puts(key1);
    for(i = 0; i < lenpt; i++)
    {
        if(ct[i] == ' ')
        {
            pt[i] = ' ';
        }
        else
        {
            pt[i] = (((26 + ct[i] - 65) - (key1[i] - 97)) % 26) + 97;
        }
    }
    pt[i] = '\0';
    printf("\nPlain Text:");
    puts(pt);
    return 0;
}
