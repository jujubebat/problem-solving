#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char **ft_split(char const *s, char c) {
	int sLen = strlen(s), i,j, tokenCount = 0, *token, idx = 0, cnt = 0;
	char **res;

	i = 0;
	while (i++ < sLen) 
		if (s[i] == c || s[i] == NULL) tokenCount++; 
	token = (int*)malloc(sizeof(int)*tokenCount);
	
	i = 0;
	while (i <= sLen) { 
		cnt++;
		if (s[i] == c || i == sLen) {
			token[idx++] = cnt-1, cnt = 0;
		} 
		i++;
	}
	
	res = (char**)malloc(sizeof(char*)*tokenCount);

	idx = 0;
	for (i = 0; i < tokenCount; i++) {
		res[i] = (char*)malloc(sizeof(char)*(token[i]+1));
		for (j = 0; j < token[i] + 1; j++) {
			res[i][j] = *(s + idx++);
			if (j == token[i]) res[i][j] = NULL;
		}
	}
	return res;
}

int main() {
    char str[20] = "wow,good,happy,fuck";
	char **arr;
	
	arr = ft_split(str, ',');

	for (int i = 0; i < 4; i++) {
		printf("%s ", arr[i]);
	}

	
	for(int j=0; j<100; j++)
		printf("%c", arr[0][j]);
	

	return 0;
}

