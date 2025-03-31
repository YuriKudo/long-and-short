#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc,  char *argv[])
{
    if (argc < 4)
    {
        printf("Must supply a source and destination file\n");
        exit(1);
    }
    

    FILE *sourceFile = fopen(argv[1], "r");
    
    if (!sourceFile)
    {
        printf("Can't open %s for reading\n", argv[1]);
        exit(1);
    }

    FILE *firstDestFile = fopen(argv[2], "w");
    if (!firstDestFile)
    {
        printf("Can't open %s for writing\n", argv[2]);
        exit(1);
    }

    FILE *secondDestFile = fopen(argv[3], "w");
    if (!secondDestFile)
    {
        printf("Can't open %s for writing\n", argv[3]);
        exit(1);
    }

    char line[1000];
    int upCount = 0;
    int lowCount = 0;
    while(1)
    {
        if(fgets(line, sizeof(line), sourceFile) ==NULL)
            break;
        
        int len = strlen(line);
        
        
        if(len < 20)
        {
            for(int i = 0; i < len; i++)
            {
                line[i] = toupper(line[i]);
            }
            fprintf(firstDestFile, "%s\n", line);
            upCount++;
        }
        else
        {
           for(int i = 0; i < len; i++)
            {
                line[i] = tolower(line[i]);
            }  
            fprintf(secondDestFile, "%s\n", line);
            lowCount++;
        }
      
    }
    fclose(sourceFile);
    fclose(firstDestFile);
    fclose(secondDestFile);

    printf("%d lines written to %s\n", lowCount, argv[2]);
    printf("%d lines written to %s\n", upCount, argv[3]);

}






