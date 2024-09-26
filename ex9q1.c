#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//https://rosettacode.org/wiki/Levenshtein_distance
//https://www.tutorialspoint.com/levenshtein-distance-in-javascript#:~:text=The%20Levenshtein%20distance%20is%20a,one%20word%20into%20the%20other.
int levenshtein(char *s1,char *s2)
{
    int m=strlen(s1);
    int n=strlen(s2);

    int **dp=(int **)malloc((m+1)*sizeof(int *));
    for (int i=0; i<=m; i++)
    {
        dp[i]=(int *)malloc((n+1)*sizeof(int));
    }

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j <= n; j++)
        {
            dp[i][j]=0;
        }
    }

    for (int i=0; i<=m; i++)
    {
        dp[i][0]=i;
    }

    for (int j=0; j<=n; j++)
    {
        dp[0][j]=j;
    }

    for (int i=1; i<=m; i++)
    {
        for (int j=1; j <= n; j++)
        {
            if (s1[i-1]==s2[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                int minDistance=dp[i-1][j-1];
                if (dp[i-1][j] < minDistance)
                {
                    minDistance=dp[i-1][j];
                }
                if (dp[i][j-1]<minDistance)
                {
                    minDistance=dp[i][j - 1];
                }
                dp[i][j]=1+minDistance;
            }
        }
    }

    int distance=dp[m][n];

    for (int i=0; i<=m; i++)
    {
        free(dp[i]);
    }
    free(dp);

    return distance;
}
char* findWord(char *word,char **dictionary, int size)
{
    int min_distance=11;
    char *closestW=NULL;

    for (int i=0; i<size; i++)
    {
        int distance=levenshtein(word,dictionary[i]);

        if (distance<min_distance)
        {
            min_distance=distance;
            closestW=dictionary[i];
        }
    }

    return closestW;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    char **dictionary=(char **)malloc(n*sizeof(char *));
    for (int i=0; i<n; i++) {
        dictionary[i]=(char *)malloc(10*sizeof(char));
        scanf("%s",dictionary[i]);
    }

    getchar();
    char **wordLine=(char **) malloc(m * sizeof(char *));
    for (int j=0; j<m; j++) {
        wordLine[j]=(char *) malloc(150 * sizeof(char));
    }

    for (int i=0; i<m; i++) {
        scanf(" %[^\n]", wordLine[i]);
    }

    for (int i=0; i<m; i++) {
        char *word=strtok(wordLine[i], " ");
        while (word!=NULL) {
            int flag=0;
            for (int j=0; j < n; j++) {
                if (strcmp(word, dictionary[j]) == 0) {
                    flag=1;
                    break;
                }
            }
            if (flag==0) {
                char *closestWord=findWord(word, dictionary, n);
                printf("%s", closestWord);
            } else {
                printf("%s", word);
            }
            word=strtok(NULL, " ");
            if(word != NULL) printf(" ");
        }
        printf("\n");
    }

    for(int i=0;i<n;i++){
        free(dictionary[i]);
    }
    free(dictionary);

    for (int i=0; i<m; i++) {
        free(wordLine[i]);
    }
    free(wordLine);

    return 0;
}
