#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TODO 10  // 최대 할 일 목록 수
#define MAX_LEN 100  // 할 일 문자열 최대 길이

// 할 일 구조체 정의
typedef struct {
    char task[MAX_LEN];
} Todo;

Todo todos[MAX_TODO];  // 할 일 목록 배열
int todo_count = 0;    // 할 일의 개수

// 할 일 추가 함수
void add_todo() {
    if (todo_count < MAX_TODO) {
        printf("할 일을 입력하세요: ");
        getchar();  // 이전 입력의 개행 문자 제거
        fgets(todos[todo_count].task, MAX_LEN, stdin);
        todos[todo_count].task[strcspn(todos[todo_count].task, "\n")] = 0; // 개행 문자 제거
        todo_count++;
        printf("할 일이 추가되었습니다!\n");
    } else {
        printf("더 이상 할 일을 추가할 수 없습니다. 목록이 가득 찼습니다.\n");
    }
}

// 할 일 목록 출력 함수
void show_todos() {
    if (todo_count == 0) {
        printf("할 일이 없습니다.\n");
        return;
    }

    printf("\n=== 할 일 목록 ===\n");
    for (int i = 0; i < todo_count; i++) {
        printf("%d. %s\n", i + 1, todos[i].task);
    }
}

// 할 일 삭제 함수
void delete_todo() {
    if (todo_count == 0) {
        printf("삭제할 할 일이 없습니다.\n");
        return;
    }

    int num;
    printf("삭제할 할 일의 번호를 입력하세요: ");
    scanf("%d", &num);

    if (num < 1 || num > todo_count) {
        printf("유효하지 않은 번호입니다.\n");
    } else {
        for (int i = num - 1; i < todo_count - 1; i++) {
            todos[i] = todos[i + 1];  // 삭제된 항목을 뒤로 당김
        }
        todo_count--;
        printf("할 일이 삭제되었습니다.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n*** ToDo List 프로그램 ***\n");
        printf("1. 할 일 추가\n");
        printf("2. 할 일 목록 보기\n");
        printf("3. 할 일 삭제\n");
        printf("4. 종료\n");
        printf("선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_todo();
                break;
            case 2:
                show_todos();
                break;
            case 3:
                delete_todo();
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}
