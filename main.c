#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main(void);

void bera31(void) {
    printf("한 번에 세 숫자만 입력할 수 있습니다. \n");
    printf("모든 입력은 띄어쓰기로만 합니다.\n");
    printf("31을 부른 사람이 지게 됩니다. \n");
    printf("제가 먼저 할게요. \n\n");
    printf("컴퓨터 : 1 2 \n");

    int arr[32] = {1, 2, };
    
    for (int i = 0; i < 32; i += 4) {
        int input = 0;
        
        printf("\n");
        
        printf("1 ) : %d\n", arr[i + 1] + 1);
        printf("2 ) : %d %d\n", arr[i + 1] + 1, arr[i + 1] + 2);
        printf("3 ) : %d %d %d\n", arr[i + 1] + 1, arr[i + 1] + 2, arr[i + 1] + 3);
        
        printf("당신 : ");
        scanf(" %d", &input);
        
        if (arr[i + 1] + 1 == 31) {
            printf("\n");
            printf("게임에서 패배하셨습니다. 안녕히 가세요~\n\n");
            main();
        }
        
        arr[i + 2] = arr[i] + 2;
        arr[i + 3] = arr[i] + 3;
        arr[i + 4] = arr[i] + 4;
        arr[i + 5] = arr[i] + 5;
        
        printf("\n");
        
        if (input == 1) {
            printf("당신 : %d\n", arr[i + 2]);
            printf("컴퓨터 : %d %d %d", arr[i + 3], arr[i + 4], arr[i + 5]);
        }
        else if (input == 2) {
            printf("당신 : %d %d\n", arr[i + 2], arr[i + 3]);
            printf("컴퓨터 : %d %d", arr[i + 4], arr[i + 5]);
        }
        else if (input == 3) {
            printf("당신 : %d %d %d\n", arr[i + 2], arr[i + 3], arr[i + 4]);
            printf("컴퓨터 : %d", arr[i + 5]);
        }
        
        printf("\n");
        
    }
}

void setnum(void) {
    printf("0부터 30까지의 수 중 하나를 맞추면 됩니다. \n");
    printf("5번 안에 맞춰야 합니다. \n");
    printf("수가 +2, -2 범위 안에 있으면 근처 도형이 색칠됩니다. \n");
    printf("수가 범위 안에 없으면 아무 일도 일어나지 않습니다. \n");
//
//    srand(time(NULL));
//
    int random = (rand() % 30);

    int arr[31] = {0, };
    
    for (int i = 0; i < 5; i ++) {
        int input = 0;
        
        printf("생각하는 수 입력: ");
        scanf("%d", &input);
        
        if (input == random) {
            printf("수를 맞췄습니다!\n\n");
            main();
        }
        else if (input > 30) {
            printf("다시 입력해주세요: \n\n");
            i --;
            continue;
        }
 
        if (input - 2 <= random && input + 2 >= random) {
            arr[input - 2] = 100;
            arr[input - 1] = 100;
            arr[input] = 100;
            arr[input + 1] = 100;
            arr[input + 2] = 100;
            
            printf("\n");
            printf("무언가 변화가 생겼습니다.\n");
        }
        else {
            printf("\n");
            printf("아무 일도 일어나지 않았습니다.\n");
        }
        
        for (int j = 0; j < 30; j ++) {
            if (arr[j] == 100) {
                printf("★ ");
            }
            else {
                printf("%d ", j);
            }
        }
        printf("\n\n");
    }
    
    printf("안타깝게도 못 맞췄네요...\n");
    printf("정답은 %d.\n\n", random);
    
    main();
}

int main(void) {
    int first_input;
    
    printf("안녕하세요! 게임 모음입니다.\n");
    printf("1 ) 배스킨라빈스 31\n");
    printf("2 ) 숫자 맞추기\n");
    printf("숫자 입력 : ");
    scanf("%d", &first_input);
    printf("\n");
    
    if (first_input == 1) {
        bera31();
    }
    else if (first_input == 2) {
        setnum();
    }
    else {
        printf("다시 입력해주세요 :) \n\n");
        main();
    }
    
    return 0;
}
