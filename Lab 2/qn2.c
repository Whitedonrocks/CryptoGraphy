    // WAP to implement Playfair Cipher Technique.
    #include<stdio.h>
    #include<string.h>
    #include<ctype.h>
    int main()
    {
        char key[30],pt[100],ct[100],dt[100];
        char matrix[5][5];
        int used[26];
        int i,j,len,r1,c1,r2,c2;
        int idx=0;

        printf("Enter Plain Text:");
        scanf("%[^\n]s",pt);
        for(i=0;i<strlen(pt);i++)
            pt[i]=tolower(pt[i]);

        getchar();
        printf("Enter Key:");
        scanf("%[^\n]s",key);
        for(i=0;i<strlen(key);i++)
            key[i]=tolower(key[i]);

        for(i=0;i<26;i++)
            used[i]=0;
        used['j'-97]=1;

        for(i=0;i<strlen(key);i++)
        {
            if(key[i]=='j') key[i]='i';
            if(!used[key[i]-97])
            {
                matrix[idx/5][idx%5]=key[i];
                used[key[i]-97]=1;
                idx++;
            }
        }
        for(i=0;i<26;i++)
        {
            if(!used[i])
            {
                matrix[idx/5][idx%5]='a'+i;
                idx++;
            }
        }

        printf("\nPlayfair Matrix:\n");
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
                printf("%c ",matrix[i][j]);
            printf("\n");
        }

        char prep[200];
        idx=0;
        for(i=0;i<strlen(pt);i++)
        {
            if(pt[i]=='j') pt[i]='i';
            prep[idx++]=pt[i];
            if(idx%2==0 && prep[idx-1]==prep[idx-2])
            {
                prep[idx-1]='x';
                prep[idx++]=pt[i];
            }
        }
        if(idx%2!=0)
            prep[idx++]='x';
        prep[idx]='\0';
        len=idx;

        printf("\nPrepared Plain Text:%s\n",prep);

        printf("\n..............Encryption Process..............\n");
        printf("\nPlain Text:%s",prep);

        // Encrypt
        for(i=0;i<len;i+=2)
        {
            for(j=0;j<5;j++)
                for(int k=0;k<5;k++)
                {
                    if(matrix[j][k]==prep[i])   { r1=j; c1=k; }
                    if(matrix[j][k]==prep[i+1]) { r2=j; c2=k; }
                }

            if(r1==r2)
            {
                ct[i]  =matrix[r1][(c1+1)%5];
                ct[i+1]=matrix[r2][(c2+1)%5];
            }
            else if(c1==c2)
            {
                ct[i]  =matrix[(r1+1)%5][c1];
                ct[i+1]=matrix[(r2+1)%5][c2];
            }
            else
            {
                ct[i]  =matrix[r1][c2];
                ct[i+1]=matrix[r2][c1];
            }
        }
        ct[len]='\0';

        printf("\nCipher Text:%s\n",ct);

        printf("\n..............Decryption Process..............\n");
        printf("\nCipher Text:%s",ct);

        // Decrypt
        for(i=0;i<len;i+=2)
        {
            for(j=0;j<5;j++)
                for(int k=0;k<5;k++)
                {
                    if(matrix[j][k]==ct[i])   { r1=j; c1=k; }
                    if(matrix[j][k]==ct[i+1]) { r2=j; c2=k; }
                }

            if(r1==r2)
            {
                dt[i]  =matrix[r1][(c1+4)%5];
                dt[i+1]=matrix[r2][(c2+4)%5];
            }
            else if(c1==c2)
            {
                dt[i]  =matrix[(r1+4)%5][c1];
                dt[i+1]=matrix[(r2+4)%5][c2];
            }
            else
            {
                dt[i]  =matrix[r1][c2];
                dt[i+1]=matrix[r2][c1];
            }
        }
        dt[len]='\0';

        printf("\nPlain Text:%s\n",dt);

        return 0;
    }