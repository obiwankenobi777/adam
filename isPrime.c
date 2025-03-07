#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long int *items;
    long long int top;
    long long int capacity;
} stack;

stack initStack(void);
void push(stack *s, long long int i);
void printStack(stack *s);
void freeStack(stack *s);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Missing parameters!\n");
        return 1;
    }

    long long int number = atoll(argv[1]);

    stack div = initStack();
    long long int i = 2;
    int count = 0;
    for (; i < number; ++i) {
        if (number % i == 0) {
            push(&div, i);
            ++count;
        }
    }

    if (count == 0) {
        printf("The number %lld is a prime number!\n", number);
    }
    else {
        printf("The nubmer %lld isn't a prime number!\n", number);
        printStack(&div);
    }
    putchar('\n');

    freeStack(&div);

    return 0;
}

stack initStack(void) {
    stack s;
    s.top  = 0;
    s.capacity = 2;
    s.items = (long long int*)malloc(s.capacity * sizeof(long long int));

    if (!s.items) {
        printf("Memory allocation failure!\n");
        exit(1);
    }

    return s;
}

void push(stack *s, long long int i) {
    if (s->top == s->capacity) {
        s->capacity *= 2;
        s->items = realloc(s->items, s->capacity * sizeof(long long int));

        if (!s->items) {
        printf("Memory allocation failure!\n");
        exit(1);
        }
    }
    s->items[s->top++] = i;
}

void printStack(stack *s) {
    printf("\nTotal divisors: %d\n", s->top);

    long long i = 0;
    putchar('[');
    for (; i < s->top - 1; ++i) {
        printf("%lld, ", s->items[i]);
    }
    printf("%lld]\n", s->items[i]);
}

void freeStack(stack *s) {
    free(s->items);
    s->items = NULL;
}
