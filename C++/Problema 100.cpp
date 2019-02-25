#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int kp (int num) {
    char *nums = (char *) malloc(5*sizeof(char));
    char *str = (char *) malloc(5*sizeof(char));
    int num1, num2;
    if (num == 6174) {
        return 0;
    }
    nums[4] = '\0';
    str[4] = '\0';
    str[0] = num/1000+48;
    str[1] = (num-(str[0]-48)*1000)/100+48;
    str[2] = (num-(str[0]-48)*1000-(str[1]-48)*100)/10+48;
    str[3] = num-(str[0]-48)*1000-(str[1]-48)*100-(str[2]-48)*10+48;
    sort(str, str+strlen(str), greater<char>());
    nums[0] = str[0];
    nums[1] = str[1];
    nums[2] = str[2];
    nums[3] = str[3];
    sort(str, str+strlen(str));
    num1 = 0;
    num1 += (nums[0]-48)*1000;
    num1 += (nums[1]-48)*100;
    num1 += (nums[2]-48)*10;
    num1 += (nums[3]-48);
    num2 = 0;
    num2 += (str[0]-48)*1000;
    num2 += (str[1]-48)*100;
    num2 += (str[2]-48)*10;
    num2 += (str[3]-48);
    free(nums);
    free(str);
    return 1+kp(num1-num2);
}

int main () {
    char *str = (char *) malloc(sizeof(char)*5);
    int i, n_casos, num;
    scanf("%d", &n_casos);
    for (i = 0; i < n_casos; i++) {
        scanf("%s", str);
        if (str[0] == str[1] && str[1] == str[2] && str[2] == str[3]) {
            printf("8\n");
        } else {
            num = 0;
            num += (str[0]-48)*1000;
            num += (str[1]-48)*100;
            num += (str[2]-48)*10;
            num += (str[3]-48);
            printf("%d\n", kp(num));
        }
    }
    return 0;
}